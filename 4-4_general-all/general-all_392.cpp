// Assuming you have a cv::cuda::GpuMat data
cv::cuda::GpuMat gpu_data = ...; 

// Create a Caffe2 CUDAContext
CUDAContext context;

// Convert the cv::cuda::GpuMat to TensorCPU (assuming data is in device memory)
TensorCPU tensor_cpu;
tensor_cpu.Resize(std::vector<int64_t>{gpu_data.rows, gpu_data.cols});
context.CopyBytes(gpu_data.data, tensor_cpu.mutable_data<uint8_t>(), tensor_cpu.nbytes());

// Create a Caffe2 CUDA Tensor and copy data from TensorCPU to it
TensorCUDA tensor_cuda;
tensor_cuda.ResizeLike(tensor_cpu);
context.CopyFrom(tensor_cpu, &tensor_cuda);

// Now tensor_cuda holds the data from cv::cuda::GpuMat in CUDA memory
