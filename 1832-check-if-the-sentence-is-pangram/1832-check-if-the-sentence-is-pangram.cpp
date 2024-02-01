class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>v(26,0);
        
    for(int x:sentence){
        v[x-97]++;
    }
        for(int i=0;i<v.size();i++)
         if(!v[i]) return false;
        return true;
    }
};