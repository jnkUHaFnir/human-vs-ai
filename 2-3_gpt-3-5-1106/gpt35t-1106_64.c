
In this modified code, we have added a mutex and a condition variable to synchronize the main thread and the worker threads. The main thread waits for the worker threads to finish their work using the condition variable. When the worker threads have finished their work, they set the `isReady` flag to true and notify the main thread using `cv.notify_one()`.

The main thread waits for the worker threads to finish using `cv.wait(lock)`, and then proceeds to mix the data. It then resets the `isReady` flag to false and spawns new worker threads for the next iteration.

With these modifications, the program should now have the desired behavior of keeping the threads alive and sleeping when the main thread is working.
