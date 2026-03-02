// Last updated: 3/2/2026, 11:16:25 PM
1/* 
2For each amount up to 'amount', find the lowest number of coins to make it.
3
4for each coinValue:
5    dp[i] = min(dp[i], dp[i - coinValue] + 1);
6 */
7public class Solution {
8    public int CoinChange(int[] coins, int amount) {
9        List<int> dp = new List<int>(Enumerable.Repeat(amount + 1, amount + 1));
10        dp[0] = 0;
11        for (int i = 0; i < coins.Length; i++) {
12            if (coins[i] > amount) {
13                continue;
14            }
15            dp[coins[i]] = 1;
16        }
17
18        for (int i = 1; i <= amount; i++) {
19            for (int j = 0; j < coins.Length; j++) {
20                if (i - coins[j] >= 0 && dp[i - coins[j]] > 0) {
21                    dp[i] = Math.Min(dp[i], dp[i - coins[j]] + 1);
22                }
23            }
24        }
25
26        // for (int i = 1; i <= amount; i++) {
27        //     Console.WriteLine($"{i} with amount {dp[amount]}");
28        // }
29
30        return dp[amount] == amount + 1 ? -1 : dp[amount];
31    }
32}