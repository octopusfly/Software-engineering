/********************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                    */
/* FILE NAME                    : menu.c                            */
/* PRINCIPAL AUTHOR             : ZhangYufei                        */
/* SUBSYSTEM NAME               : menu                              */
/* MODULE NAME                  : menu                              */
/* LANGUAGE                     : C                                 */
/* TARGET ENVIRONMENT           : ANY                               */
/* DATE OF FIRST RELEASE        : 2014/09/08                        */
/* DESCRIPTION                  : This is a menu program.           */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by ZhangYufei, 2014/09/08
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COMM_NUM 10
#define COMM_LEN 20
#define DESC_LEN 100
 
typedef struct DataNode 
{
     char command[COMM_LEN];
     char desc[DESC_LEN];
     struct DataNode *next;
} tDataNode;

char names[COMM_NUM][COMM_LEN] = 
{ 
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten"
};

/* initiate the linklist */
tDataNode* init(void);

/* compare the input with the commands in the list */ 
int check(const char *str1, const char *str2);

/* start the menu, asking user to type */
void startMenu(tDataNode *head);

int main(void)
{
    tDataNode *head = init();
    startMenu(head);
    return 0;
}

tDataNode* init(void) 
{
    tDataNode *head = NULL;
    int i;
    for(i = 0; i < COMM_NUM; i++) 
    {
        tDataNode *p = (tDataNode*) malloc(sizeof(tDataNode));
        char strDesc[DESC_LEN];
        snprintf(strDesc, DESC_LEN, "This is No.%d command.\n", i + 1);
        strcpy(p -> command, names[i]);
        strcpy(p -> desc, strDesc);
        p -> next = head;
        head = p;
        printf("%s", p -> desc);
    }
    return head;
}

void startMenu(tDataNode *head)
{
    printf("Type your command please: \n");
    char input[COMM_LEN];
    while(scanf("%s", input)) 
    {
        tDataNode *p = head;
        while(p != NULL) 
        {
            if(check(p -> command, input))
            {
                printf("%s", p -> desc);
                break;
            } 
            else
            {
                p = p -> next;
            }
        }
        if(p == NULL)
            printf("You've typed the wrong command!!\n");
    }
}

int check(const char *str1, const char *str2) 
{
    return strcmp(str1, str2) == 0;
}
