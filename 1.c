#include<stdio.h>
#include<stdlib.h>

typedef struct Dlist{
	int data;
	struct Dlist *next;
	struct Dlist *prev;
}List,*LIST;

LIST creat_head();
LIST creat_node(int data_new);
void insert_head(LIST head ,LIST node );
void insert_tail(LIST head ,LIST node );
LIST find(LIST head,int targer);
void show_next(LIST head);
void modify(LIST head,int targer,int data_new);
void all_free(LIST head);
void delete(LIST head,int targer);

//创建头节点
LIST creat_head()
{
	LIST head = malloc(sizeof(List));
	if(head==NULL)
	{
		printf("malloc failed");
		return NULL;
	}
	
	head->next=head;
	head->prev=head;
	
	return head;
}

//创建普通节点
LIST creat_node(int data_new)
{
	LIST node = malloc(sizeof(List));
	if(node==NULL)
	{
		printf("malloc failed");
		return NULL;
	}
	node->data=data_new;
	node->next=node;
	node->prev=node;
	
	return node;
}

//头插
void insert_head(LIST head ,LIST node )
{
	node->next=head->next;
	
	node->prev=head;
	
	head->next->prev=node;
	
	head->next=node;
	
}
//插入中间
void insert_middle(LIST head,LIST tail,LIST targer)
{
	head->next=targer;
	
	targer->next=tail;
	targer->prev=head;
	
	tail->prev=targer;
}

//尾插
void insert_tail(LIST head ,LIST node )
{
	node->next=head;
	
	node->prev=head->prev;
	
	head->prev->next=node;
	
	head->prev=node;
	
	
}

//查找targer所在节点
LIST find(LIST head,int targer)
{
	LIST p=head->next;
	while(p!=head)
	{
		if(p->data==targer)
		{
			break;
		}
		p=p->next;
	}
	if(p==head)
	{
		p=NULL;
	}
	return p;
}
//删除目标节点
void list_del(LIST targer)
{
	targer->next->prev=targer->prev;
	targer->prev->next=targer->next;
}

//删除两节点之间的节点
void list_del_middle(LIST head,LIST tail)
{
	head->next=tail;
	tail->prev=head;

}

//从头往尾显示链表数据
void show_next(LIST head)
{
	LIST p=head->next;
	while(p!=head)
	{
		printf("%d-",p->data);
		p=p->next;
	}
	printf("\n");
}
//从尾往头显示链表数据
void show_prev(LIST head)
{
	LIST p=head->prev;
	while(p!=head)
	{
		printf("%d-",p->data);
		p=p->prev;
	}
	printf("\n");

}

//修改targer对应的值
void modify(LIST head,int targer,int data_new)
{
	LIST p=find(head,targer);
	if(p==NULL)
	{
		printf("链表中无目标值");
		return ;
	}
	p->data=data_new;
}

//去除targer对应的节点
LIST del(LIST head,int targer)
{
	LIST p=find(head,targer);
	if(p==NULL)
	{
		printf("链表中无目标值");
		return NULL;
	}
	
	p->prev->next=p->next;
	
	p->next->prev=p->prev;
	
	p->next=p;
	p->prev=p;
	return p;
}

//释放链表的堆空间
void all_free(LIST head)
{
	LIST p=head->next;
	LIST q=head->next;
	while(p!=head)
	{
		p=p->next;
		free(q);
		q=p;
	}
	free(head);
}

int main()
{
	
	LIST head=creat_head();
	int i=1;
	for(i;i<10;i++)
	{
		insert_tail(head,creat_node(i));
	}
	
	show_next(head);
	show_prev(head);
	all_free(head);
	
	
	return 0;
}













