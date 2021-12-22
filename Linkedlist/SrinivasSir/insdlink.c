/* Insertion operations in DOUBLE Linked List */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next, *prev;
};
typedef struct node *nodeptr;
nodeptr getnode();
void create();
void insert();
void traversal();
void insertbeg(nodeptr);
void insertend(nodeptr);
void insertbefore(nodeptr);
void insertafter(nodeptr);
nodeptr first,last;
main()
{
	int choice;
	clrscr();
	create();
	traversal();
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.adding a node\n2.traversal\n");
		printf("3.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	insert();
				traversal();
				break;
			case 2:	traversal();
				break;
			case 3:	exit(0);
		}
	}
}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->info=0;
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void insert()
{
	nodeptr p2;
	int ch;
	p2=getnode();
	printf("\nenter inserted element:");
	scanf("%d",&p2->info);
	if(first==NULL)
	{
		first=p2;
		last=p2;
	}
	else
	{
		printf("\ninsert\n1.at beg\n2.at end\n3.insert before\n4.insert after\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	insertbeg(p2);
				break;
			case 2:	insertend(p2);
				break;
			case 3: insertbefore(p2);
				break;
			case 4: insertafter(p2);
				break;
		}
	}
}
void traversal()
{
	nodeptr p1;
	p1=first;
	printf("\nelements are:\n");
	while(p1!=NULL)
	{
		printf("%d-->",p1->info);
		p1=p1->next;
	}
	printf("\nelements in reverse order\n");
	p1=last;
	while(p1!=NULL)
	{
	      printf("<--%d",p1->info);
	      p1=p1->prev;
	}

}
void insertbeg(nodeptr p2)
{
	p2->next=first;
	first->prev=p2;
	first=p2;
}
void insertend(nodeptr p2)
{
	
	last->next=p2;
	p2->prev=last;
	last=p2;
}
void insertbefore(nodeptr p2)
{
	nodeptr p1,p3;
	int k;
	printf("\nEnter the element insert before:");
	scanf("%d",&k);
	if(first->info==k)
	{
		p2->next=first;
		first->prev=p2;
		first=p2;
	}
	else
	{
		p1=first;
		while(p1->next->info!=k)
			p1=p1->next;
		p3=p1->next;
		p1->next=p2;
		p2->prev=p1;
		p2->next=p3;
		p3->prev=p2;
	}
}
void insertafter(nodeptr p2)
{
	nodeptr p1,p3;
	int k;
	printf("\nEnter the element insetr after:");
	scanf("%d",&k);
	p1=first;
	while(p1->info!=k)
		p1=p1->next;
	if(p1->next==NULL)
	{
		p1->next=p2;
		p2->prev=p1;
		last=p2;
	}
	else
	{
		p3=p1->next;
		p1->next=p2;
		p2->prev=p1;
		p2->next=p3;
		p3->prev=p2;
	}
}

void create()
{

       nodeptr p,p1,p2,p3;
       p1=getnode();
       p=p1;
       p2=getnode();
       printf("\nEnter the at end -999\n");
       printf("\nEnter the number:");
       scanf("%d",&p2->info);
       while(p2->info!=-999)
       {
		p1->next=p2;
		p2->prev=p1;
		p1=p2;
		p2=getnode();
		printf("\nEnter the number:");
		scanf("%d",&p2->info);
       }
	p3=p->next;
	p->next=NULL;
	p3->prev=NULL;
	first=p3;
	last=p1;
}