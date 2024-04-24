#define SAMPLE_SIZE (8)  // For double precision
for (blockIndex = 0; blockIndex < FRAMES_PER_BUFFER; blockIndex++) {
    double sample = sampleBlockShort[blockIndex];
    sample *= multiplier;
    
    // Apply clipping
    if (sample > 1.0) {
        sample = 1.0;
    } else if (sample < -1.0) {
        sample = -1.0;
    }

    sampleBlockShort[blockIndex] = static_cast<float>(sample);
}
