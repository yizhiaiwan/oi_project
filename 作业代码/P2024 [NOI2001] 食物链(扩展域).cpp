//
// Created by yizhiaiwan on 2026/4/20.
// from:
// https://www.luogu.com.cn/problem/P2024
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4+10;
int f[N*3];
int n,k,ans;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x, int y) {
    int r1 = find(x), r2 = find(y);
    if (r1!=r2) {
        f[r1] = r2;
    }
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i = 1;i<=n*3;i++) f[i] = i;
    for (int i = 1;i<=k;i++) {
        int cop,a,b;
        scanf("%d%d%d",&cop,&a,&b);
        if (a>n || b>n || (cop==2 && a==b)) {
            ans++;
            continue;
        }
        if (cop==2) {
            if (find(a)==find(b+2*n) || find(a) == find(b)) {
                ans++;
                continue;
            }
            merge(a,b+n);
            merge(a+n,b+2*n);
            merge(a+2*n,b);
        }
        else {
            if (find(a)==find(b+n)||find(a)==find(b+2*n)) {
                ans++;
                continue;
            }
            merge(a,b);
            merge(a+n,b+n);
            merge(a+2*n,b+2*n);
        }
    }
    printf("%d\n",ans);
}