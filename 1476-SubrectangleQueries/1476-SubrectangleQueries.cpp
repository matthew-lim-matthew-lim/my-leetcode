// Last updated: 4/10/2026, 2:09:30 PM
#include <vector>

using namespace std;

static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class SubrectangleQueries {
    vector<vector<int>> rect;
    // Храним историю обновлений: {r1, c1, r2, c2, val}
    struct Update {
        int r1, c1, r2, c2, val;
    };
    vector<Update> updates;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        // Просто пушим в историю. O(1)
        updates.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        // Проверяем историю с конца (самые свежие данные)
        for (int i = updates.size() - 1; i >= 0; --i) {
            const auto& u = updates[i];
            if (row >= u.r1 && row <= u.r2 && col >= u.c1 && col <= u.c2) {
                return u.val;
            }
        }
        // Если обновлений для этой точки не было, берем оригинал
        return rect[row][col];
    }
};