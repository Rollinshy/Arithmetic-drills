#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>

struct person
{
	int number;//设置测验题数
	int score;//设置测验总分
	int nandu; //设置计算数据位数
	int leixing;//运算符号类型
	int type;//符号随机
}shezhi={10,100,90,1,1};

int tishu1,tishu2;
FILE *fp;//定义文件指针


void maindisplaymenu()//显示主菜单
{
	void exercise();
	void test();
	void limt();
	void result();
	printf("                               算数练习                                      \n\n\n");
	printf("                               1：练习                                       \n");
	printf("                               2：测验                                       \n");
	printf("                               3：设置                                       \n");
	printf("                               4：查看测验成绩                               \n");
	printf("                               0:退出系统                                    \n");
	int select;
	do
	{
	printf("请选择想进行的功能：");
	scanf("%d",&select);
		switch(select)
		{
			case 1:exercise();break;
			case 2:test();break;
			case 3:limt();break;
		    case 4:result();break;
		    case 0:exit(0);
		    default:printf("您输入的数无对应功能或输入错误，请重新输入:\n");
		}
	}while(select<0||select>4);
}

void exercise()//练习模式
{
	void maindisplaymenu();
	int num1,num2;
	int a;
	int n;

	tishu1=0;tishu2=0;
	float rate;
	srand(time(NULL));//设置种子
	int ranswer;
	int uanswer;
	char operation;
	char c;
	printf("1.加法运算，2.减法运算，3乘法运算，4。除法运算，5.随机运算:\n");
	printf("请选择想要进行的运算练习:");
	scanf("%d",&a);
	system("cls");
	switch(a)
	{
		case 1:shezhi.leixing=1;shezhi.type=0;break;
		case 2:shezhi.leixing=2;shezhi.type=0;break;
		case 3:shezhi.leixing=3;shezhi.type=0;break;
		case 4:shezhi.leixing=4;shezhi.type=0;break;
		case 5:shezhi.type=1;break;
		default:printf("输入错误！\n");
	}

	do
	{
	if(shezhi.type==1)
	shezhi.leixing=rand()%4+1;
	if(shezhi.nandu==10)
	{

	num1=rand()%shezhi.nandu+0;
	num2=rand()%shezhi.nandu+0;
    }
    else if(shezhi.nandu==90)
    {
   	num1=rand()%shezhi.nandu+10;
	num2=rand()%shezhi.nandu+10;
	}
	else if(shezhi.nandu==900)
	{
	num1=rand()%shezhi.nandu+100;
	num2=rand()%shezhi.nandu+100;
	}
	switch(shezhi.leixing)
	{
		case 1:operation='+';ranswer=num1+num2;break;
		case 2:operation='-';ranswer=num1-num2;break;
		case 3:operation='*';ranswer=num1*num2;break;
		case 4:operation='/';ranswer=num1/num2;break;
	}
	if(operation=='/'&&num2==0)
	{
		num2=1;
	}
	printf("%d%c%d=",num1,operation,num2);
	scanf("%d",&uanswer);
	getchar();
	tishu1++;
	if(uanswer==ranswer)
	{
		tishu2++;
		rate=(float)tishu2/tishu1;
		printf("回答正确\n");
		printf("正确答案:%d%c%d=%d  答题总数为:%d,答对%d道题,答题正确率:%.2f%%\n",num1,operation,num2,ranswer,tishu1,tishu2,rate*100);
	}
	else
	{
		rate=(float)tishu2/tishu1;
		printf("回答错误\n");
		printf("正确答案:%d%c%d=%d  答题总数为:%d,答对%d道题,答题正确率:%.2f%%\n",num1,operation,num2,ranswer,tishu1,tishu2,rate*100);

	}
	printf("是否继续练习:输入y或n(y表示继续，n表示返回主菜单)\n");
	c=getchar();
	getchar();
}while(c=='y'||c=='Y');
system("cls");
if(c=='n'||c=='N')
maindisplaymenu();
}


void test()//测验模式
{
	if((fp=fopen("d:\\shy.txt","w"))==NULL)
	{
		printf("Can not open this file!\n");
	}
	int grade1=shezhi.score/shezhi.number,grade=0;
	void maindisplaymenu();
	int num1,num2;
	int a;
	int n;
	char name[10];
	tishu2=0;
	float rate;
	srand(time(NULL));//设置种子
	int ranswer;
	int uanswer;
	char operation;
	char c;
	int i;
	printf("请输入您的姓名：");
	scanf("%s",name);
	printf("1.加法运算，2.减法运算，3乘法运算，4。除法运算，5.随机运算:\n");
	printf("请选择想要进行的运算测验:");
	scanf("%d",&a);
	system("cls");
	switch(a)
	{
		case 1:shezhi.leixing=1;shezhi.type=0;break;
		case 2:shezhi.leixing=2;shezhi.type=0;break;
		case 3:shezhi.leixing=3;shezhi.type=0;break;
		case 4:shezhi.leixing=4;shezhi.type=0;break;
		case 5:shezhi.type=1;break;
		default:printf("输入错误！\n");
	}

	for( i=1;i<=shezhi.number;i++)
	{

	if(shezhi.type==1)
	shezhi.leixing=rand()%4+1;
	if(shezhi.nandu==10)
	{

	num1=rand()%shezhi.nandu+0;
	num2=rand()%shezhi.nandu+0;
    }
    else if(shezhi.nandu==90)
    {
   	num1=rand()%shezhi.nandu+10;
	num2=rand()%shezhi.nandu+10;
	}
	else if(shezhi.nandu==900)
	{
	num1=rand()%shezhi.nandu+100;
	num2=rand()%shezhi.nandu+100;
	}
	switch(shezhi.leixing)
	{
		case 1:operation='+';ranswer=num1+num2;break;
		case 2:operation='-';ranswer=num1-num2;break;
		case 3:operation='*';ranswer=num1*num2;break;
		case 4:operation='/';ranswer=num1/num2;break;
	}
	if(operation=='/'&&num2==0)
	{
		num2=1;
	}
	printf("%d%c%d=",num1,operation,num2);
	scanf("%d",&uanswer);
	getchar();
	tishu1++;
	if(uanswer==ranswer)
	{
		tishu2++;
		grade+=grade1;
	}
	fprintf(fp,"%d %c %d %d %d\n",num1,operation,num2,uanswer,ranswer);
}
tishu1=shezhi.number-tishu2;
    fprintf(fp,"%d %d %d %d",shezhi.number,tishu2,tishu1,grade);
    fputs(name,fp);
	fclose(fp);
	if((fp=fopen("d:\\shy.txt","r"))==NULL)
	{
		printf("Can not open this file!\n");
	}
	system("cls");
    printf("题目\t\t答案\n");
    for( i=1;i<=shezhi.number;i++)
    {
    	fscanf(fp,"%d %c %d %d %d\n",&num1,&operation,&num2,&uanswer,&ranswer);
    	printf("%-3d%c%3d=%-4d\t%-4d\n",num1,operation,num2,uanswer,ranswer);
	}
	fscanf(fp,"%d %d %d %d",&shezhi.number,&tishu2,&tishu1,&grade);
    printf("\n");
    printf("总题数\t答对题数\t答错题数\t得分\n");
    printf("%-4d\t%4d\t\t%4d\t\t%4d\n",shezhi.number,tishu2,tishu1,grade);
	printf("点击任意键返回主菜单:\n");
	c=getchar();
	system("cls");
maindisplaymenu();
}

void limt()
{
	void exercise();
	void test();
	void maindisplaymenu();
	int i,m,n,a,b;
	char ch;
	printf("您已进入设置，1.修改测验题数和总分，2.修改计算数据位数\n");
	printf("请选择操作：");
	scanf("%d",&m);
	if(m==1)
	{
		printf("请输入修改后的题数：");
		scanf("%d",&a);
		printf("请输入修改后的总分：");
		scanf("%d",&b);
		shezhi.number=a;
		shezhi.score=b;
		printf("修改成功!\n");
}
	else if(m==2)
	{

	printf("您要将计算数据定为几位数？1.个位运算，2.两位数运算，3.三位数运算\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:shezhi.nandu=10;break;
		case 2:shezhi.nandu=90;break;
		case 3:shezhi.nandu=900;break;
		default:printf("请输入1--3的整数");
	}
	printf("修改成功!\n");
}
    printf("点击任意键返回主菜单:");
    scanf("%c",&ch);
    getchar();
	 system("cls");
    maindisplaymenu();

}

void result()//查看测验结果
{
	void maindisplaymenu();
	system("cls");
	if((fp=fopen("d:\\shy.txt","r"))==NULL)
	{
		printf("Can not open this file!\n");
	}
	else
	printf("最近一次测验结果：\t正确答案\n");
	int a[shezhi.number],b[shezhi.number],c[shezhi.number],d[shezhi.number];
	int j,k,l,m,i;
	char ch[shezhi.number],name[20];
	for(i=0;i<shezhi.number;i++)
	{
		fscanf(fp,"%d %c %d %d %d\n",&a[i],&ch[i],&b[i],&c[i],&d[i]);
		printf("%d%c%d=%-4d\t\t%4d\n",a[i],ch[i],b[i],c[i],d[i]);
	 }
	 fscanf(fp,"%d %d %d %d",&j,&k,&l,&m);
	 fscanf(fp,"%s",name);
	 printf("\n\n");
	 printf("姓名\t答题总数\t答对题数\t答错题数\t得分\n");
	 printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",name,j,k,l,m);
	 char sh;
	 printf("是否返回主菜单：y/n\n");
	 getchar();
	 sh=getchar();
	 if(sh=='y'||sh=='Y')
	 {
	  system("cls");
	 maindisplaymenu();
}
}

int main()
{
	system("color 79");
	maindisplaymenu();
	return 0;
}
