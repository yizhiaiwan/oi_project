/*
 * @Author: yizhiaiwan 2354369233@qq.com
 * @Date: 2026-07-27 13:49:19
 * from: 
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int f[N];
int n,m;
int find(int x){
    if(f[x]==x){
        return f[x];
    }
    return f[x] = find(f[x]);
}
void mergre(int a,int b){
    int ra = find(a);
    int rb = find(b);
    if(ra!=rb){
        f[ra] = rb;
    }
}

void init(){
    for(int i = 1;i<=n;i++){
        f[i] = i;
    }
}
int main() {
    cin>>n>>m;
    init();
    for (int i = 1;i<=m;i++){
        int opt,a,b;
        cin>>opt>>a>>b;
        if(opt == 1){
            mergre(a,b);
        }else{
            if(find(a)==find(b)){
                printf("Y\n");
            }else{
                printf("N\n");
            }
        }
    }
}