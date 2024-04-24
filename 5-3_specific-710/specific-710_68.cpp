#include <iostream>
#include <vector>
#include <pthread.h>
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
                std::cout << "mutex init failed\n";
            }

            if(pthread_cond_init(&cond, NULL) != 0) {
                std::cout << "cond init failed\n";
            }
        }

        ~Worker() {
            pthread_mutex_destroy(&mutex);
            pthread_cond_destroy(&cond);
        }

        void interrupt() {
            pthread_mutex_lock(&mutex);
            pthread_cond_signal(&cond);
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
                    std::cout << "item: " << queue[0] << std::endl;
                    queue.erase(queue.begin());
                }
            }
            pthread_exit(NULL);
        }

        void push(int value) {
            pthread_mutex_lock(&mutex);
            queue.push_back(value);
            pthread_mutex_unlock(&mutex);
            interrupt(); // Signal the waiting thread that data is available
        }

        void join() {
            void *status;
            pthread_join(thread, &status);
        }

        static void *run_helper(void* context) {
            return static_cast<Worker*>(context)->run();
        }

        void stop_thread() {
            stop = true;
            interrupt(); // Signal the waiting thread to exit
        }

        void start_thread() {
            stop = false;
            int status = pthread_create(&thread, NULL, run_helper, this);
            if (status != 0) {
                std::cerr << "Failed to create thread\n";
            }
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
    std::cout << "Thread exit\n";
    return 0;
}
