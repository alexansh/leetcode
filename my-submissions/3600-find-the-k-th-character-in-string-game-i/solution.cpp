class Solution {
public:

    char solve(long long k){
        if(k == 1){
            return 'a';
        }

        long long half = 1;

        while(half * 2<k){
            half *= 2;
        }

        if(k>half){
            char ch = solve(k-half);

            if(ch == 'z'){
                return 'a';
            }

            return ch + 1;
        }

        return solve(k);
    }
    char kthCharacter(int k) {
        return solve(k);
    }
};
