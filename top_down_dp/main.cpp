#include <iostream>

using namespace std;
//recursive approach
int fib(int n)
{
if(n==0)
    return 0;
if(n==1)
    return 1;
else
    return fib(n-1)+fib(n-2); //mathematical induction
}
//dp using top down
int fibDP(int n,int *dp){
    if(n==0|| n==1)
    {
        dp[n]=n;
        return n;

    }
    if(dp[n]!=-1)
        return dp[n];
    else{
        //compute it
        dp[n]=fibDP(n-1,dp)+fibDP(n-2,dp);
        return dp[n];

    }
}
//dp using bottom up and O(n) space complexity
 int fibBup(int n){
    int fib[100];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++)
            fib[i]=fib[i-1]+fib[i-2];
    return fib[n];
}
int fibO(int n)
{
  int a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}
int main()
{
    cout<<fib(5)<<"\n";
    int dp[100];
    for(int i=0;i<100;i++)
        dp[i]=-1;
    cout<<fibDP(5,dp)<<endl;
    cout<<fibBup(5)<<endl;
    cout<<fibO(5);
    return 0;
}
