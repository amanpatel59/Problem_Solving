class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;
    vector<string> commonNames;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
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
            node->commonNames.push_back(word);
        }
        node->setEnd();
    }

    void print(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->getChar(word[i]) == NULL)
            {
                break;
            }
            node = node->getChar(word[i]);
        }

        for (int i = 0; i < node->commonNames.size(); i++)
        {
            cout << node->commonNames[i] << endl;
        }
    }
};