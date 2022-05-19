#include"Double_Linked_List.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

LNode* List_init(void) {
	LNode* node = (LNode*)malloc(sizeof(LNode));
	if (node != NULL) {
		node->next = NULL;
		return node;
	}
	else return NULL;
}
int List_Insert(LData data, List* list, int position) {
	int i = 1;
	LNode* PriorNode = list;
	while (i < position && PriorNode->next != NULL)
	{
		PriorNode = PriorNode->next;
		i++;
	}//到达要插入的位置的前一个结点
	if (i < position) return Fail;
	LNode* NewNode = (LNode*)malloc(sizeof(LNode));
	if (NewNode != NULL)
	{
		NewNode->next = NULL;
		memcpy(&(NewNode->Data), &data, sizeof(data));
		//还需要判断一下是不是加在最后一个结点上
		if (PriorNode->next == NULL)
		{
			PriorNode->next = NewNode;
			NewNode->prior = PriorNode;
			return Success;
		}
		else
		{
			LNode* NextNode = PriorNode->next;
			//现在链表顺序是node node->next
			PriorNode->next = NewNode;
			NewNode->prior = PriorNode;
			NewNode->next = NextNode;
			NextNode->prior = NewNode;
			return Success;
		}
	}
	else return Fail;
}

int List_Delete(List* list, int position) {
	int i = 1;
	LNode* PriorNode = list;
	while (i < position && PriorNode->next != NULL)
	{
		PriorNode = PriorNode->next;
		i++;
	}//到达要删除的位置的前一个结点
	if (i < position) return Fail;

	if (PriorNode->next == NULL)return Fail;
	else
	{
		LNode* DeleteNode = PriorNode->next;
		PriorNode->next = DeleteNode->next;
		free(DeleteNode);
		return Success;
	}
}

int GetElemByPosition(List* list, int position, LData* data) {
	LNode* node = list;
	int i = 0;
	while (i < position && node->next != NULL)
	{
		node = node->next;
		i++;
	}
	if (i == position)
	{
		*data = node->Data;
		return Success;
	}
	else return Fail;
}

int GetElemByData(List* list, LData data) {
	LNode* node = list;
	while (node->next != NULL)
	{
		node = node->next;
		if (node->Data.ID == data.ID && strcmp(node->Data.name, data.name) == 0) return Success;
	}
	return Fail;
}

void DestroyList(List* list) {
	LNode* node = list;
	LNode* FreeNode;
	if (node != NULL)
	{
		while (node != NULL)
		{
			printf("not null");
			FreeNode = node;
			node = node->next;
			free(FreeNode);
		}
		return Success;
	}
	else return Fail;
}