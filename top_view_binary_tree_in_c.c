/*
       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int val;
    struct node* left;
    struct node* right;
}node;

typedef struct stack
{
    node *arr[100];
    int top;
}stack;

void push(node* root,stack* obj)
{
    obj->top=obj->top+1;
    obj->arr[obj->top]=root;
}

void initialize (stack*obj)
{
    obj->top=-1;
}

node *pop(stack*obj)
{
    if(obj->top==-1)
        return NULL;
    node * temp = obj->arr[obj->top];
    obj->top=obj->top-1;
    return temp;
}

int isEmpty(stack * obj)
{
    if(obj->top==-1)
        return 1;
    else
        return 0;
}

node * createBinary(node* root,int d,int v)
{
    if(root==NULL)
    {
        node *nn = (node*)malloc(sizeof(node));
        nn->data=d;
        nn->val=v;
        nn->left=NULL;
        nn->right=NULL;
        return nn;
    }
    else if(d < root->data)
    {
        root->left = createBinary(root->left,d,v-1);
    }
    else
    {
        root->right = createBinary(root->right,d,v+1);
    }
    return root;
}

void func(struct node*root)
{
    int arr2[100];
    int i;
    for(i=0;i<100;i++)
        arr2[i]=-1;
    stack *s=(stack*)malloc(sizeof(stack));
    initialize(s);
    push(root,s);
    while(!isEmpty(s))
    {
        node* x=pop(s);
        if(arr2[x->val+50]==-1)
        {
            arr2[x->val+50]=x->data;
        }
        if(x->left)
            push(x->left,s);
        if(x->right)
            push(x->right,s);
    }
    for(i=0;i<100;i++)
    {
      if(arr2[i]!=-1)
        printf("%d",arr2[i]);
    }
}

void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
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
        root = createBinary(root,a[i],0);
    }
    //inorder(root);
    func(root);
}
