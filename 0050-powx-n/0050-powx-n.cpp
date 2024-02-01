class Solution {
public:
   double binaryExp(double x, int n, bool& flag){
       if(n==0)return 1;
       if(n<0 && flag){
           x=1/x;
           flag=!flag;
       }
        if(n&1){
            return x*binaryExp(x*x,n/2,flag);
        }
         else{
             return binaryExp(x*x,n/2,flag);
         }
   }
    double myPow(double x, int n) {

        bool flag=true;
        return binaryExp(x,n,flag);
        
    }
};