/* Deletion operations in DOUBLE Linked List */
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
void del();
void traversal();
void deletebeg();
void deleteend();
void deletebefore();
void deleteafter();
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
		printf("\n1.delete a node\n2.traversal\n");
		printf("3.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	del();
				traversal();
				break;
			case 2: traversal();
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
void del( )
{

	int c;
	if(first==NULL)
	{
		printf("\nlist is empty");

	}
	else if(first==last)
		first=last=NULL;

	else
	{
		printf("\nDelete\n1.at begining\n2.at end\n3.delete before\n4.delete after");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:	deletebeg();				
				break;
			case 2:	deleteend();
				break;
			case 3:	deletebefore();
				break;
			case 4: deleteafter();
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
void deletebeg()
{
	nodeptr p1;
	p1=first;
	first=first->next;
	p1->next=NULL;
	first->prev=NULL;
}
void deleteend()
{
	nodeptr p1;
	p1=last;
	last=last->prev;
	last->next=NULL;
	p1->prev=NULL;
}
void deletebefore()
{
	nodeptr p1,p2,p3;
	int k;
	printf("\nenter the element delete before:");
	scanf("%d",&k);
	if(first->info==k)
		printf("\nDeletion is not possible");
	else if(first->next->info==k)
	{
		p1=first;
		first=first->next;
		p1->next=NULL;
		first->prev=NULL;
	}
	else
	{
		p1=first;
		while(p1->next->info!=k)
			p1=p1->next;
		p2=p1->prev;
		p3=p1->next;
		p2->next=p3;
		p3->prev=p2;
		p1->next=NULL;
		p1->prev=NULL;
	}
}
void deleteafter()
{
	nodeptr p1,p2,p3;
	int k;
	printf("\nEnter the element delete after:");
	scanf("%d",&k);
	p1=first;
	while(p1->info!=k)
		p1=p1->next;
	if(p1->next==NULL)
		printf("\ndeletion is not possible");
	else if(p1->next->next==NULL)
	{
		p2=p1->next;
		p1->next=NULL;
		p2->prev=NULL;
		last=p1;
	}
	else
	{
		p2=p1->next;
		p3=p2->next;
		p1->next=p3;
		p3->prev=p1;
		p2->next=NULL;
		p2->prev=NULL;
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