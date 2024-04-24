#include <caffe2/core/context.h>
#include <caffe2/core/context_gpu.h>
#include <caffe2/core/tensor.h>
#include <opencv2/core/cuda.hpp>
#include <vector>

// Function to copy data from cv::cuda::GpuMat to caffe2::Tensor with CUDAContext
void CopyGpuMatToCaffe2Tensor(const cv::cuda::GpuMat& inputGpuMat, caffe2::Tensor<caffe2::CUDAContext>* outputTensor) {
    // Create a new caffe2::Tensor with CUDAContext
    outputTensor->Resize(std::vector<int>{inputGpuMat.rows, inputGpuMat.cols});

    // Allocate memory on the GPU for the outputTensor
    outputTensor->mutable_data<float>();

    // Copy data from cv::cuda::GpuMat to caffe2::Tensor with CUDAContext
    cudaMemcpy(outputTensor->mutable_data<float>(), inputGpuMat.data, inputGpuMat.rows * inputGpuMat.step, cudaMemcpyDeviceToDevice);
}

int main() {
    // Example of copying data from cv::cuda::GpuMat to caffe2::Tensor with CUDAContext
    cv::cuda::GpuMat gpuMatData(256, 256, CV_32F);  // Example cv::cuda::GpuMat data

    // Create a caffe2::Tensor with CUDAContext
    caffe2::Tensor<caffe2::CUDAContext> outputTensor;

    // Copy data from cv::cuda::GpuMat to caffe2::Tensor
    CopyGpuMatToCaffe2Tensor(gpuMatData, &outputTensor);

    return 0;
}
