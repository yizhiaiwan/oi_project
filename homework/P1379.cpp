//
// Created by yizhiaiwan on 2026/8/4.
// from:
// https://www.luogu.com.cn/problem/P1379
//
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,pair<int,string>> PIIS;
string st,goal = "123804765";
PII dir[] = {{2,2},{1,1},{1,2},{1,3},{2,3},{3,3},{3,2},{3,1},{2,1}};
int nt[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int getd(int x,int y) {
    return x*3+y;
}

int fun(string s) {
    int res = 0;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            int x = s[getd(i,j)]-'0';
            if (x == 0) continue;
            PII pos = dir[x];
            res += abs(i+1-pos.first)+abs(j+1-pos.second);
        }
    }
    return res;
}

string move(string s,int opt) {
    int pos = s.find('0');
    int x = pos/3,y = pos%3;
    int nx = x+nt[opt][0],ny = y+nt[opt][1];
    if (nx<0 || nx>=3 || ny < 0 || ny >= 3) return s;
    swap(s[getd(nx,ny)],s[getd(x,y)]);
    return s;
}

int Astar(){
    priority_queue<PIIS,vector<PIIS>,greater<PIIS>> que;
    unordered_map<string,int> dis;
    que.push({fun(st),{0,st}});
    while (!que.empty()) {
        const auto top = que.top();
        que.pop();
        int d = top.second.first;
        auto u = top.second.second;
        if (u == goal) return d;
        if (dis.find(u) != dis.end() && dis[u] < d) continue;
        for (int i = 0;i<4;i++) {
            string v = move(u,i);
            if (v==u) continue;
            if (!dis.count(v) || dis[v]>d+1) {
                dis[v] = d+1;
                que.push({d+1+fun(v),{d+1,v}});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>st;
    auto ans = Astar();
    cout<<ans<<"\n";
}