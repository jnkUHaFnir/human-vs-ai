#include <iostream>
#include <omp.h>

int main(int argc, char** argv)
{
    const unsigned long int N = 100000;

    std::cout << "Number of devices: " << omp_get_num_devices() << std::endl;
    std::cout << "Default device: " << omp_get_default_device() << std::endl;

    float* buffer;

#ifdef USE_TARGET
    // Map buffer to device explicitly
    #pragma omp target enter data map(alloc:buffer[0:N]) 
    {
        buffer = (float*)omp_target_alloc(N*sizeof(float), 0);
    }

    #pragma omp target map(tofrom:buffer[0:N])
    {
#else
    buffer = (float*)malloc(N*sizeof(float));
#endif

        #pragma omp parallel for
        for(unsigned long int i = 0; i < N; ++i)
            buffer[i] = i;

#ifdef USE_TARGET
    }

    #pragma omp target exit data map(delete:buffer[0:N])
    {
        omp_target_free(buffer, 0);
    }
#else
    free(buffer);
#endif

    return 0;
}
