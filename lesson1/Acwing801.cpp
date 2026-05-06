// 位运算
// 统计二进制中1的个数
#include<iostream>
using namespace std;

int n;

int lowbit(int x){
    return x & -x;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        int res=0;
        cin>>x;
        while(x){
            x=x-lowbit(x);  //每次减去x的最后一位1
            res++;
        }
        cout<<res<<' ';
    }
    return 0;
}