// Assuming 'gpu_mats' is your std::vector<cv::cuda::GpuMat> containing image data
// and 'workspace' is your Caffe2 workspace

// Iterate through the cv::cuda::GpuMat objects
for (const auto& gpu_mat : gpu_mats) {
    // Get the device pointer from the cv::cuda::GpuMat
    const uchar* data_ptr = gpu_mat.data;

    // Create a caffe2::Tensor<CUDAContext> object with the same dimensions
    caffe2::TensorCUDA tensor_cuda(workspace.CreateBlob("tensor_name")->GetMutable<TensorCUDA>());
    tensor_cuda.Resize({gpu_mat.rows, gpu_mat.cols}); // Resize the tensor as needed

    // Get the mutable data pointer
    float* tensor_data = tensor_cuda.mutable_data<float>();

    // Copy the data from GpuMat to the Caffe2 Tensor
    size_t data_size = gpu_mat.rows * gpu_mat.cols * sizeof(float);
    cudaMemcpy(tensor_data, data_ptr, data_size, cudaMemcpyDeviceToDevice);
}
