#include <iostream>
#include <cstdio>   // scanf/printf需要这个头文件
#include <algorithm>    // swap函数需要
using namespace std;

const int N=100000;
int n;
int q[N];

void quick_sort(int q[],int l,int r){
    if(l>=r)    return;
    int x=q[(l+r)/2];
    int i=l-1;
    int j=r+1;
    
    while(i<j){
        do i++ ; while (q[i]<x);    // i先向右走，直到找到第一个大于等于x的数才停下
        do j-- ; while (q[j]>x);    // j先想左走，直到找到第一个小于等于x的数才停下
        if(i<j) swap(q[i],q[j]);    // 如果指针还没有交叉，交换这两个错位的数
    }
    
    quick_sort(q,l,j);  // 使用i可能会陷入死循环，当x=q[i]时，i停在这个位置不动
    // 同时使用j时，上面就不能用q[r]，不然也会死循环
    quick_sort(q,j+1,r);
}

int main(){
    scanf("%d",&n);
    
    for (int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    
    quick_sort(q,0,n-1);
    
    for(int i=0;i<n;i++){
        printf("%d ",q[i]);
    }
    return 0;
}
