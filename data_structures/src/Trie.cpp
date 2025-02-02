#include "../include/Trie.h"

Trie::TrieNode::TrieNode(bool isEndOfWord)
{
    _children = QList<TrieNode*>(26);
    _isEndOfWord = isEndOfWord;
}

Trie::Trie()
{
    root = new TrieNode(false);

}

Trie::~Trie()
{
    if(root != nullptr)
    {
        delete(root);
    }
}

void Trie::insert(const QString &str)
{
    TrieNode* node = root;
    for(auto& c : str.toLocal8Bit())
    {
        int i = c - 'a';
        if(node->_children[i] == nullptr)
        {
            node->_children[i] = new TrieNode(false);
        }

        node = node->_children[i];
    }
    node->_isEndOfWord = true;
}

bool Trie::search(const QString &str)
{
    TrieNode* node = root;
    for(char& c : str.toLocal8Bit())
    {
        int i = c - 'a';
        if(node->_children[i] == nullptr)
            return false;
        node = node->_children[i];
    }
    return node->_isEndOfWord;
}
