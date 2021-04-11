#include <bits/stdc++.h>

using namespace std;

int main(int argc, char ** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, src, dst, res = 0x7fffffff, sol = 0, sum = 0;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(N, 0));

    for(int i = 0; i < M; ++i)
    {
        cin >> src >> dst;
        map[src - 1][dst - 1] = map[dst - 1][src - 1] = 1;
    }

    for(int k = 0; k < N; ++k)
    {
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(i == j)
                {
                    continue;
                }
                if(map[i][k] && map[k][j])
                {
                    map[i][j] = !map[i][j] ? 
                    map[i][k] + map[k][j] : map[i][j] < map[i][k] + map[k][j] ? 
                    map[i][j] : map[i][k] + map[k][j];
                }
            }
        }
    }

    for(int i = 0; i < N; ++i)
    {
        sum = 0;
        for(int j = 0; j < N; ++j)
        {
            sum += map[i][j];
        }
        if(res > sum)
        {
            res = sum;
            sol = i + 1;
        }
    }
    cout << sol << endl;

    return 0;
}