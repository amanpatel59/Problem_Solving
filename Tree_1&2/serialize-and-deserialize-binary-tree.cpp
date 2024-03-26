/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)return "";
        queue<TreeNode*>q;
        q.push(root);
        string str = to_string(root->val)+',';
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(p->left)
            {
                q.push(p->left);
                str += to_string(p->left->val)+',';
            }
            else
            {
                str+= "@,";
            }
            if(p->right)
            {
                q.push(p->right);
                str += to_string(p->right->val)+',';
            }
            else
            {
                str+= "@,";
            }
        }
        return str;
    }




    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)return NULL;

        vector<string>str;
        string temp;
        for(int i = 0 ; i < data.size() ; i++)
        {
            if(data[i]==',')
            {
                str.push_back(temp);
                temp = "";
            }
            else temp+= data[i];
        }

        int j = 0;
        TreeNode* root = new TreeNode(stoi(str[j++]));
        
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty() and j < str.size())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(str[j]=="@")
            {
                temp->left = NULL;
                j++;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str[j++]));
                temp->left = leftNode;
                q.push(leftNode);
            }

            if(str[j]=="@")
            {
                temp->right = NULL;
                j++;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str[j++]));
                temp->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));