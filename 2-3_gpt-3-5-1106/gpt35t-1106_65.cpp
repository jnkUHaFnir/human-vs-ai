#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

void myfunc(void* p) {
  while (true) {
    std::unique_lock<std::mutex> lock(mtx);
    
    // Wait until main signals to wake up
    cv.wait(lock);
    
    // Do some work
    do_something(p);
  }
}

int main() {
  void *myp[n_threads] = {a_location, another_location, ...};
  std::thread mythread[n_threads];
  
  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i] = std::thread(myfunc, myp[i]);
  }
  
  for (unsigned long int j = 0; j < ULONG_MAX; j++) {
    {
      // Signal threads to wake up
      std::lock_guard<std::mutex> lock(mtx);
      cv.notify_all();
    }
    
    // Main can do some work here
    
    {
      // Wait for threads to finish their work
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, [] { return all_threads_finished; });
    }
    
    // Mix data
    mix_data(myp);
  }
  return 0;
}
