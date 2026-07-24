# LCA（最近公共祖先）

## 概要
LCA 是两节点在树上最深的公共祖先。常用于路径长度、路径性质合并、树上差分等问题。常见方法：枚举/暴力、倍增（binary lifting）、Tarjan 离线 LCA、欧拉序 + RMQ。

## 方法对比（适用场景）
- 枚举 / 逐步上跳：实现简单，适合深度较浅或测试。  
- 倍增（binary lifting）：通用，单次查询 O(log n)，预处理 O(n log n)。适合多次查询并需要在线查询。  
- Tarjan 离线：若查询批量且离线，复杂度接近 O(n + q α(n))。  
- 欧拉序 + RMQ：把 LCA 转为区间最小值问题，查询 O(1)（需 RMQ），预处理依赖 RMQ。

## 倍增 LCA 实现要点
1. 预处理 f[u][k]（u 的 2^k 祖先）与深度 dep[u]：
```cpp
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    f[u][0]=p;
    for(int k=1;k<=LOG;k++) f[u][k]=f[f[u][k-1]][k-1];
    for(int v:g[u]) if(v!=p) dfs(v,u);
}
```

2. 查询 LCA：
```cpp
int lca(int a,int b){
    if(dep[a] < dep[b]) swap(a,b);
    int diff = dep[a]-dep[b];
    for(int k=0;k<=LOG;k++) if(diff>>k & 1) a = f[a][k];
    if(a==b) return a;
    for(int k=LOG;k>=0;k--){
        if(f[a][k] != f[b][k]){
            a = f[a][k];
            b = f[b][k];
        }
    }
    return f[a][0];
}
```

## 注意点
- 初始化 f[][] 时要保证 f[0][*] 或根的父节点处理正确（常把根的父亲设为 0）。  
- LOG 的选择：ceil(log2(n))，数组边界要足够。  
- 若有多棵树（森林），为每棵树分别 dfs 或在查询前做根判定。

## 例题与应用（仓库示例）
- 模板：../作业代码/P3379 【模板】最近公共祖先（LCA）.cpp  
- 三点 LCA / 路径最短：../作业代码/P4281 [AHOI2008] 紧急集合.cpp （图示：../picture_date/三点LCA图例.png）  
- LCA + 树上前缀和：../作业代码/P8805 [蓝桥杯 2022 国 B] 机房.cpp

一句话建议：笔记中同时给出「倍增代码 + Tarjan 离线思路 + 常见题目链接」，并在倍增实现处注释边界情况，方便教练快速理解。
