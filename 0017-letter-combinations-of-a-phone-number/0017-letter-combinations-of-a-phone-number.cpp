class Solution {
public:
   
    unordered_map <int,string> mp;
    string ans = ""; 
    void solve(int idx,string &digits,vector<string> &v){
        if(idx >= digits.size()){ // Base Case when idx is greater or equal to digits length
            v.push_back(ans); // Save the answer
            return;
        }    
        int num = digits[idx]-'0'; // Stored is ASCII, therefore substract it with '0' 
        string s = mp[num]; // Store the mapped value to the string s
        for(int i=0;i<s.size();i++){
            ans += s[i]; // Add
            solve(idx+1,digits,v); // Move forward
            ans.pop_back(); // BackTrack 
        }
    }
    vector<string> letterCombinations(string digits) {
        mp[2] = {"abc"}; // Making int -> string Map given accordingly
        mp[3] = {"def"};
        mp[4] = {"ghi"};
        mp[5] = {"jkl"};
        mp[6] = {"mno"};
        mp[7] = {"pqrs"};
        mp[8] = {"tuv"};
        mp[9] = {"wxyz"};
        vector<string> v;
        if(digits.size() == 0)
            return v;
        solve(0,digits,v);
        return v;
    }
};