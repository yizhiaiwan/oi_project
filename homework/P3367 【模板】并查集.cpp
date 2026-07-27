//
// Created by yizhiaiwan on 2026/6/4.
// from:
// https://www.luogu.com.cn/problem/P3367
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,m;
int f[N];
int find(int x){
    if(f[x]==x){
        return x;
    }
    else{
        return f[x] = find(f[x]);
    }
}
void merge(int x,int y){
    int r1 = find(x);
    int r2 = find(y);
    if(r1!=r2){
        f[r1] = r2;
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        f[i] = i;
    }
    while(m--){
        int x,y,z;
        cin>>z>>x>>y;
        if(z==1){
            merge(x,y);
        }
        else{
            int r1 = find(x);
            int r2 = find(y);
            if(r1!=r2){
                cout<<"N"<<endl;
            }
            else cout<<"Y"<<endl;
        }
    }
}