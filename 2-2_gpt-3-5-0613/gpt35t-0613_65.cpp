#include <thread>
#include <climits>
#include <chrono>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool threadReady = false;

void myfunc(void* p) {
  while (true) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return threadReady; });
    if (!threadReady) { // Additional check in case of spurious wakeups
      break;
    }
    
    // do something with p
    
    lock.unlock();
  }
}

int main() {
  void* myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];
  
  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i] = std::thread(myfunc, myp[i]);
  }
  
  for (unsigned long int j = 0; j < ULONG_MAX; j++) {
    // Main work here
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Sleep for 1 second
    
    std::unique_lock<std::mutex> lock(mtx);
    threadReady = true;
    cv.notify_all();
    
    // Data mixing here
    
    lock.unlock();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Sleep for 1 second
    
    lock.lock();
    threadReady = false;
    lock.unlock();
  }
  
  // Stop threads
  std::unique_lock<std::mutex> lock(mtx);
  threadReady = false;
  cv.notify_all();
  lock.unlock();
  
  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i].join();
  }
  
  return 0;
}