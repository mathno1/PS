#include <bits/stdc++.h>

using namespace std;

int main(int argc, char ** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, L;
    cin >> N >> L;
    vector<int> h(N, 0);

    for(int i = 0; i < N ; ++i)
    {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    for(int i = 0; i < N; ++i)
    {
        if (L < h[i]) { break; }
        ++L;
    }

    cout << L << endl;

    return 0;
}