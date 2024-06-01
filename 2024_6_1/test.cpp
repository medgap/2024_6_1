//https://www.luogu.com.cn/problem/P4231
//P4231 三步必杀
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

const int MAXN = 10000005;
vector<long long> cnt(MAXN,0);
int n,m;

void set(int l,int r,int s,int e,int d){
    cnt[l] += s;
    cnt[l + 1] += d - s;
    cnt[r + 1] -= d + e;
    cnt[r + 2] += e;
}

void build(){
    for(int i = 1; i <= n; ++i){
        cnt[i] += cnt[i - 1];
    }
    for(int i = 1; i <= n; ++i){
        cnt[i] += cnt[i - 1];
    }
}
int main(){
    while(scanf("%d %d",&n,&m) == 2){
        cnt.assign(n + 2, 0);
        for(int i = 0, l,r,s,e; i < m;i++){
            scanf("%d%d%d%d",&l,&r,&s,&e);
            int d = (e - s) / (r - l);
            set(l,r,s,e,d);
        }
        build();
        
        long long max = 0;
        long long xorVal = 0;
        for(int i = 1; i <= n; ++i){
            max = std::max(max,cnt[i]);
            xorVal ^= cnt[i];
        }
        printf("%lld %lld\n", xorVal, max);
    }
    return 0;
}