#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int f[N];
int n;
int find(int x) {
    if (x == f[x]) {
        return x;
    }
    return f[x] = find(f[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 1e6; i++) {//初始化
        f[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        int a = find(t);
        printf("%d ", a);
        f[a] = f[a+1];
    }
}