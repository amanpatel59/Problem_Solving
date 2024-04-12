class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        isEnd = false;
    }

    TrieNode *getChar(char &ch)
    {
        return children[ch - 'a'];
    }

    void setChar(char &ch, TrieNode *node)
    {
        children[ch - 'a'] = node;
    }

    bool getEnd()
    {
        return isEnd;
    }

    void setEnd()
    {
        isEnd = true;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        int n = word.length();
        TrieNode *node = root;

        for (int i = 0; i < n; i++)
        {
            if (node->getChar(word[i]) == NULL)
            {
                TrieNode *newNode = new TrieNode();
                node->setChar(word[i], newNode);
            }
            node = node->getChar(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        TrieNode *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (node->getChar(word[i]) == NULL)
            {
                return false;
            }
            node = node->getChar(word[i]);
        }

        return node->getEnd();
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            if (node->getChar(prefix[i]) == NULL)
            {
                return false;
            }
            node = node->getChar(prefix[i]);
        }

        return true;
    }
};
