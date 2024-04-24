    // assume that you have pre-processed your images and are now splitting
    // the data along three channels. You can also split into
    // one cv::cuda::GpuMat but I kept getting SEGFAULTs so gave up
    // on that one
    std::vector<cv::cuda::GpuMat> input_channels(sample.channels());
    cv::cuda::split(mfloat, input_channels);
    caffe2::TensorCUDA tensor;
    std::vector<caffe2::TIndex> dims({1, channels, rows, cols});
    tensor.Resize(dims);
    
    // the tensor is rows * cols (224 * 224) = 50176 * 3 (channels) = 150528
    float * t_ptr = tensor.mutable_data<float>();
    unsigned int i = 0;
    for (const auto & gpu_mat : input_channels) {
        // pointer to GPU Matrix
        const void * src = gpu_mat.ptr<float>();
        // size of GPU Matrix = rows * cols
        size_t count = (gpu_mat.rows * gpu_mat.cols);
        // set tensor pointer
        void * dst = &t_ptr[i];
        // copy from device to device
        auto res = cudaMemcpy(dst, src, count, cudaMemcpyDeviceToDevice);
        if (res != cudaSuccess) {
            throw std::runtime_error(cudaGetErrorName(res));
        }
        i += count;
    }