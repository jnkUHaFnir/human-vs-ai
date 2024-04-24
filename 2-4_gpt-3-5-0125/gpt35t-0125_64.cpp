#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool is_ready = false;

void myfunc(void *p) {
  while (true) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return is_ready; });
    // Do something with p
    do_something(p);
    is_ready = false;
    lock.unlock();
    cv.notify_one();
  }
}

int main(){
  void *myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];
  
  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i] = std::thread(myfunc, myp[i]);
  }

  for (unsigned long int j = 0; j < ULONG_MAX; j++) {
    std::unique_lock<std::mutex> lock(mtx);
    is_ready = true;
    cv.notify_all();
    cv.wait(lock, []{ return !is_ready; });
    lock.unlock();
    
    mix_data(myp);
  }

  // Signal threads to exit
  is_ready = true;
  cv.notify_all();
  
  // Wait for all threads to finish
  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i].join();
  }

  return 0;
}
