#include <algorithm>

// ...

while (1) {
    // Read the input stream
    err = Pa_ReadStream(stream, sampleBlock, FRAMES_PER_BUFFER);
    if (err) xrun(stream, err, sampleBlock);

    int blockIndex;
    float* sampleBlockFloat = (float*)sampleBlock;

    // Find the maximum and minimum sample value in the input buffer
    float maxSample = *std::max_element(sampleBlockFloat, sampleBlockFloat + FRAMES_PER_BUFFER);
    float minSample = *std::min_element(sampleBlockFloat, sampleBlockFloat + FRAMES_PER_BUFFER);

    // Calculate the optimal gain that avoids clipping
    float optimalGain = std::min(multiplier, 1.0f / std::max(std::fabs(maxSample), std::fabs(minSample)));

    // Apply the optimal gain to each sample in the input buffer
    for (blockIndex = 0; blockIndex < FRAMES_PER_BUFFER; blockIndex++) {
        sampleBlockFloat[blockIndex] *= optimalGain;
    }

    // Write the output stream
    err = Pa_WriteStream(stream, sampleBlock, FRAMES_PER_BUFFER);
    if (err) xrun(stream, err, sampleBlock);
}
