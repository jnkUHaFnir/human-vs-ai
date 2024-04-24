#include <cuda_runtime_api.h>
#include <opencv2/core/cuda.hpp>
#include <caffe2/core/context.h>
#include <caffe2/core/tensor.h>

template <typename T>
void copyDataToCaffe2Tensor(const std::vector<cv::cuda::GpuMat>& data, caffe2::Tensor<caffe2::CUDAContext>* tensor) {
    // Resize the tensor to match the data dimensions
    tensor->Resize(data.size());

    // Mutable data pointer to write data into Tensor
    T* tensor_data = tensor->mutable_data<T>();

    for (int i = 0; i < data.size(); ++i) {
        cv::cuda::GpuMat gpuMat = data[i];

        // Assuming T is float for this example, adjust if needed
        cudaMemcpy(tensor_data, gpuMat.data, gpuMat.step * gpuMat.rows, cudaMemcpyDeviceToDevice);

        // Move the pointer to next address in the tensor data
        tensor_data += gpuMat.total();  
    }
}

int main() {
    // Assuming you have your cv::cuda::GpuMat data in a vector
    std::vector<cv::cuda::GpuMat> gpuMatData = ...; 

    // Create a new CUDAContext tensor
    caffe2::Tensor<caffe2::CUDAContext> cudaTensor;

    // Copy data from cv::cuda::GpuMat to caffe2::Tensor
    copyDataToCaffe2Tensor<float>(gpuMatData, &cudaTensor);

    return 0;
}
