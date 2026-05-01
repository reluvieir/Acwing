#include<iostream>
#include<cstdio>   // scanf/printf需要这个头文件
#include<algorithm>    // swap函数需要
using namespace std;

const int N=100000;
int n,k;
int q[N];

int quick_sort(int l,int r,int k){
    if(l>=r)    return q[l];
    int x=q[(l+r)/2];
    int i=l-1;
    int j=r+1;
    
    while(i<j){
        do i++ ; while (q[i]<x);    // i先向右走，直到找到第一个大于等于x的数才停下
        do j-- ; while (q[j]>x);    // j先想左走，直到找到第一个小于等于x的数才停下
        if(i<j) swap(q[i],q[j]);    // 如果指针还没有交叉，交换这两个错位的数
    }
    
    int sl=j-l+1;  // 左边的数量
    
    if(k<=sl) return quick_sort(l,j,k); // 如果第k小的数在左边，继续在左边找
    else return quick_sort(j+1,r,k-sl); // 否则在右边找，注意右边的k要减去左边的数量sl，因为我们已经排除了左边的sl个数了
}

int main(){
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>q[i];
    }
    cout<<quick_sort(0,n-1,k)<<endl;
    return 0;
}