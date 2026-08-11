/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-08-11 14:39:25
 * from: https://www.luogu.com.cn/problem/P6145
 */
/*
 * 先给一个超级原点，然后给所有的不等式赋初值
 * 接着跑spfa求不等式的解，因为有初始值，所以解>=1
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,m,C;
int cnt[N],dis[N],a[N];
bool vis[N];
struct edge
{
    int v,w;
};

vector<vector<edge>> g(N);


bool spfa(int s)
{
    memset(dis,0,sizeof dis);
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
            if(dis[v] < new_dis)
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
    scanf("%d%d%d",&n,&m,&C);
    for (int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        g[0].push_back({i,a[i]});
    }
    for (int i = 0; i < C; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    spfa(0);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n",dis[i]);
    }
}