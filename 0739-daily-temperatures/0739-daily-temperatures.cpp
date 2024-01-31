class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int hottest=INT_MIN;
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(temperatures[i]>=hottest){
                hottest = temperatures[i];
            }
             else{
                 int it = i+1;
                 while(temperatures[it]<=temperatures[i]){
                     it = it+ans[it];
                 }
                  ans[i] = it-i;
             }
        }
        return ans;
        
    }
};