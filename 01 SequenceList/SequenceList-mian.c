//
// Created by syl on 2020/9/5.
//

#include <stdio.h>
#include "SequenceList.c"

Status CmpGreater(LElemType_Sq e, LElemType_Sq data);

void PrintElem(LElemType_Sq e);

int main(int argc, char **argv) {
    Sqlist L;
    int i;
    LElemType_Sq e;
    printf("01.函数InitList_Sq 测试...\n");
    {
        printf("初始化顺序表L ...\n");
        InitList_Sq(&L);
        printf("\n");
    }
    PressEnter
    printf("04.函数 ListEmpty_Sq 测试...\n");
    {
        ListEmpty_Sq(L) ? printf("L为空！！\n") : printf("L不为空！\n");
        printf("\n");
    }
    PressEnter
    printf("10.函数ListInsert_Sq 测试...\n");
    {
        for (int i = 1; i <= 6; ++i) {
            printf("作为示范，在L第%d个位置插入 \"%d\"...\n", i, 2 * i);
            ListInsert_Sq(&L, i, 2 * i);

        }
        printf("\n");
    }
    PressEnter
    printf("12.函数 ListTraverse_Sq 测试...\n");
    {
        printf("L中的元素为：L=");
        ListTraverse_Sq(L, PrintElem);
        printf("\n\n");
    }
    PressEnter

    printf("05函数 ListLength_Sq 测试...\n");
    {
        i = ListLength_Sq(L);
        printf("L的长度为%d \n", i);

    }
    PressEnter
    printf("11.函数 ListDelete_Sq 测试...\n");
    {
        ListDelete_Sq(&L, 6, &e);
        printf("删除L中第6个元素\"%d\"...\n", e);
        printf("L中的元素为：L=");
        ListTraverse_Sq(L, PrintElem);
        printf("\n\n");
    }
    PressEnter
    printf("06.函数 GetElem_Sq 测试...\n");
    {
        GetElem_Sq(L, 4, &e);
        printf("L中第4个位置的元素为\"%d\" \n", e);
        printf("\n");

    }
    printf("07.函数 LocateElem_Sq 测试...\n");
    {
        i = LocateElem_Sq(L, 7, CmpGreater);
        printf("L中第一个元素值大于\"7\" 的元素位置为%d \n", i);
        printf("\n");
    }
    PressEnter
    printf("08.函数PriorElem_Sq测试...\n");
    {
        PriorElem_Sq(L, 6, &e);
        printf("元素\"6\"的前驱为\"%d\" \n", e);
        printf("\n");
    }
    PressEnter
    printf("09.函数 NextElem_Sq 测试...\n");
    {
        NextElem_Sq(L, 6, &e);
        printf("元素\"6\" 的元素后继为\"%d\" \n", e);
        printf("\n");
    }
    PressEnter
    printf("02.函数ClearList_Sq 测试...\n");
    {
        printf("清空L前：");
        ListEmpty_Sq(L) ? printf("L为空！！\n") : printf("L不为空！\n");
        ClearList_Sq(&L);
        printf("清空L后：");
        ListEmpty_Sq(L) ? printf("L为空！！\n") : printf("L不为空！\n");
        printf("\n");
    }
    PressEnter
    printf("03.函数 DestroyList_Sq测试...\n");
    {
        printf("销毁L前：");
        L.elem ? printf("L存在！\n") : printf("L不存在！！\n");
        DestroyList_Sq(&L);
        printf("销毁L后：");
        L.elem ? printf("L存在！\n") : printf("L不存在！！\n");
        printf("\n");
    }
    PressEnter
    return 0;
}

Status CmpGreater(LElemType_Sq e, LElemType_Sq data) {
    return data > e ? TRUE : FALSE;
}

void PrintElem(LElemType_Sq e) {
    printf("%d ", e);
}
