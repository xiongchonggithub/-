#include<stdio.h>
#include<stdlib.h>
#include<list.h>

//结构体定义
typedef struct Dlist{
	int data;
	struct Dlist *next;
	struct Dlist *prev;
}List,*LIST;

//头节点创建
LIST creat_head()
{
	LIST head = malloc(sizeof(List));
	if(head==NULL)
	{
		printf("head malloc failed");
		return NULL;
	}
	head->next=head;
	head->prev=head;
	
	return head;
}

//普通节点创建
LIST creat_node(int data_new)
{
	LIST node = malloc(sizeof(List));
	if(node==NULL)
	{
		printf("node malloc failed");
		return NULL;
	}
	node->next=node;
	node->prev=node;
	node->data=data_new;
	return node;
}

//
