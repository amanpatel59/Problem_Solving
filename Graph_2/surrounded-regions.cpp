class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<pair<int, int>> not_changing;
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if (board[i][board[0].size() - 1] == 'O') {
                q.push({i, board[0].size() - 1});
                vis[i][board[0].size() - 1] = 1;
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                vis[0][i] = 1;
            }
            if (board[board.size() - 1][i] == 'O') {
                q.push({board.size() - 1, i});
                vis[board.size() - 1][i] = 1;
            }
        }

        while (!q.empty()) {
            int curr_row = q.front().first, curr_col = q.front().second;
            not_changing.push_back({curr_row, curr_col});
            q.pop();
            int a[4] = {0, 0, -1, 1}, b[4] = {1, -1, 0, 0};

            for (int i = 0; i < 4; i++) {
                int nrow = curr_row + a[i], ncol = curr_col + b[i];
                if (nrow >= 0 and ncol >= 0 and nrow < board.size() and
                    ncol < board[0].size() and !vis[nrow][ncol] and
                    board[nrow][ncol] == 'O') {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    not_changing.push_back({nrow, ncol});
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = 'X';
            }
        }

        for (auto i : not_changing) {
            int row = i.first, col = i.second;
            cout << row << " " << col << endl;
            board[row][col] = 'O';
        }
    }
};