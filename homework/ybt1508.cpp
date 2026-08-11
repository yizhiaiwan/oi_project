/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-08-10 16:13:28
 * from: https://ybt.ssoier.cn/problem_show.php?pid=1508
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10,INF = 0x3f3f3f3f3f3f3f3f;
int dis[N],cnt[N];
bool vis[N];
struct edge
{
    int v,w;
};
vector<vector<edge>> g(N);
int n,m,s;

bool spfa(int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    queue<int> que;
    que.push(s);
    dis[s] = 0;
    vis[s] = true;
    while (!que.empty())
    {
        int u = que.front();
        vis[u] = false;
        que.pop();
        for (auto [v,w] : g[u])
        {
            int new_dis = dis[u]+w;
            if(dis[v] > new_dis)
            {
                dis[v] = new_dis;
                cnt[v] = cnt[u]+1;
                if(cnt[v]>n)
                {
                    return true;
                }
                if (!vis[v])
                {
                    que.push(v);
                    vis[v] = true;
                }
                
            }
        }
    }
    return false;
}

signed main()
{
    scanf("%lld%lld%lld",&n,&m,&s);
    for (int i = 1;i<=m;i++)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for (int i = 1;i<=n;i++)
    {
        g[0].push_back({i,0});
    }
    if(spfa(0)) printf("-1\n");
    else{
        spfa(s);
        for(int i = 1;i<=n;i++)
        {
            if(dis[i] == INF)
            {
                printf("NoPath\n");
            }
            else
            {
                printf("%lld\n",dis[i]);
            }
        }
    }
}