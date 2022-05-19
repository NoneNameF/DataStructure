#include "single_linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

LNode* List_init(void)
{
	LNode* node = (LNode*)malloc(sizeof(LNode));
	if (node != NULL) {
		node->next = NULL;
		return node;
	}
	else return NULL;
}

int List_Insert(LData data, List* list, int position) {
	int i = 1;
	LNode* node = list;
	while (i < position && node->next != NULL)
	{
		node = node->next;
		i++;
	}//到达要插入的结点的前一个结点
	if (i < position) return Fail;
	LNode* NewNode = (LNode*)malloc(sizeof(LNode));
	if (NewNode != NULL)
	{
		NewNode->next = NULL;
		memcpy(&(NewNode->Data), &data, sizeof(data));
		NewNode->next = node->next;
		node->next = NewNode;
		return Success;
	}
	else return Fail;
}

int List_Delete(List* list, int position) {
	int i = 1;
	LNode* node = list;
	while (i < position && node->next != NULL)
	{
		node = node->next;
		i++;
	}//到达要删除的结点的前一个结点
	if (i < position) return Fail;
	LNode* node2 = node->next;
	node->next = node2->next;
	free(node2);
	return Success;
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
