#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *left,*right;
};
typedef struct node *nodeptr;
nodeptr insert(nodeptr, int key);
void inorder();
void preorder();
void postorder();
nodeptr find_minimum();
main()
{
	nodeptr tree,p;
	int ch,key,x;
	tree=NULL;
	while(1)
	{
		printf("\n*************\n\n\tMENU\n");
		printf("\n*************\n\n1.Insert\n2.in order\n3.pre order\n");
		printf("\n4.post order\n5.exit\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("enter the value");
					scanf("%d",&key);
					tree=insert(tree, key);
                    inorder(tree);
					//printf("\n%d",tree);
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
struct node *insert(struct node *root, int key)
{
	
	if(root==NULL)
    {
      root=(struct node*) malloc (sizeof(struct node));
      root->left=root->right=NULL;
      root->info=key;
      //1printf("%d",root);
      return root;
   }
  else
  {
       if(key<root->info)
       root->left=insert(root->left, key);
       else
        root->right=insert(root->right, key);
  }    
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

