class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       if(root == NULL)return 0;
       
       queue<Node*>q;
       q.push(root);
       int odd = 0 , even = 0;
       bool flag = 1;
       while(!q.empty())
       {
           flag = !flag;
           int size = q.size();
           
           for(int i = 0  ; i < size; i++)
           {
               Node* curr = q.front();
               q.pop();
               if(flag)even+= curr->data;
               else odd += curr->data;
               if(curr->left)q.push(curr->left);
               if(curr->right)q.push(curr->right);
           }
       }
       return odd-even;
    }
};
