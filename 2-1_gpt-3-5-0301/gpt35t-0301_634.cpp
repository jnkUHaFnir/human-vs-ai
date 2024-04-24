#include <iostream>
#include <omp.h>

int main(int argc, char** argv)
{
    const unsigned long int N = 100000;

    std::cout << "Number of devices: " << omp_get_num_devices() << std::endl;
    std::cout << "Default device: " << omp_get_default_device() << std::endl;

    float* buffer = (float*)omp_target_alloc(N*sizeof(float), 0);

    #pragma omp target enter data map(to: buffer[0:N])
    #pragma omp target is_device_ptr(buffer)
    {
        #pragma omp parallel for
        for(unsigned long int i = 0; i < N; ++i)
            buffer[i] = i;
    }
    #pragma omp target exit data map(from: buffer[0:N])

    omp_target_free(buffer, 0);

    return 0;
}