/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-08-08 19:20:59
 * from: https://www.luogu.com.cn/problem/P2658?contestId=347124
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n,m,cnt;
int sx,sy;
int g[N][N],v[N][N];
int start;


void bfs(int x,int y){
    struct node
    {
        int x,y,w;
    };
    queue<node> que;
    que.push({x,y,0});
    while (!que.empty())
    {
        
    }
    

}



int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d",&g[i][j]);
        }

    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d",&v[i][j]);
            if(v[i][j] == 1){
                cnt++;
                sx = i;
                sy = j;
            }
            
        }

    }

}