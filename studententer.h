#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define TRUE 1			//真
#define FALSE 0			//假
//constexpr auto OK = 1;	        //通过;
#define OK 1            //通过
#define ERROR 0		    //错误
#define INFEASIBLE -1	//不可行
#define OVERFLOW -2		//堆栈上溢
#define UNDERFLOW -3	//堆栈下溢

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

//登陆界面
extern void func();

//初始化头节点
extern Status InitList(LinkList* L);

//尾插法输入学生信息
extern Status create_inf(LinkList L);

//显示学生信息
extern Status printform(LinkList L);

//根据学号修改学生信息
extern Status num_to_change(LinkList L);

//根据学号删除学生信息
extern Status num_to_delete(LinkList L);

//根据姓名查找学生信息
extern Status name_to_inf(LinkList L);

//根据学号查找学生信息
extern Status num_to_inf(LinkList L);

//按照成绩升序排序
extern Status ascending_sort(LinkList L, int k);

//求表长
extern int Length_form(LinkList L);
