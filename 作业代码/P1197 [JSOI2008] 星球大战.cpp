#include <bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
int f[N],sz[N];
bool ka[N];
int n,m,tnt;
stack<int> ans;
vector<vector<int>> g(N);
stack<int> st;
vector<int> v;
int find(int x) {
    if (x == f[x]) {
        return x;
    }
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
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {
        f[i] = i;
    }
    for (int i=1;i<=m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k;
    scanf("%d",&k);
    for (int i=1;i<=k;i++) {
        int a;
        scanf("%d",&a);
        ka[a] = true;
        st.push(a);
    }
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    for (int i=0;i<n;i++) {
        if (!ka[i]) {
            for (auto& j:g[i]) {
                if (!ka[j]) merge(i,j);
            }
        }
    }
    int point = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (!ka[i]) {
            s.insert(find(i));
        }
    }
    point = s.size();
    ans.push(point);
    for (auto& i:v) {
        ka[i] = false;
        point++;
        for (auto& j:g[i]) {
            if (!ka[j] && find(i)!=find(j)) {
                merge(i,j);
                point--;
            }
        }
        ans.push(point);
    }
    while (!ans.empty()) {
        printf("%d\n",ans.top());
        ans.pop();
    }
}