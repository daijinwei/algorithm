/*************************************************************************
	> File Name: tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月14日 星期六 09时06分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int max(int x, int y){
    return x > y ? x : y;
}

int avl_tree_height(Position pnode){
    if(NULL == pnode){
        return -1;
    }else{
        return pnode->height;
    }
}

Position avl_tree_single_rotate_with_left(Position node){
    Position k1 = NULL;
    k1 = node->left;
    node->left = k1->right;
    k1->right = node;
    node->height = max(avl_tree_height(node->left),
                      avl_tree_height(node->right)) + 1;
    k1->height = max(avl_tree_height(k1->left),
                      avl_tree_height(k1->right)) + 1;
    return k1;
}

Position avl_tree_single_rotate_with_right(Position node){
    Position k1 = NULL;
    k1 = node->right;
    node->right = k1->left;
    k1->left = node;
    node->height = max(avl_tree_height(node->left),
                      avl_tree_height(node->right)) + 1;
    k1->height = max(avl_tree_height(k1->left),
                      avl_tree_height(k1->right)) + 1;
    return k1;
}


Position avl_tree_double_rotate_with_left(Position node){
    /* A single rotate */
    node->left = avl_tree_single_rotate_with_right(node->left);

    /* A single left rotate */
    return avl_tree_single_rotate_with_left(node);
}

Position avl_tree_double_rotate_with_right(Position node){
    /* A single rotate */
    node->right = avl_tree_single_rotate_with_left(node->right);

    /* A single left rotate */
    return avl_tree_single_rotate_with_right(node);
}

AvlTree avl_tree_insert(AvlTree tree, ItemType item){
    if(NULL == tree){
        tree = (AvlTree)malloc(sizeof(struct TreeNode));
        if(NULL == tree){
            fprintf(stdout, "Out of space\n");
        }else{
            tree->left = tree->right = NULL;
            tree->height = 0;
            tree->item = item;
        }
    }else if(item < tree->item){
        tree->left = avl_tree_insert(tree->left, item);
        if(avl_tree_height(tree->left) - avl_tree_height(tree->right) >= 2){
            if(item < tree->left->item){
                avl_tree_single_rotate_with_left(tree);
            }else{
                avl_tree_double_rotate_with_left(tree);
            }
        }
    }else if(item > tree->item){
        tree->right = avl_tree_insert(tree->right, item);
        if(avl_tree_height(tree->right) - avl_tree_height(tree->left) >= 2){
            if(item > tree->right->item){
                avl_tree_single_rotate_with_right(tree);
            }else{
                avl_tree_double_rotate_with_right(tree);
            }
        }
    }
    /* Add height */
    tree->height = max(avl_tree_height(tree->left), avl_tree_height(tree->right));
    return tree;
}

Position avl_tree_inoder_traversal(AvlTree tree){
    if(NULL == tree){
        return NULL;
    }else{
        avl_tree_inoder_traversal(tree->left);
        fprintf(stdout, "Item\t%d\n", tree->item);
        avl_tree_inoder_traversal(tree->right);
    }
}    
