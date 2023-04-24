#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	char *p;
	int age;
	struct list *next;
}stu,*STU;

//创建头节点
STU creat_head()
{
	STU head = malloc(sizeof(STU));		//申请堆空间
	if(head==NULL)
	{
		printf("哥哥！！头节点创建失败哦！！");
		return NULL;
	}
	head->next=NULL;
	return head;

}
//创建节点
STU creat_node(char *name1,int age1)
{
	STU node = malloc(sizeof(STU));
	node->name = malloc(sizeof(char)*15);
	if(node==NULL)
	{
		printf("哥哥！！节点创建失败哦！！");
		return NULL;
	}
	strcpy(node->name,name1);
	node->age=age1;
	node->next=NULL;
	return node;

}

//头部插入
void insert_head(STU head,STU targer)
{
	targer->next=head->next;
	
	head->next=targer;
	
}

//尾部插入
void insert_tail(STU head,STU targer)
{
	STU *p=head;
	//遍历整个链表
	while(p->next!=NULL)
	{
		p=p->next;
	}
	
	p->next=targer;
	
	targer->next=NULL;
}

STU find_name(STU head,char *name1)
{
	STU *p=head;
	if(p->next=NULL)
	{
		printf("~_*别查了，哥哥，链表是空的捏！");
		return NULL;
	}
	while(p->next!=NULL)
	{
		if(strcmp(p->name,name1)==0)
		{
			printf("^_^!!!找到了捏");
			return p;
		}
	}
	return NULL;
}





