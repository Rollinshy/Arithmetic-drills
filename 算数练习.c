#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>

struct person
{
	int number;//���ò�������
	int score;//���ò����ܷ�
	int nandu; //���ü�������λ��
	int leixing;//�����������
	int type;//�������
}shezhi={10,100,90,1,1};

int tishu1,tishu2;
FILE *fp;//�����ļ�ָ��


void maindisplaymenu()//��ʾ���˵�
{
	void exercise();
	void test();
	void limt();
	void result();
	printf("                               ������ϰ                                      \n\n\n");
	printf("                               1����ϰ                                       \n");
	printf("                               2������                                       \n");
	printf("                               3������                                       \n");
	printf("                               4���鿴����ɼ�                               \n");
	printf("                               0:�˳�ϵͳ                                    \n");
	int select;
	do
	{
	printf("��ѡ������еĹ��ܣ�");
	scanf("%d",&select);
		switch(select)
		{
			case 1:exercise();break;
			case 2:test();break;
			case 3:limt();break;
		    case 4:result();break;
		    case 0:exit(0);
		    default:printf("����������޶�Ӧ���ܻ������������������:\n");
		}
	}while(select<0||select>4);
}

void exercise()//��ϰģʽ
{
	void maindisplaymenu();
	int num1,num2;
	int a;
	int n;

	tishu1=0;tishu2=0;
	float rate;
	srand(time(NULL));//��������
	int ranswer;
	int uanswer;
	char operation;
	char c;
	printf("1.�ӷ����㣬2.�������㣬3�˷����㣬4���������㣬5.�������:\n");
	printf("��ѡ����Ҫ���е�������ϰ:");
	scanf("%d",&a);
	system("cls");
	switch(a)
	{
		case 1:shezhi.leixing=1;shezhi.type=0;break;
		case 2:shezhi.leixing=2;shezhi.type=0;break;
		case 3:shezhi.leixing=3;shezhi.type=0;break;
		case 4:shezhi.leixing=4;shezhi.type=0;break;
		case 5:shezhi.type=1;break;
		default:printf("�������\n");
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
		printf("�ش���ȷ\n");
		printf("��ȷ��:%d%c%d=%d  ��������Ϊ:%d,���%d����,������ȷ��:%.2f%%\n",num1,operation,num2,ranswer,tishu1,tishu2,rate*100);
	}
	else
	{
		rate=(float)tishu2/tishu1;
		printf("�ش����\n");
		printf("��ȷ��:%d%c%d=%d  ��������Ϊ:%d,���%d����,������ȷ��:%.2f%%\n",num1,operation,num2,ranswer,tishu1,tishu2,rate*100);

	}
	printf("�Ƿ������ϰ:����y��n(y��ʾ������n��ʾ�������˵�)\n");
	c=getchar();
	getchar();
}while(c=='y'||c=='Y');
system("cls");
if(c=='n'||c=='N')
maindisplaymenu();
}


void test()//����ģʽ
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
	srand(time(NULL));//��������
	int ranswer;
	int uanswer;
	char operation;
	char c;
	int i;
	printf("����������������");
	scanf("%s",name);
	printf("1.�ӷ����㣬2.�������㣬3�˷����㣬4���������㣬5.�������:\n");
	printf("��ѡ����Ҫ���е��������:");
	scanf("%d",&a);
	system("cls");
	switch(a)
	{
		case 1:shezhi.leixing=1;shezhi.type=0;break;
		case 2:shezhi.leixing=2;shezhi.type=0;break;
		case 3:shezhi.leixing=3;shezhi.type=0;break;
		case 4:shezhi.leixing=4;shezhi.type=0;break;
		case 5:shezhi.type=1;break;
		default:printf("�������\n");
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
    printf("��Ŀ\t\t��\n");
    for( i=1;i<=shezhi.number;i++)
    {
    	fscanf(fp,"%d %c %d %d %d\n",&num1,&operation,&num2,&uanswer,&ranswer);
    	printf("%-3d%c%3d=%-4d\t%-4d\n",num1,operation,num2,uanswer,ranswer);
	}
	fscanf(fp,"%d %d %d %d",&shezhi.number,&tishu2,&tishu1,&grade);
    printf("\n");
    printf("������\t�������\t�������\t�÷�\n");
    printf("%-4d\t%4d\t\t%4d\t\t%4d\n",shezhi.number,tishu2,tishu1,grade);
	printf("���������������˵�:\n");
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
	printf("���ѽ������ã�1.�޸Ĳ����������ܷ֣�2.�޸ļ�������λ��\n");
	printf("��ѡ�������");
	scanf("%d",&m);
	if(m==1)
	{
		printf("�������޸ĺ��������");
		scanf("%d",&a);
		printf("�������޸ĺ���ܷ֣�");
		scanf("%d",&b);
		shezhi.number=a;
		shezhi.score=b;
		printf("�޸ĳɹ�!\n");
}
	else if(m==2)
	{

	printf("��Ҫ���������ݶ�Ϊ��λ����1.��λ���㣬2.��λ�����㣬3.��λ������\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:shezhi.nandu=10;break;
		case 2:shezhi.nandu=90;break;
		case 3:shezhi.nandu=900;break;
		default:printf("������1--3������");
	}
	printf("�޸ĳɹ�!\n");
}
    printf("���������������˵�:");
    scanf("%c",&ch);
    getchar();
	 system("cls");
    maindisplaymenu();

}

void result()//�鿴������
{
	void maindisplaymenu();
	system("cls");
	if((fp=fopen("d:\\shy.txt","r"))==NULL)
	{
		printf("Can not open this file!\n");
	}
	else
	printf("���һ�β�������\t��ȷ��\n");
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
	 printf("����\t��������\t�������\t�������\t�÷�\n");
	 printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",name,j,k,l,m);
	 char sh;
	 printf("�Ƿ񷵻����˵���y/n\n");
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
