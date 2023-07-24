#include"studententer.h"

int main()
{
	func();
	int choice;
	choice = -1;

	LinkList L;
	InitList(&L);
	while (1)
	{
		printf("请输入选择功能的选项：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0:
		{
			printf("##########0.创建学生表################\n");
			create_inf(L);
			break;
		}
		case 1:
		{
			printf("##########1.显示学生表################\n");
			printform(L);
			break;
		}
		case 2:
		{
			printf("##########2.修改学生信息##############\n");
			num_to_change(L);
			//在这里输入Num得用指针，不然传不过去？
			break;
		}
		case 3:
		{
			printf("##########3.删除学生信息##############\n");
			num_to_delete(L);
			printf("删除后现在的学生表为");
			printform(L);
			break;
		}
		case 4:
		{
			printf("##########4.查找学生信息##############\n");
			int z;

			printf("1.通过姓名查找      2.通过学号查找\n");
			scanf_s("%d", &z);
			if (z == 1)
			{
				printf("请输入想要查询的学生的姓名：\n");
				name_to_inf(L);

			}
			else if (z == 2)
			{
				printf("请输入想要查询的学生的学号：\n");
				num_to_inf(L);

			}
			else if (z != 1 && z != 2)
			{
				printf("选项输入错误！\n");
			}
			break;
		}
		case 5:
		{
			printf("##########5.按成绩升序排序############\n");
			int k;
			k = Length_form(L);
			printf("表长为%d\n", k);
			
			ascending_sort(L, k);
			printform(L);
			break;
		}
		default:
		{
			printf("输入选项错误，请重新输入！");
			break;
		}
		}
	}
	return 0;
}


