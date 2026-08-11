/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-07-31 16:45:44
 * from: https://www.luogu.com.cn/problem/P4011
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
typedef pair<int,int> PII;
struct edge {
    int v,w,ne;
}e[N<<4];
int g[110][110],key[110][110],dis[N],vis[N];
int h[N],idx;
int n,m,p,k,s;
int mx;
PII nt[] = {{0,1},{1,0},{-1,0},{0,-1}};
int getd(const int &x,const int &y,const int &t) {
    return (x-1) * m + y + t*mx;
}
void add(const int &u,const int &v,const int &w) {
    e[++idx] = {v,w,h[u]};
    h[u] = idx;
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


int main(){
    scanf("%d%d%d%d",&n,&m,&p,&k);
    int t = 1<<p;
    t--;
    mx = n*m;
    for (int i = 1;i<=k;i++) {
        int x,xx,y,yy,opt;
        scanf("%d%d%d%d%d",&x,&y,&xx,&yy,&opt);
        int u = getd(x,y,0),v = getd(xx,yy,0);
        g[v][u] = g[u][v] = opt==0?-1:opt;
    }
    scanf("%d",&s);
    for (int i = 1;i<=s;i++) {
        int x,y,ke;
        scanf("%d%d%d",&x,&y,&ke);
        key[x][y] |= 1<<(ke-1);
    }
    for (int x = 1;x<=n;x++) {
        for (int y = 1;y<=m;y++) {
            for (int j = 0;j<=t;j++) {
                if (key[x][y]) {
                    int new_j = key[x][y]|j;
                    if (new_j!=j) {
                        int u = getd(x,y,j),v = getd(x,y,new_j);
                        add(u,v,0);
                    }
                }
                for (int i = 0;i<4;i++) {
                    int new_x = x+nt[i].first,new_y = y+nt[i].second;
                    if (new_x < 1 || new_x > n || new_y < 1 || new_y > m) continue;
                    int a_id = getd(x,y,0),b_id = getd(new_x,new_y,0);
                    int opt = g[a_id][b_id];
                    a_id+=j*mx;
                    b_id+=j*mx;
                    if (opt == 0 || (j&(1<<(opt-1)))) {
                        add(a_id,b_id,1);
                        add(b_id,a_id,1);
                    }
                }
            }
        }
    }
    int ans = 1e9;
    dijk(getd(1,1,0));
    for (int j = 0;j<=t;j++) {
        ans = min(ans,dis[getd(n,m,j)]);
    }
    if (ans==1e9) {
        printf("-1");
        return 0;
    }
    printf("%d",ans);
}