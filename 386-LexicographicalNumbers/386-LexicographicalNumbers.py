# Last updated: 6/8/2025, 3:56:46 PM
""" 
You can probably go by the number of digits. 
Eg. 
111
112
113
...

n = 100

1
10
100
101
102
...
109
11
110
...
119
12
120

n = 1000

1
10
100
1000
1001
...
1009
101
1010
"""
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        lexicographical_numbers = []
        current_number = 1

        # Generate numbers from 1 to n
        for _ in range(n):
            lexicographical_numbers.append(current_number)

            # If multiplying the current number by 10 is within the limit, do it
            if current_number * 10 <= n:
                current_number *= 10
            else:
                # Adjust the current number by moving up one digit
                while current_number % 10 == 9 or current_number >= n:
                    current_number //= 10  # Remove the last digit
                current_number += 1  # Increment the number

        return lexicographical_numbers