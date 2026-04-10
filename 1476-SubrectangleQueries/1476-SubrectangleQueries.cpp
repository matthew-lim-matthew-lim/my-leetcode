// Last updated: 4/10/2026, 2:05:24 PM
1/* 
2Brute force surely works. 
3 */
4
5class SubrectangleQueries {
6public:
7    SubrectangleQueries(vector<vector<int>>& rectangle) : 
8        rec_(rectangle) 
9    {}
10    
11    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
12        for (int i = row1; i <= row2; i++) {
13            for (int j = col1; j <= col2; j++) {
14                rec_[i][j] = newValue;
15            }
16        }
17    }
18    
19    int getValue(int row, int col) {
20        return rec_[row][col];
21    }
22
23private:
24    vector<vector<int>> rec_;
25};
26
27/**
28 * Your SubrectangleQueries object will be instantiated and called as such:
29 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
30 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
31 * int param_2 = obj->getValue(row,col);
32 */