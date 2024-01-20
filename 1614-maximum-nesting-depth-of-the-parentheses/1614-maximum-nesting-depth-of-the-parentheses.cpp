class Solution {
public:
    int maxDepth(string s) {
        int res =0;
        int curr=0;
        for(int i =0;i<s.length();i++){
            if(s[i] == '('){
                res = max(res,++curr);

            }
            if(s[i] == ')'){
                curr--;
            }
        }
        return res;
        
    }
};