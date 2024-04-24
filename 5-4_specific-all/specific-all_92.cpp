#include <opencv2/opencv.hpp>
#include <caffe2/core/context.h>
#include <caffe2/core/tensor.h>

// Assuming you have your image data in cv::cuda::GpuMat
cv::cuda::GpuMat imgData = ... // Your image data

// Iterate over imgData and copy it to a std::vector<cv::cuda::GpuMat>
std::vector<cv::cuda::GpuMat> gpuMatVector;
// Fill gpuMatVector with imgData elements

// Create a new Caffe2 tensor with the correct dimensions
caffe2::TensorCPU cpuTensor(caffe2::TensorShape{your_dimensions_here});

// Iterate over gpuMatVector and copy data to Caffe2 CPU tensor
for (int i = 0; i < gpuMatVector.size(); ++i) {
    cv::cuda::GpuMat& gpuMat = gpuMatVector[i];
    // Use cuda::PtrStepSz or cuda::PtrStep to access data in gpuMat
    // and copy it to the CPU tensor
    // Be careful about memory alignment and data types
}

// Create a new Caffe2 CUDA tensor and copy data from CPU tensor
caffe2::CUDAContext context;
caffe2::TensorCUDA cudaTensor(&context);
cudaTensor.CopyFrom(cpuTensor);

// Now you have your data in a Caffe2 CUDA tensor
