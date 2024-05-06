// TRIED KIND OF FLOYD WARSHALL
// RESULTED IN TLE

// class Solution
// {
// public:
//     int calculateMinimumHP(vector<vector<int>> &dungeon)
//     {
//         int dr[] = {1, 0}, dc[] = {0, 1};
//         int n = dungeon.size(), m = dungeon[0].size();

//         // {currhealth , row , col , lowest health reached till now}
//         priority_queue<tuple<int, int, int, int>> pq;
//         pq.push({dungeon[0][0], 0, 0, min(0, dungeon[0][0])});

//         while (!pq.empty())
//         {
//             auto [currH, currR, currC, lowestH] = pq.top();
//             pq.pop();
//             lowestH = min(lowestH, currH);
//             if (currR == n - 1 and currC == m - 1)
//             {
//                 return lowestH < 0 ? abs(lowestH) + 1 : 1;
//             }
//             for (int i = 0; i < 2; i++)
//             {
//                 int nR = currR + dr[i], nC = currC + dc[i];
//                 if (nR >= n or nC >= m)
//                     continue;
//                 pq.push({currH + dungeon[nR][nC], nR, nC, lowestH});
//             }
//         }
//         return -1;
//     }
// };



// TRIED DIJKASTRA 
// RESULTED IN WRONG ANS

// class Solution {
// public:
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         int dr[] = {1, 0}, dc[] = {0, 1};
//         int n = dungeon.size(), m = dungeon[0].size();
//         vector<vector<int>> minHealth(n, vector<int>(m, INT_MAX));
//         minHealth[0][0] = dungeon[0][0];

//         // {currhealth , row , col , lowest health reached till now}
//         priority_queue<tuple<int, int, int , int>> pq;
//         pq.push({dungeon[0][0], 0, 0 ,min(0,dungeon[0][0])});

//         while (!pq.empty()) {
//             auto [currH, currR, currC , lowestH] = pq.top();
//             pq.pop();
//             lowestH = min(lowestH , currH);
//             if (currR == n - 1 and currC == m - 1) {
//                 return lowestH < 0 ? abs(lowestH) + 1 : 1;
//             }
//             for (int i = 0; i < 2; i++) {
//                 int nR = currR + dr[i], nC = currC + dc[i];
//                 if (nR >= n or nC >= m)continue;
//                 if (currH + dungeon[nR][nC] >= minHealth[nR][nC]) continue;
//                 minHealth[nR][nC] = currH + dungeon[nR][nC];
//                 pq.push({currH + dungeon[nR][nC], nR, nC , lowestH});
//             }
//         }
//         return -1;
//     }
// };


// DP

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 1e9));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                if (i == n - 1 && j == m - 1)
                {
                    dp[i][j] = (mat[i][j] < 0) ? abs(mat[i][j]) + 1 : 1;
                }

                int minHealth = INT_MAX;
                if (j + 1 < m)
                {
                    minHealth = dp[i][j + 1];
                }
                if (i + 1 < n)
                {
                    minHealth = min(minHealth, dp[i + 1][j]);
                }
                minHealth = minHealth - mat[i][j];

                if (mat[i][j] > 0)
                {
                    minHealth = max(1, minHealth);
                }

                dp[i][j] = min(dp[i][j], minHealth)
            }
        }

        return dp[0][0];
    }
};