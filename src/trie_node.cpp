#include "trie_node.hpp"

TrieNode::TrieNode() {
    term = false;
    for(int i = 0; i < 10; i++) {
        numbers[i] = NULL;
    }
}
