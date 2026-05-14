//
// Created by yizhiaiwan on 2026/5/5.
// from:
// https://www.luogu.com.cn/problem/P1816
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,m;
int a[N],f[N][20],lg[N];
void init(){
    for(int i = 2;i<=n;i++){
        lg[i] = lg[i>>1]+1;
    }
}


int main(){
    scanf("%d%d",&n,&m);
    init();
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i][0] = a[i];
    }
    for(int j = 1;j<=lg[n];j++){
        for(int i = 1;i+(1<<j)-1<=n;i++){
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int j = lg[(y-x+1)];
        printf("%d ",min(f[x][j],f[y-(1<<j)+1][j]));
    }
}