#include <iostream>
#include <omp.h>

//#define USE_TARGET // Uncomment this to see the segmentation fault

int main(int argc, char** argv)
{
    const unsigned long int N = 100000;

    std::cout << "Number of devices: " << omp_get_num_devices() << std::endl;
    std::cout << "Default device: " << omp_get_default_device() << std::endl;

    // Allocate
    float* buffer;
#ifdef USE_TARGET
    buffer = (float*)omp_target_alloc(N*sizeof(float), 0);
#else
    buffer = (float*)malloc(N*sizeof(float));
#endif

    // Evaluate
#ifdef USE_TARGET
    #pragma omp target map(tofrom:buffer[0:N])
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
    omp_target_free(buffer, 0);
#else
    free(buffer);
#endif

    return 0;
}
