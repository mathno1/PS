#include <bits/stdc++.h>

using namespace std;

int visited[100][100] = {0, };
int N = 0;

void bfs(vector<vector<char>> map, int x, int y)
{
    int _x, _y, nx, ny;
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    queue<pair<int, int>> que;
    que.push(make_pair(x, y));
    visited[x][y] = 1;
    while(!que.empty())
    {
        _x = que.front().first;
        _y = que.front().second;
        que.pop();

        for(int i = 0; i < 4; ++i)
        {
            nx = _x + dx[i];
            ny = _y + dy[i];

            if(!(nx < 0 || ny < 0 || nx >= N || ny >= N))
            {
                if(!visited[nx][ny])
                {
                    if(map[nx][ny] == map[x][y])
                    {
                        visited[nx][ny] = 1;
                        que.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main(int argc, char ** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int sol1 = 0, sol2 = 0;
    cin >> N;
    vector<vector<char>> map(N, vector<char>(N, 0));
    vector<vector<char>> map2(N, vector<char>(N, 0));

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> map[i][j];   
            if(map[i][j] == 'R')
            {
                map2[i][j] = 'G';
            }
            else
            {
                map2[i][j] = map[i][j];
            }
        }
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(!visited[i][j])
            {
                bfs(map, i, j);
                ++sol1;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(!visited[i][j])
            {
                bfs(map2, i, j);
                ++sol2;
            }
        }
    }

    cout << sol1 << " " << sol2 << endl;

    return 0;
}