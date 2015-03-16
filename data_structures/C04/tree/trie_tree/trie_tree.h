/*************************************************************************
	> File Name: trie_tree.h
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Mar 2015 10:14:38 AM CST
 ************************************************************************/

#ifndef _TRIE_TREE_H
#define _TRIE_TREE_H

#define MAX_NUM     26  // trie tree hax max 26 children
#define CHAR_TO_INDEX(s) int(*s - 'a')
struct TrieNode;
typedef struct TrieNode *Trie;
 
struct TrieNode{
    bool is_str_;   // If a string
    char value;
    Trie children[MAX_NUM];
};

/* Make a trie node */
Trie trie_make_node(char c);

/* Init a trie tree,create a empty trie, only have a root Trie node */
Trie trie_init();

/* Insert a string to a trie */
Trie trie_insert(Trie root, const char *str);

/* Retrun true is a word in the trie */
bool trie_search(Trie root, const char *str);

/* Delete a string from a trie */
//Trie Trie_delete(Trie root, char *str)

/* Destroy a trie */
void Trie_destroy(Trie root);
#endif
