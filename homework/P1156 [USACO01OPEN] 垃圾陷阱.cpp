//
// Created by yizhiaiwan on 2026/4/26.
// from:
// https://www.luogu.com.cn/problem/P1156
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10,MAXN = 1e4+10;

int D,G;
struct node {int t,f,h;};
node v[N];
int f[N][MAXN];


int main() {
    scanf("%d%d",&D,&G);
    for (int i=1;i<=G;i++) {
        scanf("%d%d%d",&v[i].t,&v[i].f,&v[i].h);
    }
    sort(v+1,v+G+1,[](node a,node b){return a.t<b.t;});
    memset(f,-0x3f,sizeof(f));
    f[0][0] = 10;
    int ans = 1e9;
    for (int i = 1; i <= G; i++) {
        int time = v[i].t - v[i - 1].t;
        for (int j = 0; j <= D + 30; j++) {
            if (f[i - 1][j] - time < 0) continue;
            f[i][j] = max(f[i][j], f[i - 1][j] - time + v[i].f); //吃
            f[i][j + v[i].h] = max(f[i][j + v[i].h], f[i - 1][j] - time); //垫
            if (j + v[i].h >= D) ans = min(ans, v[i].t);
        }
    }
    if (ans==1e9) {
        int x = 10,y = 0;
        for (int i = 1; i<=G;i++) {
            int time = v[i].t-v[i-1].t;
            if (x<time) {
                printf("%d",x+y);
                return 0;
            }
            x = x+v[i].f-time;
            y = v[i].t;
        }
        printf("%d",v[G].t+x);
        return 0;
    }
    printf("%d",ans);
}