#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
using namespace std;

// TRIES DATA STRCRURE
//--> main use in patter mtching  with good complexity
//--> it is multiway data strcture like ek node h toh uske multiple node hote h

class TrieNode
{
public:
    char value;
    unordered_map<int, TrieNode *> childern;
    bool isTerminal;

    TrieNode(char data)
    {
        this->value = data;
        this->isTerminal = false;
    }
};

void insertIntoTrie(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode *child;

    if (root->childern.count(ch) == 1)
    {
        child = root->childern[ch];
    }
    else
    {
        child = new TrieNode(ch);
        root->childern[ch] = child;
    }

    insertIntoTrie(child, word.substr(1));
}

bool searchTrie(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        if (root->isTerminal)
            return true;
        else
            return false;
    }
    TrieNode *child;
    char ch = word[0];
    if (root->childern.count(ch) == 1)
    {
        child = root->childern[ch];
    }
    else
    {
        return false;
    }

    bool ans = searchTrie(child, word.substr(1));

    return ans;
}

void removeTrie(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }
    TrieNode *child;
    char ch = word[0];
    if (root->childern.count(ch) == 1)
    {
        child = root->childern[ch];
    }
    else
    {
        return;
    }
    return removeTrie(child, word.substr(1));
}

int main()
{
    TrieNode *root = new TrieNode('_');
    insertIntoTrie(root, "cover");
    insertIntoTrie(root, "car ");
    bool ans = searchTrie(root, "cover");
    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "NotFound" << endl;
    }
    removeTrie(root, "cover");

    bool ans1 = searchTrie(root, "cover");
    if (ans1)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "NotFound" << endl;
    }
    return 0;
}