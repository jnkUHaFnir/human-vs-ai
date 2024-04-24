    #include <stdio.h>
    #include <stdlib.h>
    #include "matmul.h"
    int main(int argc, char** argv)
    {
        if (argc != 2) {
            printf("Usage: %s number_of_threads\n", argv[0]);
            return -1;
        } else {
            num_thrd = atoi(argv[1]);
        }
        pthread_t threads[num_thrd];
        matThread mt;
        void* parm = (void*)&mt;
        int i = 0;
        init_matrix(A);
        init_matrix(B);
        for (i = 0; i < num_thrd; i++) {
            mt.slice = i;
            // creates each thread working on its own slice of i
            if (pthread_create(&threads[i], NULL, &multiply, parm) != 0) {
                printf("Can't create thread\n");
                return -1;
            }
        }
        for (i = 0; i < num_thrd; i++) {
            pthread_join(threads[i], NULL);
        }
        printf("\n\n");
        print_matrix(A);
        printf("\n\n\t *\n");
        print_matrix(B);
        printf("\n\n\t=\n");
        print_matrix(C);
        printf("\n\n");
        return 0;
    }