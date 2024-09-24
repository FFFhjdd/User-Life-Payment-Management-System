#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_FILE "User.txt"      //����һ�����û���Ϣ���ļ��� 
#define w 1.8                    // ˮ1.8Ԫ/��
#define e 0.5                    // ��0.5Ԫ/



struct user {
char name[20];
char ID[20];
double water;
double electricity;
double money;
} u[100];


//�������� 
void add();          //��� 
void delete_();      //ɾ�� 
void alter();        //�޸� 
void display();      //��ʾ�����û�����Ϣ 
void save();         //���� 
void m_fee();        //�����շ�
void m_user();       //�����û� 



int main(){
int choice = 0;
int n = 0;
FILE* fin;
fin = fopen(USER_FILE, "r");
if (!fin) {
    printf("���ļ�ʧ�ܣ������ļ��Ƿ���ڻ����ļ����Ƿ���ȷ��\n");
    exit(1);     //�������˳�����δ��������
}
// ���ļ��ж�ȡ�û���Ϣ 
while (!feof(fin)) //fin ��ָ����ļ�δ����ĩβʱ����ִ��
{
    fscanf(fin, "%s%s%lf%lf", u[n].name, u[n].ID, &u[n].water, &u[n].electricity);
    u[n].money = (u[n].water) * w + (u[n].electricity) * e;
    n++;
}
fclose(fin);
//ѭ��ִ���û����� 
while (choice != 3) {
printf("1. �û�����\n");
printf("2. �շѹ���\n");
printf("3. �˳�����\n");
printf("��ѡ��Ҫִ�еĲ�����");
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
printf("��Ч��ѡ��������ѡ��\n");
break;
}
}
return 0;
}


    
void add(){
	int n;                 /*ȷ����ǰ�û�������*/
	for(n=0;n<100;n++)
		if(u[n].money==0) break;  //ʹ��һ��ѭ���ҵ��ṹ������ u �еĵ�һ����λ��
	printf("\t\t\t���������û�������:");
	scanf("%s",u[n].name);
	printf("\t\t\t���������û���ID(18λ):");
	scanf("%s",u[n].ID);
	printf("\t\t\t���������û�����ˮ��:");
	scanf("%lf",&u[n].water);
	printf("\t\t\t���������û����õ���:");
	scanf("%lf",&u[n].electricity);
	u[n].money=(u[n].water)*w+(u[n].electricity)*e;
	printf("\n��ӳɹ�!\n");
}


void display(){
	int n;                                          /*ȷ����ǰ�û�������*/
	int i;
	for(n=0;n<100;n++)
		if(u[n].money==0) break;
	if(n==0)
		printf("ϵͳ���û�,��Ҫ���!\n");
	else
		for(i=0;i<n;i++)
			printf("\n���:%d����:%sID:%s��ˮ��:%.1f���õ���:%.1f��\n",i+1,u[i].name,u[i].ID,u[i].water,u[i].electricity);
}



void delete_(){
    int n,i,j;
    for(n=0;n<100;n++)
        if(u[n].money==0) break;
    display();
    printf("\n\t\t\t������Ҫɾ���û���Ӧ�ı��:");
    scanf("%d",&i);
    for(j=i-1;j<n;j++){
        strcpy(u[j].name,u[j+1].name);
        strcpy(u[j].ID,u[j+1].ID);
        u[j].money=u[j+1].money;
        u[j].water=u[j+1].water;
        u[j].electricity=u[j+1].electricity;
    }
if (j == n - 1) { // ��������һ���û������� money ֵ��Ϊ 0
u[j].money = 0;
} else {
strcpy(u[j].name, u[j+1].name);
strcpy(u[j].ID, u[j+1].ID);
u[j].money = u[j+1].money;
u[j].water = u[j+1].water;
u[j].electricity = u[j+1].electricity;
}
//��������� j �����һ���û����򲻻����Խ����ڴ档
//���Ҫɾ�����û��������е����һ���û������� money �ֶθ�ֵΪ 0�����򣬽����һ���û�����Ϣ���ǵ�ɾ�����û���λ�á�  
    printf("\nɾ���ɹ�!\n");
}


void alter()   //�޸� 
{
	char name[10];
	int n;                     /*ȷ����ǰ�û�������*/
	int i;
	printf("\t\t\t��������������:");
	scanf("%s",name);
	for(n=0;n<100;n++)
		if(u[n].money==0) break;
	for(i=0;i<n;i++)
		if(strcmp(u[i].name,name)==0)   //ȷ��������û� 
		{
			int choice;
			printf("\n\t\t\t1.�޸�ID\n\t\t\t2.�޸���ˮ��\n\t\t\t3.�޸��õ���\n\t\t\t4.�˳�\n");
			printf("\n\t\t\t����������ѡ��:");
scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				printf("\n\t\t\t������ID:");
				scanf("%s",u[i].ID);
				break;
			case 2:
				printf("\n\t\t\t��������ˮ��:");
				scanf("%lf",&u[i].water);
				break;
			case 3:
				printf("\n\t\t\t�������õ���:");
				scanf("%lf",&u[i].electricity);
				break;
			case 4:
				break;
			default:
            printf("��Ч��ѡ��������ѡ��\n");
            break;
				
			}
			printf("\n�޸ĳɹ�!\n");
			break;
		}
		if(i==n)
			printf("\n\t\t\tû�д��û�,������ѡ��ע�����û�!\n");
}


void m_fee()    //���� 
{
	int n, i,choice=0;
	
	double w_sum=0,e_sum=0;

	printf("\t\t\t-----------------------------------\n");
	printf("\t\t\t|    �շѹ���  |\n");
	printf("\t\t\t-----------------------------------\n\n\n");

	for(n=0;n<100;n++)
		if(u[n].money==0) break;
	printf("\n\t\t\t1.�û�������Ϣ��ѯ\n\t\t\t2.��ˮ��\n\t\t\t3.�ܵ��\n\t\t\t4.�ܷ���\n\t\t\t5.�˳�\n");
	printf("\n\t\t\t����������ѡ��:");
scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		if(n==0)
			printf("\n\t\t\tϵͳ��ע���û�!\n");
		else
			for(i=0;i<n;i++)
			{
				printf("\n\t����:%s\tˮ��:%.2fԪ\t���:%.2fԪ\t���ɵ��ܷ���:%.2fԪ\n",u[i].name,(u[i].water)*w,(u[i].electricity)*e,u[i].money);
				}
	    break;
    case 2:	
		for(i=0;i<n;i++)
			w_sum+=u[i].water*w;			
				
		printf("\n\t\t\tϵͳ�û����ɵ���ˮ��:%.2fԪ\n",w_sum);
	
		break;
	case 3:
		for(i=0;i<n;i++)e_sum+=u[i].electricity*e;
		printf("\n\t\t\tϵͳ�û����ɵ��ܵ��:%.2fԪ\n",e_sum);
		
		break;
	case 4:
		for (i=0;i<n;i++)
		{
		  w_sum+=u[i].water*w;
		  e_sum+=u[i].electricity*e;
		}
		printf("\n\t\t\tϵͳ�û����ɵ��ܷ���:%.2fԪ\n",w_sum+e_sum);
	    break;
		
	case 5:
		printf("�������!\n");
		break;
	default:
		printf("\n\t\t\t�������,����������:");
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


void m_user()     //�û�����ϵͳ�Ĳ˵�
{
int ii, m, choice = 0;
while (1) {
printf("\t\t\t-----------------------------------\n");
printf("\t\t\t �û����� \n");
printf("\t\t\t-----------------------------------\n\n\n");
printf("\n\t\t\t1.��ʾ�û���Ϣ\n\t\t\t2.����û�\n\t\t\t3.�޸��û���Ϣ\n\t\t\t4.ɾ���û���Ϣ\n\t\t\t5.����\n\t\t\t6.�˳�");
printf("\n\t\t\t����������ѡ��:");
scanf("%d", &choice);
switch (choice) {
case 1:
display();
break;
case 2:
printf("������Ҫ��ӵ��û�������");
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
printf("����ɹ�\n");
break;
case 6:
break;
default:
printf("\t\t\t��������,����������:");
}
if (choice == 6)
break;
}
}
