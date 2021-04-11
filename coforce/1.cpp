#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t = 0;
    int n, m, x;
    int tmp;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m >> x;
        if(n == 1 && m == 1)
        {
            cout << 1 << endl;
            continue;
        }
        tmp = x / m;
        cout << "echo" << endl;
        for (int j = 1; j <= n; ++j)
        {
            if (tmp * m + j == x)
            {
                cout << n*(j - 1) + tmp + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
