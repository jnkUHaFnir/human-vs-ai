// Assume gpu_mat_data is your data in cv::cuda::GpuMat
cv::cuda::GpuMat gpu_mat_data = ...;

// Create a temporary buffer to copy the data from device memory
// Ensure that you handle the memory allocation correctly according to your data size
size_t data_size = gpu_mat_data.total() * gpu_mat_data.elemSize();
void* temp_data = malloc(data_size);

// Copy the data from device memory to the temp buffer
cudaMemcpy(temp_data, gpu_mat_data.ptr(), data_size, cudaMemcpyDeviceToHost);

// Create a Caffe2 Tensor with the correct dimensions
TensorCUDA tensor_cuda;
tensor_cuda.Resize({/* specify dimensions */});

// Get a pointer to the tensor's data
float* tensor_data = tensor_cuda.mutable_data<float>();

// Copy the data from the temp buffer to the Caffe2 Tensor
memcpy(tensor_data, temp_data, data_size);

// Free the temporary buffer
free(temp_data);
