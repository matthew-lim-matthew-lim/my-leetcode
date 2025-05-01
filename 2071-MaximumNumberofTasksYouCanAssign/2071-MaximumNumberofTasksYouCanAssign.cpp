// Last updated: 5/1/2025, 12:12:06 PM
class Solution {
public:

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto verify = [&](int mid) {
            int currPills = pills;
            multiset<int> workerSet;
            for (int i = workers.size() - mid; i < workers.size(); i++) {
                workerSet.insert(workers[i]);
            }

            for (int i = mid - 1; i >= 0; i--) {
                if (auto it = prev(workerSet.end()); *it >= tasks[i]) {
                    workerSet.erase(it);
                } else {
                    if (currPills <= 0) {
                        return false;
                    }
                    auto replacement = workerSet.lower_bound(tasks[i] - strength);
                    if (replacement == workerSet.end()) {
                        return false;
                    }
                    currPills--;
                    workerSet.erase(replacement);
                }
            }

            return true;
        };

        // Binary search
        int lo = 0;
        int hi = min(workers.size(), tasks.size());
        int bestSoFar = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (verify(mid)) {
                bestSoFar = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return bestSoFar; 
    }
};