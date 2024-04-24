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
            std::cerr << "mutex init failed\n";
        }
        
        if (pthread_cond_init(&cond, NULL) != 0) {
            std::cerr << "cond init failed\n";
        }
    }

    ~Worker() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }

    void interrupt() {
        std::cout << "Going to interrupt\n";
        pthread_mutex_lock(&mutex);
        if (!queue.empty()) {
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&mutex);
        std::cout << "interrupted\n";
    }

    void condition_lock() {
        pthread_mutex_lock(&mutex);
        while (queue.empty()) {
            std::cout << "Entering conditional lock\n";
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }

    void *run() {
        std::cout << "run\n";
        while (!stop) {
            std::cout << "Going for condition lock\n";
            std::cout << "size: " << queue.size() << std::endl;
            condition_lock();
            std::cout << "Exit from condition lock\n";
            while (!queue.empty()) {
                std::cout << "item: " << queue.back() << std::endl;
                queue.pop_back();
            }
        }
        pthread_exit(NULL);
    }

    void push(int value) {
        pthread_mutex_lock(&mutex);
        queue.push_back(value);
        pthread_cond_signal(&cond);
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
        pthread_cond_signal(&cond);
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
        worker.interrupt();
        usleep(500000);
    }
    worker.stop_thread();
    worker.join();
    std::cout << "Thread exit\n";
    return 0;
}
