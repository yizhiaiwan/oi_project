/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-08-10 14:05:44
 * from: https://ybt.ssoier.cn/problem_show.php?pid=1504
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-4;
int n;
int cnt[N];
double dis[N];
bool vis[N];
struct edge
{
    int v;
    double w;
};

struct edgeid
{
    int u, v;
};

vector<vector<edge>> g(N);
edgeid ord(string s)
{
    string head;
    head += s[0];
    head += s[1];
    string tail;
    int len = s.size();
    tail += s[len - 2];
    tail += s[len - 1];
    int uid = head[0]*131 + head[1];
    int vid = tail[0]*131 + tail[1];
    return {uid, vid};
}

bool spaf(double s){
    memset(dis,0,sizeof dis);
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    queue<int> que;
    for (int i = 1;i<=(131*'z'+'z');i++)
    {
        que.push(i);
        vis[i] = 1;
    }
    while (!que.empty())
    {
        auto u = que.front();
        vis[u] = 0;
        que.pop();
        for (auto [v,w] : g[u]){
            if (dis[v] < dis[u]+w-s)
            {
                dis[v] = dis[u]+w-s;
                cnt[v] = cnt[u]+1;
                if(cnt[v]>=n*2) return true;
                if(!vis[v])
                {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        double len = s.size();
        auto [u, v] = ord(s);
        g[u].push_back({v, len});
    }
    int t;
    scanf("%d",&t);
    // 二分答案
    double l = 0, r = 1000;
    while (r-l>eps)
    {   
        double mid = (l+r)/2;
        if(spaf(mid))
        {
            l = mid;
        }else
        {
            r = mid;
        }
    }
    if(l<eps) printf("No solution\n");
    else printf("%.2lf\n", l);
}