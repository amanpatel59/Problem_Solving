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

    void putChar(char &ch, TrieNode *&node)
    {
        children[ch - 'a'] = node;
    }

    void setEnd()
    {
        isEnd = true;
    }

    bool getEnd()
    {
        return isEnd;
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
            if (node->getChar(word[i]) == NULL)
            {
                TrieNode *newNode = new TrieNode();
                node->putChar(word[i], newNode);
            }
            node = node->getChar(word[i]);
        }
        node->setEnd();
    }

    string search(string &word)
    {
        TrieNode *node = root;

        string s = "";

        for (int i = 0; i < word.length(); i++)
        {
            if (node->getChar(word[i]) != NULL)
            {
                s += word[i];
            }
            else
            {
                s = word;
                break;
            }

            node = node->getChar(word[i]);

            if (node->getEnd() == true)return s;
        }
        return s;
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        int n = dictionary.size();
        int m = sentence.length();

        Trie *t = new Trie();

        for (int i = 0; i < n; i++)
        {
            t->insert(dictionary[i]);
        }

        string res = "";
        string singleWord = "";

        for (int i = 0; i < m; i++)
        {
            char ch = sentence[i];
            if (ch == ' ')
            {
                res += t->search(singleWord) + " ";
                singleWord = "";
            }
            else
            {
                singleWord += ch;
            }
        }
        res += t->search(singleWord);

        return res;
    }
};