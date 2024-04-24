#include <iostream>
#include <omp.h>

#define USE_TARGET // Comment this line for correct execution

int main(int argc, char** argv)
{
    const unsigned long int N = 100000;

    std::cout << "Number of devices: " << omp_get_num_devices() << std::endl;
    std::cout << "Default device: " << omp_get_default_device() << std::endl;

    // Allocate
    float* buffer;
#ifdef USE_TARGET
    buffer = (float*)omp_target_alloc(N*sizeof(float), omp_get_initial_device());
#else
    buffer = (float*)malloc(N*sizeof(float));
#endif

    // Evaluate
    #pragma omp target map(tofrom:buffer[0:N])
    {
        #pragma omp parallel for
        for(unsigned long int i = 0; i < N; ++i)
            buffer[i] = i;
    }

    // Cleanup
#ifdef USE_TARGET
    omp_target_free(buffer, omp_get_initial_device());
#else
    free(buffer);
#endif

    return 0;
}
