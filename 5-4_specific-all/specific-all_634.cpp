#include <iostream>
#include <omp.h>

int main(int argc, char** argv)
{
    const unsigned long int N = 100000;

    std::cout << "Number of devices: " << omp_get_num_devices() << std::endl;
    std::cout << "Default device: " << omp_get_default_device() << std::endl;

    // Allocate
    float* buffer = (float*)omp_target_alloc(N*sizeof(float), 0);

    // Evaluate
    #pragma omp target map(from:buffer[0:N])
    {
        #pragma omp parallel for
        for(unsigned long int i = 0; i < N; ++i)
            buffer[i] = i;
    }

    // Cleanup
    omp_target_free(buffer, 0);

    return 0;
}
