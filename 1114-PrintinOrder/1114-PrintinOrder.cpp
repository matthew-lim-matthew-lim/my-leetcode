// Last updated: 4/21/2025, 9:11:56 PM
class Foo {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int curr = 0;

public:
    Foo() = default;

    void first(function<void()> printFirst) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] { return curr == 0; });
            printFirst();
            ++curr;
        }
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] { return curr == 1; });
            printSecond();
            ++curr;
        }
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] { return curr == 2; });
            printThird();
            ++curr;
        }
        cv.notify_all();
    }
};
