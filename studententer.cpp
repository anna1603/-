#include"studententer.h"
//��½����
void func()
{
	printf("##########ѧ����Ϣ����ϵͳ############\n");
	printf("##########0.����ѧ����,�����Ϣ#######\n");
	printf("##########1.��ʾѧ����################\n");
	printf("##########2.�޸�ѧ����Ϣ##############\n");
	printf("##########3.ɾ��ѧ����Ϣ##############\n");
	printf("##########4.����ѧ����Ϣ##############\n");
	printf("##########5.���ɼ���������############\n");
}

//��ʼ��ͷ�ڵ�
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

//β�巨������ѧ����
Status create_inf(LinkList L)
{
	int n, i;
	LNode* p;
	LNode* q;
	printf("����ѧ��������");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));//�����ڵ���һ��Ҫ����ѭ�����棬��Ȼһֱ��p�ϸ��ǲ�����������û�����ӡ�
		if (p == NULL)
		{
			exit(OVERFLOW);
		}
		p->next = NULL;
		q = L;//ͷ�ڵ�
		while (q->next != NULL)//q����Ų��β�ڵ�
		{
			q = q->next;
		}
		q->next = p;//�Ӷ�β����
		printf("�������%d��ѧ������Ϣ��\n", i + 1);
		printf("������ѧ����������");
		scanf_s("%s", p->data.name, 20);//scanf_s�ǰ�ȫ��scanf�����������������һ����������ڶ���������С��ص����Ρ�


		while ((0 <= p->data.name[i]) && (p->data.name[i] <= 127))
		{
			printf("���������ģ�\n");
			printf("����������ѧ����������");
			scanf_s("%s", &p->data.name, 20);
		}

		printf("������ѧ����ѧ�ţ�");
		scanf_s("%d", &p->data.num);

		//while (p->data.num == q->data.num)
		//{
		//	printf("ѧ���ظ���\n");
		//	printf("����������ѧ����ѧ�ţ�");
		//	scanf_s("%d", &p->data.num);
		//}
		LinkList w;
		w = L->next;
		while (w != p)
		{
			if (w->data.num == p->data.num)
			{
				printf("ѧ���ظ���\n");
				printf("����������ѧ����ѧ�ţ�");
				scanf_s("%d", &p->data.num);
			}
			else
			{
				w = w->next;
			}
		}




		printf("������ѧ�����Ա�");
		scanf_s("%s", p->data.gender, 20);
		while ((strcmp(p->data.gender, "��") && strcmp(p->data.gender, "Ů")))//strcmp�����Ƚ��ַ����Ĵ�С�����ʱ����0�������ʱΪ�������߸�����
		{
			printf("�Ա��������ֻ������Ů��\n");
			printf("����������ѧ�����Ա�");
			scanf_s("%s", p->data.gender, 20);
		}
		printf("������ѧ�������䣺");
		scanf_s("%d", &p->data.age);
		while (p->data.age <= 0 || p->data.age >= 100)
		{
			printf("�����������������0��100��������\n");
			printf("����������ѧ�������䣺");
			scanf_s("%d", &p->data.age);
		}
		printf("������ѧ����רҵ��");
		scanf_s("%s", p->data.major, 20);
		printf("������ѧ������ϵ��ʽ��");
		scanf_s("%s", p->data.contact_way, 20);
		printf("������ѧ���ĳɼ���");
		scanf_s("%f", &p->data.score);
	}
    return OK;
}

//��ʾѧ����Ϣ
Status printform(LinkList L)
{
	LinkList q = L->next;//qΪ��Ԫ�ڵ�
	while (q)
	{
		printf("������%s  ", q->data.name);
		printf("ѧ�ţ�%d  ", q->data.num);
		printf("�Ա�%s  ", q->data.gender);
		printf("���䣺%d  ", q->data.age);
		printf("רҵ��%s  ", q->data.major);
		printf("��ϵ��ʽ��%s  ", q->data.contact_way);
		printf("�ɼ���%f  ", q->data.score);
		printf("\n");
		q = q->next;//q2
	}
	return OK;
}


//����ѧ��ѧ���޸�ѧ����Ϣ�������޸����һ���ڵ����Ϣ��
Status num_to_change(LinkList L)
{
	printf("��������Ҫ�޸�ͬѧ��Ϣ�е�ѧ��\n");
	int Num;
	scanf_s("%d", &Num);
	LinkList p = L;//��ͷ�ڵ㿪ʼ����
	printf("�����޸�����1��ȫ���޸�����2\n");
	int choice1;
	scanf_s("%d", &choice1);
	if (choice1 == 1)
	{
		//while (p->next != NULL)//��һ��p->nextΪ��Ԫ�ڵ�
		while (p)
		{
			if (p->data.num == Num)
			{
				printf("������%s  ", p->data.name);
				printf("ѧ�ţ�%d  ", p->data.num);
				printf("�Ա�%s  ", p->data.gender);
				printf("���䣺%d  ", p->data.age);
				printf("רҵ��%s  ", p->data.major);
				printf("��ϵ��ʽ��%s  ", p->data.contact_way);
				printf("�ɼ���%f  ", p->data.score);
				printf("\n");
				int choice2;
				choice2 = -1;
				printf("��������Ҫ�޸ĵ���Ϣѡ��{0.����1.ѧ��2.�Ա�3.����4.רҵ5.��ϵ��ʽ6.�ɼ�}��");
				scanf_s("%d", &choice2);
				switch (choice2)
				{
				case 0:
				{
					printf("������ѧ����������");
					scanf_s("%s", p->data.name, 20);
					int i = 0;
					while ((0 <= p->data.name[i]) && (p->data.name[i] <= 127))
					{
						printf("���������ģ�\n");
						printf("����������ѧ����������");
						scanf_s("%s", &p->data.name, 20);
					}

					return OK;
					break;
				}
				case 1:
				{
					printf("������ѧ����ѧ�ţ�");
					scanf_s("%d", &p->data.num);

					return OK;
					break;
				}
				case 2:
				{
					printf("������ѧ�����Ա�");
					scanf_s("%s", p->data.gender, 20);
					while ((strcmp(p->data.gender, "��") && strcmp(p->data.gender, "Ů")))//strcmp�����Ƚ��ַ����Ĵ�С�����ʱ����0�������ʱΪ�������߸�����
					{
						printf("�Ա��������ֻ������Ů��\n");
						printf("����������ѧ�����Ա�");
						scanf_s("%s", p->data.gender, 20);
					}
					return OK;
					break;
				}
				case 3:
				{
					printf("������ѧ�������䣺");
					scanf_s("%d", &p->data.age);
					while (p->data.age < 0 || p->data.age>100)
					{
						printf("�����������������0��100��������\n");
						printf("����������ѧ�������䣺");
						scanf_s("%d", &p->data.age);
					}
					return OK;
					break;
				}
				case 4:
				{
					printf("������ѧ����רҵ��");
					scanf_s("%s", p->data.major, 20);
					return OK;
					break;
				}
				case 5:
				{
					printf("������ѧ������ϵ��ʽ��");
					scanf_s("%s", p->data.contact_way, 20);
					return OK;
					break;
				}
				case 6:
				{
					printf("������ѧ���ĳɼ���");
					scanf_s("%f", &p->data.score);
					return OK;
					break;
				}
				default:
				{
					printf("����ѡ��������������룡");
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
			printf("ѧ���������\n");
			return ERROR;
		}
	}
	if (choice1 == 2)
	{
		while (p->next != NULL)//��һ��p->nextΪ��Ԫ�ڵ�
		{
			if (p->data.num == Num)
			{
				printf("������%s  ", p->data.name);
				printf("ѧ�ţ�%d  ", p->data.num);
				printf("�Ա�%s  ", p->data.gender);
				printf("���䣺%d  ", p->data.age);
				printf("רҵ��%s  ", p->data.major);
				printf("��ϵ��ʽ��%s  ", p->data.contact_way);
				printf("�ɼ���%f  ", p->data.score);
				printf("\n");
				printf("�����������ѧ������Ϣ\n");

				printf("������ѧ����������");
				scanf_s("%s", p->data.name, 20);//scanf_s�ǰ�ȫ��scanf�����������������һ����������ڶ���������С��ص����Ρ�
				int i = 0;
				while ((0 <= p->data.name[i]) && (p->data.name[i] <= 127))
				{
					printf("���������ģ�\n");
					printf("����������ѧ����������");
					scanf_s("%s", &p->data.name, 20);
				}
				printf("������ѧ����ѧ�ţ�");
				scanf_s("%d", &p->data.num);
				printf("������ѧ�����Ա�");
				scanf_s("%s", p->data.gender, 20);
				while ((strcmp(p->data.gender, "��") && strcmp(p->data.gender, "Ů")))//strcmp�����Ƚ��ַ����Ĵ�С�����ʱ����0�������ʱΪ�������߸�����
				{
					printf("�Ա��������ֻ������Ů��\n");
					printf("����������ѧ�����Ա�");
					scanf_s("%s", p->data.gender, 20);
				}
				printf("������ѧ�������䣺");
				scanf_s("%d", &p->data.age);
				while (p->data.age < 0 || p->data.age>100)
				{
					printf("�����������������0��100��������\n");
					printf("����������ѧ�������䣺");
					scanf_s("%d", &p->data.age);
				}
				printf("������ѧ����רҵ��");
				scanf_s("%s", p->data.major, 20);
				printf("������ѧ������ϵ��ʽ��");
				scanf_s("%s", p->data.contact_way, 20);
				printf("������ѧ���ĳɼ���");
				scanf_s("%f", &p->data.score);
				return OK;
			}
			else
			{
				p = p->next;//�����Ƽ���Ѱ��ѧ����ͬ�Ľڵ�
			}
		}

		while (p->next == NULL)//pΪ���һ���ڵ�
		{
			if (p->data.num == Num)
			{
				printf("������%s  ", p->data.name);
				printf("ѧ�ţ�%d  ", p->data.num);
				printf("�Ա�%s  ", p->data.gender);
				printf("���䣺%d  ", p->data.age);
				printf("רҵ��%s  ", p->data.major);
				printf("��ϵ��ʽ��%s  ", p->data.contact_way);
				printf("�ɼ���%f  ", p->data.score);
				printf("\n");
				printf("�����������ѧ������Ϣ\n");

				printf("������ѧ����������");
				scanf_s("%s", p->data.name, 20);//scanf_s�ǰ�ȫ��scanf�����������������һ����������ڶ���������С��ص����Ρ�
				int i = 0;
				while ((0 <= p->data.name[i]) && (p->data.name[i] <= 127))
				{
					printf("���������ģ�\n");
					printf("����������ѧ����������");
					scanf_s("%s", &p->data.name, 20);
				}
				printf("������ѧ����ѧ�ţ�");
				scanf_s("%d", &p->data.num);
				printf("������ѧ�����Ա�");
				scanf_s("%s", p->data.gender, 20);
				while ((strcmp(p->data.gender, "��") && strcmp(p->data.gender, "Ů")))//strcmp�����Ƚ��ַ����Ĵ�С�����ʱ����0�������ʱΪ�������߸�����
				{
					printf("�Ա��������ֻ������Ů��\n");
					printf("����������ѧ�����Ա�");
					scanf_s("%s", p->data.gender, 20);
				}
				printf("������ѧ�������䣺");
				scanf_s("%d", &p->data.age);
				while (p->data.age < 0 || p->data.age>100)
				{
					printf("�����������������0��100��������\n");
					printf("����������ѧ�������䣺");
					scanf_s("%d", &p->data.age);
				}
				printf("������ѧ����רҵ��");
				scanf_s("%s", p->data.major, 20);
				printf("������ѧ������ϵ��ʽ��");
				scanf_s("%s", p->data.contact_way, 20);
				printf("������ѧ���ĳɼ���");
				scanf_s("%f", &p->data.score);
				return OK;
			}
			else
			{
				printf("ѧ���������\n");
				return ERROR;
			}
		}
	}
}



//����ѧ��ɾ��ѧ����Ϣ
Status num_to_delete(LinkList L)
{
	int Num;
	printf("��������Ҫɾ����ѧ����Ϣ��ѧ�ţ�");
	scanf_s("%d", &Num);
	LinkList q = L->next; //qΪ��Ԫ�ڵ�
	LinkList p = L;       //pΪͷ�ڵ� L->p->q
	while (q != NULL)   //��Ԫ�ڵ㲻Ϊ��
	{
		if (q->data.num == Num)
		{
			p->next = q->next;  //pָ��q2
			free(q);  //�ͷ�q
			return OK;
		}
		else
		{
			p = q;//����Ų
			q = q->next;
		}


	}

	if (p->next == NULL)
	{
		printf("ѧ���������\n");
		return ERROR;
	}

}

//������������ѧ����Ϣ
Status name_to_inf(LinkList L)
{
	char name[20];
	printf("��������Ҫ����ѧ����������");
	scanf_s("%s", name, 20);
	LinkList p = L;//pΪͷ�ڵ�


	while (p->next != NULL)
	{
		if (!strcmp(p->data.name, name))
		{
			printf("������%s  ", p->data.name);
			printf("ѧ�ţ�%d  ", p->data.num);
			printf("�Ա�%s  ", p->data.gender);
			printf("���䣺%d  ", p->data.age);
			printf("רҵ��%s  ", p->data.major);
			printf("��ϵ��ʽ��%s  ", p->data.contact_way);
			printf("�ɼ���%f  ", p->data.score);
			printf("\n");
			printf("OK!");
			p = p->next;
			while (p)
			{

				if (!strcmp(p->data.name, name))
				{
					printf("������%s  ", p->data.name);
					printf("ѧ�ţ�%d  ", p->data.num);
					printf("�Ա�%s  ", p->data.gender);
					printf("���䣺%d  ", p->data.age);
					printf("רҵ��%s  ", p->data.major);
					printf("��ϵ��ʽ��%s  ", p->data.contact_way);
					printf("�ɼ���%f  ", p->data.score);
					printf("\n");
					printf("OK!");
					return OK;
				}
				else
				{
					p = p->next;
				}
			}
			while (p == NULL)//����ֱ���˳�����
			{
				return OK;
			}

		}
		else
		{
			p = p->next;//��ͷ��㿪ʼ������
		}

	}
	while (p->next == NULL)
	{
		if (!strcmp(p->data.name, name))
		{
			printf("������%s  ", p->data.name);
			printf("ѧ�ţ�%d  ", p->data.num);
			printf("�Ա�%s  ", p->data.gender);
			printf("���䣺%d  ", p->data.age);
			printf("רҵ��%s  ", p->data.major);
			printf("��ϵ��ʽ��%s  ", p->data.contact_way);
			printf("�ɼ���%f  ", p->data.score);
			printf("\n");
			printf("OK!");
			return OK;
		}
		else
		{
			printf("�����������\n");
			return ERROR;
		}

	}

}


//����ѧ�Ų���ѧ����Ϣ
Status num_to_inf(LinkList L)
{
	int Num;
	printf("��������Ҫ����ѧ����ѧ�ţ�");
	scanf_s("%d", &Num);
	LinkList p = L;//pΪͷ�ڵ�
	while (p->next != NULL)
	{
		if (p->data.num == Num)
		{
			printf("������%s  ", p->data.name);
			printf("ѧ�ţ�%d  ", p->data.num);
			printf("�Ա�%s  ", p->data.gender);
			printf("���䣺%d  ", p->data.age);
			printf("רҵ��%s  ", p->data.major);
			printf("��ϵ��ʽ��%s  ", p->data.contact_way);
			printf("�ɼ���%f  ", p->data.score);
			printf("\n");
			printf("OK!");
			return OK;
		}
		else
		{
			p = p->next;//��ͷ��㿪ʼ������
		}

	}
	while (p->next == NULL)
	{
		if (p->data.num == Num)
		{
			printf("������%s  ", p->data.name);
			printf("ѧ�ţ�%d  ", p->data.num);
			printf("�Ա�%s  ", p->data.gender);
			printf("���䣺%d  ", p->data.age);
			printf("רҵ��%s  ", p->data.major);
			printf("��ϵ��ʽ��%s  ", p->data.contact_way);
			printf("�ɼ���%f  ", p->data.score);
			printf("\n");
			printf("OK!");
			return OK;
		}
		else
		{
			printf("ѧ���������\n");
			return ERROR;
		}

	}

}

//���ճɼ���������

Status ascending_sort(LinkList L, int k)
{
	int i, j;
	stu temp;
	LinkList p = L->next;

	for (i = 0; i < k - 1; i++)//ð��
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
//���
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