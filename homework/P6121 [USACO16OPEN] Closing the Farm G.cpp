#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m;
int f[N];
bool vis[N],tnt[N];
vector<vector<int>> g(N);
stack<int> st;
stack<int> ans;
int find(int x) {
    if (f[x]==x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    int r1 = find(x);
    int r2 = find(y);
    if (r1!=r2) {
        f[r1] = r2;
    }
}
int main() {
    scanf("%d %d",&n,&m);
    for (int i = 1;i <= n;i++) f[i] = i;
    for (int i = 1;i <= m;i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1;i <= n;i++) {
        int t;
        scanf("%d",&t);
        st.push(t);
    }
    int cnt = 0;
    while (!st.empty()) {
        int i = st.top();
        vis[i] = true;
        cnt++;
        for (auto& j : g[i]) {
            if (vis[j] && find(i)!=find(j)) {
                merge(i,j);
                cnt--;
            }
        }
        ans.push(cnt);
        st.pop();
    }
    while (!ans.empty()) {
        int i = ans.top();
        if (i>1) printf("NO\n");
        else if (i==1) printf("YES\n");
        ans.pop();
    }
}