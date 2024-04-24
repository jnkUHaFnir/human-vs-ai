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
int xrun(PaStream *stream, int err, float* sampleBlock);
void error1(PaStream *stream, float* sampleBlock);
void error2(PaStream *stream, int err);
void listDevices();

// Use tinycon and a second thread for non blocking input
class tcon : public tinyConsole
{
public:
    tcon(std::string s) : tinyConsole(s) {}

    int hotkeys(char c)
    {
        if (c == 's')
        {
            if (multiplier >= (0 + multiplierStep))
            {
                multiplier -= multiplierStep;
            }
            printf("Multiplier: %f\n", multiplier);
            return 1;
        }
        if (c == 'w')
        {
            multiplier += multiplierStep;
            printf("Multiplier: %f\n", multiplier);
            return 1;
        }
        return 0;
    }
};
int inputThread(){
    tcon tc(std::string(""));
    tc.run();
}

void listDevices(){
    int i, numDevices, defaultDisplayed;
    const PaDeviceInfo *deviceInfo;

    Pa_Initialize();

    numDevices = Pa_GetDeviceCount();

    printf("Number of devices = %d\n", numDevices);
    int isInputDevice = 0;
    for (i = 0; i < numDevices; i++)
    {
        deviceInfo = Pa_GetDeviceInfo(i);
        int isInputDevice = (deviceInfo->maxInputChannels > 0);
        printf("%sDeviceID: %d, Name: %s\n", (isInputDevice ? "Input" : "Output"), i, deviceInfo->name);
    }
    fprintf(stderr, "Press any key to close\n");
    getch();
}

int main(int argc, char **argv)
{
    // Initialize PortAudio and other variables

    while (1)
    {
        // Read input stream
        err = Pa_ReadStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err)
            xrun(stream, err, sampleBlock);

        // Apply gain to the samples
        float *fSampleBlock = (float *)sampleBlock;
        for (int blockIndex = 0; blockIndex < FRAMES_PER_BUFFER; blockIndex++)
        {
            // Convert to higher precision format
            double dSample = fSampleBlock[blockIndex];
            dSample *= multiplier;

            // Apply clipping
            if (dSample > 1.0)
                dSample = 1.0;
            else if (dSample < -1.0)
                dSample = -1.0;

            // Convert back to original format
            fSampleBlock[blockIndex] = (float)dSample;
        }

        // Write output stream
        err = Pa_WriteStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err)
            xrun(stream, err, sampleBlock);
    }

    // Cleanup and return
}

