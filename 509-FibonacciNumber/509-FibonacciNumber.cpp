// Last updated: 4/10/2025, 11:37:17 AM
constexpr int fib_constexpr(int n) {
    return (n <= 1) ? n : fib_constexpr(n - 1) + fib_constexpr(n - 2);
}

template <std::size_t N>
constexpr std::array<int, N + 1> generateFibTable() {
    std::array<int, N + 1> table = {};
    table[0] = 0;
    if (N >= 1)
        table[1] = 1;
    for (std::size_t i = 2; i <= N; ++i) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table;
}

constexpr std::size_t maxFib = 30; 
constexpr auto fibTable = generateFibTable<maxFib>();

class Solution {
public:
    int fib(int n) {
        return fibTable[n];
    }
};