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
	printf("���ڳ���Ϊ%d\n", list.Length);

	Newdata.ID = 2;
	memcpy(&Newdata.name, &"dqc", sizeof("dqc"));
	List_Insert(Newdata, &list, 0);
	printf("���ڳ���Ϊ%d\n", list.Length);

	LData Newdata2;
	if (GetElemByPosition(&list, 0, &Newdata2) == Success)
	{
		printf("��ѯPosition:%d�ɹ�\n", 0);
		printf("%d\n%s\n", Newdata2.ID, Newdata2.name);
	}

	if (GetElemByPosition(&list, 1, &Newdata2) == Success)
	{
		printf("��ѯPosition:%d�ɹ�\n", 1);
		printf("%d\n%s\n", Newdata2.ID, Newdata2.name);
	}

	if (List_Delete(&list, 0) == Success)printf("ɾ���ɹ�\n");
	else printf("ɾ��ʧ��\n");
	printf("���ڳ���Ϊ%d\n", list.Length);

	if (GetElemByPosition(&list, 0, &Newdata2) == Success)
	{
		printf("��ѯPosition:0�ɹ�\n");
		printf("%d\n%s\n", Newdata2.ID, Newdata2.name);
	}
	else printf("��ѯPosition:0ʧ��\n");

	if (GetElemByPosition(&list, 1, &Newdata2) == Success)
	{
		printf("��ѯPosition:1�ɹ�\n");
		printf("%d\n%s\n", Newdata2.ID, Newdata2.name);
	}
	else printf("��ѯPosition:1ʧ��\n");

	Newdata.ID = 1;
	memcpy(&Newdata.name, &"cms", sizeof("cms"));
	int position = GetElemByData(&list, Newdata);
	if (position != -1) printf("��ѯ�ɹ� λ����%d\n", position);
	else printf("��ѯʧ��\n");

	DestroyList(&list);
	printf("%d", list.Data[0].ID);
}
