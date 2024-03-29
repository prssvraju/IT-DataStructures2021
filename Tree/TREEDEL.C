/* delete an element from BST*/
#include<stdio.h>
struct node
{
	int info;
	struct node *left,*right;
};
typedef struct node *nodeptr;
nodeptr getnode();
nodeptr create(nodeptr);
void insert(nodeptr, nodeptr);
void del(nodeptr,int);
void inorder(nodeptr);
void preorder(nodeptr);
void postorder(nodeptr);
void del1(nodeptr, nodeptr);
void rightchild(nodeptr, nodeptr);
void nochild(nodeptr, nodeptr);
void leftchild(nodeptr, nodeptr);
void twochilds(nodeptr, nodeptr);
nodeptr findmin(nodeptr);
main()
{
	nodeptr tree;
	int a,ch;
	clrscr();
	tree=NULL;
	tree=create(tree);
	while(1)
	{
		printf("\n*************\n\n\tMENU\n");
		printf("\n*************\n\n1.delete an element\n2.in order\n3.pre order\n");
		printf("\n4.post order\n5.exit\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the element to be delete:");
				scanf("%d",&a);
				del(tree,a);
				break;
			case 2:	printf("\nelements in in oreder is:\n");
				inorder(tree);
				break;
			case 3:	printf("\nelements in pre order is:\n");
				preorder(tree);
				break;
			case 4:	printf("\nelements in post order is:\n");
				postorder(tree);
				break;
			case 5:	exit(0);
		}
	}
}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->info=0;
	p->left=p->right=NULL;
	return p;
}
nodeptr create(nodeptr p)
{
	nodeptr temp;
	int k;
	temp=getnode();
	printf("\nEnter at end -999\n");
	printf("\nEnter the number:");
	scanf("%d",&k);
	temp->info=k;
	while(temp->info!=-999)
	{
		if(p==NULL)
			p=temp;
		else
		{
			printf("\nvisiting order:");
			insert(p,temp);
			temp=getnode();
			printf("\nenter the number:");
			scanf("%d",&k);
			temp->info=k;
		}
	}
	return p;
}
void insert(nodeptr p, nodeptr temp)
{
	printf("%d\t",p->info);
	if((temp->info<p->info)&&(p->left==NULL))
		p->left=temp;
	else if((temp->info<p->info)&&(p->left!=NULL))
		insert(p->left,temp);
	else if((temp->info>p->info)&&(p->right==NULL))
		p->right=temp;
	else if((temp->info>p->info)&&(p->right!=NULL))
		insert(p->right,temp);
}

void inorder(nodeptr p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d-->",p->info);
		inorder(p->right);
	}
}
void preorder(nodeptr p)
{
	if(p!=NULL)
	{
		printf("%d-->",p->info);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(nodeptr p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d-->",p->info);
	}
}
void del(nodeptr p, int a)
{
	nodeptr p1;
	p1=p;
	if(p==NULL)
		printf("\nElement not found in the BST");
	else
	{
		while(p->info!=a)
		{
			if(a<p->info)
			{
				p1=p;
				p=p->left;
			}
			else if (a>p->info)
			{
				p1=p;
				p=p->right;
			}
		}
		if(p==NULL)
			printf("\nElement not found in BST");
		else if(a==p->info)
			del1(p1,p);
	}

}
void del1(nodeptr p1, nodeptr p)
{
	if((p->left==NULL)&&(p->right==NULL))
		nochild(p1,p);
	else if((p->left==NULL)&&(p->right!=NULL))
		rightchild(p1,p);
	else if ((p->left!=NULL)&&(p->right==NULL))
		leftchild(p1,p);
	else if((p->left!=NULL)&&(p->right!=NULL))
		twochilds(p1,p);
}
void nochild(nodeptr p1, nodeptr p)
{
	if(p1->left==p)
		p1->left=NULL;
	else
		p1->right=NULL;
	free(p);
}
void leftchild(nodeptr p1, nodeptr p)
{
	if(p1->left==p)
		p1->left=p->left;
	else
		p1->right=p->left;
	p->left=NULL;
	free(p);

}
void rightchild(nodeptr p1, nodeptr p)
{
	if(p1->left==p)
		p1->left=p->right;
	else
		p1->right=p->right;
	p->right=NULL;
	free(p);
}
void twochilds(nodeptr p1, nodeptr p)
{
	int k;
	nodeptr temp;
	temp=findmin(p->right);
	k=p->info;
	p->info=temp->info;
	temp->info=k;
	if(p->right==temp)
		del1(p,temp);
	else
		del(p->right, temp->info);
}
nodeptr findmin(nodeptr p)
{
	while(p->left!=NULL)
		p=p->left;
	return p;
}






