class Solution {
public:

    int solve(vector<int>& nums, int l, int r) {

        if (l == r)
            return nums[l];

        int takeLeft = nums[l] - solve(nums, l + 1, r);
        int takeRight = nums[r] - solve(nums, l, r - 1);

        return max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {

        int difference = solve(nums, 0, nums.size() - 1);

        return difference >= 0;
    }
};
