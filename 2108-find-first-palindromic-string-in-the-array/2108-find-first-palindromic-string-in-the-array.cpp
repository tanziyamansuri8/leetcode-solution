class Solution {
public:
 bool isPalindrome(string word){
     int i=0;
     int j = word.size()-1;
     while(i<j){
         if(word[i]!= word[j])
         return 0;
         i++;
         j--;
     }
      return 1;
 }
    string firstPalindrome(vector<string>& words) {
        for(auto k:words){
            if(isPalindrome(k))
            return k;
        }
        return "";
    }
};