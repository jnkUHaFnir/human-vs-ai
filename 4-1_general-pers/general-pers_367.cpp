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

// Use tinycon and a second thread for non-blocking input
class tcon : public tinyConsole
{
public:
    tcon(std::string s) : tinyConsole(s) {}

    int hotkeys(char c)
    {
        if (c == 's' && multiplier >= 0 + multiplierStep)
        {
            multiplier -= multiplierStep;
            std::cout << "Multiplier: " << multiplier << std::endl;
            return 1;
        }
        else if (c == 'w')
        {
            multiplier += multiplierStep;
            std::cout << "Multiplier: " << multiplier << std::endl;
            return 1;
        }
        return 0;
    }
};

int inputThread()
{
    tcon tc("");
    tc.run();
}

void listDevices()
{
    Pa_Initialize();

    int numDevices = Pa_GetDeviceCount();

    std::cout << "Number of devices = " << numDevices << std::endl;
    for (int i = 0; i < numDevices; i++)
    {
        const PaDeviceInfo *deviceInfo = Pa_GetDeviceInfo(i);
        std::cout << (deviceInfo->maxInputChannels > 0 ? "Input" : "Output") << " Device ID: " << i << ", Name: " << deviceInfo->name << std::endl;
    }

    std::cout << "Press any key to close" << std::endl;
    std::cin.get();
}

int main(int argc, char **argv)
{
    // Handle command line arguments, device selection, etc.

    PaStream *stream = nullptr;
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError)
    {
        error2(stream, err);
    }

    // Setup input and output parameters, open stream, allocate sample block, and start stream

    while (true)
    {
        float sampleBlock[FRAMES_PER_BUFFER];
        err = Pa_ReadStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err)
        {
            xrun(stream, err, sampleBlock);
        }

        for (int blockIndex = 0; blockIndex < FRAMES_PER_BUFFER; blockIndex++)
        {
            float sample = sampleBlock[blockIndex] * multiplier;
            // Apply clipping
            sample = std::min(1.0f, std::max(-1.0f, sample));
            sampleBlock[blockIndex] = sample;
        }

        err = Pa_WriteStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err)
        {
            xrun(stream, err, sampleBlock);
        }
    }

    Pa_Terminate();
    return 0;
}

int xrun(PaStream *stream, int err, float *sampleBlock)
{
    std::cout << "Error: " << err << std::endl;

    if (stream)
    {
        Pa_AbortStream(stream);
        Pa_CloseStream(stream);
    }
    Pa_Terminate();
    if (err & paInputOverflow)
    {
        std::cerr << "Input Overflow." << std::endl;
    }
    if (err & paOutputUnderflow)
    {
        std::cerr << "Output Underflow." << std::endl;
    }
    return -2;
}

void error1(PaStream *stream, float *sampleBlock)
{
    if (stream)
    {
        Pa_AbortStream(stream);
        Pa_CloseStream(stream);
    }
    Pa_Terminate();
    exit(-1);
}

void error2(PaStream *stream, int err)
{
    if (stream)
    {
        Pa_AbortStream(stream);
        Pa_CloseStream(stream);
    }
    Pa_Terminate();
    std::cerr << "An error occurred while using the portaudio stream" << std::endl;
    std::cerr << "Error number: " << err << std::endl;
    std::cerr << "Error message: " << Pa_GetErrorText(err) << std::endl;
    exit(-1);
}
