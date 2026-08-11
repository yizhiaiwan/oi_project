//
// Created by yizhiaiwan on 2026/8/3.
// from:
// https://www.luogu.com.cn/problem/P2730
//
#include <bits/stdc++.h>
using namespace std;
string a,ans;
map<string,string> mp;
queue<string> q;
void movea(string s)
{
    string t=mp[s];
    reverse(s.begin(),s.end());
    if (mp.count(s)==0) mp[s]=t+'A',q.push(s);
}

//12345678  41236785
void moveb(string s)
{
    string t=mp[s];
    char tem=s[3];
    s[3]=s[2],s[2]=s[1],s[1]=s[0],s[0]=tem;
    tem=s[4],s[4]=s[5],s[5]=s[6],s[6]=s[7],s[7]=tem;
    if (mp.count(s)==0) mp[s]=t+'B',q.push(s);
}

//12345678  17245368
void movec(string s)
{
    string t=mp[s];
    char tem=s[6];
    s[6]=s[5],s[5]=s[2],s[2]=s[1],s[1]=tem;
    if (mp.count(s)==0) mp[s]=t+'C',q.push(s);
}

void bfs() { // 状压bfs
    q.push("12345678");
    mp["12345678"] = "";
    while (!q.empty()) {
        string t = q.front();
        q.pop();
        if (t == a) {
            ans = mp[t];
            return;
        }
        movea(t);
        moveb(t);
        movec(t);
    }
}


int main() {
    for (int i = 1;i<=8;i++) {
        int t;
        scanf("%d",&t);
        a += (char)t+'0';
    }
    bfs();
    cout<<ans.size()<<"\n";
    for (auto i:ans) {
        printf("%c",i);
    }
}