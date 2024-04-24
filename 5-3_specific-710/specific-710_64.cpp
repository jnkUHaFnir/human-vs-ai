#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void * p) {
  while (true) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; }); // Wait until ready is true
    do_something(p); // Do the work
    ready = false; // Notify completion
    lock.unlock();
    cv.notify_one(); // Notify main thread
  }
}

int main(){
  void * myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];
  
  for (unsigned int i=0; i < n_threads; i++) {
    mythread[i] = std::thread(myfunc, myp[i]);
  }
  
  for (unsigned long int j=0; j < ULONG_MAX; j++) {
    // Main thread work
    std::lock_guard<std::mutex> lock(mtx);
    ready = true; // Notify threads to start
    cv.notify_all();
    
    cv.wait(lock, [] { return !ready; }); // Wait until all threads finished
    mix_data(myp); // Mix the data
  }
  
  // Clean up threads
  for (unsigned int i=0; i < n_threads; i++) {
    mythread[i].join();
  }

  return 0;
}
