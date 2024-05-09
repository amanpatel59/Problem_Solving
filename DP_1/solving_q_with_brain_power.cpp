// MEMOIZATION
// long long check(vector<vector<int>> &questions, int index, int &n, vector<long long> &dp)
// {
//     // base case
//     if (index >= n)
//         return 0;
//     if (dp[index] != -1)
//         return dp[index];

//     long long not_do = 0 + check(questions, index + 1, n, dp);

//     long long do_ques = 0;
//     do_ques += questions[index][0] + check(questions, index + questions[index][1] + 1, n, dp);

//     return dp[index] = max(not_do, do_ques);
// }
// long long mostPoints(vector<vector<int>> &questions)
// {
//     int n = questions.size();

//     vector<long long> dp(n, -1);
//     int index = 0;

//     return check(questions, index, n, dp);
// }

// TABULATION
long long mostPoints(vector<vector<int>> &questions)
{
    int n = questions.size();

    vector<long long> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        long long not_do = 0 + dp[i + 1];

        long long do_ques = 0;

        if (i + questions[i][1] + 1 >= n)
            do_ques += questions[i][0] + 0;
        else
            do_ques += questions[i][0] + dp[i + questions[i][1] + 1];

        dp[i] = max(not_do, do_ques);
    }

    return dp[0];
}