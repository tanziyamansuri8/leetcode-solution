class Solution {
public:
   int solveUsingMemo(vector<int>&nums, int index, vector<int> &dp){
        // Base case
        if(index >= nums.size()){
            return 0;
        }

        // Step 3: if ans max amount already exist then return ans
        if(dp[index] != -1){
            return dp[index];
        }

        // Step 2: store ans max amount and return ans using DP array
        // TOP DOWN: Traverse from 0 to N
        int include = nums[index] + solveUsingMemo(nums, index+2, dp);
        int exclude = 0 + solveUsingMemo(nums, index+1, dp);        
        dp[index] = max(include, exclude);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        // Step 1: create DP array
        int n = nums.size();
        vector<int> dp(n, -1);
        int index = 0;
        return solveUsingMemo(nums, index, dp);
    }
};
