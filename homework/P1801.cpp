/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-07-28 18:43:54
 * from: https://www.luogu.com.cn/problem/P1801
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
priority_queue<int> l;
priority_queue<int,vector<int>,greater<int>> r;
int a[N];
int n,m,k;
void push() {
    if (l.size()>k) {
        r.push(l.top());
        l.pop();
    }
    if (l.size()<k){
        l.push(r.top());
        r.pop();
    }
}
void add(int x) {
    if (l.empty() || x<l.top()) l.push(x);
    else r.push(x);
    push();
}



int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 1,j = 1;i<=m;i++) {
        int y;
        scanf("%d",&y);
        ++k;
        while (j<=y && j<=n) add(a[j]),j++;
        push();
        printf("%d\n",l.top());
    }
}