# Last updated: 3/14/2026, 1:37:06 PM
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        # Total number of happy strings of length n
        total = 3 * (1 << (n - 1))
        if k > total:
            return ""
        ans = []
        prev = ""
        for i in range(n):
            # Try characters in lexicographical order
            for ch in ['a', 'b', 'c']:
                # Adjacent chars cannot be the same
                if ch == prev:
                    continue
                # Number of strings if we choose this character here
                remaining_len = n - i - 1
                cnt = 1 << remaining_len   # 2^remaining_len
                if k > cnt:
                    # Skip this whole block
                    k -= cnt
                else:
                    # This character belongs to the kth string
                    ans.append(ch)
                    prev = ch
                    break
        return "".join(ans)