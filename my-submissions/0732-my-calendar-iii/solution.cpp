class MyCalendarThree {
public:
    map<int, int> mp;

    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int active = 0;
        int ans = 0;

        for (auto [time, change] : mp) {
            active += change;
            ans = max(ans, active);
        }

        return ans;
    }
};
