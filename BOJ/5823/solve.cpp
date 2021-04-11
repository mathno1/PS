#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define pb push_back
using namespace std;
//using namespace __gnu_pbds; //ordered_set : find_by_order(order), order_of_key(key)
//using namespace __gnu_cxx; //crope : append(str), substr(s, e), at(idx)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> p;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int arr[151515];
int inp[151515];
int n, l, g;
int upcnt; //relax all when upcnt == sq
const int sq = 400;

struct Bucket{
    int arr[sq << 1], size;
    int cnt[sq << 1], last[sq << 1]; //현재까지 찍어야 하는 사진 수, 마지막으로 사진 찍은 위치
    void relax(){
        int t = size;
        for(int i=size; i; i--){
            while(t > i && arr[i] + l < arr[t-1]) t--;
            if(arr[i] + l >= arr[size]) cnt[i] = 1, last[i] = arr[i] + l;
            else cnt[i] = cnt[t] + 1, last[i] = last[t];
        }
    }
}group[400];

void relax(){
    upcnt = 0;
    int idx = 0;
    for(int i=1; i<=g; i++){
        for(int j=1; j<=group[i].size; j++){
            arr[++idx] = group[i].arr[j];
        }
        group[i].size = 0;
    }
    g = 1;
    for(int i=1; i<=idx; i++){
        if(group[g].size == 390) g++;
        group[g].arr[++group[g].size] = arr[i];
    }
    for(int i=1; i<=g; i++) group[i].relax();
}

void insert(int now){
    int gid, id;
    for(gid=1; gid<g; gid++){
        if(group[gid].arr[group[gid].size] > now) break;
    }
    for(id=1; id<=group[gid].size; id++){
        if(group[gid].arr[id] > now) break;
    }
    for(int i=group[gid].size; i>=id; i--) group[gid].arr[i+1] = group[gid].arr[i];
    group[gid].size++;
    group[gid].arr[id] = now;
    group[gid].relax();
}

int erase(int now){
    int gid;
    for(gid=1; gid<g; gid++){
        if(group[gid].arr[1] <= now && group[gid+1].arr[1] > now) break;
    }
    for(int i=1; i<=group[gid].size; i++){
        if(group[gid].arr[i] == now){
            for (; i<group[gid].size; i++) group[gid].arr[i] = group[gid].arr[i+1];
            group[gid].size--;
            break;
        }
    }
    group[gid].relax();
    return group[gid].size;
}

int query(){
    int ret = group[1].cnt[1], last = group[1].last[1];
    for(int i=2; i<=g; i++){
        if (!group[i].size || group[i].arr[group[i].size] <= last) continue;
        int l = 1, r = group[i].size, now;
        while (l <= r){
            int m = l + r >> 1;
            if(group[i].arr[m] > last) now = m, r = m - 1;
            else l = m + 1;
        }
        ret += group[i].cnt[now];
        last = group[i].last[now];
    }
    return ret;
}

void init(int N, int L, int x[]){
    n = N;
    l = L;
    g = 1;
    for(int i=0; i<n; i++){
        inp[i] = x[i];
        if(group[g].size == 390) g++;
        group[g].arr[++group[g].size] = x[i];
    }
    for(int i=1; i<=g; i++) group[i].relax();
}

int update(int i, int y){
    upcnt++;
    if(upcnt == 390) relax();
    if(!erase(inp[i])) relax();
    inp[i] = y; insert(y);
    return query();
}

int x[151515];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l, m; cin >> n >> l >> m;
    for(int i=0; i<n; i++) cin >> x[i];
    init(n, l, x);
    while(m--){
        int i, y; cin >> i >> y;
        cout << update(i, y) << "\n";
    }
}