/*************************************************************************
	> File Name: tree_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月14日 星期六 17时46分47秒
 ************************************************************************/

#include <stdio.h>
#include "tree.h"

int main(){
    SearchTree tree = NULL;
    SearchTree root = NULL;
    root = bstree_insert(tree, 0);
    tree = bstree_insert(tree, 1);
    tree = bstree_insert(tree, 2);
    tree = bstree_insert(tree, 3);
    tree = bstree_insert(tree, 4);
    tree = bstree_insert(tree, 5);
    tree = bstree_insert(tree, 6);
    tree = bstree_insert(tree, 7);
    tree = bstree_insert(tree, 8);
    bstree_inoder_traversal(tree);
}
