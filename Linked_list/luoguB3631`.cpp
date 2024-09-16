#include <iostream>
using namespace std;

int  f[2000000]={0};
bool  t[2000000]={0};
int main()
{
    t[1]=true;
    f[1]=0;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        if(a!=1){
            int b=0;
            cin>>b;
            if(a==2){
                cout<<f[b]<<endl;
            }
            if(a==3){
                if(t[b]==0 || t[f[b]]==0) continue;
                t[f[b]]=0;
                int temp=f[b];
                f[b]=f[temp];
                f[temp]=0;
            }
        }
        else{
            int b=0,c=0;
            cin>>b>>c;
            if(t[c]==1) continue;
            t[c]=1;
            f[c]=f[b];
            f[b]=c;
        }
    }
    return 0;
}