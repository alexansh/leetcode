class Solution {
public:
    int countMonobit(int n) {
        int count = 1;      
        long long val = 1;  

        while (val - 1 <= n) {
            count++;
            val <<= 1;
        }
        return count-1;
    }
};
