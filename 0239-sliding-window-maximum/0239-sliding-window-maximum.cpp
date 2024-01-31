class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Initialize a deque which store the index of window
        deque<int>dq;
        // vector which store the maximum element in a each window
        vector<int>ans;

        // Step 1: For the first window
        for(int i=0;i<k;i++){
            // Remove the index which have lower value
            while(!dq.empty()&&nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }          
            // push the current index in dq
            dq.push_back(i);
        }
        // store the maximum element in a first window
        ans.push_back(nums[dq.front()]);
        
        // Step 2: for rest window
        for(int i=k;i<nums.size();i++){
            // removal
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // Insert the element index
            dq.push_back(i);
            // store ans
            ans.push_back(nums[dq.front()]);
        }
         return ans;

        
    }
};