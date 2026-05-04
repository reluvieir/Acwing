//高精度除法（高精度整数/低精度整数）
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> div(vector<int> &A,int b,int &r){   //r是引用
    vector<int> C;
    
    for(int i=A.size()-1;i>=0;i--){
        r=10*r+A[i];
        C.push_back(r/b);
        r=r%b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1 && C.back()==0)    C.pop_back();
    return C;
}

int main(){
    string a;
    int b;
    int r;
    cin >> a >> b;
    
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
    }
    
    auto C = div(A,b,r);
    
    for(int i=C.size()-1;i>=0;i--){
        cout<<C[i];
    }
    cout << endl << r << endl;
    return 0;
}