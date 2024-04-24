// Assuming you have set up your CUDAContext
TensorCUDA tensor_cuda(...); // Initialize your TensorCUDA
tensor_cuda.Resize(...); // Set the dimensions as needed
float* data_ptr = tensor_cuda.mutable_data<float>(); // Get mutable data pointer
// Assuming you have data stored in std::vector<cv::cuda::GpuMat> named device_data
for (size_t i = 0; i < device_data.size(); i++) {
    cv::cuda::GpuMat& mat = device_data[i];
    cudaMemcpyAsync(data_ptr, mat.data, mat.rows * mat.step, cudaMemcpyDeviceToDevice);
    data_ptr += mat.rows * mat.step/sizeof(float); // Move the data_ptr by the size of the current GpuMat
}
