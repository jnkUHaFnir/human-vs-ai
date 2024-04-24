#include <iostream>
#include <omp.h>

#define USE_TARGET

int main(int argc, char** argv)
{
    const unsigned long int N = 100000;
    int use_target = 0;

    std::cout << "Number of devices: " << omp_get_num_devices() << std::endl;
    std::cout << "Default device: " << omp_get_default_device() << std::endl;

    if (omp_get_num_devices() > 0)
    {
        #pragma omp target
        {
            use_target = 1;
        }
    }

    float* buffer;
    if (use_target)
    {
        buffer = (float*)omp_target_alloc(N * sizeof(float), omp_get_default_device());
    }
    else
    {
        buffer = (float*)malloc(N * sizeof(float));
    }

    if (use_target)
    {
        #pragma omp target is_device_ptr(buffer)
        {
            #pragma omp parallel for
            for (unsigned long int i = 0; i < N; ++i)
                buffer[i] = i;
        }
        omp_target_free(buffer, omp_get_default_device());
    }
    else
    {
        #pragma omp target data map(tofrom:buffer[0:N])
        {
            #pragma omp parallel for
            for (unsigned long int i = 0; i < N; ++i)
                buffer[i] = i;
        }
        free(buffer);
    }

    return 0;
}
