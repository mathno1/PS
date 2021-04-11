#include <bits/stdc++.h>

#define endl '\n'
#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int dp[100010];
 
int solution(vector<int> sticker)
{
    int answer = 0;
    int N = sticker.size();
    if (N == 1) return sticker[0];
 
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    for (int i = 2; i < N - 1; ++i)
    {
        dp[i] = MAX(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    answer = MAX(answer, dp[N - 2]);
    dp[0] = 0;
    dp[1] = sticker[1];
    for (int i = 2; i < N; ++i)
    {
        dp[i] = MAX(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    answer = MAX(answer, dp[N - 1]);
 
    return answer;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int num = 0;
    vector<int> sticker;

    for(;;)
    {
        cin >> num;
        if(num == -1)
        {
            break;
        }
        sticker.push_back(num);
    }
    cout << solution(sticker) << endl;

    return 0;
}