// Last updated: 4/25/2026, 9:27:59 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int w=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1)
            {
                return dist[r][c];
            }
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m )
                {
                    int temp=abs(heights[nr][nc]-heights[r][c]);
                    if(dist[nr][nc]>max(temp,w))
                    {
                        dist[nr][nc]=max(temp,w);
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};
