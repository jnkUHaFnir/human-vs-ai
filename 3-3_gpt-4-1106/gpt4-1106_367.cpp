for (blockIndex = 0; blockIndex < FRAMES_PER_BUFFER * numChannels; blockIndex++) {
    float sample = sampleBlockShort[blockIndex];
    sample *= multiplier;
    // Now sample is in double precision, apply clipping
    if (sample > 1.0f) sample = 1.0f;
    if (sample < -1.0f) sample = -1.0f;
    // Write it back to the buffer
    sampleBlockShort[blockIndex] = sample;
}
