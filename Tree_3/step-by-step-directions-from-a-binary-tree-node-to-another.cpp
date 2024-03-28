class Solution {
public:
    void all_directions(TreeNode*& root, vector<string>& temp, unordered_map<TreeNode*, TreeNode*>& child_to_parent, unordered_map<TreeNode*, bool>& visited, vector<string>& ans, TreeNode*& destNode) {
        if (root == NULL or visited[root]) {
            return;
        }

        if (root == destNode) {
            if (ans.empty() or ans.size() > temp.size()) {
                ans = temp;
            }
            return;
        }

        visited[root] = true;

        if (root->left) {
            temp.push_back("L");
            all_directions(root->left, temp, child_to_parent, visited, ans, destNode);
            temp.pop_back();  // Backtrack
        }

        if (root->right) {
            temp.push_back("R");
            all_directions(root->right, temp, child_to_parent, visited, ans, destNode);
            temp.pop_back();  // Backtrack
        }

        if (child_to_parent.find(root) != child_to_parent.end()) {
            temp.push_back("U");
            all_directions(child_to_parent[root], temp, child_to_parent, visited, ans, destNode);
            temp.pop_back();  // Backtrack
        }
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> child_to_parent;
        TreeNode* startNode;
        TreeNode* destNode;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                if (p->val == startValue) {
                    startNode = p;
                }
                if (p->val == destValue) {
                    destNode = p;
                }
                if (p->left) {
                    q.push(p->left);
                    child_to_parent[p->left] = p;
                }
                if (p->right) {
                    q.push(p->right);
                    child_to_parent[p->right] = p;
                }
            }
        }

        vector<string> ans;
        vector<string> temp;
        unordered_map<TreeNode*, bool> visited;

        all_directions(startNode, temp, child_to_parent, visited, ans, destNode);
        
        string res = "";
        for(auto i : ans)
        {
            res += i;
        }
        return res;
    }
};
