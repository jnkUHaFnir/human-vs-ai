#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <iostream>

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
            cout << "mutex init failed" << endl;
        }

        if (pthread_cond_init(&cond, NULL) != 0) {
            cout << "cond init failed" << endl;
        }
    }

    ~Worker() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }

    void interrupt() {
        pthread_mutex_lock(&mutex);
        cout << "Going to interrupt" << endl;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        cout << "interrupted" << endl;
    }

    void condition_lock() {
        pthread_mutex_lock(&mutex);
        while (queue.size() == 0) {
            cout << "Queue empty, waiting..." << endl;
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }

    static void *run_helper(void *context) {
        return static_cast<Worker *>(context)->run();
    }

    void *run() {
        cout << "run" << endl;
        while (!stop) {
            cout << "Checking queue" << endl;
            condition_lock();
            while (queue.size() > 0) {
                cout << "Processing item: " << queue.back() << endl;
                queue.pop_back();
            }
        }
        pthread_exit(NULL);
    }

    void push(int value) {
        pthread_mutex_lock(&mutex);
        queue.push_back(value);
        pthread_cond_signal(&cond); // Signal the condition variable after pushing the value
        pthread_mutex_unlock(&mutex);
    }

    void start_thread() {
        stop = false;
        int status = pthread_create(&thread, NULL, run_helper, this);
        if (status != 0) {
            cout << "Error creating thread" << endl;
        }
    }

    void stop_thread() {
        stop = true;
        interrupt();
    }

    void join() {
        void *status;
        pthread_join(thread, &status);
    }
};

int main() {
    Worker worker;
    worker.start_thread();
    usleep(500000); // Sleep for 0.5 seconds

    for (int i = 0; i < 5; i++) {
        worker.push(i);
        usleep(500000); // Sleep for 0.5 seconds
    }

    worker.stop_thread();
    worker.join();

    cout << "Thread exit" << endl;
    return 0;
}
