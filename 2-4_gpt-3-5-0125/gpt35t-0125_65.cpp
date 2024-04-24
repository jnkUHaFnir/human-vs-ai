#include <thread>
#include <mutex>
#include <condition_variable>
#include <climits>

bool is_thread_working = false;
std::mutex mtx;
std::condition_variable cv;

void myfunc(void * p) {
  while (true) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return !is_thread_working; });

    // Do the actual work here
    // ...
    
    is_thread_working = true;
    lock.unlock();
    cv.notify_all();
  }
}

int main(){
  void * myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];
  
  for (unsigned int i=0; i < n_threads; i++) {
    mythread[i] = std::thread(myfunc, myp[i]);
  }
  
  for (unsigned long int j=0; j < ULONG_MAX; j++) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return is_thread_working; });

    // Main thread work
    mix_data(myp);
  
    is_thread_working = false;
    lock.unlock();
    cv.notify_all();
  }
  
  for (unsigned int i=0; i < n_threads; i++) {
    mythread[i].join();
  }

  return 0;
}
