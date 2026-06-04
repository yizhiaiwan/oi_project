//
// Created by yizhiaiwan on 2026/6/4.
// from:
// https://www.luogu.com.cn/problem/P1536
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m;
int cnt;
int f[N];
int find(int x){
    if(f[x]==x){
        return x;
    }
    return f[x] = find(f[x]);
}
void merge(int x,int y){
    int r1 = find(x);
    int r2 = find(y);
    if(r1!=r2){
        f[r1] = r2;
        cnt--;
    }
}

int main(){
    while(1){
        cin>>n>>m;
        if(n==0){
            return 0;
        }
        cnt = n;
        for(int i = 1;i<=n;i++){
            f[i] = i;
        }
        for(int i = 1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            merge(x,y);
        }
        cout<<cnt-1<<endl;
    }


}