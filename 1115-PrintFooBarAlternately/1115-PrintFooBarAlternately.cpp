// Last updated: 4/21/2025, 9:36:45 PM
class FooBar {
private:
    int n;
    std::binary_semaphore fooReady{1};
    std::binary_semaphore barReady{0};

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            fooReady.acquire();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            barReady.release();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            barReady.acquire();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            fooReady.release();
        }
    }
};