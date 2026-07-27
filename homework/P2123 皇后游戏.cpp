//
// Created by yizhiaiwan on 2026/7/23.
// from:
// https://www.luogu.com.cn/problem/P2123
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4+10;
int t,n;
int a[N],b[N],s[N],c[N];
typedef pair<int,int> pii;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n;
        for (int i = 1;i<=n;i++) {
            cin>>a[i]>>b[i];
        }
        vector<pii> ans1,ans2;
        for (int i = 1;i<=n;i++) {
            if (a[i]<b[i]) {
                ans1.push_back({a[i],i});
            }else {
                ans2.push_back({b[i],i});
            }
        }
        sort(ans1.begin(),ans1.end(),[](pii a,pii b){return a.first<b.first;});
        sort(ans2.begin(),ans2.end(),[](pii a,pii b){return a.first>b.first;});
        vector<int> ans;
        for (pii i:ans1) ans.push_back({i.second});
        for (pii i:ans2) ans.push_back({i.second});
        int sum = 0;
        for (int i = 0;i<ans.size();i++) {
            int o_id = ans[i];
            s[i] = s[i-1]+a[o_id];
            c[i] = max(c[i-1],s[i])+b[o_id];
            sum = max(sum,c[i]);
        }
        cout<<sum<<"\n";
    }
}