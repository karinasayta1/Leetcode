class Solution {
public: 
// Function to calculate Greatest Common Divisor
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate Least Common Multiple
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// Count how many ugly numbers <= X
long long countUgly(long long X, long long a, long long b, long long c) {
    long long ab = lcm(a, b);
    long long bc = lcm(b, c);
    long long ac = lcm(a, c);
    long long abc = lcm(a, bc);  // lcm(a,b,c)

    long long count = X / a + X / b + X / c;
    count -= (X / ab + X / ac + X / bc);
    count += X / abc;

    return count;
}

// Binary search to find nth ugly number
int nthUglyNumber(int n, int a, int b, int c) {
    long long low = 1;
    long long high = 2e9;  // safe upper bound

    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (countUgly(mid, a, b, c) < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return (int)low;
}
};