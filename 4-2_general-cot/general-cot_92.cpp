#include <caffe2/core/context_gpu.h>
#include <caffe2/core/tensor.h>
#include <opencv2/core/cuda.hpp>
#include <vector>

// Function to copy data from device memory (cv::cuda::GpuMat) to TensorCUDA
void CopyDeviceMemoryToTensor(const std::vector<cv::cuda::GpuMat>& deviceData, caffe2::Tensor<caffe2::CUDAContext>* tensor) {
    // Assuming deviceData is a vector of cv::cuda::GpuMat

    // Resizing the target Tensor
    std::vector<int64_t> dims = {deviceData[0].rows, deviceData[0].cols}; // Assuming GpuMat dimensions
    tensor->Resize(dims);

    // Assuming the GpuMat data type is float (adjust this based on your data type)
    float* tensorData = tensor->mutable_data<float>();

    // Iterating over GpuMat vector and copying data to Tensor
    for (int i = 0; i < deviceData.size(); i++) {
        cudaMemcpy(tensorData, deviceData[i].ptr<float>(), deviceData[i].step * deviceData[i].rows, cudaMemcpyDeviceToDevice);
        tensorData += deviceData[i].size().area(); // Adjust depending on your data layout
    }
}

// Usage example
int main() {
    std::vector<cv::cuda::GpuMat> deviceData; // Assume this contains your data

    // Create a new CUDAContext and TensorCUDA
    caffe2::CUDAContext context;
    caffe2::Tensor<caffe2::CUDAContext> tensor(&context);

    // Copy data from device memory to TensorCUDA
    CopyDeviceMemoryToTensor(deviceData, &tensor);

    // Now you can use 'tensor' in other parts of your code
    return 0;
}
