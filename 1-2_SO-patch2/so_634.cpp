    #include <iostream>
    #include <omp.h>
    
    int main(int argc, char** argv) {
        const unsigned long int N = 100000;
    
        std::cout << "Number of devices: " << omp_get_num_devices() << std::endl;
        std::cout << "Default device: " << omp_get_default_device() << std::endl;
    
        float *buffer = (float*)malloc(N*sizeof(float));
        #pragma omp target teams distribute parallel for map(tofrom:buffer[0:N])
        for(unsigned long int i = 0; i < N; ++i)
          buffer[i] = i;
        free(buffer);
    }