/*************************************************************************
	> File Name: trie_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月16日 星期一 21时28分01秒
 ************************************************************************/

#include <stdlib.h>
#include "trie_tree.h"

Trie trie_make_node(char c){
    int char_count = 0;
    Trie trie_node = (Trie)malloc(sizeof(struct TrieNode));
    if(!trie_node){
        return NULL;
    }else{
        trie_node->value = c;
        for(char_count; char_count < MAX_NUM; ++char_count){
            trie_node->children[char_count] = NULL;
        }
    }
    trie_node->is_str_ = false;
    return trie_node;
}

Trie trie_init(){
    return trie_make_node(' ');
}

Trie trie_insert(Trie root, const char *str){
    if(NULL == str) return NULL;
    Trie tmp = NULL;
    tmp = root;
    while(*str != '\0'){
        // The node not exists, make a node
        if(NULL == tmp->children[CHAR_TO_INDEX(str)]){
            tmp->children[CHAR_TO_INDEX(str)] = trie_make_node(*str);
            tmp = tmp->children[CHAR_TO_INDEX(str)];
        }else{
            tmp = tmp->children[CHAR_TO_INDEX(str)];
        }
        str++;
    }
    tmp->is_str_ = true;
}

bool trie_search(Trie root, const char *str){
    if((NULL == root) || (NULL == str)) return false;
    Trie p = root;
    while(NULL != p && *str != '\0'){
        p = p->children[CHAR_TO_INDEX(str)];
        str++;
    }
    return (NULL != p) && (p->is_str_ == true);
}

void trie_destroy(Trie root){
    if(NULL != root){
        int count_node = 0;
        for(count_node; count_node < MAX_NUM; ++count_node){
            if(root->children[count_node] != NULL){
                trie_destroy(root);
            }
        }
        free(root);
    }
}
