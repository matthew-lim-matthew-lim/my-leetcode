// Last updated: 12/7/2025, 2:13:53 PM
1class Solution {
2public:
3    vector<int> sortByReflection(vector<int>& nums) {
4        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
5            bitset<32> aBin(a);
6            bitset<32> bBin(b);
7            string aBinStr = aBin.to_string();
8            string bBinStr = bBin.to_string();
9            aBinStr = aBinStr.substr(aBinStr.find('1'));
10            bBinStr = bBinStr.substr(bBinStr.find('1'));
11            reverse(aBinStr.begin(), aBinStr.end());
12            reverse(bBinStr.begin(), bBinStr.end());
13            long long aNew = stoll(aBinStr, nullptr, 2);
14            long long bNew = stoll(bBinStr, nullptr, 2);
15
16            // cout << a << " " << b << ": " << aBinStr << ", " << bBinStr << endl;
17            // cout << a << " " << b << ": " << aNew << ", " << bNew << endl;
18            
19            if (aNew != bNew) {
20                return aNew < bNew;
21            }
22            return a < b;
23        });
24
25        return nums;
26    }
27};