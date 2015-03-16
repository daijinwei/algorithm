/*************************************************************************
	> File Name: trie_tree.h
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Mar 2015 10:14:38 AM CST
 ************************************************************************/

#ifndef _TRIE_TREE_H
#define _TRIE_TREE_H

#define MAX_STR_NUM     26  // trie tree hax max 26 child

struct TrieNode;
typedef struct TrieNode *trie;
    
struct TrieNode{
    struct TrieNode *child[MAX_STR_NUM];
};

#endif
