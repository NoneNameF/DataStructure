#include "linear_list.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int List_init(List* list, int Length)
{
	list->MaxLength = Length;
	list->Length = 0;
	list->Data = (LData*)malloc(sizeof(LData) * Length);
	if (list->Data != NULL) return Success;
	else return Fail;
}

int List_Insert(LData data, List* list, int position)
{
	if (position<0 || position>list->Length || position >= list->MaxLength) return Fail;
	else {
		for (int i = list->Length; i >= position; i--)
		{
			list->Data[i + 1] = list->Data[i];
		}
		list->Data[position] = data;
		list->Length++;
		return Success;
	}
}

int List_Delete(List* list, int position)
{
	if (position<0 || position>list->Length) return Fail;
	else {
		for (int i = position; i < list->Length; i++)
		{
			list->Data[i] = list->Data[i + 1];
		}
		list->Length--;
		return Success;
	}
}

int GetElemByPosition(List* list, int position, LData* data)
{
	if (position < 0 || position > list->Length - 1) return Fail;
	else {
		*data = (list->Data[position]);
		return Success;
	}
}

int GetElemByData(List* list, LData data)
{
	for (int i = 0; i <= list->Length; i++)
	{
		if (list->Data[i].ID = data.ID) {
			if (strcmp(list->Data[i].name, data.name) == 0) {
				return i;
			}
			else return -1;
		}
		else return -1;
	}
	return -1;
}

void DestroyList(List* List)
{
	free(List->Data);
}
