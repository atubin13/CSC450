#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// Mutex and condition variable to control thread execution order
std::mutex mtx;
std::condition_variable cv;
bool countUpDone = false;  // Flag to indicate when thread 1 has completed

// Function for the first thread: counts up to 20
void countUp() {
    for (int i = 1; i <= 20; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Thread 1 counting up: " << i << std::endl;
    }

    // Notify that thread 1 has finished counting
    {
        std::lock_guard<std::mutex> lock(mtx);
        countUpDone = true;
    }
    cv.notify_one();  // Signal thread 2 to start
}

// Function for the second thread: counts down to 0
void countDown() {
    // Wait until countUp is done
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return countUpDone; });

    // Start counting down from 20 to 0
    for (int i = 20; i >= 0; --i) {
        std::cout << "Thread 2 counting down: " << i << std::endl;
    }
}

int main() {
    // Start the first thread to count up
    std::thread t1(countUp);

    // Start the second thread to count down, but it will wait until t1 is done
    std::thread t2(countDown);

    // Wait for both threads to complete
    t1.join();
    t2.join();

    return 0;
}
