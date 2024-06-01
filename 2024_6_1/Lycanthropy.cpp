//https://www.luogu.com.cn/problem/P5026
//P5026 Lycanthropy
/*

*/
#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1e6;
const int OFFSET = 30001;
vector<long long> cnt(OFFSET + MAXN + OFFSET, 0);
int m; //length
int n; //num of friends

void set(int l, int r, int s, int e, int d){
    cnt[l + OFFSET] += s;
    cnt[l + 1 + OFFSET] += d - s;
    cnt[r + 1 + OFFSET] -= d + e;
    cnt[r + 2 + OFFSET] += e;
}

void build(){
    for(int i = 1; i <= m + OFFSET; ++i){
        cnt[i] += cnt[i - 1];
    }
    for(int i = 1; i <= m + OFFSET; ++i){
        cnt[i] += cnt[i - 1];
    }
}

int main(){
//(i-v+1, i, -1, -v, -1)
//(i+1, i+v-1, -v+1, -1, -1)

//(i-v-1, i-2*v-1, 1, v-1, 1)
//(i-2*v, i-3*v+1, v, 1, -1)

//(i+v+1, i+2*v-1, 1, v-1, 1)
//(i+2*v, i+3*v-1, v, 1, -1)
    cin >> n >> m;
    //cnt.assign(m+2,0);
    for(int i = 0; i < n; ++i){
        int v,x;//volume and where
        cin >> v >> x;
        set(x - 3 * v + 1, x - 2 * v, 1, v, 1);
		set(x - 2 * v + 1, x, v - 1, -v, -1);
		set(x + 1, x + 2 * v, -v + 1, v, 1);
		set(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1);
    }
    build();
    int start = 1 + OFFSET;
    cout << cnt[start++];
    for(int i = 2; i <= m; i++){
        cout << " " << cnt[start++];
    }
    
}