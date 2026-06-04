//
// Created by yizhiaiwan on 2026/6/4.
// from:
// https://www.luogu.com.cn/problem/B3872#ide
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int f[N];
struct node{
    int t,w;
}a[N];
int n,ans;
int find(int x) {
    if (f[x]!=x) {
        f[x] = find(f[x]);
    }
    return f[x];
}

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i].t);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i].w);
    }
    sort(a+1,a+n+1,[](node a,node b){return a.w>b.w;});
    for(int i = 1;i<=n;i++) f[i] = i;
    for(int i = 1;i<=n;i++){
        int rt = find(a[i].t);
        if(rt>0){
            f[rt] = find(rt-1);
            ans+=a[i].w;
        }
    }
    cout<<ans;
}