// MEMO
// int getWays(string &s, int index, int &n, vector<int> &dp)
// {
//     // base case
//     if (index >= n)
//     {
//         return 1;
//     }
//     if (dp[index] != -1)
//         return dp[index];

//     int ways = 0;
//     if (s[index] != '0')
//         ways = getWays(s, index + 1, n, dp);

//     if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')))
//     {
//         ways += getWays(s, index + 2, n, dp);
//     }

//     return dp[index] = ways;
// }

// int numDecodings(string s)
// {
//     int n = s.length();

//     int index = 0;
//     vector<int> dp(n + 1, -1);

//     return getWays(s, index, n, dp);
// }

// TABULATION
// int numDecodings(string s)
// {
//     int n = s.length();

//     unordered_map<string, char> mp;
//     int number = 1;
//     for (char ch = 'A'; ch <= 'Z'; ch++)
//         mp[to_string(number++)] = ch;

//     int index = 0;
//     vector<int> dp(n + 1, -1);

//     // base case
//     dp[n] = 1;

//     for (int ind = n - 1; ind >= 0; ind--)
//     {
//         int ways = 0;

//         if (mp.find(s.substr(ind, 1)) != mp.end())
//             ways += dp[ind + 1];

//         if (ind + 1 < n)
//         {
//             string two = s.substr(ind, 2);

//             if (mp.find(two) != mp.end())
//             {
//                 ways += dp[ind + 2];
//             }
//         }

//         dp[ind] = ways;
//     }

//     return dp[0];
// }

// SPACE OPTIMIZATION
int numDecodings(string s)
{
    int n = s.length();

    unordered_map<string, char> mp;
    int number = 1;
    for (char ch = 'A'; ch <= 'Z'; ch++)
        mp[to_string(number++)] = ch;

    // base case
    int forward1 = 1, forward2 = -1;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        int ways = 0;

        if (mp.find(s.substr(ind, 1)) != mp.end())
            ways += forward1;

        if (ind + 1 < n)
        {
            string two = s.substr(ind, 2);

            if (mp.find(two) != mp.end())
            {
                ways += forward2;
            }
        }

        forward2 = forward1;
        forward1 = ways;
    }

    return forward1;
}