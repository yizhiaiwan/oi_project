# LCA(最近公共祖先)

## LCA的概念
- LCA只是两点直接的公共祖先，只有一个，然而求LCA的方法有很多种，这里只总结几种

---

## 枚举LCA
- 枚举LCA的代码很简单，总体思路就是枚举向上跑点直到两点在一个点重合

![枚举LCA图例](/picture_date/枚举LCA.png)

>注意：枚举LCA是总体找LCA的思路，其他LCA只是优化找的时间复杂度，总体原理还是一样

代码如下:

```c++
int LCA (int a,int b){
    if(dep[a]<dep[b]) swap(a,b);// 确认 a 点较深
    while(dep[a]!=dep[b]) a = fa[a];// 此时 dep[a] >= dep[b]，所以把 a 往上提
    if(a==b) return a;
    while(a!=b) a = fa[a],b = fa[b];
    return a;// 返回 a 或 b 都可以
}
```
[枚举LCA例题](/homework/P3379%20【模板】最近公共祖先（LCA）.cpp)

---

## 倍增LCA

- 倍增LCA就是在枚举LCA的基础上把找祖先的这个过程使用st表来优化
- 具体来说就是创建一个为 f [] [] 的st表然后在找的过程中倍增寻找
- 总结:倍增其实就是用来减少时间复杂度而已

---

### 倍增LCA的实现

1. 初始化:把所有的点都指向自己的父亲并且算出深度

代码如下:
```c++
void init(int x,int pre) {// x:自己 pre:父亲
    dep[x] = dep[pre]+1;
    f[x][0] = pre;// 把自己指向自己的父亲
    for (int i = 1;i<=20;i++) {
        f[x][i] = f[f[x][i-1]][i-1];
    }
    for (auto& i:g[x]) {
        if (i!=pre) init(i,x);
    }
}
```

2. 求LCA:本质还是一样只是降低了跑的时间

```c++
int LCA(int a,int b) {
    if (dep[a]<dep[b]) swap(a,b);
    for (int i = 20;i>=0;i--) { // 使用倍增让深度较深的点向上跑
        if (dep[f[a][i]]>=dep[b]) {
            a = f[a][i];
        }
    }
    if (a==b) return b;// 重点！不要忘了判断b点是他们的公共祖先

    for (int i = 20;i>=0;i--) { // 使用倍增让两点一起向上跑
        if (f[a][i]!=f[b][i]) {
            a = f[a][i],b = f[b][i];
        }
    }
    return f[a][0];
}
```

---

### LCA例题

1. [LCA+树上前缀和](/homework/P8805%20%5B蓝桥杯%202022%20国%20B%5D%20机房.cpp)
> 这题的主要思想就是在树上做前缀和，具体操作就是把父节点加到自己的节点上然后再用前缀和公式 “ 左节点-LCA+右节点-LCA+LCA（本身值）”

2. [三点LCA](/homework/P4281%20%5BAHOI2008%5D%20紧急集合.cpp)
> 这道题主要是求三个点的LCA然后求走的路最少的，所以主要思想就是求LCA会有两个点，而我们要求较深的那个点的值，因为较深的点走的路最短

![三点LCA图例](/picture_date/三点LCA图例.png)

3. [求两条路径是否相交](/homework/P3398%20仓鼠找%20sugar.cpp)
> 这道题是两条路径是否相交，而判断两条路径是否相交就是判断一条较深路径的LCA有没有在另一条路径上，具体判断就是 左(浅)与LCA(深)的LCA是否等于LCA(深)和右(浅)与LCA(深)的LCA是否等于LCA(深)
