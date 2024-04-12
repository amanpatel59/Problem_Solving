
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEnd;
    int prefixCount;

    TrieNode()
    {
        isEnd = false;
        prefixCount = 0;
    }

    TrieNode *getChar(char &ch)
    {
        return children[ch];
    }

    void putChar(char &ch, TrieNode *&node)
    {
        children[ch] = node;
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

    void insert(string &word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->getChar(word[i]))
            {
                TrieNode *newNode = new TrieNode();
                node->putChar(word[i], newNode);
            }
            node = node->getChar(word[i]);
            node->prefixCount += 1;
        }
        node->setEnd();
    }

    long long search(string &word)
    {
        long long sum = 0;

        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            node = node->getChar(word[i]);
            sum += node->prefixCount;
        }
        return sum;
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        int n = words.size();

        Trie *t = new Trie();
        for (int i = 0; i < n; i++)
        {
            t->insert(words[i]);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = t->search(words[i]);
        }
        return res;
    }
};