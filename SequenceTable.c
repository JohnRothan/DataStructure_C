/*
title:顺序表的基本操作
author:JohnRothan
date:2023/10/20 12:32
*/

#include<stdio.h>
#include<stdlib.h>

#define Size 5

typedef struct{
    int *head;
    int length;
    int size;
}Table;

void InitTable(Table* t){
    t->head = (int*)malloc(Size * sizeof(int));
    if(!t->head){
        printf("初始化失败");
        exit(0);
    }
    t->length=0;
    t->size=Size;
}

void DisplayTable(Table t){
    int i;
    for(i=0;i<t.length;i++){
        printf("%d ",t.head[i]);
    }
    printf("\n");
}
void InsertTable(Table* t,int elem,int add){
    int i;
    if(add > t->length+1 || add < 1){
        printf("非法插入位置！\n");
        return;
    }
    if(t->length>t->size){
        t->head=(int*)realloc(t->head,(t->size+1)*sizeof(int));
        if(!t->head){
            printf("分配失败！\n");
            return;
        }
        t->size+=1;
    }
    for(i=t->length-1;i>=add-1;i--){
        t->head[i+1]=t->head[i];
    }
    t->head[add-1]=elem;
    t->length++;
}

void DelTable(Table* t,int add){
    int i;
    if(add < 1 || add > t-length){
        printf("非法删除位置！\n");
        return;
    }
    for(i=add;i < t->length;i++){
        t->head[i-1]=t->head[i];
    }
    t->length--;
}

int SelectTable(Table t,int elem){
    int i;
    for(i=0;i<t.length;i++){
        if(t.head[i]==elem){
            return i+1;
        }
    }
    return -1;
}

void EditTable(Table* t,int elem,int newElem){
    int add=SelectTable(*t,elem);
    if(add==-1){
        printf("没有该元素！\n");
        return;
    }
    t->head[add-1]=newElem;
}

int main(){
    int i;
    Table t={NULL,0,0};
    InitTable(&t);
    for(i=1;i<=Size;i++){
        t.head[i-1]=i;
        t.length++;
    }
    printf("顺序表的元素：\n");
    DisplayTable(t);
    printf("删除元素3：\n")；
    DelTable(&t,3);
    DisplayTable(t);
    printf("在第四个位置插入10：\n");
    InsertTable(&t,10,4);
    DisplayTable(t);
    printf("查找元素4的位置：%d\n",SelectTable(t,4));
    printf("将元素10改为20：\n");
    EditTable(&t,10,20);
    DisplayTable(t);
    free(t.head);
    return 0;
}
