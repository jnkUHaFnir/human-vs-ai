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
            std::cerr << "mutex init failed" << std::endl;
        }

        if (pthread_cond_init(&cond, NULL) != 0) {
            std::cerr << "cond init failed" << std::endl;
        }
    }

    ~Worker() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }

    void interrupt() {
        pthread_mutex_lock(&mutex);
        pthread_cond_broadcast(&cond); // Change to broadcast
        pthread_mutex_unlock(&mutex);
    }

    void condition_lock() {
        pthread_mutex_lock(&mutex);
        while (queue.size() == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }

    void *run() {
        while (!stop) {
            condition_lock();
            while (queue.size() > 0) {
                int item = queue.back();
                queue.pop_back();
                std::cout << "item: " << item << std::endl;
            }
        }
        pthread_exit(NULL);
    }

    void push(int value) {
        pthread_mutex_lock(&mutex);
        queue.push_back(value);
        pthread_cond_signal(&cond); // Signal after pushing
        pthread_mutex_unlock(&mutex);
    }

    void join() {
        void *status;
        pthread_join(thread, &status);
    }

    static void *run_helper(void *context) {
        return static_cast<Worker *>(context)->run();
    }

    void stop_thread() {
        stop = true;
        interrupt();
    }

    void start_thread() {
        stop = false;
        int status = pthread_create(&thread, NULL, run_helper, this);
    }
};

int main() {
    Worker worker;
    worker.start_thread();
    usleep(500000);
    for (int i = 0; i < 5; i++) {
        worker.push(i);
        usleep(500000);
    }
    worker.stop_thread();
    worker.join();
    std::cout << "Thread exit" << std::endl;
    return 0;
}
