// Last updated: 4/21/2025, 9:07:40 PM
class Foo {
// CV might be good performance since blocking
private:
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<int> curr = 0;

public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] {
                return curr.load(std::memory_order_acquire) == 0;
            });
            printFirst();
            curr.fetch_add(1, std::memory_order_release);
        }
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] {
                return curr.load(std::memory_order_acquire) == 1;
            });
            printSecond();
            curr.fetch_add(1, std::memory_order_release);
        }
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] {
                return curr.load(std::memory_order_acquire) == 2;
            });
            printThird();
            curr.fetch_add(1, std::memory_order_release);
        }
        cv.notify_all();
    }
};