//
// Created by syl on 2020/9/5.
//

#ifndef DATASTRUCTURE_SEQUENCELIST_H
#define DATASTRUCTURE_SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h> //提供malloc 、realloc、free、exit原型
#include "../Status.h" //
/* 宏定义 */
#define LIST_INIT_SIZE 100 //顺序表存储空间的初始分配量
#define  LISTINCREMENT 10 //顺序表存储空间的分配增量
/* 顺序表类型定义 */
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct{
    LElemType_Sq  *elem; //存储空间基址（指向第一个结点的指针）
    int length;//当前顺序表的长度
    int listsize;//当前分配的存储空间
}Sqlist;//顺序表0号单元正常使用
/*顺序表函数列表*/

Status InitList_Sq(Sqlist *L);
//算法2.3：初始化空顺序表L。
void ClearList_Sq(Sqlist *L);
//02.清空顺序表L。
void DestroyList_Sq(Sqlist *L);
//03.销毁顺序表L。
Status  ListEmpty_Sq(Sqlist L);
//04.判断顺序表L是否为空。
int ListLength_Sq(Sqlist L);
//05.返回顺序表L中元素个数。
int LocationElem_Sq(Sqlist L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq));
//算法2.6：返回顺序表L中首个与e满足Compare关系的元素位序，
Status PriorElem_Sq(Sqlist L,LElemType_Sq cur_e,LElemType_Sq *pre_e);
//08.用pre_e接受cur_e的前驱。
Status NextElem_Sq(Sqlist L,LElemType_Sq cur_e,LElemType_Sq *next_e);
//09.用next_e接受cur_e的后继。
Status ListInsert_Sq(Sqlist *L,int i,LElemType_Sq e);
//10.算法2.4在顺序表L的第i个位置上插入e。
Status ListDelete_Sq(Sqlist *L,int i,LElemType_Sq *e);
//11.算法2.5：删除顺序表L上第i个位置的元素，并用e返回。
Status ListTraverse_Sq(Sqlist L,void (Visit)(LElemType_Sq));
//12.用visit函数访问顺序表L

#endif //SEQUENCELIST_H
