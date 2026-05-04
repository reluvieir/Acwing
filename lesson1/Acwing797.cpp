//一维差分数组
#include<iostream>
using namespace std;

int n,m;
int const N=100010;
int a[N],b[N]; //原数组和差分数组

void insert(int l,int r,int c){
    b[l]=b[l]+c;
    b[r+1]=b[r+1]-c;
}

//求前缀和差分数组下标都是从1开始
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    //初始化差分数组
    for(int i=1;i<=n;i++){
        insert(i,i,a[i]);
    }
    
    //执行+c循环
    while(m--){
        int l,r,c;
        cin>>l>>r>>c;
        insert(l,r,c);
    }
    
    //计算完差分数组后，要把他们求前缀最后输出a数组，也可在差分数组基础b空间上计算前缀
    for(int i=1;i<=n;i++){
        b[i]+=b[i-1];
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}