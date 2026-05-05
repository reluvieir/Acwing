// 双指针算法
// 数组元素的目标和

#include<iostream>
using namespace std;

const int N=100010;
int A[N],B[N];
int n,m,x;

int main(){
    cin>>n>>m>>x;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<m;i++){
        cin>>B[i];
    }
    
    int a=0,b=m-1;
    for(a=0,b=m-1;a<n;a++){
        while(b>=0 && A[a]+B[b]>x){
            b--;
        }
        if(A[a]+B[b]==x)    break;
    }
    
    cout<<a<<' '<<b;
    return 0;
}

