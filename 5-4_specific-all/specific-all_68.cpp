#include <pthread.h>
#include <vector>
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
            cout << "\n mutex init failed\n";
        }

        if(pthread_cond_init(&cond,NULL) != 0){
            cout << "\n cond init failed\n";
        }
    }
    ~Worker() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }
    void interrupt(){
        cout << "Going to interrupt\n";
        pthread_mutex_lock(&mutex);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        cout << "interrupted \n";
    }
    void condition_lock(){
        pthread_mutex_lock(&mutex);
        while (queue.size() == 0) {
            cout << "Entering conditional lock\n";
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    void *run(){
        cout << "run\n";
        while (!stop) {
            cout << "Going for condition lock\n";
            cout << "size: " << queue.size() << endl;
            condition_lock();
            cout << "Exit from condition lock\n";
            while (queue.size() > 0) {
                cout << "item: " << queue[0] << endl;
                queue.erase(queue.begin());
            }
        }
        pthread_exit(NULL);
    }
    void push(int value){
       pthread_mutex_lock(&mutex);
       queue.push_back(value);
       pthread_mutex_unlock(&mutex);
       pthread_cond_signal(&cond);
    }
    void join(){
        void *status;
        pthread_join(thread, &status);
    }
    static void *run_helper(void* context){
        return ((Worker *)context)->run();
    }
    void stop_thread(){
        stop = true;
        interrupt();
    }
    void start_thread(Worker *worker){
        stop = false;
        int status = pthread_create(&thread, NULL, run_helper, worker);
    }
};

int main(){
    Worker worker;
    worker.start_thread(&worker);
    usleep(500000);
    for (int i = 0; i < 5; i++){
        worker.push(i);
        worker.interrupt();
        usleep(500000);
    }
    worker.stop_thread();
    worker.join();
    cout << "Thread exit\n";
    return 0;
}
