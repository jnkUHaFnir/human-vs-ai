#include <pthread.h>

pthread_mutex_t flag_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int interrupt_flag = 0;

void interrupt_handler(){
    pthread_mutex_lock(&flag_mutex); 
    interrupt_flag = 1;
    pthread_cond_signal(&cond); // signal the condition to the waiting (monitoring) thread.
    pthread_mutex_unlock(&flag_mutex);
}

void* monitoring_thread(void* arg){
    pthread_mutex_lock(&flag_mutex);
    while(interrupt_flag == 0){
        pthread_cond_wait(&cond, &flag_mutex); // unlock mutex and wait for signal, re-acquire lock if signaled.
    }
    // After signaled, start the thread here
    interrupt_flag = 0;
    pthread_mutex_unlock(&flag_mutex);   
}

int main(){
    pthread_t monitoring_tid;
    pthread_create(&monitoring_tid, NULL, monitoring_thread, NULL); // start monitoring thread at the start of the program
    ...
}

