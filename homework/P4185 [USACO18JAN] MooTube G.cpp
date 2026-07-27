#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,m;
int f[N],sz[N];
struct edge{int x,y,v;};
struct my_pair{int x,y,id;};
vector<edge> g;
vector<my_pair> e;
vector<int> ans(N);
int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}
void merge(int x,int y) {
    int r1 = find(x);
    int r2 = find(y);
    if (r1 != r2) {
        if (sz[r1] < sz[r2]) {
            swap(r1,r2);
        }
        f[r2] = r1;
        sz[r1]+=sz[r2];
    }
}
int main() {
    scanf("%d %d",&n,&m);
    for (int i = 1;i<=n;i++) f[i] = i;//初始化
    for (int i = 1;i<=n;i++) sz[i] = 1;
    for (int i = 1;i<n;i++) {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        g.push_back({x,y,w});
    }
    for (int i = 1;i<=m;i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        e.push_back({x,y,i});
    }
    sort(g.begin(),g.end(),[](edge& a,edge& b) {return a.v>b.v;});
    sort(e.begin(),e.end(),[](my_pair& a,my_pair& b){return a.x>b.x;});//按权值升序排序
    int tnt = 0;
    for (auto& i:e) {
        int k = i.x, x = i.y;

        while (g[tnt].v >= k && tnt<g.size()) {
            merge(g[tnt].x,g[tnt].y);
            tnt++;
        }
        ans[i.id] = sz[find(x)]-1;
    }
    for (int i = 1;i<=m;i++) {
        printf("%d\n",ans[i]);
    }
}