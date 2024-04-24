#include <thread>
#include <mutex>
#include <condition_variable>
#include <climits>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void* p) {
  do_something(p);
  std::unique_lock<std::mutex> lck(mtx);
  cv.wait(lck, [] { return ready; });
}

int main() {
  void* myp[n_threads] = {a_location, another_location, ...};
  std::thread mythread[n_threads];
  for (unsigned long int j = 0; j < ULONG_MAX; j++) {
    for (unsigned int i = 0; i < n_threads; i++) {
      mythread[i] = std::thread(myfunc, myp[i]);
    }
    // Do some work in the main
    {
      std::lock_guard<std::mutex> lck(mtx);
      ready = true;
    }
    cv.notify_all();
    // Perform data mixing
    mix_data(myp);
    {
      std::lock_guard<std::mutex> lck(mtx);
      ready = false;
    }
  }
  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i].join();
  }
  return 0;
}
