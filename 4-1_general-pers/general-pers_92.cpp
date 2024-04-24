#include <caffe2/core/context.h>
#include <caffe2/core/context_gpu.h>
#include <caffe2/core/tensor.h>
#include <opencv2/core/cuda.hpp>
#include <vector>

// Function to copy data from a vector of cv::cuda::GpuMat to a caffe2::Tensor<CUDAContext>
void CopyGpuMatToCaffe2Tensor(const std::vector<cv::cuda::GpuMat>& gpuMatVector, caffe2::Tensor<caffe2::CUDAContext>* tensor) {
    // Check if the dimensions match
    CAFFE_ENFORCE_EQ(tensor->size(), gpuMatVector.size(), "Number of dimensions do not match");

    // Iterate over each GpuMat and copy data to the corresponding dimension in the tensor
    for (int i = 0; i < gpuMatVector.size(); ++i) {
        cv::cuda::GpuMat gpuMat = gpuMatVector[i];
        
        // Get the pointer to the device data in GpuMat
        uchar* gpuDataPointer = gpuMat.ptr<uchar>();

        // Copy the data to the corresponding dimension in the tensor
        cudaMemcpy(tensor->mutable_data<uchar>() + i * gpuMat.total(), gpuDataPointer, gpuMat.total(), cudaMemcpyDeviceToDevice);
    }
}

int main() {
    // Assuming you have a vector of cv::cuda::GpuMat
    std::vector<cv::cuda::GpuMat> gpuMatVector;

    // Assuming you have a caffe2::Tensor<CUDAContext> tensor with correct dimensions
    caffe2::Tensor<caffe2::CUDAContext> caffe2Tensor;

    // Call the function to copy data from GpuMat to Tensor
    CopyGpuMatToCaffe2Tensor(gpuMatVector, &caffe2Tensor);

    return 0;
}
