class Solution {
public:

    char solve(int n, int k) {

        // S1 = "0"
        if (n == 1)
            return '0';

        int mid = 1 << (n - 1);

        // Middle element
        if (k == mid)
            return '1';

        // First half
        if (k < mid)
            return solve(n - 1, k);

        // Second half
        char ch = solve(n - 1, (1 << n) - k);

        // Invert the bit
        return ch == '0' ? '1' : '0';
    }

    char findKthBit(int n, int k) {
        return solve(n, k);
    }
};
