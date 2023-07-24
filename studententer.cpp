#include"studententer.h"
//登陆界面
void func()
{
	printf("##########学生信息管理系统############\n");
	printf("##########0.创建学生表,添加信息#######\n");
	printf("##########1.显示学生表################\n");
	printf("##########2.修改学生信息##############\n");
	printf("##########3.删除学生信息##############\n");
	printf("##########4.查找学生信息##############\n");
	printf("##########5.按成绩升序排序############\n");
}

//初始化头节点
Status InitList(LinkList* L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
	{
		exit(OVERFLOW);
	}
	(*L)->next = NULL;

	return OK;
}

//尾插法来创建学生表
Status create_inf(LinkList L)
{
	int n, i;
	LNode* p;
	LNode* q;
	printf("输入学生人数：");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));//创建节点这一步要放在循环里面，不然一直在p上覆盖操作，链表长度没有增加。
		if (p == NULL)
		{
			exit(OVERFLOW);
		}
		p->next = NULL;
		q = L;//头节点
		while (q->next != NULL)//q往后挪到尾节点
		{
			q = q->next;
		}
		q->next = p;//从队尾加入
		printf("请输入第%d个学生的信息：\n", i + 1);
		printf("请输入学生的姓名：");
		scanf_s("%s", p->data.name, 20);//scanf_s是安全的scanf，有三个参数，最后一个参数是与第二个参数大小相关的整形。


		while ((0 <= p->data.name[i]) && (p->data.name[i] <= 127))
		{
			printf("请输入中文！\n");
			printf("请重新输入学生的姓名：");
			scanf_s("%s", &p->data.name, 20);
		}

		printf("请输入学生的学号：");
		scanf_s("%d", &p->data.num);

		//while (p->data.num == q->data.num)
		//{
		//	printf("学号重复！\n");
		//	printf("请重新输入学生的学号：");
		//	scanf_s("%d", &p->data.num);
		//}
		LinkList w;
		w = L->next;
		while (w != p)
		{
			if (w->data.num == p->data.num)
			{
				printf("学号重复！\n");
				printf("请重新输入学生的学号：");
				scanf_s("%d", &p->data.num);
			}
			else
			{
				w = w->next;
			}
		}




		printf("请输入学生的性别：");
		scanf_s("%s", p->data.gender, 20);
		while ((strcmp(p->data.gender, "男") && strcmp(p->data.gender, "女")))//strcmp用来比较字符串的大小，相等时等于0，不相等时为正数或者负数。
		{
			printf("性别输入错误！只有男与女。\n");
			printf("请重新输入学生的性别：");
			scanf_s("%s", p->data.gender, 20);
		}
		printf("请输入学生的年龄：");
		scanf_s("%d", &p->data.age);
		while (p->data.age <= 0 || p->data.age >= 100)
		{
			printf("输入年龄错误！请输入0至100的整数。\n");
			printf("请重新输入学生的年龄：");
			scanf_s("%d", &p->data.age);
		}
		printf("请输入学生的专业：");
		scanf_s("%s", p->data.major, 20);
		printf("请输入学生的联系方式：");
		scanf_s("%s", p->data.contact_way, 20);
		printf("请输入学生的成绩：");
		scanf_s("%f", &p->data.score);
	}
    return OK;
}

//显示学生信息
Status printform(LinkList L)
{
	LinkList q = L->next;//q为首元节点
	while (q)
	{
		printf("姓名：%s  ", q->data.name);
		printf("学号：%d  ", q->data.num);
		printf("性别：%s  ", q->data.gender);
		printf("年龄：%d  ", q->data.age);
		printf("专业：%s  ", q->data.major);
		printf("联系方式：%s  ", q->data.contact_way);
		printf("成绩：%f  ", q->data.score);
		printf("\n");
		q = q->next;//q2
	}
	return OK;
}


//根据学生学号修改学生信息（不能修改最后一个节点的信息）
Status num_to_change(LinkList L)
{
	printf("请输入想要修改同学信息中的学号\n");
	int Num;
	scanf_s("%d", &Num);
	LinkList p = L;//从头节点开始找起
	printf("部分修改输入1，全部修改输入2\n");
	int choice1;
	scanf_s("%d", &choice1);
	if (choice1 == 1)
	{
		//while (p->next != NULL)//第一个p->next为首元节点
		while (p)
		{
			if (p->data.num == Num)
			{
				printf("姓名：%s  ", p->data.name);
				printf("学号：%d  ", p->data.num);
				printf("性别：%s  ", p->data.gender);
				printf("年龄：%d  ", p->data.age);
				printf("专业：%s  ", p->data.major);
				printf("联系方式：%s  ", p->data.contact_way);
				printf("成绩：%f  ", p->data.score);
				printf("\n");
				int choice2;
				choice2 = -1;
				printf("请输入想要修改的信息选项{0.姓名1.学号2.性别3.年龄4.专业5.联系方式6.成绩}：");
				scanf_s("%d", &choice2);
				switch (choice2)
				{
				case 0:
				{
					printf("请输入学生的姓名：");
					scanf_s("%s", p->data.name, 20);
					int i = 0;
					while ((0 <= p->data.name[i]) && (p->data.name[i] <= 127))
					{
						printf("请输入中文！\n");
						printf("请重新输入学生的姓名：");
						scanf_s("%s", &p->data.name, 20);
					}

					return OK;
					break;
				}
				case 1:
				{
					printf("请输入学生的学号：");
					scanf_s("%d", &p->data.num);

					return OK;
					break;
				}
				case 2:
				{
					printf("请输入学生的性别：");
					scanf_s("%s", p->data.gender, 20);
					while ((strcmp(p->data.gender, "男") && strcmp(p->data.gender, "女")))//strcmp用来比较字符串的大小，相等时等于0，不相等时为正数或者负数。
					{
						printf("性别输入错误！只有男与女。\n");
						printf("请重新输入学生的性别：");
						scanf_s("%s", p->data.gender, 20);
					}
					return OK;
					break;
				}
				case 3:
				{
					printf("请输入学生的年龄：");
					scanf_s("%d", &p->data.age);
					while (p->data.age < 0 || p->data.age>100)
					{
						printf("输入年龄错误！请输入0至100的整数。\n");
						printf("请重新输入学生的年龄：");
						scanf_s("%d", &p->data.age);
					}
					return OK;
					break;
				}
				case 4:
				{
					printf("请输入学生的专业：");
					scanf_s("%s", p->data.major, 20);
					return OK;
					break;
				}
				case 5:
				{
					printf("请输入学生的联系方式：");
					scanf_s("%s", p->data.contact_way, 20);
					return OK;
					break;
				}
				case 6:
				{
					printf("请输入学生的成绩：");
					scanf_s("%f", &p->data.score);
					return OK;
					break;
				}
				default:
				{
					printf("输入选项错误，请重新输入！");
					return ERROR;
					break;
				}
				}
			}
			else
			{
				p = p->next;
			}

		}
		while (p == NULL)
		{
			printf("学号输入错误！\n");
			return ERROR;
		}
	}
	if (choice1 == 2)
	{
		while (p->next != NULL)//第一个p->next为首元节点
		{
			if (p->data.num == Num)
			{
				printf("姓名：%s  ", p->data.name);
				printf("学号：%d  ", p->data.num);
				printf("性别：%s  ", p->data.gender);
				printf("年龄：%d  ", p->data.age);
				printf("专业：%s  ", p->data.major);
				printf("联系方式：%s  ", p->data.contact_way);
				printf("成绩：%f  ", p->data.score);
				printf("\n");
				printf("请重新输入该学生的信息\n");

				printf("请输入学生的姓名：");
				scanf_s("%s", p->data.name, 20);//scanf_s是安全的scanf，有三个参数，最后一个参数是与第二个参数大小相关的整形。
				int i = 0;
				while ((0 <= p->data.name[i]) && (p->data.name[i] <= 127))
				{
					printf("请输入中文！\n");
					printf("请重新输入学生的姓名：");
					scanf_s("%s", &p->data.name, 20);
				}
				printf("请输入学生的学号：");
				scanf_s("%d", &p->data.num);
				printf("请输入学生的性别：");
				scanf_s("%s", p->data.gender, 20);
				while ((strcmp(p->data.gender, "男") && strcmp(p->data.gender, "女")))//strcmp用来比较字符串的大小，相等时等于0，不相等时为正数或者负数。
				{
					printf("性别输入错误！只有男与女。\n");
					printf("请重新输入学生的性别：");
					scanf_s("%s", p->data.gender, 20);
				}
				printf("请输入学生的年龄：");
				scanf_s("%d", &p->data.age);
				while (p->data.age < 0 || p->data.age>100)
				{
					printf("输入年龄错误！请输入0至100的整数。\n");
					printf("请重新输入学生的年龄：");
					scanf_s("%d", &p->data.age);
				}
				printf("请输入学生的专业：");
				scanf_s("%s", p->data.major, 20);
				printf("请输入学生的联系方式：");
				scanf_s("%s", p->data.contact_way, 20);
				printf("请输入学生的成绩：");
				scanf_s("%f", &p->data.score);
				return OK;
			}
			else
			{
				p = p->next;//往后移继续寻找学号相同的节点
			}
		}

		while (p->next == NULL)//p为最后一个节点
		{
			if (p->data.num == Num)
			{
				printf("姓名：%s  ", p->data.name);
				printf("学号：%d  ", p->data.num);
				printf("性别：%s  ", p->data.gender);
				printf("年龄：%d  ", p->data.age);
				printf("专业：%s  ", p->data.major);
				printf("联系方式：%s  ", p->data.contact_way);
				printf("成绩：%f  ", p->data.score);
				printf("\n");
				printf("请重新输入该学生的信息\n");

				printf("请输入学生的姓名：");
				scanf_s("%s", p->data.name, 20);//scanf_s是安全的scanf，有三个参数，最后一个参数是与第二个参数大小相关的整形。
				int i = 0;
				while ((0 <= p->data.name[i]) && (p->data.name[i] <= 127))
				{
					printf("请输入中文！\n");
					printf("请重新输入学生的姓名：");
					scanf_s("%s", &p->data.name, 20);
				}
				printf("请输入学生的学号：");
				scanf_s("%d", &p->data.num);
				printf("请输入学生的性别：");
				scanf_s("%s", p->data.gender, 20);
				while ((strcmp(p->data.gender, "男") && strcmp(p->data.gender, "女")))//strcmp用来比较字符串的大小，相等时等于0，不相等时为正数或者负数。
				{
					printf("性别输入错误！只有男与女。\n");
					printf("请重新输入学生的性别：");
					scanf_s("%s", p->data.gender, 20);
				}
				printf("请输入学生的年龄：");
				scanf_s("%d", &p->data.age);
				while (p->data.age < 0 || p->data.age>100)
				{
					printf("输入年龄错误！请输入0至100的整数。\n");
					printf("请重新输入学生的年龄：");
					scanf_s("%d", &p->data.age);
				}
				printf("请输入学生的专业：");
				scanf_s("%s", p->data.major, 20);
				printf("请输入学生的联系方式：");
				scanf_s("%s", p->data.contact_way, 20);
				printf("请输入学生的成绩：");
				scanf_s("%f", &p->data.score);
				return OK;
			}
			else
			{
				printf("学号输入错误！\n");
				return ERROR;
			}
		}
	}
}



//根据学号删除学生信息
Status num_to_delete(LinkList L)
{
	int Num;
	printf("请输入想要删除的学生信息的学号：");
	scanf_s("%d", &Num);
	LinkList q = L->next; //q为首元节点
	LinkList p = L;       //p为头节点 L->p->q
	while (q != NULL)   //首元节点不为空
	{
		if (q->data.num == Num)
		{
			p->next = q->next;  //p指向q2
			free(q);  //释放q
			return OK;
		}
		else
		{
			p = q;//往后挪
			q = q->next;
		}


	}

	if (p->next == NULL)
	{
		printf("学号输入错误！\n");
		return ERROR;
	}

}

//根据姓名查找学生信息
Status name_to_inf(LinkList L)
{
	char name[20];
	printf("请输入需要查找学生的姓名：");
	scanf_s("%s", name, 20);
	LinkList p = L;//p为头节点


	while (p->next != NULL)
	{
		if (!strcmp(p->data.name, name))
		{
			printf("姓名：%s  ", p->data.name);
			printf("学号：%d  ", p->data.num);
			printf("性别：%s  ", p->data.gender);
			printf("年龄：%d  ", p->data.age);
			printf("专业：%s  ", p->data.major);
			printf("联系方式：%s  ", p->data.contact_way);
			printf("成绩：%f  ", p->data.score);
			printf("\n");
			printf("OK!");
			p = p->next;
			while (p)
			{

				if (!strcmp(p->data.name, name))
				{
					printf("姓名：%s  ", p->data.name);
					printf("学号：%d  ", p->data.num);
					printf("性别：%s  ", p->data.gender);
					printf("年龄：%d  ", p->data.age);
					printf("专业：%s  ", p->data.major);
					printf("联系方式：%s  ", p->data.contact_way);
					printf("成绩：%f  ", p->data.score);
					printf("\n");
					printf("OK!");
					return OK;
				}
				else
				{
					p = p->next;
				}
			}
			while (p == NULL)//否则直接退出程序
			{
				return OK;
			}

		}
		else
		{
			p = p->next;//从头结点开始往后找
		}

	}
	while (p->next == NULL)
	{
		if (!strcmp(p->data.name, name))
		{
			printf("姓名：%s  ", p->data.name);
			printf("学号：%d  ", p->data.num);
			printf("性别：%s  ", p->data.gender);
			printf("年龄：%d  ", p->data.age);
			printf("专业：%s  ", p->data.major);
			printf("联系方式：%s  ", p->data.contact_way);
			printf("成绩：%f  ", p->data.score);
			printf("\n");
			printf("OK!");
			return OK;
		}
		else
		{
			printf("姓名输入错误\n");
			return ERROR;
		}

	}

}


//根据学号查找学生信息
Status num_to_inf(LinkList L)
{
	int Num;
	printf("请输入需要查找学生的学号：");
	scanf_s("%d", &Num);
	LinkList p = L;//p为头节点
	while (p->next != NULL)
	{
		if (p->data.num == Num)
		{
			printf("姓名：%s  ", p->data.name);
			printf("学号：%d  ", p->data.num);
			printf("性别：%s  ", p->data.gender);
			printf("年龄：%d  ", p->data.age);
			printf("专业：%s  ", p->data.major);
			printf("联系方式：%s  ", p->data.contact_way);
			printf("成绩：%f  ", p->data.score);
			printf("\n");
			printf("OK!");
			return OK;
		}
		else
		{
			p = p->next;//从头结点开始往后找
		}

	}
	while (p->next == NULL)
	{
		if (p->data.num == Num)
		{
			printf("姓名：%s  ", p->data.name);
			printf("学号：%d  ", p->data.num);
			printf("性别：%s  ", p->data.gender);
			printf("年龄：%d  ", p->data.age);
			printf("专业：%s  ", p->data.major);
			printf("联系方式：%s  ", p->data.contact_way);
			printf("成绩：%f  ", p->data.score);
			printf("\n");
			printf("OK!");
			return OK;
		}
		else
		{
			printf("学号输入错误\n");
			return ERROR;
		}

	}

}

//按照成绩升序排序

Status ascending_sort(LinkList L, int k)
{
	int i, j;
	stu temp;
	LinkList p = L->next;

	for (i = 0; i < k - 1; i++)//冒泡
	{
		p = L->next;
		for (j = 0; j < k - i - 1; j++)
		{
			if (p->data.score > p->next->data.score)
			{
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;

			}
			p = p->next;

		}

	}
	return OK;
}
//求表长
int Length_form(LinkList L)
{
	LinkList p;
	int i;

	if (L)
	{
		i = 0;
		p = L->next;
		while (p)
		{
			i++;
			p = p->next;
		}
	}
	return i;

}