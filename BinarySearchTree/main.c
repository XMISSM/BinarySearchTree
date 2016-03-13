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

//查找某一个值
//返回1表示找到该值，返回0表示没有找到
BiTNode *SearchValue(BiTree T,int x){
    if (T == NULL) {
        return 0;
    }else{
        if (x < T->data) {
            //查左子树
            SearchValue(T->lChild, x);
        }else if (x > T->data){
            //查右子树
            SearchValue(T->rChild, x);
        }else{
            //找到该值
            printf("该值的内存地址为：%p\n",T);
            return T;
        }
    }

    return NULL;
}

//删除某一个元素
BiTree *DeleteValue(BiTree *T,int x){


    //先要查找该节点，同时也要保存该节点的父节点
    BiTNode *searchNode;
    BiTNode *parentNode;

    searchNode = *T;
    parentNode = *T;

    while (searchNode->data != x) {

        if (x < searchNode->data) {

            parentNode = searchNode;
            searchNode = searchNode->lChild;
        }else if (x > searchNode->data){

            parentNode = searchNode;
            searchNode = searchNode->rChild;
        }else{
            break;
        }
    }

    if (searchNode->lChild == NULL && searchNode->rChild == NULL) {
        //是叶子节点

        if ((*T)->lChild == NULL && (*T)->rChild == NULL) {
            //是根节点
            free(*T);
            *T = NULL;
        }else{
            //不是根节点,是普通的叶子节点
            //需要判断要删除的节点是父节点的左孩子还是右孩子
            if (searchNode->data < parentNode->data) {
                //是左孩子
                parentNode->lChild = NULL;
            }else{
                //是右孩子
                parentNode->rChild = NULL;
            }
            free(searchNode);
            searchNode = NULL;
        }
    }

    return T;
}

int main(int argc, const char * argv[]) {

    BiTree tree;

    //这个是引用传递
    CreateBinarySearchTree(&tree);
    
    MiddleOrder(tree);
    printf("\n");

    printf("请输入要查找的元素：");
    int searchValue;
    scanf("%d",&searchValue);
    SearchValue(tree,searchValue);


    printf("请输入要删除的元素：");
    int deleteValue;
    scanf("%d",&deleteValue);
    DeleteValue(&tree, deleteValue);
    MiddleOrder(tree);//遍历检查
    printf("\n");
    
    return 0;
}


























