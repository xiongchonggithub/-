

#include<stdio.h>
#include<stdlib.h>

typedef struct heap{
	int *arr;
	int size;
	int cnt;
}Heap,*HEAP;

//创建堆空间
HEAP creat_heapst(int number)
{
	HEAP head = (HEAP)malloc(sizeof(Heap));
	if(head==NULL)
	{
		printf("heap堆空间申请失败");
		return NULL;
	}
	head->arr=(int *)malloc(sizeof(int )*number);
	if(head->arr==NULL)
	{
		printf("arr堆空间申请失败");
		return NULL;
	}
	
	head->size=number;//容纳
	head->cnt =0;//元素个数
	return head;
}

int insert_back(HEAP heap,int data)
{
	if(heap->cnt==heap->size)
	{
		printf("空间已经被塞满了");
		return -1;
	}
	*(heap->arr+heap->cnt)=data;
	(heap->cnt)++;
	return 0;
}

int remove_heap(HEAP heap)
{
	if(heap->cnt==0)
	{
		printf("别偷了里面东西都被你偷光了");
		return -1;
	}
	*(heap->arr+heap->cnt)=0;
	(heap->cnt)--;
	return 0;
}

void show(HEAP heap)
{
	int i=0;
	for(i;i<(heap->cnt);i++)
	{
		printf(" %d ",*(heap->arr+i));
	}
	printf("\n");
}

int main()
{
	char *b=(char *)malloc(10);
	int data_main=0;
	HEAP addr =  creat_heapst(100);
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<10;i++)
	{
		
		*((addr->arr)+i)=a[i];
		(addr->cnt)++;
	}
	while(1)
	{
		show(addr);
		printf("请输入一个数");
		scanf("%s",b);
		while(getchar()!='\n');
		data_main=atoi(b);
		if(data_main>0)
		{
			insert_back(addr,data_main);
		}
		if(data_main<0)
		{
			remove_heap(addr);
		}
		if(b[0]=='q')
		{
			break;
		}
	}
	free(b);
	free(addr);
	free(addr->);
	return 0;
}

