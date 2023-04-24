#include<stdio.h>
#include<curses.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


//结构体变量
typedef struct Dlist{
	char *name;
	char *num;
	int age;
	struct Dlist *next;
}List,*LIST;

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
//函数声明

void menu_start();
LIST creat_head();
LIST creat_node(char *name_new,char *num_new,int age_new);
void insert_head(LIST head,LIST targer);
void insert_tail(LIST head,LIST targer);
LIST find_num(LIST head,char *num_targer);
LIST get_node(LIST head,LIST node);
void mod_node(LIST node,char *name_new,char *num_new,int age_new);
void init_interface();
void all_free(LIST head);
void arrow(int control);
void system_select();
void del_node(LIST head,LIST p);
void system_register(LIST head);
void system_logout(LIST head);
void syste_modify(LIST head);
void syste_check(LIST head);

//主函数
int main()
{
	init_interface();
	LIST head=creat_head();
	menu_start();
	refresh();
	while(quit)
	{
		system_select(head);
	}
	endwin();
	return 0;
}
void system_select(LIST head)
{
	int key;
	key = getch();
	switch(key)
		{
			case KEY_UP:   
						if(control>0)
						{
							control--;
						}
							
						
							break;
			case KEY_DOWN: 
						if(control<3)
						{
							control++;
						}
							break;
			case KEY_LEFT:
						
							break;
			case KEY_RIGHT:
						
							break;
			case '\n':
							clear();
							if(control==0)
							{
								system_register(head);
							}
							else if(control==1)
							{
								system_logout(head);
							}
							else if(control==2)
							{
								syste_modify(head);
							}
							else if(control==3)
							{
								mvprintw(30,33,"5");	
								syste_check(head);
								mvprintw(30,33,"5");
							}
							break; 
			case 'q'://字符'q'退出 ---- 对应'q'的ASCII值
							quit=0;
							break;
		}
		clear();
		menu_start();
}
//创建头节点
LIST creat_head()
{
	LIST head=(LIST)malloc(sizeof(List));
	head->name=(char *)malloc(sizeof(char)*15);
	head->num=(char *)malloc(sizeof(char)*12);
	if(head==NULL)
	{
		printf("head malloc failed");
		return NULL;
	}
	head->next=NULL;
	return head;
}

//创建普通节点
LIST creat_node(char *name_new,char *num_new,int age_new)
{
	LIST node=(LIST)malloc(sizeof(List));
	node->name=(char *)malloc(sizeof(char)*15);
	node->num=(char *)malloc(sizeof(char)*12);
	if(node==NULL)
	{
		printf("node malloc failed");
		return NULL;
	}
	stpcpy(node->name,name_new);
	stpcpy(node->num,num_new);
	node->age=age_new;
	node->next=NULL;
	return node;
}

//头插
void insert_head(LIST head,LIST targer)
{
	targer->next=head->next;
	
	head->next=targer;
}

//尾插
void insert_tail(LIST head,LIST targer)
{
	LIST p=head->next;
	if(p==NULL)
	{
		insert_head(head,targer);
	}
	else
	{
		while(p!=NULL)
		{
			p=p->next;
		}	
		p->next=targer;
		targer->next=NULL;
	}
}

//查找名字
LIST find_num(LIST head,char *num_targer)
{
	LIST p=head->next;
	while(p!=NULL)
	{
		if(strcmp(p->num,num_targer)==0)
		{
			return p;
		}
		
		p=p->next;
	}
	return NULL;
}

//取出某个节点
LIST get_node(LIST head,LIST node)
{
	LIST p=head->next;
	LIST q=node;
	if(p==q)
	{
		head->next=q->next;
		q->next=NULL;
	}
	else
	{
		while(p->next!=q)
		{
			p=p->next;
		}
		p->next=q->next;
		q->next=NULL;
	}
	return q;
}

//删除某个学号对应的节点
void del_node(LIST head,LIST p)
{
	get_node(head,p);
	free(p->num);
	free(p->name);
	free(p);
}

//修改节点数据
void mod_node(LIST node,char *name_new,char *num_new,int age_new)
{
	node->age=age_new;
	stpcpy(node->name,name_new);
	stpcpy(node->num,num_new);
}

//开始菜单
void menu_start()
{
	attron(COLOR_PAIR(1));//开启颜色索引i
	move(0,0);
	hline(' ',40);
	move(0,0);
	vline(' ',20);
	move(20,0);
	hline(' ',41);
	move(0,40);
	vline(' ',20);
	attroff(COLOR_PAIR(1));//关闭颜色索引i
	for(int i=0;i<4;i++)
	{
		attron(COLOR_PAIR(2));//开启颜色索引i
		mvprintw(3+4*i,20,"%-8s",p[i]);
		attroff(COLOR_PAIR(2));//关闭颜色索引i
		
	}
	mvprintw(2,45,"Welcome to this system!!");
	arrow(control);
	
}

//curses初始化
void init_interface()
{
	initscr();
	//初始化
	keypad(stdscr,TRUE);
	//去掉键盘的回显
	//noecho();
	//启动特殊字符的输入
	raw();
	//开启颜色索引
	start_color();
	//设置索引的目标
	init_pair(1,COLOR_BLACK,COLOR_WHITE   );//颜色索引1,文字白色,背景黑色
	init_pair(2,COLOR_RED  ,COLOR_WHITE   );//颜色索引2,文字红色,背景白色	
	init_pair(3,COLOR_GREEN,COLOR_YELLOW  );//颜色索引3,文字绿色,背景黄色	
	init_pair(4,COLOR_BLUE ,COLOR_MAGENTA );//颜色索引4,文字蓝色,背景粉色	
	init_pair(5,COLOR_RED  ,COLOR_WHITE);	//颜色索引5,文字红色,背景白色		
	init_pair(6,COLOR_CYAN ,COLOR_RED);		//颜色索引6,文字青色,背景红色		
	//开启六个颜色索引备用
}

//释放链表
void all_free(LIST head)
{
	LIST p=head->next;
	LIST q=NULL;
	while(p!=NULL)
	{
		q=p;
		free(q->name);
		free(q->num);
		free(q);
		p=p->next;
	}
	free(head);
}

//箭头显示
void arrow(int control)
{
	mvprintw(3+4*control-1,8,"%s",p[5]);	
	mvprintw(3+4*control,6+control+1,"%s",p[4]);
	mvprintw(3+4*control+1,8,"%s",p[6]);
}

//注册操作
void system_register(LIST head)
{
	char age1[15]={0};
	int age=0;
	char name[15]={0};
	char number[12]={0};
	
	move(0,1);
	hline('_',39);
	move(1,0);
	vline('|',20);
	move(20,1);
	hline('_',40);
	move(1,40);
	vline('|',20);
	mvprintw(3+4,2,"please input your name");move(3+4,2+22+1);
	getstr(name);
	mvprintw(3+4*2,2,"please input your number");move(3+4*2,2+24+1);
	getstr(number);
	mvprintw(3+4*3,2,"please input your age");move(3+4*3,2+21+1);
	getstr(age1);
	age=atoi(age1);
	
	LIST p=find_num(head,number);
	if(p==NULL)
	{
		LIST node=creat_node(name,number,age);
		insert_head(head,node);
	}
	else
	{
		mvprintw(30,2,"The user cannot register due to system issues");
		
	}
	
}

//注销操作
void system_logout(LIST head)
{
	char *number=(char * )malloc(12);
	move(0,1);
	hline('_',39);
	move(1,0);
	vline('|',20);
	move(20,1);
	hline('_',40);
	move(1,40);
	vline('|',20);
	mvprintw(3+4*2,2,"please input your number");
	getstr(number);
	LIST p=find_num(head,number);
	if(p==NULL)
	{
		mvprintw(3+4*3,2,"The system does not exist. The user cannot be logged out");
	}
	else
	{
		del_node(head ,p);
	}
	
	free(number);
}

//修改操作
void syste_modify(LIST head)
{
	move(0,1);
	hline('_',39);
	move(1,0);
	vline('|',20);
	move(20,1);
	hline('_',40);
	move(1,40);
	vline('|',20);
	char *number=(char * )malloc(12);
	char *name=(char * )malloc(15);
	int age;
	char age1[12]={0};
	mvprintw(3+4*1,2,"please input your number");move(3+4*1,2+24+1);
	getstr(number);
	LIST p=find_num(head,number);
	if(p==NULL)
	{
		mvprintw(3+4*2,2,"The student ID is not registered in this system");
	}
	else
	{
		mvprintw(3+4*2,2,"please input your name");move(3+4*2,2+24+1);
		getstr(name);
		mvprintw(3+4*3,2,"please input your age");move(3+4*3,2+24+1);
		getstr(age1);
		age=atoi(age1);
		mod_node(p,name,number,age);
	}
	free(name);
	free(number);
}
//查看
void syste_check(LIST head)
{
	int j=1;
	move(0,1);
	hline('_',39);
	move(1,0);
	vline('|',20);
	move(20,1);
	hline('_',40);
	move(1,40);
	vline('|',20);
	mvprintw(3,3,"label");
	mvprintw(3,11,"%s",p1);
	mvprintw(3,22,"%s",p2);
	mvprintw(3,30,"%s",p3);
	LIST p=head->next;
	while(p!=NULL)
	{
		mvprintw(3+j+1,3,"%d",j);
		mvprintw(3+j+1,11,"%s",p->name);
		mvprintw(3+j+1,22,"%s",p->num);
		mvprintw(3+j+1,30,"%d",p->age);
		p=p->next;
		j++;
	}
	int key=getch();
	while(key==0);
}












