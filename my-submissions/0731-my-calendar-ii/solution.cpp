class MyCalendarTwo {
public:
    map<int, int> mp;

    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int active = 0;

        for (auto [time, change] : mp) {
            active += change;

            if (active >= 3) {
                mp[startTime]--;
                mp[endTime]++;

                if (mp[startTime] == 0)
                    mp.erase(startTime);

                if (mp[endTime] == 0)
                    mp.erase(endTime);

                return false;
            }
        }

        return true;
    }
};
