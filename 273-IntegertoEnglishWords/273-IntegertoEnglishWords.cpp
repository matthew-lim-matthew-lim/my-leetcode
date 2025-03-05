class Solution {
public:
    unordered_map<int, string> d = {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        {100, "Hundred"},
        {1000, "Thousand"},
        {1000000, "Million"},
        {1000000000, "Billion"}
    };

    vector<string> deconstructThreeDigits(int curr) {
        vector<string> words;

        int index;
        int firstTwoDigits = curr % 100;
        // First digit
        if (firstTwoDigits >= 10 && firstTwoDigits <= 20) {
            words.push_back(d[firstTwoDigits]);
        } else {
            index = firstTwoDigits % 10;
            if (index > 0) {
                words.push_back(d[index]);
            }
            // Second digit
            index = firstTwoDigits % 100 - index;
            if (index > 0) {
                words.push_back(d[index]);
            }
        }

        // Third digit
        index = curr / 100;
        if (index > 0) {
            words.push_back(d[100]);
            words.push_back(d[index]);
        }

        return words;
    }

    string numberToWords(int num) {
        // Gotta say like "Hundred" "Thousand" "Million" etc
        // Split into place values and then add those. At most each split has 3 values -> a hundred.
        // Split by Thousand, Million, Billion.
        if (num == 0) {
            return d[0];
        }

        vector<string> words;
        // At most curr is a 3 digit number
        int curr = num % 1000;
        if (curr > 0) {
            vector<string> wordsString = deconstructThreeDigits(curr);
            words.insert(words.end(), wordsString.begin(), wordsString.end());
        }

        curr = (num % 1000000) / 1000;
        if (curr > 0) {
            words.push_back(d[1000]);
            vector<string> wordsString = deconstructThreeDigits(curr);
            words.insert(words.end(), wordsString.begin(), wordsString.end());
        }
   
        curr = (num % 1000000000) / 1000000;
        if (curr > 0) {
            words.push_back(d[1000000]);
            vector<string> wordsString = deconstructThreeDigits(curr);
            words.insert(words.end(), wordsString.begin(), wordsString.end());
        }

        curr = num / 1000000000;
        if (curr > 0) {
            words.push_back(d[1000000000]);
            vector<string> wordsString = deconstructThreeDigits(curr);
            words.insert(words.end(), wordsString.begin(), wordsString.end());
        }

        string res = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            if (res.size() == 0) {
                res += words[i];
            } else {
                res += " " + words[i];
            }
        }

        return res;
    }
};