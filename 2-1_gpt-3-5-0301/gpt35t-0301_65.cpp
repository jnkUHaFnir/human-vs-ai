#include <thread>
#include <mutex>
#include <condition_variable>
#include <climits>

std::mutex mutex;
std::condition_variable cv;
bool worker_done[n_threads] {false};
bool done = false;

void myfunc(void * p, int id) {
  while (true) {
    {
      std::unique_lock<std::mutex> lock(mutex);
      cv.wait(lock, [&] { return done || !worker_done[id]; });
      if (done) {
        return;
      }
    }
    do_something(p);
    {
      std::unique_lock<std::mutex> lock(mutex);
      worker_done[id] = true;
      cv.notify_all();
    }
  }
}

int main() {
  void * myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];
  for (unsigned int i=0; i < n_threads; i++) {
    mythread[i] = std::thread(myfunc, myp[i], i);
  }
  for (unsigned long int j=0; j < ULONG_MAX; j++) {
    {
      std::unique_lock<std::mutex> lock(mutex);
      while (std::count(worker_done, worker_done + n_threads, false) > 0) {
        cv.wait(lock);
      }
      std::fill(worker_done, worker_done + n_threads, false);
    }
    mix_data(myp); 
    {
      std::unique_lock<std::mutex> lock(mutex);
      done = true;
      cv.notify_all();
    }
  }
  done = true;
  cv.notify_all();
  for (unsigned int i=0; i < n_threads; i++) {
    mythread[i].join();
  }
  return 0;
}