//单链表
#include<iostream>
using namespace std;

int head;
const int N=100010;
int e[N],ne[N];
int idx;

void init(){
    head=-1;
    idx=0;
}

void addhead(int x){ //头插，把新节点插到第一个
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}

void add(int k, int x){
    e[idx]=x;
    ne[idx]=ne[k-1];
    ne[k-1]=idx;
    idx++;
}

void removing(int k){
    if(k==0){
        head=ne[head];
    }   
    else{
        ne[k-1]=ne[ne[k-1]];
    }
}

int main(){
    int m,k,x;
    cin>>m;
    
    init();
    
    for(int i=0;i<m;i++){
        char flag;
        
        cin>>flag;
        
        if(flag=='H'){  //向链表头插入一个数
            cin>>x;
            addhead(x);
        }
        else if(flag=='I'){ //在第k个插入的数后插入一个x
            cin>>k>>x;
            add(k,x);
        }   
        else if(flag=='D'){ //删除第k个插入的数后面的数
            cin>>k;
            removing(k);
        }
    }
    
    //打印链表
    for(int i=head;i!=-1;i=ne[i]){
        cout<<e[i]<<' ';
    }
    return 0;
}