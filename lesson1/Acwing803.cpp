// 区间合并

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N=100010;

typedef pair<int,int> PII;

void merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(),segs.end());
    
    int st,ed;
    st=-2e9;
    ed=-2e9;
    
    for(auto seg:segs){
        if(seg.first>ed){
            if(st!=-2e9) res.push_back({st,ed});
            st=seg.first;
            ed=seg.second;
        }
        else{
            ed=max(ed,seg.second);
        }
    }
    
    if(st!=-2e9) res.push_back({st,ed});
    segs=res;
}

int main(){
    int n;
    int st,ed;
    vector<PII> segs;
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>st>>ed;
        segs.push_back({st,ed});
    }
    
    merge(segs);
    
    cout<<segs.size()<<endl;
    
    return 0;
}