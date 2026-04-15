// Last updated: 4/15/2026, 4:53:38 PM
1class Solution {
2public:
3
4    // Encodes a URL to a shortened URL.
5    string encode(string longUrl) {
6        urlMap_[counter_++] = longUrl;
7        return to_string(counter_-1);
8    }
9
10    // Decodes a shortened URL to its original URL.
11    string decode(string shortUrl) {
12        return urlMap_[stoul(shortUrl)];
13    }
14private:
15    unsigned long counter_;
16    unordered_map<unsigned long, string> urlMap_;
17};
18
19// Your Solution object will be instantiated and called as such:
20// Solution solution;
21// solution.decode(solution.encode(url));