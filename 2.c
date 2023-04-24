#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	int data;
	struct list *next;
}List,*LIST;

//头节点
LIST creat_head()
{
	LIST head =malloc(sizeof(List));
	if(head==NULL)
	{
		printf("*_*!大事不好堆空间申请失败");
		return NULL;
	}
	head->next=NULL;
	return head;
}

//子节点
LIST creat_node(int number)
{
	LIST node =malloc(sizeof(List));
	if(node==NULL)
	{
		printf("*_*!大事不好堆空间申请失败");
		return NULL;
	}
	node->data=number;
	node->next=NULL;
	
	return node;
}

/*头部插入
*/
void insert_head(LIST head,LIST node)
{
	//必须先让node->next指针指向 头结点的下一个节点
	node->next=head->next;
	
	//头结点的next指针指向 新的node节点
	head->next=node;
	
}
//中间插入
void insert_middle(int data_new,int target,LIST head)
{
	LIST p=head;
	LIST q=head;
	LIST node = creat_node(data_new);
	for(int i=0;i<target;i++)
	{
		p=p->next;
	}
	while(q->next!=p)
	{
		q=q->next;
	}
	q->next=node;
	node->next=p;
	
	
}
//修改第几个节点
void modify(int data_new,int target,LIST head)
{
	LIST p=head;
	for(int i=0;i<target;i++)
	{
		p=p->next;
	}
	p->data=data_new;
}

//删除第几个节点
void delete_position(int target,LIST head)
{
	LIST p=head;
	LIST q=head;
	for(int i=0;i<target;i++)
	{
		p=p->next;
	}
	while(q->next!=p)
	{
		q=q->next;
	}
	q->next=p->next;
	free(p);
}
//删除数据对应的节点
void delete_position(int target,LIST head)
{
	LIST p=find(target,head);
	
	
	
}


//尾部插入
void insert_tail(LIST tail,LIST node)
{
	LIST p=node;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=tail;
}
//查找
LIST find(int target,LIST head)
{
	LIST p=head;
	while(p->next!=NULL)
	{
		
		if(p->data==target)
		{
			
			return p;
		}	
	}
	return NULL;
}

//打印出来
void show(LIST head)
{
	LIST p=head;
	if(p->next==NULL)
	{
		printf("^_^笨蛋链表被删除了捏!!!\n");
		return ;
	}
	while(p->next!= NULL )
	{
		p=p->next;
		printf("%d-",p->data);
		
	}
	printf("\n");
	return ;
}

int run(int a, LIST head)
{
	int b=0,c=0;
	
	switch(a)
	{
		case 1 :
			printf("请输入您插入的数据");
			scanf("%d",&b);
			insert_tail(creat_node(b),head);
			break;
		case 2 :
			printf("请输入您修改的数据和位数");
			scanf("%d %d",&b,&c);
			modify(b,c,head);
			break;
		case 3 :
			printf("请输入您删除的位置");
			scanf("%d",&b);	
			delete_position(b,head);	
			break;	
		case 4 :
			printf("请输入您插入的数据和位数");
			scanf("%d %d",&b,&c);
			insert_middle(b,c,head);
			break;	
		case 5 :
			printf("请输入您查询的数据");
			scanf("%d",&b);	
			if(find(b,head)!=NULL)
		
		
		case 6 :
			return 0;
			break;
	}
	
}

void all_free(LIST head)
{
	LIST p=head;
	LIST q=head;
	while(p->next!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	
	
}

int main()
{
	int a=0,d=1;
	LIST head = creat_head();
	

	while(1)
	{
		printf("请输入您选择的方式");
		scanf("%d",&a);
		while(getchar()!='\n');
		d=run(a,head);
		show(head);
		
	}
	all_free(head);
	return 0;
}










