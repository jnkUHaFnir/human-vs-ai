#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <climits>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
bool processed = false;

void myfunc(void* p) {
  while (true) {
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, [] { return ready; });

    if (!processed) {
      // Do the work
      std::cout << "Thread processing data at address: " << p << std::endl;
    }

    processed = true;
    ready = false;
    lk.unlock();
    cv.notify_one();
  }
}

int main() {
  void* myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];

  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i] = std::thread(myfunc, myp[i]);
  }

  for (unsigned long int j = 0; j < ULONG_MAX; j++) {
    {
      std::unique_lock<std::mutex> lk(mtx);
      ready = true;
      processed = false;
      lk.unlock();
      cv.notify_all();
    }

    {
      std::unique_lock<std::mutex> lk(mtx);
      cv.wait(lk, [] { return processed; });
    }

    mix_data(myp);
  }

  // To stop the threads, you can set a flag or signal threads to finish their work
  // For simplicity, this example does not handle stopping the threads
  return 0;
}
