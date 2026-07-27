#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int f[N];
int n,maxt,ans;
pair<int,int> p[N];
int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}
inline bool cmp( pair<int,int> const &a, pair<int,int> const &b) {
    return a.first > b.first;
}
int main() {
    while (scanf("%d", &n)==1) {
        ans = 0;
        maxt = -0x3fffffff;//初始化
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &p[i].first, &p[i].second);
            maxt = max(maxt, p[i].second);
        }
        for (int i = 1; i <= maxt; i++) { //初始化f[]数组
            f[i] = i;
        }
        sort(p+1, p+n+1,cmp);
        for (int i = 1; i <= n; i++) {
            int t = find(p[i].second);//t是p[i]的根
            if (t>0) {//t<=0时已经到头了
                ans+=p[i].first;
                f[t] = find(t-1);//要找t的前一个的根
            }
        }
        printf("%d\n", ans);
    }
}