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

void func3(int arr[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void func2(struct node *root,int arr[],int len)
{
    if(root==NULL)
        return;
    arr[len]=root->data;
    len++;
    if(root->left==NULL&&root->right==NULL)
    {
        func3(arr,len);
    }
    else
    {
        func2(root->left,arr,len);
        func2(root->right,arr,len);
    }
}

void func1(struct node*root)
{
    int arr[1000];
    func2(root,arr,0);
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
    func1(root);
}
