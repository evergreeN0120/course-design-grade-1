 										/*********************************************************ѡ�ι���ϵͳ**********************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{			///////////ѧ���ṹ������ 
	char name[20];/////	�������� 
	int number;////ѧ��
	char clas[20];//////�༶ 
	char cname[20][20];//////ѡ��Ŀγ� 
}STU;
typedef struct teacher{			////////////��ʦ�ṹ�� 
	char name[20];///���� 
	int number;///���� 
	char institute[20];///Ժϵ 
	char cname[20][20];///���ڿγ� 
}TEA;
typedef struct course{
	char name[20];///�γ�����
	int number;///�γ̱��
	char institute[20];///�γ�����Ժϵ 
	char tname[20];////���ڵĽ�ʦ 
}COUR;

typedef struct Snode{		////ѧ������ 
	STU data;
	Snode *next;
	
}Snode,*Slist;
typedef struct Tnode{		////��ʦ���� 
	TEA data;
	Tnode *next;
	
}Tnode,*Tlist;
typedef struct Cnode{		////�γ����� 
	COUR data;
	Cnode *next;
}Cnode,*Clist;

int menu()					//////�˵� 
{	int chioce;
	printf("*********��ӭʹ��ѡ�ι���ϵͳ************\n");
	printf("	1.���ѧ����Ϣ\n");
	printf("	2.��ӽ�ʦ��Ϣ\n");
	printf("	3.��ӿγ���Ϣ\n");
	printf("	4.�޸�ѧ����Ϣ\n");	//////����ѧ��������Ϣ���Լ�   ѧ��ѡ��Ŀγ� 
	printf("	5.�޸Ľ�ʦ��Ϣ\n"); /////// ������ʦ�ĸ�����Ϣ���Լ�   ��ʦ���ڵĿγ� 
	printf("	6.�޸Ŀγ���Ϣ\n"); ///////�޸Ŀγ���Ϣ���ڿεص㣬ʱ�䣬�ڿ���ʦ�� 
	printf("	7.��ʾ����ѧ����Ϣ\n");
	printf("	8.��ʾ���пγ���Ϣ\n");
	printf("	9.��ʾ������ʦ��Ϣ\n");
	printf("	10.����ѧ����Ϣ\n");
	printf("	11.������ʦ��Ϣ\n");
	printf("	12.���ҿγ���Ϣ\n");
	printf("**********���������Ĳ���ѡ��**************\n");
	scanf("%d",&chioce);
	getchar();
	return chioce;
 
}
void Sini(Slist &L)		////ѧ�������ʼ�� 
{	L=new Snode;
	L->next=NULL;
	
}
void Cini(Clist &L)		////�γ������ʼ�� 
{	L=new Cnode;
	L->next=NULL;
	
}
void Tini(Tlist &L)		////��ʦ�����ʼ�� 
{	L=new Tnode;
	L->next=NULL;
	
}
void Sinsert(Slist &L)		////ѧ��������� 
{	Slist p=L;
	Slist q;///����Ľ��
	int i=0;
	char ch;
	q=new Snode;
	printf("������ѧ��������: ");
	scanf("%s",q->data.name);
	printf("������ѧ����ѧ�ţ� ");
	scanf("%d",&q->data.number);
	printf("������ѧ���İ༶�� ");
	scanf("%s",q->data.clas);
	printf("������ѧ��ѡ��Ŀγ̣� ");
	do{
		scanf("%s",q->data.cname[i]);
		i++;
		getchar();
		printf("����������y/n ");
		scanf("%c",&ch);
		getchar();
	} while(ch=='y'||ch=='Y');

	strcpy(q->data.cname[i],"0");

	q->next=NULL;
	while(p->next!=NULL) p=p->next;
	p->next=q;

}
void Cinsert(Clist &L)		////�γ�����Ĳ���		
{	Clist p=L;
	Clist q;
	q=new Cnode;
	printf("������γ̵����ƣ�");
	scanf("%s",q->data.name);
	printf("������γ̵ı�ţ�");
	scanf("%d",&q->data.number);
	printf("������γ̵�����Ժϵ�� ");
	scanf("%s",q->data.institute);
	printf("������γ̵��ڿ���ʦ�� ");
	scanf("%s",q->data.tname);
	q->next=NULL;
	while(p->next!=NULL) p=p->next;
	p->next=q;
}
void Tinsert(Tlist &L)		////��ʦ����Ĳ��� 
{	Tlist p=L;
	Tlist q;///����Ľ��
	int i=0;
	char ch;
	q=new Tnode;
	printf("�������ʦ������: ");
	scanf("%s",q->data.name);
	printf("�������ʦ�Ĺ��ţ� ");
	scanf("%d",&q->data.number);
	printf("�������ʦ��Ժϵ�� ");
	scanf("%s",q->data.institute);
	printf("��������ڵĿγ̣� ");
	do{
		scanf("%s",q->data.cname[i]);
		i++;
		getchar();
		printf("����������y/n: ");
		scanf("%c",&ch);
		getchar();
	} while(ch=='y'||ch=='Y');
	strcpy(q->data.cname[i],"0");
	q->next=NULL;
	while(p->next!=NULL) p=p->next;
	p->next=q;

}
void Stravel(Slist L)		////ѧ������ı��� 
{	Slist p=L->next;
	while(p!=NULL){
		int i=0;
		printf("������%s  ѧ�ţ�%d  �༶��%s ��ѡ�γ̣� ",p->data.name,p->data.number,p->data.clas);
		while(strcmp(p->data.cname[i],"0")!=0)
		{	 
			printf("%s ",p->data.cname[i]); 
			i++;
		 } 
		putchar('\n');
		p=p->next;
		
	}
}
void Ctravel(Clist L)		////�γ�����ı��� 
{	Clist p=L->next;
	while(p!=NULL)
	{	printf("���ƣ�%s  ��ţ�%d  ����Ժϵ��%s  �ڿν�ʦ��%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
		putchar('\n');
	}
}
void Ttravel(Tlist L)		////��ʦ����ı���		
{	Tlist p=L->next;
	while(p!=NULL){
		int i=0;
		printf("������%s  ���ţ�%d  Ժϵ��%s ���ڿγ̣� ",p->data.name,p->data.number,p->data.institute);
		while(strcmp(p->data.cname[i],"0")!=0)
		{	 
			printf("%s ",p->data.cname[i]); 
			i++;
		 } 
		putchar('\n');
		p=p->next;
		
	}
}
void Ssearch(Slist L)		////ѧ������Ĳ��� 
{	Slist p=L->next;
	int ch;
	int nu;
	char na[20];
	printf("��������Ҫ���ҵ�ѧ����	1��������2��ѧ��"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1: printf("�������ѧ���ĵ�������"); scanf("%s",na); getchar();
				while(p!=NULL){
					int i=0;
				if(strcmp(p->data.name,na)==0) {
					printf("������%s  ѧ�ţ�%d  �༶��%s  ��ѡ�γ̣� ",p->data.name,p->data.number,p->data.clas);
					while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
				}
				p=p->next;
		}
				if(p=NULL) printf("�޸�ѧ������Ϣ!\n"); 
				break;
		case 2: printf("�������ѧ����ѧ�ţ� "); scanf("%d",&nu); getchar();
				while(p!=NULL){
					int i=0; 
					if(p->data.number==nu) {
						printf("������%s  ѧ�ţ�%d  �༶��%s  ��ѡ�γ̣� ",p->data.name,p->data.number,p->data.clas);
						while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
					}
					p=p->next;
				}
				if(p=NULL) printf("�޸�ѧ������Ϣ!\n"); 
				break;
				
		}
	}
void Tsearch(Tlist L)		////��ʦ����Ĳ��� 
{	Tlist p=L->next;
	int ch;
	int nu;
	char na[20];
	printf("��������Ҫ���ҵĽ�ʦ��1��������2������"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1: printf("������ý�ʦ��������"); scanf("%s",na); getchar(); 
				while(p!=NULL){
					int i=0;
				if(strcmp(p->data.name,na)==0) {
					printf("������%s  ���ţ�%d  Ժϵ��%s  ���ڿγ̣� ",p->data.name,p->data.number,p->data.institute);
					while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
				}
				p=p->next;
		}
				if(p=NULL) printf("�޸ý�ʦ����Ϣ!\n"); 
				break;
		case 2: printf("������ý�ʦ�Ĺ��ţ� "); scanf("%d",&nu); getchar();
				while(p!=NULL){
					int i=0;
					if(p->data.number==nu) {
						printf("������%s  ���ţ�%d  Ժϵ��%s  ���ڿγ̣� ",p->data.name,p->data.number,p->data.institute);
						while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
					}
					p=p->next;
				}
				if(p=NULL) printf("�޸ý�ʦ����Ϣ!\n"); 
				break;
				
		}
	}
void Csearch(Clist L)		////�γ�����Ĳ��� 
{	Clist p=L->next;
	int ch;
	char na[20];
	int nu;
	printf("��������Ҫ���ҵĿγ̵�1�����ƻ�2�����"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1:printf("������γ̵����ƣ�"); scanf("%s",na); getchar();
		while (p!=NULL) {
			if(strcmp(p->data.name,na)==0) {
				printf("���ƣ�%s  ��ţ�%d  ����Ժϵ��%s  �ڿν�ʦ��%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
				break;
			}
			p=p->next;
		}
			   if(p=NULL) printf("�޸ÿγ̵���Ϣ!\n"); 
			   break;
		case 2:printf("������γ̵ı�ţ�"); scanf("%d",&nu); getchar();
		while (p!=NULL) {
			if(nu==p->data.number) {
				printf("���ƣ�%s  ��ţ�%d  ����Ժϵ��%s  �ڿν�ʦ��%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
				break;
			}
			p=p->next;
		}
			   if(p=NULL) printf("�޸ÿγ̵���Ϣ!\n"); 
			   break;
			
	}
}
void Schange(Slist &L)		////ѧ��������޸� 
{	Slist p=L->next;
	int ch;
	int nu;
	char na[20];
	char xg;
	int ch1;
	int ch2;
	char cna1[20];
	char cna2[20];
	printf("��������Ҫ�޸ĵ�ѧ����1��������2��ѧ��"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1: printf("�������ѧ���ĵ�������"); scanf("%s",na); getchar();
				while(p!=NULL){
					int i=0;
				if(strcmp(p->data.name,na)==0) {
					printf("������%s  ѧ�ţ�%d  �༶��%s  ��ѡ�γ̣� ",p->data.name,p->data.number,p->data.clas);
					while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					putchar('\n');
					break;
				}
				p=p->next;
		}
				if(p!=NULL){
				
				do{
					int i=0;
					int n=0;
					int e;
					printf("��Ҫ�޸�ѧ����1������  2��ѧ��  3���༶  4��ѡ��Ŀγ�"); scanf("%d",&ch1); 
					switch(ch1){
						case 1: printf("�������޸ĺ��ѧ��������: "); scanf("%s",p->data.name); getchar(); printf("�޸ĳɹ�!\n"); break;
						case 2: printf("�������޸ĺ��ѧ����ѧ��: "); scanf("%d",&p->data.number); getchar(); printf("�޸ĳɹ�\n"); break;
						case 3: printf("�������޸ĺ��ѧ���İ༶: "); scanf("%s",p->data.clas); getchar(); printf("�޸ĳɹ�\n"); break;
						case 4: printf("Ҫ1.�޸Ŀγ̻���2.ɾ���γ̣�"); scanf("%d",&ch2); getchar(); 
								printf("������Ҫ�޸ĵĿγ����ƣ�");  scanf("%s",cna1); getchar();
								switch(ch2){
									case 1: 
											printf("�������޸ĺ�Ŀγ����ƣ� "); scanf("%s",cna2); getchar();
											while(strcmp("0",p->data.cname[i])!=0){
												if(strcmp(p->data.cname[i],cna1)==0) strcpy(p->data.cname[i],cna2);
												i++;
											}
											printf("�޸ĳɹ�!\n");
											 break;
											
									case 2: 
											while(strcmp(cna1,p->data.cname[i])!=0)  i++;
											while(strcmp("0",p->data.cname[n])!=0) n++;
											for(e=i;e<n;e++){
												strcpy(p->data.cname[e],p->data.cname[e+1]);
											}
											printf("ɾ���ɹ�!\n");
											break;
								}
	
					}
					printf("��Ҫ�ٴ��޸��� y/n"); scanf("%c",&xg); getchar();
					
				}while(xg=='y'||xg=='Y');
				}
				
				else printf("�޸�ѧ������Ϣ!\n");
				
				break;
		case 2: printf("�������ѧ����ѧ�ţ� "); scanf("%d",&nu);
				while(p!=NULL){
					int i=0; 
					if(p->data.number==nu) {
						printf("������%s  ѧ�ţ�%d  �༶��%s  ��ѡ�γ̣� ",p->data.name,p->data.number,p->data.clas);
						while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
					}
					p=p->next;
				}
				if(p!=NULL){
				
				do{
					int i=0;
					int n=0;
					int e;
					printf("��Ҫ�޸�ѧ����1������  2��ѧ��  3���༶  4��ѡ��Ŀγ�"); scanf("%d",&ch1); 
					switch(ch1){
						case 1: printf("�������޸ĺ��ѧ��������: "); scanf("%s",p->data.name); getchar(); printf("�޸ĳɹ�!\n"); break;
						case 2: printf("�������޸ĺ��ѧ����ѧ��: "); scanf("%d",&p->data.number); getchar(); printf("�޸ĳɹ�\n"); break;
						case 3: printf("�������޸ĺ��ѧ���İ༶: "); scanf("%s",p->data.clas); getchar(); printf("�޸ĳɹ�\n"); break;
						case 4: printf("Ҫ1.�޸Ŀγ̻���2.ɾ���γ̣�"); scanf("%d",&ch2); getchar(); 
								printf("������Ҫ�޸ĵĿγ����ƣ�");  scanf("%s",cna1);getchar();
								switch(ch2){
									case 1: 
											printf("�������޸ĺ�Ŀγ����ƣ� "); scanf("%s",cna2); getchar();
											while(strcmp("0",p->data.cname[i])!=0){
												if(strcmp(p->data.cname[i],cna1)==0) strcpy(p->data.cname[i],cna2);
												i++;
											}
											printf("�޸ĳɹ�!\n"); break;
									case 2: 
											while(strcmp(cna1,p->data.cname[i])!=0)  i++;
											while(strcmp("0",p->data.cname[n])!=0) n++;
											for(e=i;e<n;e++){
												strcpy(p->data.cname[e],p->data.cname[e+1]);
											}
											break;
								}
	
					}
					printf("��Ҫ�ٴ��޸��� y/n"); scanf("%c",&xg); getchar();
					
				}while(xg=='y'||xg=='Y');
				}
				else printf("�޸�ѧ������Ϣ!\n");
				
				break;
				
		}
	}
void Tchange(Tlist &L)		////��ʦ������޸� 
{	Tlist p=L->next;
	int ch;
	int nu;
	char na[20];
	char xg;
	int ch1;
	int ch2;
	char cna1[20];
	char cna2[20];
	printf("��������Ҫ�޸ĵĽ�ʦ��1��������2������"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1: printf("������ý�ʦ��������"); scanf("%s",na); getchar();
				while(p!=NULL){
					int i=0;
				if(strcmp(p->data.name,na)==0) {
					printf("������%s  ���ţ�%d  Ժϵ��%s  ���ڿγ̣� ",p->data.name,p->data.number,p->data.institute);
					while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					putchar('\n');
					break;
				}
				p=p->next;
		}
				if(p!=NULL){
				
				do{
					int i=0;
					int n=0;
					int e;
					printf("��Ҫ�޸Ľ�ʦ��1������  2������  3��Ժϵ  4�����ڵĿγ�"); scanf("%d",&ch1); 
					switch(ch1){
						case 1: printf("�������޸ĺ�Ľ�ʦ������: "); scanf("%s",p->data.name); getchar(); printf("�޸ĳɹ�!\n"); break;
						case 2: printf("�������޸ĺ�Ľ�ʦ�Ĺ���: "); scanf("%d",&p->data.number); getchar(); printf("�޸ĳɹ�\n"); break;
						case 3: printf("�������޸ĺ�Ľ�ʦ��Ժϵ: "); scanf("%s",p->data.institute); getchar(); printf("�޸ĳɹ�\n"); break;
						case 4: printf("Ҫ1.�޸Ŀγ̻���2.ɾ���γ̣�"); scanf("%d",&ch2); getchar(); 
								printf("������Ҫ�޸ĵĿγ����ƣ�");  scanf("%s",cna1);getchar();
								switch(ch2){
									case 1: 
											printf("�������޸ĺ�Ŀγ����ƣ� "); scanf("%s",cna2); getchar();
											while(strcmp("0",p->data.cname[i])!=0){
												if(strcmp(p->data.cname[i],cna1)==0) strcpy(p->data.cname[i],cna2);
												break;
												i++;
											}
											printf("�޸ĳɹ�!\n");
											 break;
									case 2: 
											while(strcmp(cna1,p->data.cname[i])!=0)  i++;
											while(strcmp("0",p->data.cname[n])!=0) n++;
											for(e=i;e<n;e++){
												strcpy(p->data.cname[e],p->data.cname[e+1]);
											}
											printf("ɾ���ɹ�!\n");
											break;
								}
	
					}
					printf("��Ҫ�ٴ��޸��� y/n"); scanf("%c",&xg); getchar();
					
				}while(xg=='y'||xg=='Y');
				}
				
				else printf("�޸ý�ʦ����Ϣ!\n");
				
				break;
		case 2: printf("������ý�ʦ�Ĺ��ţ� "); scanf("%d",&nu);
				while(p!=NULL){
					int i=0; 
					if(p->data.number==nu) {
						printf("������%s  ���ţ�%d  Ժϵ��%s  ���ڿγ̣� ",p->data.name,p->data.number,p->data.institute);
						while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
					}
					p=p->next;
				}
				if(p!=NULL){
				
				do{
				int i=0;
				int n=0;
				int e;
					printf("��Ҫ�޸�ѧ����1������  2������  3��Ժϵ  4�����ڵĿγ�"); scanf("%d",&ch1); 
					switch(ch1){
						case 1: printf("�������޸ĺ�Ľ�ʦ������: "); scanf("%s",p->data.name); getchar(); printf("�޸ĳɹ�!\n"); break;
						case 2: printf("�������޸ĺ�Ľ�ʦ�Ĺ���: "); scanf("%d",&p->data.number); getchar(); printf("�޸ĳɹ�\n"); break;
						case 3: printf("�������޸ĺ�Ľ�ʦ��Ժϵ: "); scanf("%s",p->data.institute); getchar(); printf("�޸ĳɹ�\n"); break;
						case 4: printf("Ҫ1.�޸Ŀγ̻���2.ɾ���γ̣�"); scanf("%d",&ch2); getchar(); 
								printf("������Ҫ�޸ĵĿγ����ƣ�");  scanf("%s",cna1);getchar();
								switch(ch2){
									case 1: 
											printf("�������޸ĺ�Ŀγ����ƣ� "); scanf("%s",cna2); getchar();
											while(strcmp("0",p->data.cname[i])!=0){
												if(strcmp(p->data.cname[i],cna1)==0) strcpy(p->data.cname[i],cna2);
												break; 
												i++;
											}
											printf("�޸ĳɹ�!\n"); 
											break;
									case 2: 
											while(strcmp(cna1,p->data.cname[i])!=0)  i++;
											while(strcmp("0",p->data.cname[n])!=0) n++;
											for(e=i;e<n;e++){
												strcpy(p->data.cname[e],p->data.cname[e+1]);
											}
											printf("ɾ���ɹ�!\n");
											break;
								}
	
					}
					printf("��Ҫ�ٴ��޸��� y/n "); scanf("%c",&xg); getchar();
					
				}while(xg=='y'||xg=='Y');
				}
				else printf("�޸�ѧ������Ϣ!\n");
				
				break;
				
		}
	}
void Cchange(Clist &L)		////�γ�������޸� 
{	Clist p=L->next;
	int ch;
	int ch1;
	char na[20];
	int nu;
	char xg;
	printf("��������Ҫ�޸ĵĿγ̵�1�����ƻ�2�����"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1:printf("������γ̵����ƣ�"); scanf("%s",na); 
		while (p!=NULL) {
			if(strcmp(p->data.name,na)==0) {
				printf("���ƣ�%s  ��ţ�%d  ����Ժϵ��%s  �ڿν�ʦ��%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
				break;
			}
			p=p->next;
		}
			   if(p=NULL) printf("�޸ÿγ̵���Ϣ!\n"); 
			   else{
			   		do{
			   			printf("��Ҫ�޸Ŀγ̵�1.���� 2.��� 3.����Ժϵ 4.�ڿν�ʦ"); scanf("%d",&ch1); getchar();
			   			switch(ch1){
			   				case 1: printf("�������޸ĺ�Ŀγ̵����ƣ�"); scanf("%s",p->data.name); getchar(); break;
			   				case 2: printf("�������޸ĺ�Ŀγ̵ı�ţ�"); scanf("%d",&p->data.number); getchar(); break;
			   				case 3: printf("�������޸ĺ������Ժϵ��"); scanf("%s",p->data.institute); getchar(); break;
			   				case 4: printf("�������޸ĺ���ڿν�ʦ��"); scanf("%s",p->data.tname); getchar(); break;
						   }
						printf("��Ҫ�����޸��� y/n "); scanf("%c",&xg); getchar();
						
						
			   			
					   }while(xg=='y'||xg=='Y');
			   }
			   break;
		case 2:printf("������γ̵ı�ţ�"); scanf("%d",&nu);
		while (p!=NULL) {
			if(nu==p->data.number) {
				printf("���ƣ�%s  ��ţ�%d  ����Ժϵ��%s  �ڿν�ʦ��%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
				break;
			}
			p=p->next;
		}
			   if(p=NULL) printf("�޸ÿγ̵���Ϣ!\n"); 
			   else{
			   		do{
			   			printf("��Ҫ�޸Ŀγ̵�1.���� 2.��� 3.����Ժϵ 4.�ڿν�ʦ"); scanf("%d",&ch1); getchar();
			   			switch(ch1){
			   				case 1: printf("�������޸ĺ�Ŀγ̵����ƣ�"); scanf("%s",p->data.name); getchar(); break;
			   				case 2: printf("�������޸ĺ�Ŀγ̵ı�ţ�"); scanf("%d",&p->data.number); getchar(); break;
			   				case 3: printf("�������޸ĺ������Ժϵ��"); scanf("%s",p->data.institute); getchar(); break;
			   				case 4: printf("�������޸ĺ���ڿν�ʦ��"); scanf("%s",p->data.tname); getchar(); break;
						   }
						printf("��Ҫ�����޸��� y/n "); scanf("%c",&xg); getchar();
						
						
			   			
					   }while(xg=='y'||xg=='Y');
			   		
			   }
			   break;
			
	}	
}
	int main()
{	char  yn='y';
	int mn=0;
	Slist SL;
	Clist CL;
	Tlist TL;
	Sini(SL);//////��ʼ�� 
	Cini(CL);
	Tini(TL);
	
	
	
	while(yn=='y'||yn=='Y')
	{	system("cls");
		mn=menu();
		switch(mn){
			case 1: Sinsert(SL); printf("��ӳɹ�!\n"); break;
			case 2: Tinsert(TL); printf("��ӳɹ�!\n"); break;
			case 3: Cinsert(CL); printf("��ӳɹ�!\n"); break;
			case 4: Schange(SL); break;
			case 5: Tchange(TL); break;
			case 6: Cchange(CL); break;
			case 7: Stravel(SL); break;
			case 8: Ctravel(CL); break;
			case 9: Ttravel(TL); break;
			case 10:Ssearch(SL); break;
			case 11:Tsearch(TL); break;
			case 12:Csearch(CL); break;

			
			
			
		}
		printf("�ٴβ����� y/n�� ");
		scanf("%c",&yn); 
		getchar();///���ջس� 
	}
	
}
