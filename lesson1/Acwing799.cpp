// 双指针算法
// 最长连续不重复子序列
#include<iostream>
using namespace std;

//用一个临时数组s去储存a[i]出现的次数
int const N=100010;
int a[N],s[N];
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int res=0;
    for(int i=0,j=0;i<n;i++){
        s[a[i]]++;
        while(s[a[i]]>1){
            s[a[j]]--;
            j++;
        }
        res=max(res,i-j+1);
    }
    
    cout<<res;
    return 0;
}