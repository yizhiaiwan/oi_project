/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-08-11 13:39:30
 * from: https://www.luogu.com.cn/problem/P5960
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int n,m;
int dis[N],cnt[N];
bool vis[N];
struct edge
{
    int v,w;
};

vector<vector<edge>> g(N);

bool spfa(int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    queue<int> que;
    que.push(s);
    vis[s] = true;
    dis[s] = 0;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (auto [v,w]:g[u])
        {
            int new_dis = dis[u]+w;
            if(dis[v] > new_dis)
            {
                dis[v] = new_dis;
                cnt[v] = cnt[u]+1;
                if(cnt[v] > n) return false;
                if(!vis[v])
                {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return true;
}




int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[v].push_back({u,w});
    }
    for (int i = 1; i <= n; i++)
    {
        g[0].push_back({i,0});
    }
    if(!spfa(0)) printf("NO");
    else{
        for (int i = 1; i <= n; i++)
        {
            printf("%d ",dis[i]);
        }
    }
}