#include <iostream>
#include <omp.h>

//#define USE_TARGET // Uncomment this to see the segmentation fault

int main(int argc, char** argv)
{
    const unsigned long int N = 100000;
    int num_devices = omp_get_num_devices();
    int default_device = omp_get_default_device();

    std::cout << "Number of devices: " << num_devices << std::endl;
    std::cout << "Default device: " << default_device << std::endl;

    if (num_devices < 1) {
        std::cerr << "Error: No OpenMP devices found." << std::endl;
        return 1;
    }

    int target_device = default_device >= 0 ? default_device : 0; // Use default device if available

    // Allocate
    float *buffer = nullptr;
    #ifdef USE_TARGET
        int error_alloc = 0;
        buffer = (float*)omp_target_alloc(N*sizeof(float), target_device);
        if (!buffer) {
            std::cerr << "Error allocating memory on device " << target_device << std::endl;
            error_alloc = 1;
        }
    #else
        buffer = (float*)malloc(N*sizeof(float));
    #endif

    if (!error_alloc) {
        // Evaluate
        #ifdef USE_TARGET
        #pragma omp target is_device_ptr(buffer)
        {
        #else
        #pragma omp target data map(tofrom:buffer[0:N])
        {
        #endif
            #pragma omp parallel for
            for(unsigned long int i = 0; i < N; ++i)
                buffer[i] = i;
        }

        // Cleanup
        #ifdef USE_TARGET
        omp_target_free(buffer, target_device);
        #else
        free(buffer);
        #endif
    }

    return 0;
}
