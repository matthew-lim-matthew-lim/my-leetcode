// Last updated: 4/21/2025, 10:08:32 PM
class ZeroEvenOdd {
private:
    int n;
    int curr = 1;
    std::mutex mtx;
    bool zeroStep = true;
    std::condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (true) {
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [&] {
                    return (zeroStep == true) || curr > n;
                });
                if (curr > n) {
                    cv.notify_all();
                    return;
                }
                printNumber(0);
                zeroStep = false;
            }
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [&] {
                    return (curr % 2 == 0 && zeroStep == false) || curr > n;
                });
                if (curr > n) {
                    cv.notify_all();
                    return;
                }
                printNumber(curr);
                curr++;
                zeroStep = true;
            }
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [&] {
                    return (curr % 2 == 1 && zeroStep == false) || curr > n;
                });
                if (curr > n) {
                    cv.notify_all();
                    return;
                }
                printNumber(curr);
                curr++;
                zeroStep = true;
            }
            cv.notify_all();
        }
    }
};