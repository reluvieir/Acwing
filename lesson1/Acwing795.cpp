// 一维前缀和
#include<iostream>
using namespace std;

int n,m;
const int N=100010;
int q[N],s[N];

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    
    //算一下前缀
    s[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+q[i-1];
    }
    
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}