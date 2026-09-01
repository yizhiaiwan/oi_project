# SPFA

## SPFA 的概念

* SPFA 是一种属于图论的单源最短路算法，它通过松弛操作来求最短路
* 松弛操作: 如果 `dis[v] > dis[u]+w`，就更新 `dis[v] = dis[u]+w`
* 与 dijkstra 的区别: dijkstra 不能处理负权边，SPFA 可以
* SPFA 最坏时间复杂度是 $O(nm)$，容易被特殊数据卡掉，没有负权边时优先用 dijkstra

## SPFA 的实现

- 用队列维护所有被松弛过、需要继续松弛邻居的点
- 一个点出队后 `vis` 要置回 false，因为它之后还可能再次入队
- `cnt` 数组统计最短路经过的边数，用来判断负权环

代码模板(带负环判定):

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
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
            if(dis[v] > new_dis) // 松弛操作
            {
                dis[v] = new_dis;
                cnt[v] = cnt[u]+1; // 统计最短路经过的边数
                if(cnt[v] > n) return false; // 存在负权环
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
```

### 负环的判定

* `cnt[v]` 表示从源点到 v 的最短路经过的边数
* 一条最短路最多经过 n-1 条边，如果 `cnt[v] > n` 说明路径上一定有环，而且只能是负权环
* 存在负权环时最短路不存在(可以无限松弛)，所以 SPFA 返回 false

## 例题

1. [ybt1508 单源最短路径模板](/homework/ybt1508.cpp)
    > SPFA 模板题(带负环判定)

2. [差分约束](差分约束.md)
    > 差分约束问题常用 SPFA 来实现，本质就是在做松弛和负环检测
