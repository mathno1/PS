#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

ull p[2020][2020], N, K, M;

ull polynomial(ull x, ull y)
{
    if (x < y)
    {
        return 0;
    }
    if (!y || y == x)
    {
        return 1;
    }
    ull &res = p[x][y];
    if (res != -1)
    {
        return res;
    }
    res = polynomial(x - 1, y - 1) % M + polynomial(x - 1, y) % M;
    res %= M;
    return res;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N >> K >> M;
    memset(p, -1, sizeof(p));

    ull res = 1;
    while(N || K)
    {
        res *= polynomial(N % M, K % M);
        res %= M;
        N /= M;
        K /= M;
    }
    cout << res << endl;

    return 0;
}