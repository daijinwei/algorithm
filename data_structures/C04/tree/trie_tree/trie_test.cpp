/*************************************************************************
	> File Name: trie_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月16日 星期一 22时08分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "trie_tree.h"


int main()
{
    int exists_string = 0;
    Trie root = NULL;
    root = trie_init();
    trie_insert(root, "daijinwei");
    trie_insert(root, "hello");
    trie_insert(root, "wangsan");
    trie_insert(root, "ccnp");
    trie_insert(root, "linux");
    exists_string = trie_search(root,"daijinwei");
    if(0 != exists_string){
        fprintf(stdout, "The string is exists the trie\n");
    }else{
        fprintf(stdout, "The string is not exists the trie\n");
    }

    exists_string = trie_search(root,"daijinw");
    if(0 != exists_string){
        fprintf(stdout, "The string is exists the trie\n");
    }else{
        fprintf(stdout, "The string is not exists the trie\n");
    }
    trie_destroy(root);
}
