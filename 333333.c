#include<stdio.h>
#include<curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//全局变量
char *p[10]={
	"add",
	"delete",
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
//结构体定义
struct student {
	char name[15];
	char num[12];
	int age;
};



//函数声明

void display();		//显示函数	
void init_interface();//初始化
void arrow(int a);	//箭头函数
void memu1();	//菜单1
void wait();  //等待任意键退出
void check(struct student *gaojunnan);//查看
void modify(struct student *gaojunnan);//修改
void delete(int n,struct student *gaojunnan);//删除
void add(struct student *gaojunnan);//添加
void move_back(struct student *gaojunnan);


void memu1()
{
	move(0,1);
	hline('_',39);
	move(1,0);
	vline('|',20);
	move(20,1);
	hline('_',40);
	move(1,40);
	vline('|',20);
	for(int i=0;i<4;i++)
	{
		mvprintw(3+4*i,20,"%s",p[i]);
		
	}
}

void memu2()
{
	int i;
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
}


void init_interface()
{
	initscr();
	//初始化
	
	keypad(stdscr,TRUE);
	//去掉键盘的回显
	noecho();
	//启动特殊字符的输入
	raw();
	//开启颜色索引
	start_color();
	//设置索引的目标
	init_pair(1,COLOR_WHITE,COLOR_BLACK   );//颜色索引1,文字白色,背景黑色	用于数值 2
	init_pair(2,COLOR_RED  ,COLOR_WHITE   );//颜色索引2,文字红色,背景白色	用于数值 4,128
	init_pair(3,COLOR_GREEN,COLOR_YELLOW  );//颜色索引3,文字绿色,背景黄色	用于数值 8,256
	init_pair(4,COLOR_BLUE ,COLOR_MAGENTA );//颜色索引4,文字蓝色,背景粉色	用于数值 16,512
	init_pair(5,COLOR_RED  ,COLOR_WHITE);//颜色索引5,文字红色,背景白色		用于数值 32,1024
	init_pair(6,COLOR_CYAN ,COLOR_RED);//颜色索引6,文字青色,背景白色		用于数值 64,2048
}

int main()
{
	int a=1;
	struct student *gaojunnan=(struct student *)malloc(sizeof(struct student)*100);
	
	stpcpy(gaojunnan[0].name,"gaojunnan");
	stpcpy(gaojunnan[0].num,"1cm");
	gaojunnan[0].age=99;
	init_interface();

	refresh();	
	
	memu1();
	 while(quit)
	{
		
		arrow(control);
		display(gaojunnan);
		refresh(); 

	} 
	refresh();
	endwin();
	free(gaojunnan);
	return 0;
}




void display(struct student *gaojunnan)
{

	key = getch();
		switch(key)
		{
			case KEY_UP:   
						if(control>0)
						{
							control--;
							clear();
							
						}
							break;
			case KEY_DOWN: 
						if(control<3)
						{
							control++;
							clear();
						
						}
							break;
			case KEY_LEFT:
						
							break;
			case KEY_RIGHT:
						
							break;
			case '\n':
							
							switch(control)
							{
								case 0:
										clear();
										
										add(gaojunnan);
										student_number++;
										break;
								case 1:
										clear();
										
										delete(student_number,gaojunnan);
										break;
								case 2:
										clear();	
										
										modify(gaojunnan);
										break;
								case 3:
										memu2();
										clear();
										check(gaojunnan);
										wait();
										break;
								
							}
							break;
			case 'q'://字符'q'退出 ---- 对应'q'的ASCII值
				quit=0;
				break;
		}
		clear();
		memu1();
	/* 	int ch = getch();  // 读取用户输入
		if (ch == KEY_ENTER || ch == '\n') 	// 判断是否为回车键 回车键被按下
		{
			
		} */
}

void wait()
{
	int t=getch();
	while(1)
	{
		if(t)
		{
			break;
		}
	}
}

void arrow(int control)
{
	
	mvprintw(3+4*control-1,10+2,"%s",p[5]);	
	mvprintw(3+4*control,10,"%s",p[4]);
	mvprintw(3+4*control+1,10+2,"%s",p[6]);
	
}

void move_back(struct student *gaojunnan)
{
	stpcpy(gaojunnan[student_number+1].name,gaojunnan[student_number].name);
	stpcpy(gaojunnan[student_number+1].num,gaojunnan[student_number].num);
	gaojunnan[student_number+1].age=gaojunnan[student_number].age;
	
}

void add(struct student *gaojunnan)
{

	move_back(gaojunnan);
	char *name=(char *)malloc(15);
	char *num=(char *)malloc(12);
	int *age=(int *)malloc(4);
	mvprintw(3+5,10+2,"please input name");move(3+5,10+2+18);
	getstr(name);
	mvprintw(3+6,10+2,"please input num");move(3+6,10+2+18);
	getstr(num);
	mvprintw(3+7,10+2,"please input age");move(3+7,10+2+18);
	scanw("%d", age);
	stpcpy(gaojunnan[student_number].name,name);
	stpcpy(gaojunnan[student_number].num,num);
	gaojunnan[student_number].age=*age;
	free(name);
	free(num);
	free(age);
	
}

void delete(int n,struct student *gaojunnan)
{
	stpcpy(gaojunnan[n].name,"");
	stpcpy(gaojunnan[n].num,"");
	gaojunnan[n].age=0;
	student_number--;
}



void modify(struct student *gaojunnan)
{

	while(1)
	{
		int *k=(int *)malloc(4*100);
		int n=0,i=0,j=0;
		char name1[15];
		mvprintw(3+5,10+2,"please input name");
		move(3+5,10+2+18);
		getstr(name1);
		for(n;n<=student_number;n++)
		{
			*(k+n)=strcmp(name1,gaojunnan[n].name);
		}
		for(i;i<=student_number;i++)
		{
			if(*(k+i)==1)
			{
				j=i;
			}
		}
		if(j==0)
		{
			clear();
			mvprintw(3,10+2,"please again");
			continue;
			
		}
		char *name=(char *)malloc(15);
		char *num=(char *)malloc(12);
		int *age=(int *)malloc(4);
		clear();
		mvprintw(3+5,10+2,"please input name");move(3+5,10+2+18);
		getstr(name);
		mvprintw(3+6,10+2,"please input num");move(3+6,10+2+18);
		getstr(num);
		mvprintw(3+7,10+2,"please input age");move(3+7,10+2+18);
		scanw("%d", age);
		stpcpy(gaojunnan[j].name,name);
		stpcpy(gaojunnan[j].num,num);
		gaojunnan[j].age=*age;
		free(name);
		free(num);
		free(age);
		free(k);
		
		break;
		
	}
} 

void check(struct student *gaojunnan)
{
	memu2();
	int j=0;
	for(j;j<student_number+1;j++)
	{
		mvprintw(3+j+1,3,"%d",j+1);
		mvprintw(3+j+1,11,"%s",gaojunnan[j].name);
		mvprintw(3+j+1,22,"%s",gaojunnan[j].num);
		mvprintw(3+j+1,30,"%d",gaojunnan[j].age);
	}
	
}

