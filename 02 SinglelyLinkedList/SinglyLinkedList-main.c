//
// Created by syl on 2020/9/9.
//
#include <stdio.h>
#include "SinglyLinkedList.c"
/*函数原型*/
Status CmpGreater(LElemType_L e,LElemType_L data);//判断data是否大于e，若data大于e，返回TRUE
void PrintElem(LElemType_L e); //测试函数，打印整型
int main(int argc,char **argv){
    LinkList L;
    int i;
    LElemType_L e;
    printf("01.函数InitLIst_L 测试...\n");
    {
        printf("初始化单链表L ...\n");
        InitList_L(&L);
        printf("\n");
    }
    PressEnter
    printf("04.函数ListEmpty_L 测试...\n");
    {
        ListEmpty_L(L)?printf("L 为空！！\n"):printf("L 不为空！\n");
        printf("\n");
    }
    PressEnter
    printf("10.函数 ListInsert_L 测试...\n");
    {
        for ( i = 1; i <=6 ; ++i) {
            printf("在L第%d个位置插入\"%d\"...\n ", i, 2 * i);
            ListInsert_L(L, i, 2 * i);

        }
        printf("\n");
    }
    PressEnter
    printf("12函数 ListTraverse_L 测试...\n");
    {
        printf("L中的元素为：L=");
        ListTraverse_L(L, PrintElem);
        printf("\n\n");
    }
    PressEnter
    printf("05.函数ListLength_L测试..\n");
    {
        printf("L的长度为%d \n", ListLength_L(L));
        printf("\n");
    }
    PressEnter
    printf("11.函数GetElem_L 测试...\n");
    {
        GetElem_L(L, 4, &e);
        printf("L中第4个位置的元素为\"%d\" \n", e);
        printf("\n");
    }
    PressEnter
    printf("08函数PriorElem_L测试...\n");
    {
        PriorElem_L(L, 6, &e);
        printf("元素\" 6\" 的后继为\"%d\" \n", e);
        printf("\n");
    }
    PressEnter
    printf("13.函数 CreateList_HL测试...\n");
    {
        FILE *fp;
        LinkList L;
        printf("头插法建立单链表L=");
        fp = fopen("TestData_HL.txt", "r");
        CreatList_HL(fp, &L, 5);
        fclose(fp);
        ListTraverse_L(L, PrintElem);
        printf("\n\n");
    }
    PressEnter
    printf("14函数CreateList_TL 测试...\n");
    {
        FILE *fp;
        LinkList L;
        printf("尾插法建立单链表L=");
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

