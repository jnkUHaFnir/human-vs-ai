#include <opencv2/core/cuda.hpp>
#include <caffe2/core/context.h>
#include <caffe2/core/context_gpu.h>
#include <caffe2/core/tensor.h>

void copyGpuMatToCaffe2Tensor(const cv::cuda::GpuMat& gpuMat, caffe2::Tensor<caffe2::CUDAContext>* tensor) {
    // Make sure the shapes match
    tensor->Resize(gpuMat.rows, gpuMat.cols);

    // Get a pointer to the data in the tensor
    float* tensor_data = tensor->mutable_data<float>();

    // Copy data from GpuMat to tensor
    cudaMemcpy(tensor_data, gpuMat.data, gpuMat.rows * gpuMat.cols * sizeof(float), cudaMemcpyDeviceToDevice);
}

int main() {
    // Assuming you have a cv::cuda::GpuMat called gpuMat with data

    // Create a caffe2::Tensor on CUDA context
    caffe2::Tensor<caffe2::CUDAContext> tensor;

    // Copy data from GpuMat to caffe2::Tensor
    copyGpuMatToCaffe2Tensor(gpuMat, &tensor);

    return 0;
}
