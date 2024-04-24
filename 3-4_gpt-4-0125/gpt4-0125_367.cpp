float* sampleBlockFloat = (float*)sampleBlock;
for (int blockIndex = 0; blockIndex < FRAMES_PER_BUFFER * numChannels; ++blockIndex) {
    // Apply the gain
    double dSample = (double)sampleBlockFloat[blockIndex] * multiplier;

    // Clipping check - since we are in floating point, just ensure we do not exceed the -1.0 to 1.0 range
    if (dSample > 1.0) dSample = 1.0;
    else if (dSample < -1.0) dSample = -1.0;

    // Write back the possibly clipped value
    sampleBlockFloat[blockIndex] = (float)dSample;
}
