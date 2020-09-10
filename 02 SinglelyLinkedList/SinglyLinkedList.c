//
// Created by syl on 2020/9/7.
//
#ifndef SINGLYLINKEDLIST_C
#define SINGLYLINKEDLIST_C

#include "SinglyLinkedList.h"

Status InitList_L(LinkList *L) {
    (*L) = (LinkList) malloc(sizeof(LNode));
    if (!(*L))
        exit(OVERFLOW);
    (*L)->next = NULL;
    return OK;
}

Status ClearList_L(LinkList L) {
    LinkList pre, p;
    if (!L)
        return ERROR;
    pre = L->next;
    while (pre) {
        p = pre->next;
        free(pre);
        pre = p;
    }
    L->next = NULL;
    return OK;

}

void DestroyList_L(LinkList *L) { //销毁所有结点
    LinkList p = *L;
    while (p) {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
}

Status ListEmpty_L(LinkList L) {//04.判断单链表L是否为空。
    if (L != NULL && L->next == NULL)
        return TRUE;
    else
        return FALSE;
}


int ListLength_L(LinkList L) {//05.返回单链表L元素个数。
    LinkList p;
    int i;
    if (L) {
        i = 0;
        p = L->next;
        while (p) {
            i++;
            p = p->next;
        }
    }
    return i;

}


Status GetElem_L(LinkList L, int i, LElemType_L *e) { //06.算法2.8：用e接受单链表中第i个元素
    int j;
    LinkList p = L->next;
    j = 1;
    p = L->next;
    while (p && j < i) {
        j++;
        p = p->next;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}


int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L)) {
    //07.返回单链表L中第一个与满足Compare关系的元素位序。
    int i;
    LinkList p;
    i = -1; //L不存在时返回-1
    if (L) {
        i = 0;
        p = L->next;
        while (p) {
            i++;
            if (!Compare(e, p->data)) {
                p = p->next;
                if(p==NULL) //失败时已经是最后一个结点
                    i++;
            }
            else
                break;
        }
    }
    return i;
}
/*银行排队算法中，此处两个函数不能直接使用，元婴是结构不能直接比较*/
#ifndef BANKQUEUING_C

Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e) {
    //08.用pre_e接受cur_e的前驱。
    LinkList p, suc;
    if (L) {
        p = L->next;
        if (p->data != cur_e) {
            while (p->next) {
                suc = p->next;
                if (suc->data == cur_e) {
                    *pre_e = p->data;
                    return OK;
                }
                p = suc;
            }
        }
    }
    return ERROR;
}


Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e) {
    //09.用next_e接受cur_e的后继。
    LinkList p, suc;
    if (L) {
        p = L->next;
        while (p && p->next) {
            suc = p->next;
            if (suc && p->next) {
                suc = p->next;
                if (suc && p->data == cur_e) {
                    *next_e = suc->data;
                    return OK;
                }
                if (suc)
                    p = suc;
                else
                    break;
            }
        }
    }
    return ERROR;
}

#endif


Status ListInsert_L(LinkList L, int i, LElemType_L e) {
    //10.算法2.9 在单链表L第i个位置之前插入e。
    LinkList p, s;
    int j;
    p = L;
    j = 0;
    while (p && j < i - 1) { //寻找第i-1结点
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return ERROR;
    s = (LinkList) malloc(sizeof(LNode));
    if (!s)
        exit(OVERFLOW);

    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList L, int i, LElemType_L *e) {
    //11.算法2.10：删除单链表L第i个位置的值，并用e接受。
    LinkList pre, p;
    int j;
    pre = L;
    j = 1;
    while (pre->next && j < i) {
        pre = pre->next;
        ++j;
    }
    if (pre->next || j > i)
        return ERROR;
    p = pre->next;
    pre->next=p->next;
    *e=p->data;
    free(p);
    return OK;
}


Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L)) {
    //12.用Visit函数访问单链表L。
    LinkList p;
    if(!L)
        return ERROR;
    else
        p = L->next;
    while(p){
        Visit(p->data);
        p = p->next;
    }
    return OK;
}


Status CreatList_HL(FILE *fp, LinkList *L, int n) {
    //13.算法2.11：头插法建立单链表L（逆序输入）。
    int i;
    LinkList p;
    LElemType_L  tmp;
    *L = (LinkList) malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next=NULL; //建立头结点
    for (i = 0; i <= n; ++i) {
        if (Scanf(fp,"%d",&tmp)==1){
            p = (LinkList) malloc(sizeof(LNode));
            if(!p)
                exit(OVERFLOW);
            p->data=tmp;    //录入数据
            p->next=(*L)->next;
            (*L)->next=p;
        }
        else
            return ERROR;
    }
    return OK;
}


Status CreateList_TL(FILE *fp, LinkList *L, int n) {
    //14.尾插法建立单链表L（逆序输入）。
    int i;
    LinkList p,q;
    LElemType_L  tmp;
    *L = (LinkList) malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next=NULL;
    for ( i = 1,q=*L; i <= n; ++i) {
        if (Scanf(fp,"%d", &tmp)==1){
            p = (LinkList) malloc(sizeof(LNode));
            if(!p)
                exit(OVERFLOW);
            p->data=tmp;
            q->next=p;
            q = q->next;
        }
        else
            return ERROR;
    }
    q->next = NULL;
    return OK;
}


#endif