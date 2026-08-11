/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-08-11 14:12:54
 * from: https://www.luogu.com.cn/problem/P1993
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int n,m;
struct edge
{
    int v,w;
};
int dis[N],cnt[N];
bool vis[N];
vector<vector<edge>> g(N);

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
        int opt,u,v,w;
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back({v,-w});
        }else if(opt==2)
        {
            scanf("%d%d%d",&u,&v,&w);
            g[v].push_back({u,w});
        }else
        {
            scanf("%d%d",&u,&v);
            g[u].push_back({v,0});
            g[v].push_back({u,0});
        }
    }
    for (int i = 1;i<=n;i++)
    {
        g[0].push_back({i,0});
    }
    if(!spfa(0))
    {
        printf("No");
        return 0;
    }
    printf("Yes");
}