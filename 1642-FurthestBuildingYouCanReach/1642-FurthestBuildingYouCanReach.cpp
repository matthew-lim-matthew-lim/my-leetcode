class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int> pq;
        // Each loop actually processes the next step - whether or not it is possible. 
        for (int i = 0; i < heights.size() - 1; i++) {
            int bricksRequired = heights[i + 1] - heights[i];

            if (bricksRequired <= 0) {
                continue;
            }

            pq.push(bricksRequired);
            bricks -= bricksRequired;

            if (bricks < 0 && ladders == 0) {
                return i;
            }

            if (bricks < 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
        }

        return heights.size() - 1;
    }
};