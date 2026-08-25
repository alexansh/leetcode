class Solution {
public:

    long long MOD = 1000000007;

    long long power(long long a, long long n) {

        if (n == 0)
            return 1;

        long long half = power(a, n / 2);

        long long ans = (half * half) % MOD;

        if (n % 2 == 1)
            ans = (ans * a) % MOD;

        return ans;
    }

    int monkeyMove(int n) {

        long long total = power(2, n);

        return (total - 2 + MOD) % MOD;
    }
};
