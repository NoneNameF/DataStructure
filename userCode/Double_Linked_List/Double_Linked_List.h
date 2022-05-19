#pragma once

#define Success 0
#define Fail -1

typedef struct {
	int ID;
	char name[10];
} LData;

typedef struct {
	LData Data;
	struct LNode* prior;
	struct LNode* next;
} LNode, List;

/******************************************************************/
LNode* List_init(void);
/*
* 函数名称：双向链表初始化函数
* 输出：双向链表是否建立并初始化成功
*/
int List_Insert(LData data, List* list, int posotion);
/*
* 函数名称：双向链表插入函数
* 输入：要插入的数据
		插入的双向链表
		插入的位置
* 输出：是否插入成功
*/
int List_Delete(List* list, int position);
/*
* 函数名称：双向链表删除函数
* 输入：要操作的双向链表
		要删除的位置
* 输出：是否删除成功
*/
int GetElemByPosition(List* list, int position, LData* data);
/*
* 函数名称：根据标号寻找结点
* 输入：要查找的双向链表
		位置标号
		数据存放的地址
* 输出：是否成功
*/
int GetElemByData(List* list, LData data);
/*
* 函数名称：根据数据查找
* 输入：要操作的双向链表
*		查找的数据
* 输出：结点数据的位次
*/
void DestroyList(List* list);
/*
* 函数名称：线性表销毁函数
* 输入：要销毁的线性表
* 输出：是否成功销毁
*/
