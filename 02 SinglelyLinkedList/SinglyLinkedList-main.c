//
// Created by syl on 2020/9/9.
//
#include <stdio.h>
#include "SinglyLinkedList.c"
/*����ԭ��*/
Status CmpGreater(LElemType_L e,LElemType_L data);//�ж�data�Ƿ����e����data����e������TRUE
void PrintElem(LElemType_L e); //���Ժ�������ӡ����
int main(int argc,char **argv){
    LinkList L;
    int i;
    LElemType_L e;
    printf("01.����InitLIst_L ����...\n");
    {
        printf("��ʼ��������L ...\n");
        InitList_L(&L);
        printf("\n");
    }
    PressEnter
    printf("04.����ListEmpty_L ����...\n");
    {
        ListEmpty_L(L)?printf("L Ϊ�գ���\n"):printf("L ��Ϊ�գ�\n");
        printf("\n");
    }
    PressEnter
    printf("10.���� ListInsert_L ����...\n");
    {
        for ( i = 1; i <=6 ; ++i) {
            printf("��L��%d��λ�ò���\"%d\"...\n ", i, 2 * i);
            ListInsert_L(L, i, 2 * i);

        }
        printf("\n");
    }
    PressEnter
    printf("12���� ListTraverse_L ����...\n");
    {
        printf("L�е�Ԫ��Ϊ��L=");
        ListTraverse_L(L, PrintElem);
        printf("\n\n");
    }
    PressEnter
    printf("05.����ListLength_L����..\n");
    {
        printf("L�ĳ���Ϊ%d \n", ListLength_L(L));
        printf("\n");
    }
    PressEnter
    printf("11.����GetElem_L ����...\n");
    {
        GetElem_L(L, 4, &e);
        printf("L�е�4��λ�õ�Ԫ��Ϊ\"%d\" \n", e);
        printf("\n");
    }
    PressEnter
    printf("08����PriorElem_L����...\n");
    {
        PriorElem_L(L, 6, &e);
        printf("Ԫ��\" 6\" �ĺ��Ϊ\"%d\" \n", e);
        printf("\n");
    }
    PressEnter
    printf("13.���� CreateList_HL����...\n");
    {
        FILE *fp;
        LinkList L;
        printf("ͷ�巨����������L=");
        fp = fopen("TestData_HL.txt", "r");
        CreatList_HL(fp, &L, 5);
        fclose(fp);
        ListTraverse_L(L, PrintElem);
        printf("\n\n");
    }
    PressEnter
    printf("14����CreateList_TL ����...\n");
    {
        FILE *fp;
        LinkList L;
        printf("β�巨����������L=");
        fp = fopen("TestData_TL.txt", "r");
        CreateList_TL(fp, &L, 5);
        fclose(fp);
        ListTraverse_L(L, PrintElem);
        printf("\n\n");
    }
    PressEnter;
    return 0;


}
Status CmpGreater(LElemType_L e,LElemType_L data){
    return data>e?TRUE:FALSE;
}
void PrintElem(LElemType_L e){
    printf("%d ",e);
}

