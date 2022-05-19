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
* �������ƣ�˫�������ʼ������
* �����˫�������Ƿ�������ʼ���ɹ�
*/
int List_Insert(LData data, List* list, int posotion);
/*
* �������ƣ�˫��������뺯��
* ���룺Ҫ���������
		�����˫������
		�����λ��
* ������Ƿ����ɹ�
*/
int List_Delete(List* list, int position);
/*
* �������ƣ�˫������ɾ������
* ���룺Ҫ������˫������
		Ҫɾ����λ��
* ������Ƿ�ɾ���ɹ�
*/
int GetElemByPosition(List* list, int position, LData* data);
/*
* �������ƣ����ݱ��Ѱ�ҽ��
* ���룺Ҫ���ҵ�˫������
		λ�ñ��
		���ݴ�ŵĵ�ַ
* ������Ƿ�ɹ�
*/
int GetElemByData(List* list, LData data);
/*
* �������ƣ��������ݲ���
* ���룺Ҫ������˫������
*		���ҵ�����
* �����������ݵ�λ��
*/
void DestroyList(List* list);
/*
* �������ƣ����Ա����ٺ���
* ���룺Ҫ���ٵ����Ա�
* ������Ƿ�ɹ�����
*/
