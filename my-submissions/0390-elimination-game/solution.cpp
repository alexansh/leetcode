class Solution {
public:

    int solve(int head, int step, int remaining, bool left) {

        if (remaining == 1)
            return head;

        if (left || remaining % 2 == 1)
            head += step;

        remaining /= 2;

        step *= 2;
        
        left = !left;

        return solve(head, step, remaining, left);
    }

    int lastRemaining(int n) {
        return solve(1, 1, n, true);
    }
};
