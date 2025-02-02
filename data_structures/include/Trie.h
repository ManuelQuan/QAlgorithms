#ifndef TRIE_H
#define TRIE_H

#include <QList>
#include "data_structures_global.h"
class DATA_STRUCTURES_EXPORT Trie
{

public:
    static constexpr uint8_t NUM_CHARS = 26;
    Trie();
    ~Trie();
    void insert(const QString& str);
    bool search(const QString& str);

private:
    class TrieNode
    {
        public:
            TrieNode(bool isEndOfWord);
            bool _isEndOfWord;
            QList<TrieNode*> _children;
    };

    TrieNode* root;
};

#endif // TRIE_H
