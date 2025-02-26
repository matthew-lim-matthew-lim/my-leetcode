/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
private:
    bool match(string currUrl, string newUrl) {
        for (int i = 7; i < currUrl.size() && currUrl[i] != '/'; i++) {
            if (i == newUrl.size()) {
                return false;
            }
            if (newUrl[i] != currUrl[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
       // Start matching from index 7 until end or '/'.
       

       unordered_set<string> explored;
       explored.insert(startUrl);

       // DFS
       stack<string> stk;
       stk.push(startUrl);

        while (!stk.empty()) {
            string curr = stk.top();
            stk.pop();
            vector<string> toExplore = htmlParser.getUrls(curr);
            for (string s : toExplore) {
                if (!explored.contains(s) && match(curr, s)) {
                    explored.insert(s);
                    stk.push(s);
                }
            }
        }

       return { explored.begin(), explored.end() }; 
    }
};