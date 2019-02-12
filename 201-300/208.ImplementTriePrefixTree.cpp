#include <iostream>
#include <vector>

#include <string>
#include <array>
using std::array;
using std::cout, std::endl;
using std::string;
using std::vector;

class Trie
{
  private:
    // array<Trie *>[26] subT;
    bool isword = false;

    vector<Trie *> subT = vector<Trie *>(26, NULL);

  public:
    /** Initialize your data structure here. */
    Trie()
    {
        ;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if (word.size() == 0)
        {
            isword = true;
            return;
        }
        int charn = word[0] - 'a';
        if (subT[charn] == NULL)
        {
            subT[charn] = new Trie();
        }
        subT[charn]->insert(
            word.substr(1, word.size() - 1));
        // string(word.begin() + 1, word.end()));
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        if (word.size() == 0)
            return isword;
        int charn = word[0] - 'a';
        if (subT[charn] != NULL)
        {
            return subT[charn]->search(word.substr(1, word.size() - 1));
            // return subT[charn]->search(string(word.begin() + 1, word.end()));
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        if (prefix.size() == 0)
            return true;
        int charn = prefix[0] - 'a';
        if (subT[charn] != NULL)
        {
            return subT[charn]->startsWith(prefix.substr(1, prefix.size() - 1)); 
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main()
{
    Trie trie = *new Trie();

    trie.insert("apple");
    cout << trie.search("apple") << endl;      // returns true
    cout << trie.search("app") << endl;        // returns false
    cout << trie.search("apdfkjfldp") << endl; // returns false
    cout << trie.startsWith("app") << endl;    // returns true
    trie.insert("app");
    cout << trie.search("app") << endl;
}