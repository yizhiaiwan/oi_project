//
// Created by yizhiaiwan on 2026/5/14.
// from:
// https://www.luogu.com.cn/problem/P1198
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int f[N][30],lg[N];
int M,D,t,len;
void init(){
    for(int i = 2;i<=N-10;i++){
        lg[i] = lg[i>>1]+1;
    }
}




signed main(){
    scanf("%lld%lld",&M,&D);
    init();
    for(int i = 1;i<=M;i++){
        int x;
        char opt;
        scanf("\n%c %lld",&opt,&x);
        if(opt=='A'){
            x = (x+t)%D;
            f[++len][0] = x;
            for(int j = 1;j<=lg[len];j++){
                f[len][j] = max(f[len][j-1],f[len-(1<<j-1)][j-1]);
            }
        }
        else{
            t = max(f[len][lg[x]],f[len-x+(1<<lg[x])][lg[x]]);
            printf("%lld\n",t);
        }
    }
}