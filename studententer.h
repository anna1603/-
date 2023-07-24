#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define TRUE 1			//��
#define FALSE 0			//��
//constexpr auto OK = 1;	        //ͨ��;
#define OK 1            //ͨ��
#define ERROR 0		    //����
#define INFEASIBLE -1	//������
#define OVERFLOW -2		//��ջ����
#define UNDERFLOW -3	//��ջ����

typedef char Status;
typedef struct
{
	char name[20];
	int num;
	char gender[20];
	int age;
	char major[20];
	char  contact_way[20];
	float score;
}stu;
typedef struct LinkNode
{
	stu data;
	struct LinkNode* next;
}LNode;
typedef LNode* LinkList;

//��½����
extern void func();

//��ʼ��ͷ�ڵ�
extern Status InitList(LinkList* L);

//β�巨����ѧ����Ϣ
extern Status create_inf(LinkList L);

//��ʾѧ����Ϣ
extern Status printform(LinkList L);

//����ѧ���޸�ѧ����Ϣ
extern Status num_to_change(LinkList L);

//����ѧ��ɾ��ѧ����Ϣ
extern Status num_to_delete(LinkList L);

//������������ѧ����Ϣ
extern Status name_to_inf(LinkList L);

//����ѧ�Ų���ѧ����Ϣ
extern Status num_to_inf(LinkList L);

//���ճɼ���������
extern Status ascending_sort(LinkList L, int k);

//���
extern int Length_form(LinkList L);
