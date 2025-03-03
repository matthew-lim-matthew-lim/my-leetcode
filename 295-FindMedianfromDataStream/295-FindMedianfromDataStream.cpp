// Inserting into a std::set does not invalidate the iterators since it uses a balanced bst.

class MedianFinder {
public:
    map<int, vector<int>> numMap;
    map<int, vector<int>>::iterator currIter;
    int mapIndex = 0;
    int mapSize = 0; 

    int currIndex = -1;

    MedianFinder() {
        
    }

    // 0100
    
    void addNum(int num) {
        mapSize++;

        numMap[num].push_back(numMap[num].size());
        if (currIndex == -1) {
            currIndex = 0;
            currIter = numMap.begin();
        } 
        if (num < currIter->first) {
            mapIndex++;
        }
    }
    
    double findMedian() {
        cout << "findMedian" << endl;
        cout << mapIndex << " " << (mapSize / 2.0) << " " << mapSize << endl;
        while (mapIndex < (mapSize / 2.0) - 1) {
            mapIndex++;
            currIndex++;
            if (currIndex > currIter->second.size() - 1) {
                currIter++;
                currIndex = 0;
            }
        }
        while (mapIndex >= (mapSize / 2.0)) {
            mapIndex--;
            currIndex--;
            if (currIndex < 0) {
                currIter--;
                currIndex = currIter->second.size() - 1;
            }
        }
        cout << mapIndex << " " << (mapSize / 2.0) << " " << mapSize << endl;
        // cout << currIter->first << " " << currIndex << endl;
        if (mapSize % 2 == 0) {
            auto iterCopy = currIter;
            int indexCopy = currIndex;
            indexCopy++;
            if (indexCopy > iterCopy->second.size() - 1) {
                iterCopy++;
            }
            return (currIter->first + iterCopy->first) / 2.0;
        } else {
            return currIter->first;
        }

        // -1, -2, -3, -4, -5
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */