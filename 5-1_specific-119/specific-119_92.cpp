#include <caffe2/core/context.h>
#include <caffe2/core/context_gpu.h>
#include <caffe2/core/tensor.h>
#include <opencv2/core/cuda.hpp>
#include <iostream>

// Function to copy data from cv::cuda::GpuMat to caffe2::Tensor<CUDAContext>
void CopyGpuMatToCaffe2Tensor(const cv::cuda::GpuMat& gpu_mat, caffe2::Tensor<caffe2::CUDAContext>* tensor) {
    // Resize the caffe2 tensor to match GPU matrix size
    std::vector<int64_t> dims = {gpu_mat.rows, gpu_mat.cols}; // Assuming 2D data
    tensor->Resize(dims);

    // Get mutable data pointer
    float* data_ptr = tensor->mutable_data<float>();

    // Copy data from GpuMat to tensor
    gpu_mat.download(data_ptr, gpu_mat.step); // Direct download

    // You may need to adjust the download parameters based on your data
    // For more complex data types or different data layouts

    // Example: If the data in GpuMat is in uchar format, and tensor is float
    // gpu_mat.convertTo(tmp_mat, CV_32F); // Convert to float
    // tmp_mat.download(data_ptr, tmp_mat.step); // Download to tensor
}

int main() {
    // Assuming you have a cv::cuda::GpuMat image_mat that you want to copy to a caffe2 tensor
    cv::cuda::GpuMat image_mat(480, 640, CV_8UC3); // Example GpuMat

    // Create a caffe2::Tensor<CUDAContext>
    caffe2::Tensor<caffe2::CUDAContext> tensor;

    // Copy data from GpuMat to caffe2 tensor
    CopyGpuMatToCaffe2Tensor(image_mat, &tensor);

    // Now you can use the tensor in caffe2 framework for further processing or inference

    return 0;
}
