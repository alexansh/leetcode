class Solution {
public:
    bool canFinish(long long time, int mountainHeight, vector<int>& workerTimes) {
        long long removed = 0;

        for (int w : workerTimes) {

            long long low = 0;
            long long high = mountainHeight;

            while (low <= high) {
                long long mid = low + (high - low) / 2;

                if (1LL * w * mid * (mid + 1) / 2 <= time)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            removed += high;

            if (removed >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long low = 0;
        long long high = 1LL * (*min_element(workerTimes.begin(), workerTimes.end()))
                         * mountainHeight * (mountainHeight + 1) / 2;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (canFinish(mid, mountainHeight, workerTimes))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
