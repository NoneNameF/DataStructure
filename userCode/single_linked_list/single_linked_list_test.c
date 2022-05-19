#include"single_linked_list_test.h"
#include"single_linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void single_linked_list_test() {
	List* list = List_init();
	if (list == NULL)printf("创建链表失败\n");

	LData data;
	data.ID = 1;
	memcpy(data.name, "cms", sizeof("cms"));
	List_Insert(data, list, 1);

	data.ID = 2;
	memcpy(data.name, "dqc", sizeof("dqc"));
	List_Insert(data, list, 2);

	List_Delete(list, 1);

	LData data2;
	if (GetElemByPosition(list, 1, &data2) == Success)
	{
		printf("根据序号查询成功信息：%d  %s\n", data2.ID, data2.name);
	}
	else printf("根据序号查询错误\n");


	data2.ID = 2;
	memcpy(data2.name, "dqc", sizeof("dqc"));
	if (GetElemByData(list, data2) == Success)
	{
		printf("根据数据查询成功 信息：%d  %s\n", data2.ID, data2.name);
	}
	else printf("根据数据查询错误\n");

	print_all(list);

	DestroyList(list);
}

void print_all(List* list) {
	if (list->next != NULL)
	{
		LNode* node = list;
		while (node->next != NULL)
		{
			node = node->next;
			printf("信息：%d  %s\n", node->Data.ID, node->Data.name);
		}
	}
	else printf("链表为空\n");
}