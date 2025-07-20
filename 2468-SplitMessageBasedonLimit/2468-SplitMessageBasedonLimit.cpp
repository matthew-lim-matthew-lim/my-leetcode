// Last updated: 7/21/2025, 12:18:21 AM

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

const std::vector<int> amount_of_numbers_by_digit {0, 9, 90, 900, 9'000, 90'000};
const int suffix_len = 3; // </>

class Solution {
public:
    std::pair<int, int> GetSizeOfMessage(int limit, int groups_count) {
        int result = 0; 
        int d = static_cast<int>(std::log10(groups_count)) + 1;
        if (limit <= suffix_len + d * 2) {
            return {0, 0};
        }
        int i = 1;
        while (i < d) {
            result += amount_of_numbers_by_digit[i] * (limit - (suffix_len + d + i));
            ++i;
        }
        result += (groups_count - std::pow(10, d - 1) + 1) * (limit - (suffix_len + d * 2));
        return {result - (limit - (suffix_len + d * 2)) + 1, result};
    }

    int GetNumberOfDigits(size_t size, int limit) {
        int d = 0;
        do {   
            ++d;
            int i = 1;
            int cur_size = 0;
            if (limit <= suffix_len + d * 2) {
                return 0;
            }
            while (i <= d) {
                cur_size += amount_of_numbers_by_digit[i] * (limit - (suffix_len + d + i));
                ++i;
            }
            if (cur_size >= size) {
                return d;
            }
        } while (true);
    }

    int GuessAmountOfGroups(int size, int limit) {
        int digits = GetNumberOfDigits(size, limit);
        if (digits == 0) {
            return 0;
        }
        int best_case = 0;
        int r = std::min(static_cast<int>(std::pow(10, digits)), size + 1); 
        int l = static_cast<int>(std::pow(10, digits - 1));
        do {
            int mid = (r + l) / 2;
            auto [min, max] = GetSizeOfMessage(limit, mid);
            if (min == 0) {
                r = mid;
            } else if (size >= min && size <= max) {
                best_case = mid;
                r = mid;
            } else if (size < min) {
                r = mid;
            } else {
                l = mid + 1;
            }
        } while (l != r);
        return best_case;
    }
public:
    std::vector<std::string> splitMessage(std::string message, int limit) {
        if (limit < 6) { // min suffix = <a/b>
            return {};
        }
        int groups_count = GuessAmountOfGroups(static_cast<int>(message.size()), limit);
        if (groups_count == 0) {
            return {};
        }
        std::vector<std::string> groups(groups_count);
        std::string end_of_suffix = "/" + std::to_string(groups_count) + ">";
        size_t idx = 0;
        int total_digits = end_of_suffix.size() - 2;
        int digits = 0;
        size_t i = 1;
        do {
            ++digits;
            size_t free_space = limit - (suffix_len + digits + total_digits);
            int n = std::min(groups_count + 1, static_cast<int>(std::pow(10, digits)));
            while (i < n) {                
                std::string group = message.substr(idx, free_space) + "<" + std::to_string(i) + end_of_suffix;
                groups[i - 1] = std::move(group);
                idx += free_space;
                ++i;
            }
        } while (i <= groups_count);

        return groups;
    }
};