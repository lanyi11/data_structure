#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int V,n,sum=0;
    int v[40]={0};
    int dp[40005]={0};
    cin>>V;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>v[i];
        sum+=v[i];
    }

    // for(int i=1;i<=V;++i){
    //     for(int j=0;j<n;++j){
    //         if(v[j]<=i){
    //             dp[i]=max(dp[i],dp[i-v[j]]+v[j]);
    //         }
    //     }
    // }

    for(int i=0;i<n;++i){
        for(int j=V;j>=v[i];--j){//必须是--不能是++
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
    }
    
    cout<<V-dp[V];
    return 0;
}//很困惑,很纠结要不要判断超过总容量V,但是实际上是不需要判定的.