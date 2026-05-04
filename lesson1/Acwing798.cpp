//二维差分数组
#include<iostream>
using namespace std;

const int N=1010;
int n,m;
int q; //操作数
int a[N][N],b[N][N]; //原矩阵和差分矩阵

void insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1]+=c;
    b[x2+1][y1]-=c;
    b[x1][y2+1]-=c;
    b[x2+1][y2+1]+=c;
}

int main(){
    cin>>n>>m>>q;
    
    //读取原数组
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    
    //初始化差分数组
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            insert(i,j,i,j,a[i][j]);
        }
    }
    
    //进行操作
    while(q--){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c);
    }
    
    //b差分数组求前缀和
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1]; //运用b数组放前缀和
        }
    }
    
    //打印b也就是运算过后的原数组
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
