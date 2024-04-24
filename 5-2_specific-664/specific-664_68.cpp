#include <iostream>
#include <vector>
#include <pthread.h>

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
            std::cerr << "Mutex init failed" << std::endl;
        }

        if (pthread_cond_init(&cond, NULL) != 0) {
            std::cerr << "Cond init failed" << std::endl;
        }
    }

    ~Worker() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }

    void interrupt() {
        std::cout << "Going to interrupt" << std::endl;
        pthread_cond_signal(&cond);
        std::cout << "Interrupted" << std::endl;
    }

    void wait_for_work() {
        pthread_mutex_lock(&mutex);
        while (queue.size() == 0) {
            std::cout << "Waiting for work" << std::endl;
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }

    static void* run_helper(void* context) {
        return ((Worker*)context)->run();
    }

    void start_thread() {
        stop = false;
        int status = pthread_create(&thread, NULL, run_helper, this);
    }

    void stop_thread() {
        stop = true;
        pthread_cond_signal(&cond);
    }

    void join() {
        void* status;
        pthread_join(thread, &status);
    }

    void push(int value) {
        pthread_mutex_lock(&mutex);
        queue.push_back(value);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }

    void* run() {
        std::cout << "run" << std::endl;
        while (!stop) {
            std::cout << "Waiting for work" << std::endl;
            wait_for_work();
            std::cout << "Work available" << std::endl;
            while (!queue.empty()) {
                std::cout << "Item: " << queue.back() << std::endl;
                queue.pop_back();
            }
        }
        pthread_exit(NULL);
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

    std::cout << "Thread exit" << std::endl;

    return 0;
}
