/*************************************************************************
	> File Name: tree_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月15日 星期日 23时23分09秒
 ************************************************************************/

#include <stdio.h>
#include "tree.h"

int main(){
    AvlTree root = NULL;
    root = avl_tree_insert(root, 100);
    root = avl_tree_insert(root, 10);
    root = avl_tree_insert(root, 1);
    root = avl_tree_insert(root, 1000);
    root = avl_tree_insert(root, 999);
    root = avl_tree_insert(root, 19);
    root = avl_tree_insert(root, 129);
    root = avl_tree_insert(root, 99);
    root = avl_tree_insert(root, 156);
    root = avl_tree_insert(root, 98);
    root = avl_tree_insert(root, 55);
    avl_tree_inoder_traversal(root);
}
