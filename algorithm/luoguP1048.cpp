//01背包问题
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int c,n,maxn=0;
    int w[105]={0},v[105]={0};
    int ret[1005][105]={0};
    cin>>c>>n;
    for(int i=0;i<n;++i){
        cin>>w[i]>>v[i];
    }
    for(int j=1;j<=c;++j){
        for(int i=0;i<n;++i){
            if(w[i]<=j) ret[j][i]=max(ret[j][i-1],ret[j-w[i]][i-1]+v[i]);
            else ret[j][i]=ret[j][i-1];
        }
    }
    cout<<ret[c][n-1];
    return 0;
}