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
    printf("01.����InitList_Sq ����...\n");
    {
        printf("��ʼ��˳���L ...\n");
        InitList_Sq(&L);
        printf("\n");
    }
    PressEnter
    printf("04.���� ListEmpty_Sq ����...\n");
    {
        ListEmpty_Sq(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ�\n");
        printf("\n");
    }
    PressEnter
    printf("10.����ListInsert_Sq ����...\n");
    {
        for (int i = 1; i <= 6; ++i) {
            printf("��Ϊʾ������L��%d��λ�ò��� \"%d\"...\n", i, 2 * i);
            ListInsert_Sq(&L, i, 2 * i);

        }
        printf("\n");
    }
    PressEnter
    printf("12.���� ListTraverse_Sq ����...\n");
    {
        printf("L�е�Ԫ��Ϊ��L=");
        ListTraverse_Sq(L, PrintElem);
        printf("\n\n");
    }
    PressEnter

    printf("05���� ListLength_Sq ����...\n");
    {
        i = ListLength_Sq(L);
        printf("L�ĳ���Ϊ%d \n", i);

    }
    PressEnter
    printf("11.���� ListDelete_Sq ����...\n");
    {
        ListDelete_Sq(&L, 6, &e);
        printf("ɾ��L�е�6��Ԫ��\"%d\"...\n", e);
        printf("L�е�Ԫ��Ϊ��L=");
        ListTraverse_Sq(L, PrintElem);
        printf("\n\n");
    }
    PressEnter
    printf("06.���� GetElem_Sq ����...\n");
    {
        GetElem_Sq(L, 4, &e);
        printf("L�е�4��λ�õ�Ԫ��Ϊ\"%d\" \n", e);
        printf("\n");

    }
    printf("07.���� LocateElem_Sq ����...\n");
    {
        i = LocateElem_Sq(L, 7, CmpGreater);
        printf("L�е�һ��Ԫ��ֵ����\"7\" ��Ԫ��λ��Ϊ%d \n", i);
        printf("\n");
    }
    PressEnter
    printf("08.����PriorElem_Sq����...\n");
    {
        PriorElem_Sq(L, 6, &e);
        printf("Ԫ��\"6\"��ǰ��Ϊ\"%d\" \n", e);
        printf("\n");
    }
    PressEnter
    printf("09.���� NextElem_Sq ����...\n");
    {
        NextElem_Sq(L, 6, &e);
        printf("Ԫ��\"6\" ��Ԫ�غ��Ϊ\"%d\" \n", e);
        printf("\n");
    }
    PressEnter
    printf("02.����ClearList_Sq ����...\n");
    {
        printf("���Lǰ��");
        ListEmpty_Sq(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ�\n");
        ClearList_Sq(&L);
        printf("���L��");
        ListEmpty_Sq(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ�\n");
        printf("\n");
    }
    PressEnter
    printf("03.���� DestroyList_Sq����...\n");
    {
        printf("����Lǰ��");
        L.elem ? printf("L���ڣ�\n") : printf("L�����ڣ���\n");
        DestroyList_Sq(&L);
        printf("����L��");
        L.elem ? printf("L���ڣ�\n") : printf("L�����ڣ���\n");
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
