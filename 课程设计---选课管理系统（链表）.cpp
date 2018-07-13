 										/*********************************************************选课管理系统**********************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{			///////////学生结构体类型 
	char name[20];/////	中文名字 
	int number;////学号
	char clas[20];//////班级 
	char cname[20][20];//////选择的课程 
}STU;
typedef struct teacher{			////////////教师结构体 
	char name[20];///姓名 
	int number;///工号 
	char institute[20];///院系 
	char cname[20][20];///教授课程 
}TEA;
typedef struct course{
	char name[20];///课程名称
	int number;///课程编号
	char institute[20];///课程所属院系 
	char tname[20];////教授的教师 
}COUR;

typedef struct Snode{		////学生链表 
	STU data;
	Snode *next;
	
}Snode,*Slist;
typedef struct Tnode{		////教师链表 
	TEA data;
	Tnode *next;
	
}Tnode,*Tlist;
typedef struct Cnode{		////课程链表 
	COUR data;
	Cnode *next;
}Cnode,*Clist;

int menu()					//////菜单 
{	int chioce;
	printf("*********欢迎使用选课管理系统************\n");
	printf("	1.添加学生信息\n");
	printf("	2.添加教师信息\n");
	printf("	3.添加课程信息\n");
	printf("	4.修改学生信息\n");	//////包括学生个人信息，以及   学生选择的课程 
	printf("	5.修改教师信息\n"); /////// 包括老师的个人信息，以及   老师教授的课程 
	printf("	6.修改课程信息\n"); ///////修改课程信息（授课地点，时间，授课老师） 
	printf("	7.显示所有学生信息\n");
	printf("	8.显示所有课程信息\n");
	printf("	9.显示所有老师信息\n");
	printf("	10.查找学生信息\n");
	printf("	11.查找老师信息\n");
	printf("	12.查找课程信息\n");
	printf("**********请输入您的操作选项**************\n");
	scanf("%d",&chioce);
	getchar();
	return chioce;
 
}
void Sini(Slist &L)		////学生链表初始化 
{	L=new Snode;
	L->next=NULL;
	
}
void Cini(Clist &L)		////课程链表初始化 
{	L=new Cnode;
	L->next=NULL;
	
}
void Tini(Tlist &L)		////教师链表初始化 
{	L=new Tnode;
	L->next=NULL;
	
}
void Sinsert(Slist &L)		////学生链表插入 
{	Slist p=L;
	Slist q;///插入的结点
	int i=0;
	char ch;
	q=new Snode;
	printf("请输入学生的姓名: ");
	scanf("%s",q->data.name);
	printf("请输入学生的学号： ");
	scanf("%d",&q->data.number);
	printf("请输入学生的班级： ");
	scanf("%s",q->data.clas);
	printf("请输入学生选择的课程： ");
	do{
		scanf("%s",q->data.cname[i]);
		i++;
		getchar();
		printf("继续输入吗？y/n ");
		scanf("%c",&ch);
		getchar();
	} while(ch=='y'||ch=='Y');

	strcpy(q->data.cname[i],"0");

	q->next=NULL;
	while(p->next!=NULL) p=p->next;
	p->next=q;

}
void Cinsert(Clist &L)		////课程链表的插入		
{	Clist p=L;
	Clist q;
	q=new Cnode;
	printf("请输入课程的名称：");
	scanf("%s",q->data.name);
	printf("请输入课程的编号：");
	scanf("%d",&q->data.number);
	printf("请输入课程的所属院系： ");
	scanf("%s",q->data.institute);
	printf("请输入课程的授课老师： ");
	scanf("%s",q->data.tname);
	q->next=NULL;
	while(p->next!=NULL) p=p->next;
	p->next=q;
}
void Tinsert(Tlist &L)		////教师链表的插入 
{	Tlist p=L;
	Tlist q;///插入的结点
	int i=0;
	char ch;
	q=new Tnode;
	printf("请输入教师的姓名: ");
	scanf("%s",q->data.name);
	printf("请输入教师的工号： ");
	scanf("%d",&q->data.number);
	printf("请输入教师的院系： ");
	scanf("%s",q->data.institute);
	printf("请输入教授的课程： ");
	do{
		scanf("%s",q->data.cname[i]);
		i++;
		getchar();
		printf("继续输入吗？y/n: ");
		scanf("%c",&ch);
		getchar();
	} while(ch=='y'||ch=='Y');
	strcpy(q->data.cname[i],"0");
	q->next=NULL;
	while(p->next!=NULL) p=p->next;
	p->next=q;

}
void Stravel(Slist L)		////学生链表的遍历 
{	Slist p=L->next;
	while(p!=NULL){
		int i=0;
		printf("姓名：%s  学号：%d  班级：%s 所选课程： ",p->data.name,p->data.number,p->data.clas);
		while(strcmp(p->data.cname[i],"0")!=0)
		{	 
			printf("%s ",p->data.cname[i]); 
			i++;
		 } 
		putchar('\n');
		p=p->next;
		
	}
}
void Ctravel(Clist L)		////课程链表的遍历 
{	Clist p=L->next;
	while(p!=NULL)
	{	printf("名称：%s  编号：%d  所属院系：%s  授课教师：%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
		putchar('\n');
	}
}
void Ttravel(Tlist L)		////教师链表的遍历		
{	Tlist p=L->next;
	while(p!=NULL){
		int i=0;
		printf("姓名：%s  工号：%d  院系：%s 教授课程： ",p->data.name,p->data.number,p->data.institute);
		while(strcmp(p->data.cname[i],"0")!=0)
		{	 
			printf("%s ",p->data.cname[i]); 
			i++;
		 } 
		putchar('\n');
		p=p->next;
		
	}
}
void Ssearch(Slist L)		////学生链表的查找 
{	Slist p=L->next;
	int ch;
	int nu;
	char na[20];
	printf("请输入您要查找的学生的	1：姓名或2：学号"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1: printf("请输入该学生的的姓名："); scanf("%s",na); getchar();
				while(p!=NULL){
					int i=0;
				if(strcmp(p->data.name,na)==0) {
					printf("姓名：%s  学号：%d  班级：%s  所选课程： ",p->data.name,p->data.number,p->data.clas);
					while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
				}
				p=p->next;
		}
				if(p=NULL) printf("无该学生的信息!\n"); 
				break;
		case 2: printf("请输入该学生的学号： "); scanf("%d",&nu); getchar();
				while(p!=NULL){
					int i=0; 
					if(p->data.number==nu) {
						printf("姓名：%s  学号：%d  班级：%s  所选课程： ",p->data.name,p->data.number,p->data.clas);
						while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
					}
					p=p->next;
				}
				if(p=NULL) printf("无该学生的信息!\n"); 
				break;
				
		}
	}
void Tsearch(Tlist L)		////教师链表的查找 
{	Tlist p=L->next;
	int ch;
	int nu;
	char na[20];
	printf("请输入您要查找的教师的1：姓名或2：工号"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1: printf("请输入该教师的姓名："); scanf("%s",na); getchar(); 
				while(p!=NULL){
					int i=0;
				if(strcmp(p->data.name,na)==0) {
					printf("姓名：%s  工号：%d  院系：%s  教授课程： ",p->data.name,p->data.number,p->data.institute);
					while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
				}
				p=p->next;
		}
				if(p=NULL) printf("无该教师的信息!\n"); 
				break;
		case 2: printf("请输入该教师的工号： "); scanf("%d",&nu); getchar();
				while(p!=NULL){
					int i=0;
					if(p->data.number==nu) {
						printf("姓名：%s  工号：%d  院系：%s  教授课程： ",p->data.name,p->data.number,p->data.institute);
						while(strcmp(p->data.cname[i],"0")!=0){
						printf("%s ",p->data.cname[i]);
						i++;
					}
					break;
					}
					p=p->next;
				}
				if(p=NULL) printf("无该教师的信息!\n"); 
				break;
				
		}
	}
void Csearch(Clist L)		////课程链表的查找 
{	Clist p=L->next;
	int ch;
	char na[20];
	int nu;
	printf("请输入您要查找的课程的1：名称或2：编号"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1:printf("请输入课程的名称："); scanf("%s",na); getchar();
		while (p!=NULL) {
			if(strcmp(p->data.name,na)==0) {
				printf("名称：%s  编号：%d  所属院系：%s  授课教师：%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
				break;
			}
			p=p->next;
		}
			   if(p=NULL) printf("无该课程的信息!\n"); 
			   break;
		case 2:printf("请输入课程的编号："); scanf("%d",&nu); getchar();
		while (p!=NULL) {
			if(nu==p->data.number) {
				printf("名称：%s  编号：%d  所属院系：%s  授课教师：%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
				break;
			}
			p=p->next;
		}
			   if(p=NULL) printf("无该课程的信息!\n"); 
			   break;
			
	}
}
void Schange(Slist &L)		////学生链表的修改 
{	Slist p=L->next;
	int ch;
	int nu;
	char na[20];
	char xg;
	int ch1;
	int ch2;
	char cna1[20];
	char cna2[20];
	printf("请输入您要修改的学生的1：姓名或2：学号"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1: printf("请输入该学生的的姓名："); scanf("%s",na); getchar();
				while(p!=NULL){
					int i=0;
				if(strcmp(p->data.name,na)==0) {
					printf("姓名：%s  学号：%d  班级：%s  所选课程： ",p->data.name,p->data.number,p->data.clas);
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
					printf("您要修改学生的1：姓名  2：学号  3：班级  4：选择的课程"); scanf("%d",&ch1); 
					switch(ch1){
						case 1: printf("请输入修改后的学生的姓名: "); scanf("%s",p->data.name); getchar(); printf("修改成功!\n"); break;
						case 2: printf("请输入修改后的学生的学号: "); scanf("%d",&p->data.number); getchar(); printf("修改成功\n"); break;
						case 3: printf("请输入修改后的学生的班级: "); scanf("%s",p->data.clas); getchar(); printf("修改成功\n"); break;
						case 4: printf("要1.修改课程还是2.删除课程？"); scanf("%d",&ch2); getchar(); 
								printf("请输入要修改的课程名称：");  scanf("%s",cna1); getchar();
								switch(ch2){
									case 1: 
											printf("请输入修改后的课程名称： "); scanf("%s",cna2); getchar();
											while(strcmp("0",p->data.cname[i])!=0){
												if(strcmp(p->data.cname[i],cna1)==0) strcpy(p->data.cname[i],cna2);
												i++;
											}
											printf("修改成功!\n");
											 break;
											
									case 2: 
											while(strcmp(cna1,p->data.cname[i])!=0)  i++;
											while(strcmp("0",p->data.cname[n])!=0) n++;
											for(e=i;e<n;e++){
												strcpy(p->data.cname[e],p->data.cname[e+1]);
											}
											printf("删除成功!\n");
											break;
								}
	
					}
					printf("需要再次修改吗？ y/n"); scanf("%c",&xg); getchar();
					
				}while(xg=='y'||xg=='Y');
				}
				
				else printf("无该学生的信息!\n");
				
				break;
		case 2: printf("请输入该学生的学号： "); scanf("%d",&nu);
				while(p!=NULL){
					int i=0; 
					if(p->data.number==nu) {
						printf("姓名：%s  学号：%d  班级：%s  所选课程： ",p->data.name,p->data.number,p->data.clas);
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
					printf("您要修改学生的1：姓名  2：学号  3：班级  4：选择的课程"); scanf("%d",&ch1); 
					switch(ch1){
						case 1: printf("请输入修改后的学生的姓名: "); scanf("%s",p->data.name); getchar(); printf("修改成功!\n"); break;
						case 2: printf("请输入修改后的学生的学号: "); scanf("%d",&p->data.number); getchar(); printf("修改成功\n"); break;
						case 3: printf("请输入修改后的学生的班级: "); scanf("%s",p->data.clas); getchar(); printf("修改成功\n"); break;
						case 4: printf("要1.修改课程还是2.删除课程？"); scanf("%d",&ch2); getchar(); 
								printf("请输入要修改的课程名称：");  scanf("%s",cna1);getchar();
								switch(ch2){
									case 1: 
											printf("请输入修改后的课程名称： "); scanf("%s",cna2); getchar();
											while(strcmp("0",p->data.cname[i])!=0){
												if(strcmp(p->data.cname[i],cna1)==0) strcpy(p->data.cname[i],cna2);
												i++;
											}
											printf("修改成功!\n"); break;
									case 2: 
											while(strcmp(cna1,p->data.cname[i])!=0)  i++;
											while(strcmp("0",p->data.cname[n])!=0) n++;
											for(e=i;e<n;e++){
												strcpy(p->data.cname[e],p->data.cname[e+1]);
											}
											break;
								}
	
					}
					printf("需要再次修改吗？ y/n"); scanf("%c",&xg); getchar();
					
				}while(xg=='y'||xg=='Y');
				}
				else printf("无该学生的信息!\n");
				
				break;
				
		}
	}
void Tchange(Tlist &L)		////教师链表的修改 
{	Tlist p=L->next;
	int ch;
	int nu;
	char na[20];
	char xg;
	int ch1;
	int ch2;
	char cna1[20];
	char cna2[20];
	printf("请输入您要修改的教师的1：姓名或2：工号"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1: printf("请输入该教师的姓名："); scanf("%s",na); getchar();
				while(p!=NULL){
					int i=0;
				if(strcmp(p->data.name,na)==0) {
					printf("姓名：%s  工号：%d  院系：%s  教授课程： ",p->data.name,p->data.number,p->data.institute);
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
					printf("您要修改教师的1：姓名  2：工号  3：院系  4：教授的课程"); scanf("%d",&ch1); 
					switch(ch1){
						case 1: printf("请输入修改后的教师的姓名: "); scanf("%s",p->data.name); getchar(); printf("修改成功!\n"); break;
						case 2: printf("请输入修改后的教师的工号: "); scanf("%d",&p->data.number); getchar(); printf("修改成功\n"); break;
						case 3: printf("请输入修改后的教师的院系: "); scanf("%s",p->data.institute); getchar(); printf("修改成功\n"); break;
						case 4: printf("要1.修改课程还是2.删除课程？"); scanf("%d",&ch2); getchar(); 
								printf("请输入要修改的课程名称：");  scanf("%s",cna1);getchar();
								switch(ch2){
									case 1: 
											printf("请输入修改后的课程名称： "); scanf("%s",cna2); getchar();
											while(strcmp("0",p->data.cname[i])!=0){
												if(strcmp(p->data.cname[i],cna1)==0) strcpy(p->data.cname[i],cna2);
												break;
												i++;
											}
											printf("修改成功!\n");
											 break;
									case 2: 
											while(strcmp(cna1,p->data.cname[i])!=0)  i++;
											while(strcmp("0",p->data.cname[n])!=0) n++;
											for(e=i;e<n;e++){
												strcpy(p->data.cname[e],p->data.cname[e+1]);
											}
											printf("删除成功!\n");
											break;
								}
	
					}
					printf("需要再次修改吗？ y/n"); scanf("%c",&xg); getchar();
					
				}while(xg=='y'||xg=='Y');
				}
				
				else printf("无该教师的信息!\n");
				
				break;
		case 2: printf("请输入该教师的工号： "); scanf("%d",&nu);
				while(p!=NULL){
					int i=0; 
					if(p->data.number==nu) {
						printf("姓名：%s  工号：%d  院系：%s  教授课程： ",p->data.name,p->data.number,p->data.institute);
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
					printf("您要修改学生的1：姓名  2：工号  3：院系  4：教授的课程"); scanf("%d",&ch1); 
					switch(ch1){
						case 1: printf("请输入修改后的教师的姓名: "); scanf("%s",p->data.name); getchar(); printf("修改成功!\n"); break;
						case 2: printf("请输入修改后的教师的工号: "); scanf("%d",&p->data.number); getchar(); printf("修改成功\n"); break;
						case 3: printf("请输入修改后的教师的院系: "); scanf("%s",p->data.institute); getchar(); printf("修改成功\n"); break;
						case 4: printf("要1.修改课程还是2.删除课程？"); scanf("%d",&ch2); getchar(); 
								printf("请输入要修改的课程名称：");  scanf("%s",cna1);getchar();
								switch(ch2){
									case 1: 
											printf("请输入修改后的课程名称： "); scanf("%s",cna2); getchar();
											while(strcmp("0",p->data.cname[i])!=0){
												if(strcmp(p->data.cname[i],cna1)==0) strcpy(p->data.cname[i],cna2);
												break; 
												i++;
											}
											printf("修改成功!\n"); 
											break;
									case 2: 
											while(strcmp(cna1,p->data.cname[i])!=0)  i++;
											while(strcmp("0",p->data.cname[n])!=0) n++;
											for(e=i;e<n;e++){
												strcpy(p->data.cname[e],p->data.cname[e+1]);
											}
											printf("删除成功!\n");
											break;
								}
	
					}
					printf("需要再次修改吗？ y/n "); scanf("%c",&xg); getchar();
					
				}while(xg=='y'||xg=='Y');
				}
				else printf("无该学生的信息!\n");
				
				break;
				
		}
	}
void Cchange(Clist &L)		////课程链表的修改 
{	Clist p=L->next;
	int ch;
	int ch1;
	char na[20];
	int nu;
	char xg;
	printf("请输入您要修改的课程的1：名称或2：编号"); 
	scanf("%d",&ch);
	getchar();
	switch(ch){
		case 1:printf("请输入课程的名称："); scanf("%s",na); 
		while (p!=NULL) {
			if(strcmp(p->data.name,na)==0) {
				printf("名称：%s  编号：%d  所属院系：%s  授课教师：%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
				break;
			}
			p=p->next;
		}
			   if(p=NULL) printf("无该课程的信息!\n"); 
			   else{
			   		do{
			   			printf("您要修改课程的1.名称 2.编号 3.所属院系 4.授课教师"); scanf("%d",&ch1); getchar();
			   			switch(ch1){
			   				case 1: printf("请输入修改后的课程的名称："); scanf("%s",p->data.name); getchar(); break;
			   				case 2: printf("请输入修改后的课程的编号："); scanf("%d",&p->data.number); getchar(); break;
			   				case 3: printf("请输入修改后的所属院系："); scanf("%s",p->data.institute); getchar(); break;
			   				case 4: printf("请输入修改后的授课教师："); scanf("%s",p->data.tname); getchar(); break;
						   }
						printf("还要继续修改吗？ y/n "); scanf("%c",&xg); getchar();
						
						
			   			
					   }while(xg=='y'||xg=='Y');
			   }
			   break;
		case 2:printf("请输入课程的编号："); scanf("%d",&nu);
		while (p!=NULL) {
			if(nu==p->data.number) {
				printf("名称：%s  编号：%d  所属院系：%s  授课教师：%s",p->data.name,p->data.number,p->data.institute,p->data.tname);
				break;
			}
			p=p->next;
		}
			   if(p=NULL) printf("无该课程的信息!\n"); 
			   else{
			   		do{
			   			printf("您要修改课程的1.名称 2.编号 3.所属院系 4.授课教师"); scanf("%d",&ch1); getchar();
			   			switch(ch1){
			   				case 1: printf("请输入修改后的课程的名称："); scanf("%s",p->data.name); getchar(); break;
			   				case 2: printf("请输入修改后的课程的编号："); scanf("%d",&p->data.number); getchar(); break;
			   				case 3: printf("请输入修改后的所属院系："); scanf("%s",p->data.institute); getchar(); break;
			   				case 4: printf("请输入修改后的授课教师："); scanf("%s",p->data.tname); getchar(); break;
						   }
						printf("还要继续修改吗？ y/n "); scanf("%c",&xg); getchar();
						
						
			   			
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
	Sini(SL);//////初始化 
	Cini(CL);
	Tini(TL);
	
	
	
	while(yn=='y'||yn=='Y')
	{	system("cls");
		mn=menu();
		switch(mn){
			case 1: Sinsert(SL); printf("添加成功!\n"); break;
			case 2: Tinsert(TL); printf("添加成功!\n"); break;
			case 3: Cinsert(CL); printf("添加成功!\n"); break;
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
		printf("再次操作？ y/n： ");
		scanf("%c",&yn); 
		getchar();///吸收回车 
	}
	
}
