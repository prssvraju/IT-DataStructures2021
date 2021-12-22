/* Insertion operations in CIRCULAR Linked List  */
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
nodeptr insert(nodeptr);
void traversal(nodeptr);
nodeptr insertbeg(nodeptr,nodeptr);
nodeptr insertend(nodeptr,nodeptr);
nodeptr insertbefore(nodeptr,nodeptr);
nodeptr insertafter(nodeptr,nodeptr);
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
		printf("\n1.adding a node\n2.traversal\n3.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	first=insert(first);
				traversal(first);
				break;
			case 2:	traversal(first);
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
nodeptr insert(nodeptr p)
{
	nodeptr p2;
	int ch;
	p2=getnode();
	printf("\nenter inserted element:");
	scanf("%d",&p2->info);
	if(p==NULL)
	{
		p2->next=p2;
		p=p2;
		return p;
	}
	else
	{
		printf("\ninsert\n1.at beg\n2.at end\n3.insert before\n4.insert after\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	return insertbeg(p,p2);
			case 2:	return insertend(p,p2);
			case 3: return insertbefore(p,p2);
			case 4: return insertafter(p,p2);
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
nodeptr insertbeg(nodeptr p, nodeptr p2)
{
	nodeptr p1;
	p1=p;
	while(p1->next!=p)
		p1=p1->next;
	p2->next=p;
	p1->next=p2;
	return(p2);
}
nodeptr insertend(nodeptr p, nodeptr p2)
{
	nodeptr p1;
	p1=p;
	while(p1->next!=p)
		p1=p1->next;
	p2->next=p;
	p1->next=p2;
	return p;
}
nodeptr insertbefore(nodeptr p, nodeptr p2)
{

	nodeptr p1;
	int k;
	p1=p;
	printf("\nEnter the element insert before:");
	scanf("%d",&k);
	if(p1->info==k)
	{
		while(p1->next!=p)
			p1=p1->next;
		p2->next=p;
		p1->next=p2;
		p=p2;
	}
	else
	{
		while(p1->next->info!=k)
			p1=p1->next;
		p2->next=p1->next;
		p1->next=p2;
	}
	return p;
}
nodeptr insertafter(nodeptr p, nodeptr p2)
{
	nodeptr p1;
	int k;
	p1=p;
	printf("\nEnter the element insetr after:");
	scanf("%d",&k);
	while(p1->info!=k)
		p1=p1->next;
	p2->next=p1->next;
	p1->next=p2;
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