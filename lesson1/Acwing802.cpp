// 离散化
// 题目描述：给定n个数值对(x,c)，表示在坐标x上加上c，给定m个数值对(l,r)，表示询问区间[l,r]上的数值和

//不能直接用前缀和，因为x的范围是2*10^9，没办法开那么大的数组
//但实际操作次数只有10^5，只有10^5个坐标是有意义的，其余全是0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;

vector<int> all; //存放所有出现过的下标
vector<PII> add,query; //存放加入的下标+数值以及l+r

const int N=300010; //x+l+r数值上等于n+2m
int a[N],s[N];  //离散化后,原数组和求和数组，用于求前缀和
int n,m;

int find(int x){
    int l,r;
    l=0;
    r=all.size()-1;
    while(l<r){
        int mid=(l+r)/2;
        // 找 最小的 大于等于x的那个值
        if(all[mid]>=x)  r=mid;
        else l=mid+1;
    }
    return l+1;
}

int main(){
    cin>>n>>m;
    
    //读取add
    for(int i=0;i<n;i++){
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        
        all.push_back(x); 
        
    }
    
    //读取query
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        
        all.push_back(l);
        all.push_back(r);
    }
    
    // 对all下标数组去重
    // 原来的all数组：[1,3,7,1,3,4,6,7,8]
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    // 现在的all数组：[1,3,4,6,7,8]
    
    //插入数值
    //因为后面要用前缀，所以数组下标从1开始
    //find函数：find(1)->返回下标1，find(3)->返回下标2...，相当于缩小数组空间，进行了压缩映射。用二分查找
    for(auto item:add){ //{3,6}
        a[find(item.first)]+=item.second;
    }
    
    //处理l，r这个query，需要先计算前缀和
    for(int i=1;i<=all.size();i++){   //all vector和a数组的长度应该是一致的
        s[i]=s[i-1]+a[i];
    }
    
    for(auto item:query){ 
        int l,r;
        l=find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}
