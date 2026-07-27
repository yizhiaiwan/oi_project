//
// Created by yizhiaiwan on 2026/5/8.
// from:
// https://www.luogu.com.cn/problem/P2216
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
struct node{int max_num,min_num;};
node f[N][N][7];
int v;
int lg[N];
int a,b,n,ans = 0x7fffffff;
void init() {
    for (int i = 2;i<=N-1;i++) {
        lg[i] = lg[i>>1]+1;
    }
}
int main() {
    init();
    scanf("%d%d%d",&a,&b,&n);
    for (int i = 1;i<=a;i++) {
        for (int j = 1;j<=b;j++) {
            scanf("%d",&v);
            f[i][j][0].max_num = v;
            f[i][j][0].min_num = v;
        }
    }
    for (int k = 1;k<=lg[n];k++) {
        for (int x = 1;x+(1<<k)-1<=a;x++) {
            for (int y = 1;y+(1<<k)-1<=b;y++) {
                f[x][y][k].max_num = max(max(f[x][y][k-1].max_num,f[x][y+(1<<(k-1))][k-1].max_num),max(f[x+(1<<(k-1))][y][k-1].max_num,f[x+(1<<(k-1))][y+(1<<(k-1))][k-1].max_num));
                f[x][y][k].min_num = min(min(f[x][y][k-1].min_num,f[x][y+(1<<(k-1))][k-1].min_num),min(f[x+(1<<(k-1))][y][k-1].min_num,f[x+(1<<(k-1))][y+(1<<(k-1))][k-1].min_num));
            }
        }
    }
    for (int x = 1;x+n-1<=a;x++) {
        for (int y = 1;y+n-1<=b;y++) {
            ans = min(
                max(max(f[x][y][lg[n]].max_num,f[x+n-(1<<lg[n])][y][lg[n]].max_num),max(f[x][y+n-(1<<lg[n])][lg[n]].max_num,f[x+n-(1<<lg[n])][y+n-(1<<lg[n])][lg[n]].max_num))-
                  min(min(f[x][y][lg[n]].min_num,f[x+n-(1<<lg[n])][y][lg[n]].min_num),min(f[x][y+n-(1<<lg[n])][lg[n]].min_num,f[x+n-(1<<lg[n])][y+n-(1<<lg[n])][lg[n]].min_num)),ans);
        }
    }
    printf("%d\n",ans);
}
