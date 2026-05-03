// 二分法数的范围
#include<iostream>
using namespace std;

const int N=100000;
int q[N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>> q[i];
    }
    
    while(m--){
        int x;
        cin>>x;
        int l=0;
        int r=n-1;
        
        while(l<r){
            int mid= (l+r)/2;
            if(q[mid]>=x)   r=mid;
            else l=mid+1;
        }
        
        if(q[l]!=x) cout<<"-1 -1"<<endl;
        else{
            cout<<l<<' ';
            
            int l=0;
            int r=n-1;
            while(l<r){
                int mid= (l+r+1)/2;
                if(q[mid]<=x)   l=mid;
                else    r=mid-1;
            }
            cout<<l<<endl;
        }
    }
    return 0;
}