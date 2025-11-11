class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int input=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "--X"){
                --input;
            }
            if(operations[i] == "X++"){
                input++;
            }
            if(operations[i] == "++X"){
                ++input;
            }
            if(operations[i] == "X--"){
                input--;
            }
        }
        return input;
    }
};
