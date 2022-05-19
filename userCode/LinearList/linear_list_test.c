#include"linear_list.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linear_list_test.h"

void linear_list_test(void) {
	List list;
	List_init(&list, 10);

	LData Newdata;
	Newdata.ID = 1;
	memcpy(&Newdata.name, &"cms", sizeof("cms"));
	List_Insert(Newdata, &list, 0);
	printf("现在长度为%d\n", list.Length);

	Newdata.ID = 2;
	memcpy(&Newdata.name, &"dqc", sizeof("dqc"));
	List_Insert(Newdata, &list, 0);
	printf("现在长度为%d\n", list.Length);

	LData Newdata2;
	if (GetElemByPosition(&list, 0, &Newdata2) == Success)
	{
		printf("查询Position:%d成功\n", 0);
		printf("%d\n%s\n", Newdata2.ID, Newdata2.name);
	}

	if (GetElemByPosition(&list, 1, &Newdata2) == Success)
	{
		printf("查询Position:%d成功\n", 1);
		printf("%d\n%s\n", Newdata2.ID, Newdata2.name);
	}

	if (List_Delete(&list, 0) == Success)printf("删除成功\n");
	else printf("删除失败\n");
	printf("现在长度为%d\n", list.Length);

	if (GetElemByPosition(&list, 0, &Newdata2) == Success)
	{
		printf("查询Position:0成功\n");
		printf("%d\n%s\n", Newdata2.ID, Newdata2.name);
	}
	else printf("查询Position:0失败\n");

	if (GetElemByPosition(&list, 1, &Newdata2) == Success)
	{
		printf("查询Position:1成功\n");
		printf("%d\n%s\n", Newdata2.ID, Newdata2.name);
	}
	else printf("查询Position:1失败\n");

	Newdata.ID = 1;
	memcpy(&Newdata.name, &"cms", sizeof("cms"));
	int position = GetElemByData(&list, Newdata);
	if (position != -1) printf("查询成功 位置在%d\n", position);
	else printf("查询失败\n");

	DestroyList(&list);
	printf("%d", list.Data[0].ID);
}
