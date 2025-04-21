// Last updated: 4/21/2025, 8:56:17 PM
class Foo {
private:
    std::mutex mtx;
    std::atomic<int> curr = 0; 
public:
// Atomics is the clear way to do this
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        while (true) {
            std::lock_guard<std::mutex> lock(mtx);
            curr.load(std::memory_order_acquire);
            if (curr != 0) {
                continue;
            }
            // printFirst() outputs "first". Do not change or remove this line.
            printFirst();
            curr.fetch_add(1, std::memory_order_release);
            return;
        }
    }

    void second(function<void()> printSecond) {
        while (true) {
            std::lock_guard<std::mutex> lock(mtx);
            curr.load(std::memory_order_acquire);
            if (curr != 1) {
                continue;
            }
            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();
            curr.fetch_add(1, std::memory_order_release);
            return;
        }
    }

    void third(function<void()> printThird) {
        while (true) {
            std::lock_guard<std::mutex> lock(mtx);
            curr.load(std::memory_order_acquire);
            if (curr != 2) {
                continue;
            }
            // printThird() outputs "third". Do not change or remove this line.
            printThird();
            curr.fetch_add(1, std::memory_order_release);
            return;
        }
    }
};