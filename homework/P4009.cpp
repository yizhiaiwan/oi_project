//
// Created by yizhiaiwan on 2026/7/31.
// from:
// https://www.luogu.com.cn/problem/P4009
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int oil[110][110],dis[N],vis[N];
typedef pair<int,int> PII;
struct edge {
    int v,w,ne;
}e[N<<5];
int h[N],idx;
int n,k,a,b,c;

void add(int u,int v,int w) {
    e[++idx] = {v,w,h[u]};
    h[u] = idx;
}

int getd(int x,int y,int t) {
    return (x-1) * n + y + t * n * n;
}

void dijk(int s) {
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> que;
    que.push({0,s});
    while (!que.empty()) {
        int top = que.top().second;
        que.pop();
        if (vis[top]) continue;
        vis[top] = 1;
        for (int i = h[top];i;i = e[i].ne) {
            if (dis[e[i].v] > dis[top]+e[i].w) {
                dis[e[i].v] = dis[top]+e[i].w;
                que.push({dis[e[i].v],e[i].v});
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d%d",&n,&k,&a,&b,&c);
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            scanf("%d",&oil[i][j]);
        }
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            int mxy = getd(i,j,k);
            if (oil[i][j]) {
                for (int t = 0;t<k;t++) {
                    int nxy = getd(i,j,t);
                    add(nxy,mxy,a);
                }
                if (i>1) add(mxy,getd(i-1,j,k-1),b);
                if (j>1) add(mxy,getd(i,j-1,k-1),b);
                if (i<n) add(mxy,getd(i+1,j,k-1),0);
                if (j<n) add(mxy,getd(i,j+1,k-1),0);
            }else {
                for (int t = k;t>=1;t--) {
                    int u = getd(i,j,t);
                    if (i>1) add(u,getd(i-1,j,t-1),b);
                    if (j>1) add(u,getd(i,j-1,t-1),b);
                    if (j<n) add(u,getd(i,j+1,t-1),0);
                    if (i<n) add(u,getd(i+1,j,t-1),0);
                }
                int u = getd(i,j,0),v = getd(i,j,k);
                add(u,v,a+c);
            }
        }
    }
    dijk(getd(1,1,k));
    int ans = 1e9;
    for (int i = 0;i<=k;i++) {
        ans = min(ans,dis[getd(n,n,i)]);
    }
    printf("%d",ans);
}