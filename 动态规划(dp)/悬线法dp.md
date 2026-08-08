


```c++
int maxRectangle() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // 初始化 l: 从当前行向左找最近障碍
        for (int j = 1, last = 1; j <= m; j++) {
            if (a[i][j] == 0) { l[i][j] = 1; last = j + 1; }
            else l[i][j] = last;
        }
        // 初始化 r: 从当前行向右找最近障碍
        for (int j = m, last = m; j >= 1; j--) {
            if (a[i][j] == 0) { r[i][j] = m; last = j - 1; }
            else r[i][j] = last;
        }
        // 递推 h, l, r, 并更新答案
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                h[i][j] = 0;
                l[i][j] = 1;
                r[i][j] = m;
            } else {
                h[i][j] = h[i-1][j] + 1;
                l[i][j] = max(l[i][j], l[i-1][j]); // 取更紧约束
                r[i][j] = min(r[i][j], r[i-1][j]);
                ans = max(ans, h[i][j] * (r[i][j] - l[i][j] + 1));
            }
        }
    }
    return ans;
}
```