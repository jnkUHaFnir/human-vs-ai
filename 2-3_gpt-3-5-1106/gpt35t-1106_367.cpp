while (1) {
    // ...
    err = Pa_ReadStream( stream, sampleBlock, FRAMES_PER_BUFFER );
    if( err ) xrun(stream, err, sampleBlock);

    float* sampleBlockFloat = (float*)sampleBlock;

    for (int blockIndex = 0; blockIndex < FRAMES_PER_BUFFER; blockIndex++) {
        sampleBlockFloat[blockIndex] *= multiplier;

        // Apply clipping to maintain quality
        if (sampleBlockFloat[blockIndex] > 1.0) {
            sampleBlockFloat[blockIndex] = 1.0;
        } else if (sampleBlockFloat[blockIndex] < -1.0) {
            sampleBlockFloat[blockIndex] = -1.0;
        }
    }

    err = Pa_WriteStream( stream, sampleBlock, FRAMES_PER_BUFFER );
    if( err ) xrun(stream, err, sampleBlock);
}
