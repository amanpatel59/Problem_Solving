class TrieNode
{
public:
    TrieNode *children[26];
    int minWordIndex;

    TrieNode(int index)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        minWordIndex = index;
    }

    TrieNode *getChar(char &ch)
    {
        return children[ch - 'a'];
    }

    void setChar(char &ch, TrieNode *node)
    {
        children[ch - 'a'] = node;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode(-1);
    }

    void insert(string &word, int &ind, vector<string> &wordsContainer)
    {
        int n = word.length();
        TrieNode *node = root;

        for (int i = n - 1; i >= 0; i--)
        {
            if (node->getChar(word[i]) == NULL)
            {
                TrieNode *newNode = new TrieNode(ind);
                node->setChar(word[i], newNode);
            }
            node = node->getChar(word[i]);

            if (n < wordsContainer[node->minWordIndex].length())
            {
                node->minWordIndex = ind;
            }
        }
    }

    int search(string &suffix)
    {
        int n = suffix.length();
        TrieNode *node = root;

        for (int i = n - 1; i >= 0; i--)
        {
            if (node->getChar(suffix[i]) == NULL)
            {
                break;
            }
            node = node->getChar(suffix[i]);
        }
        return node->minWordIndex;
    }
};

class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        int n = wordsContainer.size();
        int m = wordsQuery.size();

        Trie *t = new Trie();

        int miniIndex = 0;

        for (int i = 0; i < n; i++)
        {
            string word = wordsContainer[i];
            int l = word.length();

            t->insert(word, i, wordsContainer);

            if (wordsContainer[miniIndex].length() > l)
                miniIndex = i;
        }
        vector<int> res(m);
        for (int i = 0; i < m; i++)
        {
            res[i] = t->search(wordsQuery[i]);
            if (res[i] == -1)
                res[i] = miniIndex;
        }
        return res;
    }
};
