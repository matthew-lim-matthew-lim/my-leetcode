// Last updated: 4/19/2026, 5:31:02 PM
1/* 
2Use the bigger banknotes first. 
3
4It must use the biggest available banknote. 
5Then it can use the smaller ones as necessary. 
6 */
7class ATM {
8private:
9    vector<int> balance{0, 0, 0, 0, 0};
10    vector<int> values{20, 50, 100, 200, 500};
11public:
12    ATM() {
13        
14    }
15    
16    void deposit(vector<int> banknotesCount) {
17        for (int i = 0; i < banknotesCount.size(); i++) {
18            balance[i] += banknotesCount[i];
19        }
20    }
21    
22    vector<int> withdraw(int amount) {
23        vector<int> transaction(5, 0);
24        for (int i = balance.size()-1; i >= 0; i--) {
25            if (balance[i] - transaction[i] > 0 && 
26                values[i] <= amount
27            ) {
28                int multiple = min(amount / values[i], balance[i]);
29                amount -= (values[i] * multiple);
30                transaction[i] += multiple;
31            }
32        }
33
34        if (amount != 0) {
35            return {-1};
36        }
37
38        for (int i = 0; i < balance.size(); i++) {
39            balance[i] -= transaction[i];
40        }
41
42        return transaction;
43    }
44};
45
46/**
47 * Your ATM object will be instantiated and called as such:
48 * ATM* obj = new ATM();
49 * obj->deposit(banknotesCount);
50 * vector<int> param_2 = obj->withdraw(amount);
51 */