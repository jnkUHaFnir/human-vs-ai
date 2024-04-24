#include "portaudio.h"
#include <iostream>
#include <thread>
#include <mutex>
#include "tinycon.h"

#define SAMPLE_RATE       (44100)
#define FRAMES_PER_BUFFER (441)
#define DITHER_FLAG       (1)

// Use double for higher precision calculations
#define PA_SAMPLE_TYPE    paFloat64
#define SAMPLE_SIZE       (8)

/*******************************************************************/
double multiplier = 1.0;
double multiplierStep = 0.1;

int main(int argc, char **argv);
void listDevices();

void applyGain(float* samples, int numSamples, double gain) {
    for (int i = 0; i < numSamples; i++) {
        // Apply gain and clip the values
        samples[i] *= gain;
        if (samples[i] > 1.0) {
            samples[i] = 1.0;
        } else if (samples[i] < -1.0) {
            samples[i] = -1.0;
        }
    }
}

int main(int argc, char **argv) {
    // Your existing code for device selection and initialization

    while (1) {
        err = Pa_ReadStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err) xrun(stream, err, sampleBlock);

        float* sampleBlockFloat = (float*)sampleBlock;

        // Convert to higher precision format for gain calculation
        double* sampleBlockDouble = new double[FRAMES_PER_BUFFER];
        for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
            sampleBlockDouble[i] = sampleBlockFloat[i];
        }

        // Apply gain using higher precision and clip
        applyGain(sampleBlockDouble, FRAMES_PER_BUFFER, multiplier);

        // Cast back to original format for output
        for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
            sampleBlockFloat[i] = static_cast<float>(sampleBlockDouble[i]);
        }

        delete[] sampleBlockDouble;

        err = Pa_WriteStream(stream, sampleBlock, FRAMES_PER_BUFFER);
        if (err) xrun(stream, err, sampleBlock);
    }

    // Your existing cleanup code

    return 0;
}
