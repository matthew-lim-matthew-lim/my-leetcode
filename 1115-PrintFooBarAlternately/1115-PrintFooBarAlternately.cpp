// Last updated: 4/21/2025, 9:48:15 PM
class FooBar {
private:
  int n;
  mutex m;
  condition_variable canPrint;
  bool shouldPrintFoo = true;

public:
  FooBar(int n) {
      this->n = n;
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      {
        unique_lock<mutex> lck(m);
        while (!shouldPrintFoo) {
          canPrint.wait(lck);
        }
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        shouldPrintFoo = false;
      }
      canPrint.notify_one();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      {
        unique_lock<mutex> lck(m);
        while (shouldPrintFoo) {
          canPrint.wait(lck);
        }
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        shouldPrintFoo = true;
      }
      canPrint.notify_one();
    }
  }
};