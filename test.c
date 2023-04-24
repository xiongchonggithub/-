#include<stdio.h>
#include<list.h>

/*
 * @ptr:        the pointer to the member. 
				指向成员的指针。
 * @type:       the type of the container struct this is embedded in.
				它所嵌入的容器结构的类型。
 * @member:     the name of the member within the struct.
				结构中成员的名称。
 */

//list.h宏定义
struct list_head {
	struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
//
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({                      \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

//得到大结构体（Stu）的地址，通过member
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)
//

//测试head是否为空
static inline int list_empty(const struct list_head *head)
{
	return head->next == head;
}
//
//删除链表中的某个节点（通过前后的节点进行）
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;
	prev->next = next;
}
//遍历整个链表
#define list_for_each_entry(pos, head, member)				\
	for (pos = list_entry((head)->next, typeof(*pos), member);	\
	     &pos->member != (head); 	\
	     pos = list_entry(pos->member.next, typeof(*pos), member))
//
//插入某个节点在prev和next直接
static inline void __list_add(struct list_head *_new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = _new;
	_new->next = next;
	_new->prev = prev;
	prev->next = _new;
}
//尾部插入
static inline void list_add_tail(struct list_head *_new, struct list_head *head)
{
	__list_add(_new, head->prev, head);
}		 
//

//头插
static inline void list_add_head(struct list_head *_new, struct list_head *head)
{
	__list_add(_new, head, head->next);
}

//
#define NAMESIZE 15
#define NUMSIZE 12
//全局变量
char *p[10]={
	"register",
	"log off",
	"modify",
	"check",
	"---->",
	"|\\",
	"|/",
};
char *p1="name";
char *p2="number";
char *p3="age";
int key;
int control=0;
int quit=1;
int student_number;
//结构体
typedef struct stu{
	char name[NAMESIZE];
	char num[NUMSIZE];
	int age;
	struct list_head node;
}Stu ,*STU; 


int main()
{
	LIST p=NULL;
	LIST_HEAD(head);
	for(int i=0;i<7;i++)
	{
		p=malloc(sizeof(LIST));
		if(p==NULL)
		{
			return 0;
		}
		p->age=i;
		stpcpy(p->name,q[i]);
		list_add_tail(p,head);
	}
	
	
	
	
	
	return 0
}





