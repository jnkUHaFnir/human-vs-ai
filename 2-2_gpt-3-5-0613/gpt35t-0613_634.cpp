#include <iostream>
#include <omp.h>

//#define USE_TARGET // Uncomment this to see the segmentation fault

int main(int argc, char** argv)
{
    const unsigned long int N = 100000;

    std::cout << "Number of devices: " << omp_get_num_devices() << std::endl;

    // Set default device to CPU
    omp_set_default_device(omp_get_initial_device());

    std::cout << "Default device: " << omp_get_default_device() << std::endl;

    // Allocate
#ifdef USE_TARGET
    float* buffer = (float*)malloc(N*sizeof(float));
#else
    float* buffer = (float*)malloc(N*sizeof(float));
#endif

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
    free(buffer);
#endif

    return 0;
}