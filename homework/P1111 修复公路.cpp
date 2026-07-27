#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,m;
int f[N],sz[N];
struct edge {int x,y,w;};
vector<edge> edges;

int find(int x) {
    if (f[x]==x) return x;
    return f[x] = find(f[x]);
}
void merge(const int& x,const int& y) {
    int r1 = find(x);
    int r2 = find(y);
    if (r1!=r2) {
        if (sz[r1]<sz[r2]) swap(r1,r2);
        f[r2] = r1;
        sz[r1]+=sz[r2];
    }
}
int main() {
    scanf("%d %d",&n,&m);
    for (int i = 1;i<=n;i++) f[i] = i,sz[i] = 1;
    for (int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edges.push_back({a,b,c});
    }
    sort(edges.begin(),edges.end(),[](edge &a,edge &b){ return a.w<b.w;});
    for (auto& e:edges) {
        int x = e.x, y = e.y,w = e.w;
        merge(x,y);
        if (sz[find(x)]==n) {
            printf("%d\n",w);
            return 0;
        }
    }
    cout<<-1;
}