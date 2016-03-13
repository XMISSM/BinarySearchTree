//
//  main.c
//  BinarySearchTree
//
//  Created by chenyufeng on 16/3/13.
//  Copyright © 2016年 Netease. All rights reserved.
//

/**
 *  我这里要实现一颗二叉查找树（二叉排序树）
 包括构造、遍历、查找、删除、插入操作
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct BTNode{

    int data;
    struct BTNode *lChild;
    struct BTNode *rChild;
}BiTNode,*BiTree;

//声明
int CreateBinarySearchTree(BiTree *T);
void Insert(BiTree *T,int x);
void MiddleOrder(BiTree T);

//创建二叉查找树
/**
 *  输入-1时创建结束,其实是一个不断插入的过程
 */
int CreateBinarySearchTree(BiTree *T){

    printf("请输入创建二叉查找树的数字序列：\n");

    int num;
    scanf("%d",&num);

    while (num != -1) {
        Insert(T,num);
        scanf("%d",&num);
    }

    printf("%s函数执行，二叉查找树创建成功\n",__FUNCTION__);
    return 1;
}

//插入节点
void Insert(BiTree *T,int x){

    //这里创建一个要插入的节点
    BiTNode *pInsert = (BiTNode *)malloc(sizeof(BiTNode));
    pInsert->data = x;
    pInsert->lChild = NULL;
    pInsert->rChild = NULL;

    if ((*T) == NULL) {
        *T = pInsert;
    }

    if ((*T)->lChild == NULL && x < (*T)->data) {
        (*T)->lChild = pInsert;
    }

    if ((*T)->rChild == NULL && x > (*T)->data) {
        (*T)->rChild = pInsert;
    }

    //递归实现
    if (x < (*T)->data) {
        Insert(&(*T)->lChild, x);
    }

    if (x > (*T)->data) {
        Insert(&(*T)->rChild, x);
    }

    return;
}

//中遍历二叉查找树
//打印的应该是一个递增的序列
void MiddleOrder(BiTree T){
    if (T == NULL) {
        return;
    }else{

        MiddleOrder(T->lChild);
        printf("%d ",T->data);
        MiddleOrder(T->rChild);
    }
}

int main(int argc, const char * argv[]) {

    BiTree tree;

    //这个是引用传递
    CreateBinarySearchTree(&tree);
    
    MiddleOrder(tree);
    printf("\n");
    
    return 0;
}


























