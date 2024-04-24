#include <caffe2/core/context_gpu.h>
#include <caffe2/core/tensor.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>

void copyDeviceDataToCaffe2Tensor(cv::cuda::GpuMat& deviceData, caffe2::Tensor<caffe2::CUDAContext>* tensor) {
    // Assuming deviceData is in float format
    float* deviceDataPtr = (float*)deviceData.ptr();

    // Resize the Caffe2 CUDA tensor to match the dimensions of deviceData
    std::vector<int> dims = {deviceData.rows, deviceData.cols};
    tensor->Resize(dims);

    // Get the mutable data pointer of the tensor
    float* tensorDataPtr = tensor->mutable_data<float>();

    // Copy data from device memory to Caffe2 CUDA tensor
    cudaMemcpy(tensorDataPtr, deviceDataPtr, deviceData.rows * deviceData.cols * sizeof(float), cudaMemcpyDeviceToDevice);
}

int main() {
    // Assuming you have a cv::cuda::GpuMat object named deviceImage
    cv::cuda::GpuMat deviceImage;

    // Assuming you have a Caffe2 CUDA tensor object
    caffe2::Tensor<caffe2::CUDAContext> caffe2Tensor;

    // Copy data from deviceImage to caffe2Tensor
    copyDeviceDataToCaffe2Tensor(deviceImage, &caffe2Tensor);

    return 0;
}
