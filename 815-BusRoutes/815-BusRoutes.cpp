// Last updated: 7/21/2025, 10:46:52 PM
/* 
Feels like BFS, where you keep track of levels. 
 */

class Solution {
struct Step {
    int route;
    int lvl;
};

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // The queue stores the bus number
        int n = routes.size();

        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> stopToRoute;

        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                stopToRoute[stop].push_back(i);
            }
        }

        unordered_set<int> visitedRoutes;

        queue<Step> q;
        for (int route : stopToRoute[source]) {
            if (!visitedRoutes.contains(route)) {
                q.push(Step(route, 1));
                visitedRoutes.insert(route);
            }
        }

        while (!q.empty()) {
            Step curr = q.front();
            q.pop();

            int currRoute = curr.route;
            int currLvl = curr.lvl;

            for (int stop : routes[currRoute]) {
                if (stop == target) {
                    return currLvl;
                }
                for (int route : stopToRoute[stop]) {
                    if (!visitedRoutes.contains(route)) {
                        q.push(Step(route, currLvl + 1));
                        visitedRoutes.insert(route);
                    }
                }
            }
        }

        return -1;
    }
};