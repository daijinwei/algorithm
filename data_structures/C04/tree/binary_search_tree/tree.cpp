/*************************************************************************
	> File Name: tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月14日 星期六 09时06分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

SearchTree bstree_make_empty(SearchTree tree){
    if(NULL == tree){
        return NULL;
    }else{
        bstree_make_empty(tree->left);
        bstree_make_empty(tree->right);
        free(tree);
    }
}

SearchTree bstree_insert(SearchTree tree, ItemType item){
    if(NULL == tree){
        /* Create a binary search tree with only one tree node */
        tree = (SearchTree)malloc(sizeof(struct TreeNode));
        if (NULL == tree){
            fprintf(stdout, "Out of space\n");
        }else{
            tree->item = item;
            tree->left = NULL;
            tree->right = NULL;
        }
    }else if(item < tree->item){
        tree->left = bstree_insert(tree->left, item);
    }else if(item > tree->item){
        tree->right = bstree_insert(tree->right, item);
    }else{
        fprintf(stdout, "The tree allready have the item\n");
    }
    return tree;
}

Position bstree_find(SearchTree tree, ItemType item){
    if(NULL == tree){
        fprintf(stdout,"The tree is NULL\n");
        return NULL;
    }

    if(item < tree->item){
        bstree_find(tree->left, item); 
    }else if(item > tree->item){
        bstree_find(tree->right, item);
    }else{
        return tree;
    }
}

Position bstree_find_min(SearchTree tree){
    if(NULL == tree){
        return NULL;
    } 

    if(NULL == tree->left){
        return tree;
    }else{
        return bstree_find_min(tree->left);
    }
}

Position bstree_find_max(SearchTree tree){
    if(NULL == tree){
        return NULL;
    }
    
    if(NULL == tree->right){
        return tree;
    }else{
        return bstree_find_max(tree->right);
    }
}

void bstree_delete_min(SearchTree tree){
    Position tmp = bstree_find_min(tree);
    if(NULL != tmp){
        free(tmp);
    }
}

SearchTree bstree_delete(SearchTree tree, ItemType item){
    Position tmp = NULL;
    if(NULL == tree){
        return NULL;
    }else if(item < tree->item){
        tree->left = bstree_delete(tree->left, item);
    }else if(item > tree->item){
        tree->right = bstree_delete(tree->right, item);
    }else if((NULL != tree->left) && (NULL != tree->right)){// The node have two child
        tmp = bstree_find_min(tree->right);
        tree->item = tmp->item;
        bstree_delete(tree->right, tree->item);
    }else{
        tmp = tree;
        if(NULL == tree->left){
            tree = tree->right;
        }else if(NULL == tree->right){
            tree = tree->left;
        }
        free(tmp);
    }
    return tree;
}

Position bstree_inoder_traversal(SearchTree tree){
    if(NULL == tree){
        return NULL;
    }else{
        bstree_inoder_traversal(tree->left);
        fprintf(stdout, "Item\t%d\n", tree->item);
        bstree_inoder_traversal(tree->right);
    }
}
