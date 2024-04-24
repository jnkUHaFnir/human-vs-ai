// Suppose you have a pre-processed vector of cv::cuda::GpuMat
std::vector<cv::cuda::GpuMat> gpuData = ...;

// Allocate a Tensor<CUDAContext> with the correct dimensions
TensorCUDA* tensor_cuda = workspace.CreateBlob("input")->GetMutable<TensorCUDA>();
tensor_cuda->Resize(std::vector<int64_t>{...}); // Specify dimensions accordingly

// Access the data in the GpuMat and copy it to the Tensor<CUDAContext>
// Assuming gpuData has your processed GpuMat data
for (int i = 0; i < gpuData.size(); i++) {
    const uchar* data = gpuData[i].ptr<uchar>(); // Access GpuMat data pointer

    // Copy the data from GpuMat to the TensorCUDA
    tensor_cuda->mutable_data<uchar>()[i] = new uchar[gpuData[i].rows * gpuData[i].cols * gpuData[i].channels()];
    CUDAContext context;
    context.CopyFromGPU<uchar>(
        data,   // Source data pointer (GpuMat)
        gpuData[i].rows * gpuData[i].cols * gpuData[i].channels(), // Data size
        tensor_cuda->mutable_data<uchar>() + offset,   // Destination data pointer (TensorCUDA)
        &context   // Context for the copy operation
    );
}

