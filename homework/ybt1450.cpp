//
// Created by yizhiaiwan on 2026/8/4.
// from:
// https://ybt.ssoier.cn/problem_show.php?pid=1450
//
#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int n,L;
int dis[N][N];
bool vis1[N][N],vis2[N][N];
int nt[8][2] = {{1,2},
                {2,1},
                {2,-1},
                {1,-2},
                {-1,-2},
                {-2,-1},
                {-2,1},
                {-1,2}};
struct node {
    int x,y,d;
};
int bfs(int x,int y,int xx,int yy) {
    memset(vis1,0,sizeof vis1);
    memset(vis2,0,sizeof vis2);
    memset(dis,0,sizeof dis);
    if (x==xx && y==yy) return 0;
    queue<node> que,que2;
    vis1[x][y] = true;
    vis2[xx][yy] = true;
    que.push({x,y,0});
    que2.push({xx,yy,0});
    while (!que.empty() || !que2.empty()) {
        if (que.size()<=que2.size()) {
            auto top = que.front();
            que.pop();
            for (int i = 0;i<8;i++) {
                int xt = top.x+nt[i][0];
                int yt = top.y+nt[i][1];
                if (xt < 0 || xt > L || yt < 0 || yt > L || vis1[xt][yt]) continue;
                vis1[xt][yt] = true;
                que.push({xt,yt,top.d+1});
                dis[xt][yt] += top.d+1;
                if (vis1[xt][yt] && vis2[xt][yt]) {
                    return dis[xt][yt];
                }
            }
        }else {
            auto top = que2.front();
            que2.pop();
            for (int i = 0;i<8;i++) {
                int xt = top.x+nt[i][0];
                int yt = top.y+nt[i][1];
                if (xt < 0 || xt > L || yt < 0 || yt > L || vis2[xt][yt]) continue;
                vis2[xt][yt] = true;
                que2.push({xt,yt,top.d+1});
                dis[xt][yt] += top.d+1;
                if (vis1[xt][yt] && vis2[xt][yt]) {
                    return dis[xt][yt];
                }
            }
        }
    }
    return 0;
}


int main() {
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%d",&L);
        int sx,sy,ex,ey;
        scanf("%d%d",&sx,&sy);
        scanf("%d%d",&ex,&ey);
        int ans = bfs(sx,sy,ex,ey);
        printf("%d\n",ans);
    }
}