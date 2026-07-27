//
// Created by yizhiaiwan on 2026/4/24.
// from:
// https://www.luogu.com.cn/problem/P5937
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int f[N*2];
int n,m,ans;
struct node{int x,y,z;};
vector<node> vt;
int vis[N*2],vis_size = 1;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y) {
    int r1 = find(x),r2 = find(y);
    if (r1!=r2) f[r1] = r2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for (int i = 1; i<=m; i++) {
        int a,b;
        string c;
        cin>>a>>b>>c;
        if (c=="odd") {
            vt.push_back({--a,b,1});
            vis[++vis_size] = a;
            vis[++vis_size] = b;
        }
        else if (c=="even") {
            vt.push_back({--a,b,2});
            vis[++vis_size] = a;
            vis[++vis_size] = b;
        }
    }
    sort(vis+1,vis+vis_size+1);
    vis_size = unique(vis+1,vis+vis_size+1)-vis-1;
    for (int i = 1;i<=vis_size<<1;i++) f[i] = i;
    for (auto& i: vt) {
        i.x = lower_bound(vis+1,vis+vis_size+1,i.x) - vis;
        i.y = lower_bound(vis+1,vis+vis_size+1,i.y) - vis;
    }
    for (auto i:vt) {
        int x = i.x, y = i.y,z = i.z;
        if (z==1) {
            if (find(x)==find(y)) {
                cout<<ans;
                return 0;
            }
            merge(x,y+vis_size);
            merge(y,x+vis_size);

        }
        if (z==2) {
            if (find(x)==find(y+vis_size)) {
                cout<<ans;
                return 0;
            }
            merge(x,y);
            merge(x+vis_size,y+vis_size);

        }
        ans++;
    }
    cout<<ans;
}