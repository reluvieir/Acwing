// 双指针算法
// 判断子序列

#include<iostream>
using namespace std;

const int N=100010;
int a[N],b[N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    
    int i=0,j=0;
    
    // a[]=1 3 5  //i 总长度n

    // b[]=1 2 3 4 5  //j 总长度m
    
    while(i<n && j<m){
        if(a[i]==b[j])  i++;
        j++;
    }
    
    if(i==n)    cout<<"Yes";
    else    cout<<"No";
    
    return 0;
}