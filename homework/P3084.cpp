/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-08-11 16:59:55
 * from: https://www.luogu.com.cn/problem/P3084
 */
/*
 * b_i-a_i = 1 可以转换为
 * v_i-u_i >= w && u_i-v_i <= w
 * 
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m;
int dis[N],cnt[N],max_cnt = 0;
bool vis[N];
vector<vector<pair<int,int>>>g(N);

bool spfa(int s) 
{
    memset(dis,0x3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    memset(vis,0,sizeof vis);
    deque<int> que;
    que.push_front(s);
    vis[s] = true;
    dis[s] = 0;
    while (!que.empty()) 
    {
        int u = que.front();
        que.pop_front();
        vis[u] = false;
        for (auto [v,w]:g[u]) 
        {
            if (dis[v] > dis[u]+w) 
            {
                dis[v] = dis[u]+w;
                cnt[v] = cnt[u]+1;
                if (cnt[v] > n+1) return false;
                if (++max_cnt > 2e6) return false;
                if (!vis[v]) {
                    vis[v] = true;
                    if(!que.empty() && dis[v] > dis[que.front()]) 
                    {
                        que.push_back(v);
                    } 
                    else 
                    {
                        que.push_front(v);
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=m;i++) 
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u-1].push_back({v,1});
        g[v].push_back({u-1,-1});
    }
    for (int i = 1; i <= n; i++)
    {
        g[i].push_back({i-1,0});
        g[i-1].push_back({i,1});
    }
    if(!spfa(0)) 
    {
        printf("-1\n");
    } 
    else 
    {
        printf("%d\n", dis[n]);
    }
}