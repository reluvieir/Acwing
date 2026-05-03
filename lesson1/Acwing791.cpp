//高精度加法
#include<iostream>
#include<vector>
using namespace std;

vector<int> add(vector<int> A,vector<int> B){
    if(B.size()>A.size())   return add(B,A);
    vector<int> C;
    
    int t=0;
    for(int i=0;i<A.size();i++){
        t+=A[i];
        if(i<B.size()){
            t+=B[i];
        }
        C.push_back(t%10);
        t=t/10;
    }
    
    //算一下最高位,即t不等于0
    if(t)   C.push_back(t);
    return C;
}


int main(){
    string a,b;
    vector<int> A,B;//A=[6,5,4,3,2,1]

    cin>>a>>b;  //a=123456
    for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
    }
    for(int i=b.size()-1;i>=0;i--){
        B.push_back(b[i]-'0');
    }
    
    auto C=add(A,B);    //C是一个数组[7,6,5,4,3,2,1]，最后要倒着输出
    for(int i=C.size()-1;i>=0;i--){
        cout<<C[i];
    }
    return 0;
}
