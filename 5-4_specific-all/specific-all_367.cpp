// Inside the main loop where you process the samples
while (1) {
    err = Pa_ReadStream(stream, sampleBlock, FRAMES_PER_BUFFER);
    if (err) xrun(stream, err, sampleBlock);

    float* sampleBlockFloat = (float*)sampleBlock;
    for (int i = 0; i < FRAMES_PER_BUFFER * numChannels; i++) {
        double sample = sampleBlockFloat[i];
        // Apply gain multiplication in higher precision
        sample *= multiplier;

        // Clipping
        if (sample > 1.0) sample = 1.0;
        if (sample < -1.0) sample = -1.0;

        sampleBlockFloat[i] = (float)sample;
    }

    err = Pa_WriteStream(stream, sampleBlock, FRAMES_PER_BUFFER);
    if (err) xrun(stream, err, sampleBlock);
}
