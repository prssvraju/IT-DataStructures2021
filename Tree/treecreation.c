/* 	insert an element into the Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *left, *right;
};
typedef struct node *nodeptr;
nodeptr getnode();
nodeptr create(nodeptr);
void insert(nodeptr, nodeptr);
void inorder(nodeptr);
main()
{
	nodeptr head, newnode;
	int k;
	head = NULL;
	head = create(head);
	printf("\nEnter the inserted element:");
	scanf("%d", &k);
	newnode = getnode();
	newnode->info = k;
	insert(head, newnode);
	printf("\n");
	inorder(head);
}
nodeptr getnode()
{
	nodeptr p;
	p = (nodeptr)malloc(sizeof(struct node));
	p->info = 0;
	p->left = p->right = NULL;
	return p;
}
nodeptr create(nodeptr firstnode)
{
	nodeptr newnode;
	int k;
	newnode = getnode();
	printf("\nEnter at end -999\n");
	printf("\nEnter the number:");
	scanf("%d", &k);
	newnode->info = k;
	while (newnode->info != -999)
	{
		if (firstnode == NULL)
			firstnode = newnode;
		else
		{
			printf("\nvisiting order:");
			insert(firstnode, newnode);
			newnode = getnode();
			printf("\nenter the number:");
			scanf("%d", &k);
			newnode->info = k;
		}
	}
	return firstnode;
}
void insert(nodeptr firstnode, nodeptr newnode)
{
	printf("%d\t", firstnode->info);
	if ((newnode->info < firstnode->info) && (firstnode->left == NULL))
	{
		firstnode->left = newnode;
	}
	else if ((newnode->info < firstnode->info) && (firstnode->left != NULL))
	{
		insert(firstnode->left, newnode);
	}
	else if ((newnode->info > firstnode->info) && (firstnode->right == NULL))
	{
		firstnode->right = newnode;
	}
	else if ((newnode->info > firstnode->info) && (firstnode->right != NULL))
	{
		insert(firstnode->right, newnode);
	}
	// if (newnode->info < firstnode->info)
	// {
	// 	if (firstnode->left == NULL)
	// 	{
	// 		firstnode->left = newnode;
	// 	}
	// 	else
	// 	{
	// 		insert(firstnode->left, newnode);
	// 	}
	// }
	// if (newnode->info < firstnode->info)
	// {
	// 	if (firstnode->right == NULL)
	// 	{
	// 		firstnode->right = newnode;
	// 	}	
	// 	else
	// 	{
	// 		insert(firstnode->right, newnode);
	// 	}
	// }
}

void inorder(nodeptr p)
{
	if (p != NULL)
	{
		inorder(p->left);
		printf("%d-->", p->info);
		inorder(p->right);
	}
}
void preorder(nodeptr p)
{
	if (p != NULL)
	{
		printf("%d-->", p->info);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(nodeptr p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d-->", p->info);
	}
}
