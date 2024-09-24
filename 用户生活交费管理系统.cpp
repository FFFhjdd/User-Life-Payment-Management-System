#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_FILE "User.txt"      //定义一个‘用户信息’文件名 
#define w 1.8                    // 水1.8元/吨
#define e 0.5                    // 电0.5元/



struct user {
char name[20];
char ID[20];
double water;
double electricity;
double money;
} u[100];


//声明函数 
void add();          //添加 
void delete_();      //删除 
void alter();        //修改 
void display();      //显示所有用户的信息 
void save();         //保存 
void m_fee();        //管理收费
void m_user();       //管理用户 



int main(){
int choice = 0;
int n = 0;
FILE* fin;
fin = fopen(USER_FILE, "r");
if (!fin) {
    printf("打开文件失败，请检查文件是否存在或者文件名是否正确。\n");
    exit(1);     //程序已退出，但未正常结束
}
// 从文件中读取用户信息 
while (!feof(fin)) //fin 所指向的文件未到达末尾时继续执行
{
    fscanf(fin, "%s%s%lf%lf", u[n].name, u[n].ID, &u[n].water, &u[n].electricity);
    u[n].money = (u[n].water) * w + (u[n].electricity) * e;
    n++;
}
fclose(fin);
//循环执行用户操作 
while (choice != 3) {
printf("1. 用户管理\n");
printf("2. 收费管理\n");
printf("3. 退出程序\n");
printf("请选择要执行的操作：");
scanf("%d", &choice);
switch (choice) {
case 1:
m_user();
break;
case 2:
m_fee();
break;
case 3:
return 0;
default:
printf("无效的选择，请重新选择。\n");
break;
}
}
return 0;
}


    
void add(){
	int n;                 /*确定当前用户的人数*/
	for(n=0;n<100;n++)
		if(u[n].money==0) break;  //使用一个循环找到结构体数组 u 中的第一个空位置
	printf("\t\t\t请输入新用户的姓名:");
	scanf("%s",u[n].name);
	printf("\t\t\t请输入新用户的ID(18位):");
	scanf("%s",u[n].ID);
	printf("\t\t\t请输入新用户的用水量:");
	scanf("%lf",&u[n].water);
	printf("\t\t\t请输入新用户的用电量:");
	scanf("%lf",&u[n].electricity);
	u[n].money=(u[n].water)*w+(u[n].electricity)*e;
	printf("\n添加成功!\n");
}


void display(){
	int n;                                          /*确定当前用户的人数*/
	int i;
	for(n=0;n<100;n++)
		if(u[n].money==0) break;
	if(n==0)
		printf("系统无用户,需要添加!\n");
	else
		for(i=0;i<n;i++)
			printf("\n编号:%d姓名:%sID:%s用水量:%.1f吨用电量:%.1f度\n",i+1,u[i].name,u[i].ID,u[i].water,u[i].electricity);
}



void delete_(){
    int n,i,j;
    for(n=0;n<100;n++)
        if(u[n].money==0) break;
    display();
    printf("\n\t\t\t请输入要删除用户对应的编号:");
    scanf("%d",&i);
    for(j=i-1;j<n;j++){
        strcpy(u[j].name,u[j+1].name);
        strcpy(u[j].ID,u[j+1].ID);
        u[j].money=u[j+1].money;
        u[j].water=u[j+1].water;
        u[j].electricity=u[j+1].electricity;
    }
if (j == n - 1) { // 如果是最后一个用户，将其 money 值赋为 0
u[j].money = 0;
} else {
strcpy(u[j].name, u[j+1].name);
strcpy(u[j].ID, u[j+1].ID);
u[j].money = u[j+1].money;
u[j].water = u[j+1].water;
u[j].electricity = u[j+1].electricity;
}
//这样，如果 j 是最后一个用户，则不会访问越界的内存。
//如果要删除的用户是数组中的最后一个用户，则将其 money 字段赋值为 0；否则，将最后一个用户的信息覆盖到删除的用户的位置。  
    printf("\n删除成功!\n");
}


void alter()   //修改 
{
	char name[10];
	int n;                     /*确定当前用户的人数*/
	int i;
	printf("\t\t\t请输入您的姓名:");
	scanf("%s",name);
	for(n=0;n<100;n++)
		if(u[n].money==0) break;
	for(i=0;i<n;i++)
		if(strcmp(u[i].name,name)==0)   //确定有这个用户 
		{
			int choice;
			printf("\n\t\t\t1.修改ID\n\t\t\t2.修改用水量\n\t\t\t3.修改用电量\n\t\t\t4.退出\n");
			printf("\n\t\t\t请输入您的选择:");
scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				printf("\n\t\t\t请输入ID:");
				scanf("%s",u[i].ID);
				break;
			case 2:
				printf("\n\t\t\t请输入用水量:");
				scanf("%lf",&u[i].water);
				break;
			case 3:
				printf("\n\t\t\t请输入用电量:");
				scanf("%lf",&u[i].electricity);
				break;
			case 4:
				break;
			default:
            printf("无效的选择，请重新选择。\n");
            break;
				
			}
			printf("\n修改成功!\n");
			break;
		}
		if(i==n)
			printf("\n\t\t\t没有此用户,您可以选择注册新用户!\n");
}


void m_fee()    //计算 
{
	int n, i,choice=0;
	
	double w_sum=0,e_sum=0;

	printf("\t\t\t-----------------------------------\n");
	printf("\t\t\t|    收费管理  |\n");
	printf("\t\t\t-----------------------------------\n\n\n");

	for(n=0;n<100;n++)
		if(u[n].money==0) break;
	printf("\n\t\t\t1.用户费用信息查询\n\t\t\t2.总水费\n\t\t\t3.总电费\n\t\t\t4.总费用\n\t\t\t5.退出\n");
	printf("\n\t\t\t请输入您的选择:");
scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		if(n==0)
			printf("\n\t\t\t系统无注册用户!\n");
		else
			for(i=0;i<n;i++)
			{
				printf("\n\t姓名:%s\t水费:%.2f元\t电费:%.2f元\t缴纳的总费用:%.2f元\n",u[i].name,(u[i].water)*w,(u[i].electricity)*e,u[i].money);
				}
	    break;
    case 2:	
		for(i=0;i<n;i++)
			w_sum+=u[i].water*w;			
				
		printf("\n\t\t\t系统用户缴纳的总水费:%.2f元\n",w_sum);
	
		break;
	case 3:
		for(i=0;i<n;i++)e_sum+=u[i].electricity*e;
		printf("\n\t\t\t系统用户缴纳的总电费:%.2f元\n",e_sum);
		
		break;
	case 4:
		for (i=0;i<n;i++)
		{
		  w_sum+=u[i].water*w;
		  e_sum+=u[i].electricity*e;
		}
		printf("\n\t\t\t系统用户缴纳的总费用:%.2f元\n",w_sum+e_sum);
	    break;
		
	case 5:
		printf("管理完毕!\n");
		break;
	default:
		printf("\n\t\t\t输入错误,请重新输入:");
		break;
	}
}


void save()
{FILE* fout;
int n=0;
fout=fopen("User.txt","w");
while(u[n].money!=0)
{fprintf(fout,"%s\t\t%s\t\t%lf\t\t%lf\n",u[n].name,u[n].ID,u[n].water,u[n].electricity);
 n++;

}
fclose(fout);
}


void m_user()     //用户管理系统的菜单
{
int ii, m, choice = 0;
while (1) {
printf("\t\t\t-----------------------------------\n");
printf("\t\t\t 用户管理 \n");
printf("\t\t\t-----------------------------------\n\n\n");
printf("\n\t\t\t1.显示用户信息\n\t\t\t2.添加用户\n\t\t\t3.修改用户信息\n\t\t\t4.删除用户信息\n\t\t\t5.保存\n\t\t\t6.退出");
printf("\n\t\t\t请输入您的选择:");
scanf("%d", &choice);
switch (choice) {
case 1:
display();
break;
case 2:
printf("请输入要添加的用户数量：");
scanf("%d", &m);
for (ii = 0; ii < m; ii++)
add();
break;
case 3:
alter();
break;
case 4:
delete_();
break;
case 5:
save();
printf("保存成功\n");
break;
case 6:
break;
default:
printf("\t\t\t输入有误,请重新输入:");
}
if (choice == 6)
break;
}
}
