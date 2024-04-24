#include <thread>
#include <mutex>
#include <condition_variable>
#include <climits>

std::mutex mtx; // mutex for synchronization
std::condition_variable cv; // condition variable for threads to sleep
bool ready = false; // flag indicating if threads should run or sleep

void myfunc(void * p) {
  while (true) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; }); // threads wait until ready flag is true
    do_something(p);
    ready = false; // set ready flag to false to make threads sleep again
    cv.notify_all(); // notify main thread that threads are sleeping
  }
}

int main() {
  void * myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];
  for (unsigned int i=0; i < n_threads; i++) {
    mythread[i] = std::thread(myfunc, myp[i]);
  }
  for (unsigned long int j=0; j < ULONG_MAX; j++) {
    {
      std::lock_guard<std::mutex> lock(mtx);
      ready = true; // set ready flag to true to wake up threads
    }
    cv.notify_all(); // notify threads that they should run
    {
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, []{ return !ready; }); // main thread waits until threads finish
    }
    mix_data(myp);
  }
  {
    std::lock_guard<std::mutex> lock(mtx);
    ready = true; // set ready flag to true to wake up threads for the last time
  }
  cv.notify_all(); // notify threads that they should run for the last time
  for (unsigned int i=0; i < n_threads; i++) {
    mythread[i].join();
  }
  return 0;
}