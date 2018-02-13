
#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node *right;
struct node *left;
}*t=NULL;
typedef struct node N;
N* create();
void preorder(N *);
void inorder(N *);
void postorder(N *);
void insert(N *);
void Output(N *T, int Level)
{
	int i;
	if (T!=NULL)
	{

		Output(T->right, Level+1);
		printf("\n");
		for (i = 0; i < Level; i++)

			printf("   ");

		printf(" %d", T->data);

		Output(T->left, Level+1);

	}

	}

void main()
{
int n,i,m;
clrscr();
do
{
printf("\n\n1.create\n2.insert \n3.preorder\n4.postorder\n5.inorder\n6.exit\n");
printf("n\nenter the choice");
scanf("%d",&m);
switch(m)
{
case 1:
t=create();
break;
case 2:
insert(t);
Output(t,1);
break;
case 3:
printf("\nPreorder traversal\n\n");
preorder(t);
break;
case 4:
printf("\nPostorder\n");
postorder(t);
break;
case 5:
printf("\n\nInorder\n\n");
inorder(t);
break;
case 6:
exit(0);
case 7:  Output(t,1);
break;
}
}
while(n!=5);
getch();
}
void insert(N *root)
{
N *ptr;
if(root==NULL)
{
//newnode=create();
root=create();

}
else
{
ptr=create();
while(1)
{

if(ptr->data<root->data)
{
//printf("left =%d",root->data);
if(root->left==NULL)
{
//printf("left =%u",&root->data);
root->left=ptr;
//printf("left =%u",&root->data);
break;
}
root=root->left;
//printf("left =%u",&root->data);
}

else if(ptr->data>root->data)
{
//printf("right =%d",root->data);
if(root->right==NULL)
{
//printf("right =%u",&root->data);
root->right=ptr;
break;
}
root=root->right;
//printf("right =%u",&root->data);
}
}
}
}
N *create()
{
N *newnode;
int n;
newnode=(N *)malloc(sizeof(N));
printf("\n\nEnter the Data ");
scanf("%d",&n);
newnode->data=n;
newnode->left=NULL;
newnode->right=NULL;
return(newnode);
}
void postorder(N *tmp)
{
if(tmp!=NULL)
{
postorder(tmp->left);
postorder(tmp->right);
printf("%d->",tmp->data);
}
}
void inorder(N *tmp)
{
if(tmp!=NULL)
{
inorder(tmp->left);
printf("%d->",tmp->data);
inorder(tmp->right);
}
}
void preorder(N *tmp)
{
if(tmp!=NULL)
{
printf("%d->",tmp->data);
preorder(tmp->left);
preorder(tmp->right);
}
}