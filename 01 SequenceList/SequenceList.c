//
// Created by syl on 2020/9/5.
//
#ifndef DATASTRUCTURE_SEQUENCELIST_C
#define DATASTRUCTURE_SEQUENCELIST_C

#include "SequenceList.h" //02线性表

Status InitList_Sq(Sqlist *L) {
    (*L).elem = (LElemType_Sq *) malloc(LIST_INIT_SIZE * sizeof(LElemType_Sq));
    if (!(*L).elem)
        exit(OVERFLOW);
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return OK;
}

void ClearList_Sq(Sqlist *L) {
    (*L).length = 0;
}

void DestroyList_Sq(Sqlist *L) {
    free((*L).elem);
    (*L).elem = NULL;
    (*L).length = 0;
    (*L).listsize = 0;
}

Status ListEmpty_Sq(Sqlist L) {
    return L.length = 0 ? TRUE : FALSE;
}

int ListLength_Sq(Sqlist L) {
    return L.length;
}

Status GetElem_Sq(Sqlist L, int i, LElemType_Sq *e) {
    if (i < 1 || i > L.length)
        return ERROR;
    else
        *e = L.elem[i - 1];
    return OK;
}

//算法2.6
int LocateElem_Sq(Sqlist L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq)) {
    int i = 1;
    while (i <= L.length && !Compare(e, L.elem[i - 1]))
        ++i;
    if (i <= L.length)
        return i;
    else
        return 0;

}

Status PriorElem_Sq(Sqlist L, LElemType_Sq cur_e, LElemType_Sq *pre_e) {
    int i = 1;
    if (L.elem[0] != cur_e) {
        while (i < L.length && L.elem[i] != cur_e)
            ++i;
        if (i < L.length) {
            *pre_e = L.elem[i - 1];
            return OK;
        }
    }
    return ERROR;
}

Status NextElem_Sq(Sqlist L,LElemType_Sq cur_e,LElemType_Sq *next_e)
{
    int i = 0;
    while (i<L.length && L.elem[i]!=cur_e)
        ++i;
    if (i < L.length - 1) {
        *next_e = L.elem[i + 1];
        return OK;
    }
    return ERROR;
}
//算法2.4
Status ListInsert_Sq(Sqlist *L, int i, LElemType_Sq e) {
    LElemType_Sq *newbase;
    LElemType_Sq *p, *q;
    if (i < 1 || i > (*L).listsize) {
        newbase = (LElemType_Sq *) realloc((*L).elem, ((*L).listsize + LISTINCREMENT * sizeof(LElemType_Sq)));
        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }
    q = &(*L).elem[i - 1];
    for (p = &(*L).elem[(*L).length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;
    (*L).length++;
    return OK;
}

Status ListDelete_Sq(Sqlist *L, int i, LElemType_Sq *e) {

    LElemType_Sq *p, *q;
    if (i < 1 || i > (*L).length)
        return ERROR;
    p = &(*L).elem[i - 1];
    *e = *p;
    q = (*L).elem + (*L).length - 1;
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    (*L).length--;
    return OK;

}

Status ListTraverse_Sq(Sqlist L, void(Visit)(LElemType_Sq)) {
    int i;
    for (i = 0; i < L.length; i++)
        Visit(L.elem[i]);
    return OK;
}


#endif




