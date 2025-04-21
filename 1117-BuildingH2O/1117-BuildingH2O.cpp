// Last updated: 4/21/2025, 11:16:32 PM
class H2O {
private:
    std::mutex m;
    std::condition_variable cvH, cvO;
    int hRem = 2;  
    int oRem = 1; 

    // helper to reset for next molecule
    void reset_and_wake() {
        hRem = 2;
        oRem = 1;
        cvH.notify_all();  
        cvO.notify_one(); 
    }

public:
    H2O() = default;

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(m);
        cvH.wait(lock, [&]{ return hRem > 0; });

        --hRem;
        releaseHydrogen();

        if (hRem == 0 && oRem == 0) {
            reset_and_wake();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(m);
        cvO.wait(lock, [&]{ return oRem > 0; });

        --oRem;
        releaseOxygen();

        if (hRem == 0 && oRem == 0) {
            reset_and_wake();
        }
    }
};
