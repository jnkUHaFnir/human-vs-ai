#include <opencv2/core/cuda.hpp>
#include <caffe2/core/tensor.h>

// Assuming you have cv::cuda::GpuMat data_gpu as input

// Create a new CUDAContext
caffe2::CUDAContext context_for_copy;

// Construct a tensor with the correct dimensions
caffe2::Tensor<caffe2::CUDAContext> tensor_cuda;
tensor_cuda.Resize({rows, cols});

// Get mutable data pointer
float* tensor_data = tensor_cuda.mutable_data<float>();

// Iterate through your std::vector<cv::cuda::GpuMat>
for (const auto& gpu_mat : your_gpu_mat_vector) {
    // Get access to the underlying device allocated data
    cv::cuda::PtrStepSz<float> ptr_step(gpu_mat.rows, gpu_mat.cols, gpu_mat.data);

    // Copy data from cv::cuda::GpuMat to tensor
    cudaMemcpy(tensor_data, ptr_step.data, rows * cols * sizeof(float), cudaMemcpyDeviceToDevice);

    // Update tensor data pointer for next iteration
    tensor_data += rows * cols;
}
