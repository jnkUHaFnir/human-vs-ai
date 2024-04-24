#include <thread>
#include <mutex>
#include <condition_variable>

// Define global locks and condition variables
std::mutex lock;
std::condition_variable cv_main, cv_workers;
bool ready_for_workers = false;
bool ready_for_main = false;

void myfunc(void * p) {
    while(true) {
        std::unique_lock<std::mutex> locker(lock);
        cv_workers.wait(locker, []{return ready_for_workers;}); // Worker thread waits until it's ready to process
        do_something(p);
        ready_for_main = true; // Now main can continue
        ready_for_workers = false; // but workers should wait
        cv_main.notify_all(); // Notify main that workers are done
        locker.unlock();
    }
}

int main(){
  void * myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];
  
  for (unsigned long int j=0; j < ULONG_MAX; j++) {
      
    for (unsigned int i=0; i < n_threads; i++) {
      mythread[i] = std::thread(myfunc, myp[i]);
    }
    {
      std::unique_lock<std::mutex> locker(lock);
      ready_for_workers = true; // Now workers can start
      cv_workers.notify_all(); // Notify workers to start
    }
    for (unsigned int i=0; i < n_threads; i++) {
      std::unique_lock<std::mutex> locker(lock);
      cv_main.wait(locker, []{return ready_for_main;}); // Main waits until workers are done
    }
    {
      std::unique_lock<std::mutex> locker(lock);
      ready_for_main = false; // Now main can continue, but
      ready_for_workers = false; // workers should wait
    }
    
    mix_data(myp); 
    ready_for_workers = true;  // After mixing data, let workers proceed
    cv_workers.notify_all(); // Inform workers to proceed
  }
  
  // Don't forget to join your threads at the end!
  for(auto& thread : mythread) {
    thread.join();
  }
  
  return 0; 
}
