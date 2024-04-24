#include <pthread.h>
#include <cstdio>
#include <vector>
#include <unistd.h>

using namespace std;

class Worker {
private:
    pthread_t thread;
    vector<int> queue;
    bool stop;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

public:
    Worker() {
        stop = false;
        if (pthread_mutex_init(&mutex, NULL) != 0) {
            printf("\n mutex init failed\n");
        }

        if (pthread_cond_init(&cond, NULL) != 0) {
            printf("\n cond init failed\n");
        }
    }

    ~Worker() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }

    void interrupt() {
        printf("Going to interrupt\n");
        pthread_mutex_lock(&mutex);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        printf("interrupted\n");
    }

    void condition_lock() {
        pthread_mutex_lock(&mutex);
        while (queue.size() == 0) {
            printf("Entering conditional lock\n");
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }

    void *run() {
        while (!stop) {
            printf("Going for condition lock\n");
            printf("size: %lu\n", queue.size());
            condition_lock();
            printf("Exit from condition lock\n");
            while (queue.size() > 0) {
                printf("item: %d\n", queue[0]);
                queue.erase(queue.begin());
            }
        }
        pthread_exit(NULL);
    }

    void push(int value) {
        pthread_mutex_lock(&mutex);
        queue.push_back(value);
        pthread_cond_signal(&cond); // Signal waiting thread(s) that data is available
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
        if (status != 0) {
            printf("Error in creating thread\n");
        }
    }
};

int main() {
    Worker worker;
    worker.start_thread();
    usleep(500000); // Wait for the thread to start

    for (int i = 0; i < 5; i++) {
        worker.push(i);
        usleep(500000);
    }

    worker.stop_thread();
    worker.join();

    printf("Thread exit\n");

    return 0;
}
