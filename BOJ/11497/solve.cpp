#include <bits/stdc++.h>

using namespace std;

int main(int argc, char ** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, N, complexity = 0;
    cin >> T;

    for(int i = 0; i < T; ++i)
    {
        cin >> N;
        vector<int> arr(N, 0);
        for(int j = 0; j < N; ++j)
        {
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());
        complexity = abs(arr[N - 1] - arr[N - 1]) > abs(arr[N - 1] - arr[N - 3]) ? abs(arr[N - 1] - arr[N - 1]) : abs(arr[N - 1] - arr[N - 3]);

        cout << complexity << endl;
    }

    return 0;
} 