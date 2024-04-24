#include <thread>
#include <condition_variable>
#include <mutex>
#include <climits>

std::mutex mtx;
std::condition_variable cv;
bool ready = false; // Flag to be checked by threads when notified

void myfunc(void * p) {
  std::unique_lock<std::mutex> lock(mtx);
  while (!ready) { 
    cv.wait(lock); // Thread will sleep until main thread sends notification
  }
  
  // Process data here
  do_something(p);
  
  ready = false; // Reset the flag for next iteration
}

int main(){
  void * myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];
  
  for (auto& th : mythread) 
    th = std::thread(myfunc, myp[i]);

  for (unsigned long int j=0; j < ULONG_MAX; j++) {

    // Lock is required to avoid data race on 'ready' variable
    {
      std::unique_lock<std::mutex> lock(mtx);
      ready = true; // Threads can start processing
    }

    cv.notify_all(); // Notify to all threads
    for (auto& th : mythread)
      th.join();

    mix_data(myp);

    // If you want threads to run continuously, rather than recreating them on each iteration,
    // you'll need to move the thread creation out of the loop.
  }

  // Don't forget to join the threads at the end
  for (auto& th : mythread) 
    th.join();

  return 0;
}
