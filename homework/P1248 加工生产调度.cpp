//
// Created by yizhiaiwan on 2026/7/23.
// from:
// https://www.luogu.com.cn/problem/P1248
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n;
typedef pair<int,int> pl;
vector<int> a,b;
vector<pl> ans1,ans2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i = 1;i<=n;i++) {
        int t;
        cin>>t;
        a.push_back(t);
    }
    for (int i = 1;i<=n;i++) {
        int t;
        cin>>t;
        b.push_back(t);
    }
    for (int i = 0;i<n;i++) {
        // 这个是被a[i]影响的
        if (a[i]<b[i]) {
            ans1.push_back({a[i],i+1});
        }else { // 被b[i]影响
            ans2.push_back({b[i],i+1});
        }
    }
    sort(ans1.begin(),ans1.end(),[](pl a,pl b){return a.first<b.first;});
    sort(ans2.begin(),ans2.end(),[](pl a,pl b){return a.first>b.first;});

    vector<int> order;
    for (auto &p : ans1) order.push_back(p.second);
    for (auto &p : ans2) order.push_back(p.second);
    int sum1 = 0,sum2 = 0;
    for (int i:order) {
        sum1 += a[i-1];
        if (sum2<sum1) sum2 = sum1;
        sum2+=b[i-1];
    }
    cout<<sum2<<"\n";
    for (int i:order) {
        cout<<i<<" ";
    }
}