class MKAverage {
private:
    int m_;
    int k_;
    vector<int> q;
    multiset<int> lowK;
    multiset<int> highK;
    multiset<int> middle;
    long long allSum = 0;
public:
    MKAverage(int m, int k) {
        m_ = m;
        k_ = k;
    }
    
    void addElement(int num) {
        q.push_back(num);
        // See if it belongs in low, middle, or high.
        if (q.size() < m_) {
            return;
        } 
        if (q.size() == m_) {
            vector<int> q2 = q;
            sort(q2.begin(), q2.end());
            for (int i = 0; i < k_; i++) lowK.insert(q2[i]);
            for (int i = k_; i < m_ - k_; i++) {
                middle.insert(q2[i]);
                allSum += q2[i];
            }
            for (int i = m_ - k_; i < m_; i++) highK.insert(q2[i]);
            return;
        }
        // Otherwise, q.size() > m_;
        middle.insert(num);
        allSum += num;
        // Swap to keep in sorted order
        if (*lowK.rbegin() > *middle.begin()) {
            int fromMid = *middle.begin();
            int fromLow = *lowK.rbegin();
            middle.insert(fromLow);
            lowK.insert(fromMid);
            middle.erase(middle.begin());
            lowK.erase(--lowK.end());
            allSum -= fromMid;
            allSum += fromLow;
        }
        if (*middle.rbegin() > *highK.begin()) {
            int fromHigh = *highK.begin();
            int fromMid = *middle.rbegin();
            highK.insert(fromMid);
            middle.insert(fromHigh);
            highK.erase(highK.begin());
            middle.erase(--middle.end());
            allSum -= fromMid;
            allSum += fromHigh;
        }

        // Remove element at end of queue
        int v = q[q.size() - 1 - m_];
        if (*lowK.rbegin() >= v) {
            lowK.erase(lowK.find(v));
            lowK.insert(*middle.begin());
            allSum -= *middle.begin();
            middle.erase(middle.begin());
        } else if (*middle.rbegin() >= v) {
            middle.erase(middle.find(v));
            allSum -= v;
        } else {
            highK.erase(highK.find(v));
            highK.insert(*middle.rbegin());
            allSum -= *middle.rbegin();
            middle.erase(--middle.end());
        }

        // cout << "display elems" << endl;
        // cout << "lowK" << endl;
        // for (int e : lowK) {
        //     cout << e << " ";
        // }
        // cout << endl;
        // cout << endl;
        // cout << "middle" << endl;
        // for (int e : middle) {
        //     cout << e << " ";
        // }
        // cout << endl;
        // cout << endl;
        // cout << "highK" << endl;
        // for (int e : highK) {
        //     cout << e << " ";
        // }
        // cout << endl;
        // cout << endl;
        // cout << endl;
    }
    
    int calculateMKAverage() {
        if (q.size() < m_) {
            return -1;
        }
        return allSum / (m_ - 2 * k_);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */