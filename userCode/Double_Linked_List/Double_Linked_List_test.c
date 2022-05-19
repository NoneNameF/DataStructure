#include"Double_Linked_List_test.h"
#include"Double_Linked_List.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void Double_Linked_List_test(void) {
	List* list = List_init();
	if (list == NULL)printf("创建链表失败\n");

	LData data;
	data.ID = 1;
	memcpy(data.name, "cms", sizeof("cms"));
	List_Insert(data, list, 1);

	data.ID = 3;
	memcpy(data.name, "sxa", sizeof("sxa"));
	List_Insert(data, list, 2);

	data.ID = 2;
	memcpy(data.name, "dqc", sizeof("dqc"));
	List_Insert(data, list, 2);



	List_Delete(list, 2);

	LData data2;
	if (GetElemByPosition(list, 1, &data2) == Success)
	{
		printf("根据序号查询成功信息：%d  %s\n", data2.ID, data2.name);
	}
	else printf("根据序号查询错误\n");

	if (GetElemByPosition(list, 2, &data2) == Success)
	{
		printf("根据序号查询成功信息：%d  %s\n", data2.ID, data2.name);
	}
	else printf("根据序号查询错误\n");

	data2.ID = 1;
	memcpy(data2.name, "cms", sizeof("dqc"));
	if (GetElemByData(list, data2) == Success)
	{
		printf("根据数据查询成功 信息：%d  %s\n", data2.ID, data2.name);
	}
	else printf("根据数据查询错误\n");

	DestroyList(list);

}