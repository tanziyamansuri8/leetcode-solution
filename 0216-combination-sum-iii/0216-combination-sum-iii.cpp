class Solution {
public:

set<vector<int>> st;
void solve(int k,int n,vector<int> v,int idx)
{
    if(k==0&&n!=0)
    return;
    if(n==0&&k!=0)
    return;
    if(n==0&&k==0)
    {
        st.insert(v);
        return;
    }

    for(int i=idx+1;i<=9;i++)
    {
        if(i<=n)
        {
            v.push_back(i);
            solve(k-1,n-i,v,i);
            v.pop_back();
        }
        else
        break;
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;


       if(n>45||n==0)
       return ans;


       
       for(int i=1;i<=9;i++)
       {
              vector<int> v;
              if(i<=n)
              {
                  v.push_back(i);
              solve(k-1,n-i,v,i);
              v.pop_back();
              }
              else
              break;

       }
       for(auto itr:st)
       ans.push_back(itr);


return ans;

        
    }
};