while (1) {
    // You may get underruns or overruns if the output is not primed by PortAudio.
    err = Pa_ReadStream( stream, sampleBlock, FRAMES_PER_BUFFER );
    if( err ) xrun(stream, err, sampleBlock);

    float* sampleBlockFloat = (float*)sampleBlock;
    for (int blockIndex = 0; blockIndex < FRAMES_PER_BUFFER * numChannels; blockIndex++) {
        double dSample = (double)sampleBlockFloat[blockIndex];
        
        // Apply gain multiplication
        dSample *= multiplier;
        
        // Apply clipping
        if (dSample > 1.0) {
            dSample = 1.0;
        } else if (dSample < -1.0) {
            dSample = -1.0;
        }
        
        sampleBlockFloat[blockIndex] = (float)dSample;
    }

    err = Pa_WriteStream( stream, sampleBlock, FRAMES_PER_BUFFER );
    if( err ) xrun(stream, err, sampleBlock);
}
