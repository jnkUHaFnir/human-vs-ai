#include "portaudio.h"
#include <iostream>

#define SAMPLE_RATE  (44100)
#define FRAMES_PER_BUFFER   (441)
#define DITHER_FLAG           (1)
#define PA_SAMPLE_TYPE  paFloat32
#define SAMPLE_SIZE (4)
#define SAMPLE_SILENCE  (0)

double multiplier = 1.0;

int main()
{
    PaStreamParameters inputParameters, outputParameters;
    PaStream *stream = nullptr;
    PaError err;
    float* sampleBlock = nullptr;

    err = Pa_Initialize();
    if (err != paNoError)
    {
        std::cerr << "PortAudio initialization error: " << Pa_GetErrorText(err) << std::endl;
        return -1;
    }

    // Configure input and output parameters

    // Open the stream
    err = Pa_OpenStream(&stream, &inputParameters, &outputParameters, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, nullptr, nullptr);
    if (err != paNoError)
    {
        std::cerr << "PortAudio stream error: " << Pa_GetErrorText(err) << std::endl;
        Pa_Terminate();
        return -1;
    }

    // Start the stream
    err = Pa_StartStream(stream);
    if (err != paNoError)
    {
        std::cerr << "PortAudio start stream error: " << Pa_GetErrorText(err) << std::endl;
        Pa_CloseStream(stream);
        Pa_Terminate();
        return -1;
    }

    while (true)
    {
        // Read samples from the input stream
        err = Pa_ReadStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err != paNoError)
        {
            std::cerr << "PortAudio read stream error: " << Pa_GetErrorText(err) << std::endl;
            break;
        }

        // Apply gain adjustment
        for (int i = 0; i < FRAMES_PER_BUFFER; i++)
        {
            sampleBlock[i] *= multiplier;

            // Apply clipping
            if (sampleBlock[i] > 1.0f)
            {
                sampleBlock[i] = 1.0f;
            }
            else if (sampleBlock[i] < -1.0f)
            {
                sampleBlock[i] = -1.0f;
            }
        }

        // Write the processed samples to the output stream
        err = Pa_WriteStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err != paNoError)
        {
            std::cerr << "PortAudio write stream error: " << Pa_GetErrorText(err) << std::endl;
            break;
        }
    }

    // Stop and clean up
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();

    return 0;
}
