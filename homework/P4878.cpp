/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-08-11 15:10:53
 * from: https://www.luogu.com.cn/problem/P4878
 */
/*
 * 如果是情敌: B-A >= D md
 * 如果是好基友: B-A <= D ml
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,ml,md;
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
    dis[s] = 0;
    que.push(s);
    vis[s] = true;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (auto [v,w] : g[u])
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

signed main()
{
    scanf("%d%d%d",&n,&ml,&md);
    for (int i = 0; i < ml; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for (int i = 0; i < md; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[v].push_back({u,-w});
    }
    for (int i = 1;i<=n;i++)
    {
        g[0].push_back({i,0});
    }
    for (int i = 1; i < n; i++)
    {
        g[i+1].push_back({i,0});
    }
    
    if(!spfa(0))
    {
        printf("-1");
        return 0;
    }
    if(dis[n] == 0x3f3f3f3f)
    {
        printf("-2");
        return 0;
    }
    spfa(1);
    if(dis[n] == 0x3f3f3f3f)
    {
        printf("-2");
        return 0;
    }
    else
    {
        printf("%d",abs(dis[n]-dis[1]));
    }
}