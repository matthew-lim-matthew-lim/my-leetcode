// Last updated: 8/27/2025, 1:29:38 AM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDia = 0;
        int areaMaxDia = 0;
        for (vector<int>& dim : dimensions) {
            if (sqrt(pow(dim[0], 2) + pow(dim[1], 2)) > maxDia) {
                maxDia = sqrt(pow(dim[0], 2) + pow(dim[1], 2));
                areaMaxDia = dim[0] * dim[1];
            } else if (sqrt(pow(dim[0], 2) + pow(dim[1], 2)) == maxDia &&
                dim[0] * dim[1] > areaMaxDia)
            {
                areaMaxDia = dim[0] * dim[1];
            }
        }

        return areaMaxDia;
    }
};