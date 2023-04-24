#include<stdio.h>
#include<stdlib.h>

typedef struct sort{
	int data;
	struct sort *next;
}Sort,*SORT;


void change(SORT head);

void swap(int *x,int *y)
{
	int p=*x;
	*x=*y;
	*y=p;
}
SORT creat_head()
{
	SORT head = malloc(sizeof(Sort));		//申请堆空间
	if(head==NULL)
	{
		printf("哥哥！！头节点创建失败哦！！");
		return NULL;
	}
	head->next=NULL;
	return head;

}
//创建节点
SORT creat_node(int data_a)
{
	SORT node = malloc(sizeof(Sort));
	if(node==NULL)
	{
		printf("哥哥！！节点创建失败哦！！");
		return NULL;
	}
	node->data=data_a;
	node->next=NULL;
	return node;

}

void insert(SORT head,SORT node)
{
	node->next=head->next;
	
	head->next=node;
	
}

void change(SORT head)
{
	int i=0,j=0;
	SORT p=head;
	SORT q[5];
	int a[5]={0};
	while(p->next!=NULL)
	{
		p=p->next;
		q[i]=p;
		i++;
	}
	p=head;
	for(i=4;i>=0;i--)
	{
		p->next=q[i];
		p=p->next;
	}
	q[0]->next=NULL;
}

void show(SORT head)
{
	SORT p=head;
	if(p->next==NULL)
	{
		printf("空空如也啊！！");
	}
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d-",p->data);
	}
	printf("\n");
}

void all_free(SORT head)
{
	SORT p=head;
	SORT q=head;
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}

int main()
{
	SORT head = creat_head();
	
	for(int i=0;i<5;i++)
	{
		insert(head,creat_node(i+1));
	}
	show(head);
	change(head);
	show(head);
	all_free(head);
	return 0;
}



