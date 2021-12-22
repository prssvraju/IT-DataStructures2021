/* Deletion operations in CIRCULAR Linked List */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;
nodeptr getnode();
nodeptr create();
nodeptr del(nodeptr);
void traversal(nodeptr);
nodeptr deletebeg(nodeptr);
nodeptr deleteend(nodeptr);
nodeptr deletebefore(nodeptr);
nodeptr deleteafter(nodeptr);
main()
{
	nodeptr first,last;
	int choice;
	clrscr();
	first=create();
	traversal(first);
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.delete a node\n2.traversal\n");
		printf("3.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	first=del(first);
				traversal(first);
				break;
			case 2: traversal(first);
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
	p->next=p;
	return p;
}
nodeptr del( nodeptr p)
{

	int c;
	nodeptr p1,p2;
	p1=p;
	if(p1==NULL)
	{
		printf("\nlist is empty");
		return p;
	}
	else
	{
		printf("\nDelete\n1.at begining\n2.at end\n3.delete before\n4.delete after");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:	return deletebeg(p);
			case 2:	return deleteend(p);
			case 3:	return deletebefore(p);
			case 4: return deleteafter(p);
		  }
	}
}

void traversal(nodeptr p)
{
	nodeptr p1;
	p1=p;
	printf("\nelements are:\n");
	while(p1->next!=p)
	{
		printf("%d-->",p1->info);
		p1=p1->next;
	}
	printf("%d",p1->info);
}
nodeptr deletebeg(nodeptr p)
{
	nodeptr p1,p2;
	p1=p;
	if(p1->next==p1)
	{
		p=NULL;
		return p;
	}
	else
	{
		while(p1->next!=p)
			p1=p1->next;
		p2=p->next;
		p1->next=p2;
		p->next=NULL;
		return p2;
	}
}
nodeptr deleteend(nodeptr p)
{
	nodeptr p1;
	p1=p;
	if(p1->next==p1)
	{
		p=NULL;
		return p;
	}
	while(p1->next->next!=p)
		p1=p1->next;
	p1->next=p;
	return p;
}
nodeptr deletebefore(nodeptr p)
{
	nodeptr p1,p2;
	int k;
	p1=p;
	printf("\nenter the element delete before:");
	scanf("%d",&k);
	if(p1->info==k)
		printf("\nDeletion is not possible");
	else if(p1->next->info==k)
	{	while(p1->next!=p)
			p1=p1->next;
		p1->next=p->next;
		p2=p->next;
		p->next=NULL;
		p=p2;
	}
	else
	{
		while(p1->next->info!=k)
		{
			p2=p1;
			p1=p1->next;
		}
		p2->next=p1->next;
		p1->next=NULL;
	}
	return p;
}
nodeptr deleteafter(nodeptr p)
{
	nodeptr p1,p2;
	int k;
	p1=p;
	printf("\nEnter the element delete after:");
	scanf("%d",&k);
	while(p1->info!=k)
		p1=p1->next;
	if(p1->next==p)
		printf("\ndeletion is not possible");
	else
	{
		p2=p1->next;
		p1->next=p2->next;
		p2->next=NULL;
	}
	return p;
}
nodeptr create()
{

       nodeptr p,p1,p2;
       p1=getnode();
	p=p1;
       p2=getnode();
       printf("\nEnter the at end -999\n");
       printf("\nEnter the number:");
       scanf("%d",&p2->info);
       while(p2->info!=-999)
       {
		p1->next=p2;
		p1=p2;
		p2=getnode();
		printf("\nEnter the number:");
		scanf("%d",&p2->info);
       }
	p=p->next;
	p1->next=p;
	return p;
}