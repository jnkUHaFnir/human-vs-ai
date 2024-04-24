#include <caffe2/core/context_gpu.h>
#include <caffe2/core/tensor.h>

#include <opencv2/core/cuda.hpp>
#include <opencv2/core/cuda/vec_traits.hpp>

void CopyGpuMatToCaffe2Tensor(const cv::cuda::GpuMat& gpuMat, caffe2::TensorCUDA* tensorCUDA) {
    // Resize the Caffe2 Tensor to match the GpuMat
    tensorCUDA->Resize(gpuMat.rows, gpuMat.cols);

    // Get mutable data pointer
    float* tensorData = tensorCUDA->mutable_data<float>();

    // Access the underlying data from GpuMat
    cv::cuda::PtrStepSz<float> gpuMatData = gpuMat;
    
    // Copy data from GpuMat to Caffe2 Tensor
    const int numElems = gpuMat.rows * gpuMat.cols;
    CUDA_CHECK(cudaMemcpy(tensorData, gpuMatData.data, numElems * sizeof(float), cudaMemcpyDeviceToDevice));
}

int main() {
    // Assuming you have a cv::cuda::GpuMat named gpuMat
    // and a Caffe2 CUDA Tensor named tensorCUDA
    cv::cuda::GpuMat gpuMat(/* initialize your GpuMat here */);
    caffe2::TensorCUDA tensorCUDA;

    CopyGpuMatToCaffe2Tensor(gpuMat, &tensorCUDA);

    return 0;
}
