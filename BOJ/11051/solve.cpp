#include <bits/stdc++.h>
#define endl '\n'
#define MOD 10007LL
#define MAX 1001
using namespace std;
using ll = long long;

ll factorial[MAX] = {
    0,
    1,
};

ll inverse(ll a)
{
    // pow(a, MOD - 2, MOD)
    ll out = 1;
    ll n = MOD - 2;
    while (n > 0)
    {
        if (n%2)
        {
            out *= a;
            out %= MOD;
        }
        a *= a;
        a %= MOD;
        n >>= 1;
    }
    return out;
}

void init()
{
    for (ll i = 2; i < MAX; ++i)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    init();
    int N, K;
    cin >> N >> K;
    if (N == K || !K)
    {
        cout << 1 << endl;
    }
    else
    {
        ll ans = (factorial[N] * inverse(factorial[N - K]))%MOD;
        ans = (ans * inverse(factorial[K])) % MOD;
        cout << ans << endl;
    }
    return 0;
}