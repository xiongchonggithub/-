#include<stdio.h>
#include<stdlib.h>

//结构体定义
typedef struct Dlist{
	int data;
	struct Dlist *next;
	struct Dlist *prev;
}List,*LIST;

//函数声明
LIST creat_head();
LIST creat_node(int data_new);
void insert_head(LIST head , LIST node);
void insert_tail(LIST head , LIST node);
void show_list_next(LIST head);
void show_list_prev(LIST head);
void node_change_list(LIST node,LIST head);
int odd_even_change(LIST head);
void odd_even_sort(LIST head);
void all_free(LIST head);
LIST get_node(LIST node);
void change(LIST ahead,LIST after);
//主函数
int main()
{
	LIST head=creat_head();
	LIST p=NULL;
	for(int i=1;i<10;i++)
	{
		p=creat_node(i);
		insert_tail(head,p);
	}
	
	odd_even_sort(head);
	
	all_free(head);
	return 0;
}

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

//头插
void insert_head(LIST head , LIST node)
{
	node->next=head->next;
	
	node->prev=head;
	
	head->next->prev=node;

	head->next=node;
}

//尾插
void insert_tail(LIST head , LIST node)
{
	node->prev=head->prev;
	
	node->next=head;
	
	head->prev->next=node;
	
	head->prev=node;
}

//next遍历显示
void show_list_next(LIST head)
{
	LIST p=head->next;
	while(p!=head)
	{
		printf("-%d-",p->data);
		p=p->next;
	}
	printf("\n");
}

//prev遍历显示
void show_list_prev(LIST head)
{
	LIST p=head->prev;
	while(p!=head)
	{
		printf("-%d-",p->data);
		p=p->prev;
	}
	printf("\n");
}
//交换
void change(LIST ahead,LIST after)
{
	after->next->prev=ahead;
	
	ahead->prev->next=after;
	
	after->prev=ahead->prev;
	
	ahead->next=after->next;
	
	after->next=ahead;
	
	ahead->prev=after;
	
}
//前交换
void change_ahead(LIST targer)
{
	change(targer->prev,targer);
}

//后交换
void change_after(LIST targer)
{
	change(targer,targer->next);
}
//奇偶交换
int odd_even_change(LIST head)
{
	LIST p=head->next;
	LIST q=NULL;
	int cnt=0;
	if(p==head)
	{
		printf("odd_even change failed\n");
		return 0;
	}
	while(p!=head)
	{
		q=p;
		p=p->next;
		if(p->data%2==1)
		{
			cnt--;
			q=get_node(q);
			insert_tail(head,q);
		}
		cnt++;
	}
	return cnt;
}
//取出一个节点
LIST get_node(LIST node)
{
	
	node->prev->next=node->next;
	
	node->next->prev=node->prev;
	
	return node;
}
//偶排
void even_sort(LIST head)
{
	LIST p=head->next;
	LIST q=NULL;

	while(p!=head)
	{
		if(p->data%2==0)
		{
			for(q=p;q!=head;q=q->next)
			{
				if((q->data)<(q->next->data))
				{
					change_after(q);
				}
			}
		}
		p=p->next;
		//q=p->next;
	} 
}
//奇排
void odd_sort(LIST head)
{
	LIST p=head->next;
	LIST q=NULL;

	while(p!=head)
	{
		if(p->data%2==1)
		{
			q=p->next;
			if((p->data)>(q->data))
			{
				change_after(p);
			}
			p=q;
			p=p->next;
		}
		p=p->next;
		//q=p->next;
	}
	
}
void odd_even_sort(LIST head)
{
	int a=0;
	show_list_next(head);
	a=odd_even_change(head);
	for(int i=0;i<a;i++)
	{
		even_sort(head);
	}
	//for(int i=0;i<a;i++)
	//{
		odd_sort(head);
	//}
	show_list_next(head);
	//show_list_prev(head);
}

//释放
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




