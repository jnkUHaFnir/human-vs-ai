#include "portaudio.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include "tinycon.h"

#define SAMPLE_RATE       (44100)
#define FRAMES_PER_BUFFER   (441)
#define DITHER_FLAG           (1)

#define PA_SAMPLE_TYPE  paFloat32
#define SAMPLE_SIZE (4)
#define SAMPLE_SILENCE  (0)
#define PRINTF_S_FORMAT "%f"

/*******************************************************************/
double multiplier = 1.0;
double multiplierStep = 0.1;
int main(int argc, char **argv);
int xrun(PaStream *stream, int err, char* sampleBlock);
void error1(PaStream *stream, char* sampleBlock);
void error2(PaStream *stream, int err);
void listDevices();

// Use tinycon and a second thread for non blocking input
class tcon : public tinyConsole
{
public:
    tcon (std::string s): tinyConsole(s) {;}

    int hotkeys(char c)
    {
        if (c == 's') {
            if (multiplier >= (0+multiplierStep)) {
                multiplier -= multiplierStep;
            }
            printf( "Multiplier: %f\n", multiplier );
            return 1;
        }
        if (c == 'w') {
            multiplier += multiplierStep;
            printf( "Multiplier: %f\n", multiplier );
            return 1;
        }
        return 0;
    }
};

int inputThread() {
    tcon tc (std::string(""));
    tc.run();
}

void listDevices() {
    int i, numDevices, defaultDisplayed;
    const PaDeviceInfo *deviceInfo;

    Pa_Initialize();

    numDevices = Pa_GetDeviceCount();

    printf( "Number of devices = %d\n", numDevices );
    int isInputDevice = 0;
    for( i=0; i<numDevices; i++ )
    {
        deviceInfo = Pa_GetDeviceInfo( i );
        int isInputDevice = (deviceInfo->maxInputChannels > 0);
        printf( "%sDeviceID: %d, Name: %s\n", (isInputDevice ? "Input" : "Output"), i, deviceInfo->name);
    }
    fprintf (stderr, "Press any key to close\n");
    getch();
}

int main(int argc, char **argv)
{
    int c;
    int inputDeviceId = -1;
    int outputDeviceId = -1;
    opterr = 0;
    const char* helpMessage =
            "-h : show this help message\n"
            "-i <int> : select the INPUT DEVICE by id\n"
            "-o <int> : select the OUPUT DEVICE by id\n"
            "-m <double> : SIGNAL MULTIPLIER\n"
            "-s <double> : SIGNAL MULTIPLIER STEP (press w or s while console focused to go up and down by this amount.\n"
            "-d : list devices\n";

    while ((c = getopt (argc, argv, "i:o:l:m:s:hd")) != -1) {
        switch (c) {
            case 'i':
                inputDeviceId = atoi(optarg);
                break;
            case 'o':
                outputDeviceId = atoi(optarg);
                break;
            case 'm':
                multiplier = atof(optarg);
                break;
            case 's':
                multiplierStep = atof(optarg);
                break;
            case 'd':
                listDevices();
                return 0;
            case '?':
                if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
            case 'h':
                fprintf (stderr, helpMessage);
                fprintf (stderr, "Press any key to close\n");
                getch();
                return 1;
            default:
                abort ();
        }
    }

    // Start non-blocking input thread
    std::thread nonBlockingInputThread(inputThread);

    PaStreamParameters inputParameters, outputParameters;
    PaStream *stream = NULL;
    PaError err;
    const PaDeviceInfo *inputInfo;
    const PaDeviceInfo *outputInfo;
    char *sampleBlock = NULL;
    int i;
    int numBytes;
    int numChannels;

    err = Pa_Initialize();
    if( err != paNoError ) error2(stream, err);

    inputParameters.device = (inputDeviceId == -1) ? Pa_GetDefaultInputDevice() : inputDeviceId; /* default input device */
    inputInfo = Pa_GetDeviceInfo(inputParameters.device);
    outputParameters.device = (outputDeviceId == -1) ? Pa_GetDefaultOutputDevice() : outputDeviceId; /* default output device */
    outputInfo = Pa_GetDeviceInfo(outputParameters.device);

    numChannels = inputInfo->maxInputChannels < outputInfo->maxOutputChannels
                  ? inputInfo->maxInputChannels : outputInfo->maxOutputChannels;

    inputParameters.channelCount = numChannels;
    inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    inputParameters.suggestedLatency = inputInfo->defaultHighInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;
    printf("Input device # %d.\n", inputParameters.device);
    printf("    Name: %s\n", inputInfo->name);

    outputParameters.channelCount = numChannels;
    outputParameters.sampleFormat = PA_SAMPLE_TYPE;
    outputParameters.suggestedLatency = outputInfo->defaultHighOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;
    printf("Output device # %d.\n", outputParameters.device);
    printf("    Name: %s\n", outputInfo->name);

    /* -- setup -- */

    err = Pa_OpenStream(
            &stream,
            &inputParameters,
            &outputParameters,
            SAMPLE_RATE,
            FRAMES_PER_BUFFER,
            paClipOff,      /* we won't output out of range samples so don't bother clipping them */
            NULL, /* no callback, use blocking API */
            NULL); /* no callback, so no callback userData */
    if (err != paNoError) error2(stream, err);

    numBytes = FRAMES_PER_BUFFER * numChannels * SAMPLE_SIZE;
    sampleBlock = (char *) malloc(numBytes);
    if (sampleBlock == NULL)
    {
        printf("Could not allocate record array.\n");
        error1(stream, sampleBlock);
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) error1(stream, sampleBlock);

    while (1) {
        // You may get underruns or overruns if the output is not primed by PortAudio.
        err = Pa_ReadStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err) xrun(stream, err, sampleBlock);

        float* sampleBlockFloat = (float*) sampleBlock;
        for (int blockIndex = 0; blockIndex < FRAMES_PER_BUFFER * numChannels; blockIndex++) {
            double dSample = sampleBlockFloat[blockIndex];
            dSample *= multiplier;

            // Apply clipping
            if (dSample > 1.0) dSample = 1.0; // Upper limit
            if (dSample < -1.0) dSample = -1.0; // Lower limit

            sampleBlockFloat[blockIndex] = (float) dSample;
        }

        err = Pa_WriteStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err) xrun(stream, err, sampleBlock);
    }
    printf("Wire off.\n");

    err = Pa_StopStream(stream);
    if (err != paNoError) error1(stream, sampleBlock);

    free(sampleBlock);

    Pa_Terminate();
    return 0;
}

int xrun(PaStream *stream, int err, char *sampleBlock) {
    printf("err = %d\n", err);
    if (stream) {
        Pa_AbortStream(stream);
        Pa_CloseStream(stream);
    }
    free(sampleBlock);
    Pa_Terminate();
    if (err & paInputOverflow)
        fprintf(stderr, "Input Overflow.\n");
    if (err & paOutputUnderflow)
        fprintf(stderr, "Output Underflow.\n");
    return -2;
}

void error1(PaStream *stream, char *sampleBlock) {
    free(sampleBlock);
    exit(-1);
}

void error2(PaStream *stream, int err) {
    if (stream) {
        Pa_AbortStream(stream);
        Pa_CloseStream(stream);
    }
    Pa_Terminate();
    fprintf(stderr, "An error occurred while using the PortAudio stream\n");
    fprintf(stderr, "Error number: %d\n", err);
    fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
    exit(-1);
}
