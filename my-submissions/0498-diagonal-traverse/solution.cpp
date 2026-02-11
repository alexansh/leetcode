class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int, vector<int>>mp;
        vector<int> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flip = true;
        for(auto &it: mp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }

        flip = !flip;
        
        for(int &num: it.second){
            res.push_back(num);
        }
        }
        return res;
    }
};
