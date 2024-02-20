class Solution {
public: 
  
        
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
        int result =0;
        for(int i=0;i<=n;i++){
            result ^= i;
           
        }
        for(int num : nums){
            result ^= num;
        }
         
        return result;
    
    }
};