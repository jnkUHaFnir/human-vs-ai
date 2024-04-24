#include <pthread.h>
#include <vector>
#include <iostream>
#include <unistd.h>

class Worker {
private:
    pthread_t thread;
    std::vector<int> queue;
    bool stop;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
public:
    Worker() {
        stop = false;
        if (pthread_mutex_init(&mutex, NULL) != 0) {
            std::cout << "mutex init failed" << std::endl;
        }

        if (pthread_cond_init(&cond, NULL) != 0) {
            std::cout << "cond init failed" << std::endl;
        }
    }
    ~Worker() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }
    void interrupt() {
        std::cout << "Going to interrupt" << std::endl;
        pthread_mutex_lock(&mutex);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        std::cout << "interrupted" << std::endl;
    }
    void condition_lock() {
        pthread_mutex_lock(&mutex);
        while(queue.size() == 0) {
            std::cout << "Waiting for data..." << std::endl;
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    void *run() {
        std::cout << "Running..." << std::endl;
        while (!stop) {
            std::cout << "Checking for data..." << std::endl;
            condition_lock();
            while (queue.size() > 0) {
                std::cout << "Processing item: " << queue.back() << std::endl;
                queue.pop_back();
            }
        }
        std::cout << "Exiting..." << std::endl;
        pthread_exit(NULL);
    }
    void push(int value) {
        pthread_mutex_lock(&mutex);
        queue.push_back(value);
        pthread_cond_signal(&cond); // Signal that new data is available
        pthread_mutex_unlock(&mutex);
    }
    void join() {
        void *status;
        pthread_join(thread, &status);
    }
    static void *run_helper(void *context) {
        return ((Worker *)context)->run();
    }
    void stop_thread() {
        stop = true;
        interrupt();
    }
    void start_thread() {
        int status = pthread_create(&thread, NULL, run_helper, this);
        if (status != 0) {
            std::cerr << "Error creating thread" << std::endl;
        }
    }
};

int main() {
    Worker worker;
    worker.start_thread();
    for (int i = 0; i < 5; i++) {
        worker.push(i);
        usleep(500000);
    }
    worker.stop_thread();
    worker.join();
    std::cout << "Thread exited" << std::endl;
    return 0;
}
