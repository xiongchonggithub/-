#include<stdio.h>
#include<stdlib.h>
#include<list.h>

//�ṹ�嶨��
typedef struct Dlist{
	int data;
	struct Dlist *next;
	struct Dlist *prev;
}List,*LIST;

//ͷ�ڵ㴴��
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

//��ͨ�ڵ㴴��
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
