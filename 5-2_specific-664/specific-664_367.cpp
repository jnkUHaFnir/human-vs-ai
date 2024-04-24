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

int main (int argc, char **argv)
{
    // Your initialization code remains the same

    while (1) {
        err = Pa_ReadStream( stream, sampleBlock, FRAMES_PER_BUFFER );
        if( err ) xrun(stream, err, sampleBlock);

        float* sampleBlockFloat = (float*)sampleBlock;
        for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
            // Applying gain multiplication to each sample
            sampleBlockFloat[i] = sampleBlockFloat[i] * multiplier;

            // Applying clipping to prevent overflow
            if (sampleBlockFloat[i] > 1.0) {
                sampleBlockFloat[i] = 1.0;
            } else if (sampleBlockFloat[i] < -1.0) {
                sampleBlockFloat[i] = -1.0;
            }
        }

        err = Pa_WriteStream( stream, sampleBlock, FRAMES_PER_BUFFER );
        if( err ) xrun(stream, err, sampleBlock);
    }

    // Cleanup code remains the same

    return 0;
}

// Error handling functions remain the same
