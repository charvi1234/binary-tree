/*
For example, in the following tree, there are three leaf to root paths 8->-2->10, -4->-2->10 and 7->10. 
The sums of these three paths are 16, 4 and 17 respectively. 
The maximum of them is 17 and the path for maximum is 7->10.

                  10
               /      \
	     -2        7
           /   \     
	 8     -4   
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node * createBinary(node* root,int d)
{
    if(root==NULL)
    {
        node *nn = (node*)malloc(sizeof(node));
        nn->data=d;
        nn->left=NULL;
        nn->right=NULL;
        return nn;
    }
    else if(d < root->data)
    {
        root->left = createBinary(root->left,d);
    }
    else
    {
        root->right = createBinary(root->right,d);
    }
    return root;
}
void func(struct node *root,int sum,int *max)
{
    if(root==NULL)
        return;
    sum = sum+root->data;
    if(root->left==NULL&&root->right==NULL)
    {
        if(sum>*max)
            *max=sum;
    }
    else
    {
        func(root->left,sum,max);
        func(root->right,sum,max);
    }
}

int main()
{
    int n;
    struct node* root=NULL;
    scanf("%d",&n);
    int i;
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        root = createBinary(root,a[i]);
    }
    int max = 0,sum = 0;
    func(root,sum,&max);
    printf("%d",max);
}
