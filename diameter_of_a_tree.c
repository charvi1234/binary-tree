#include<stdio.h>

#include<string.h>
typedef struct btree
{
    int data;
    int hd; /*horizontal distance*/
    struct btree* left;
    struct btree* right;
}btree;

btree* initializeNode(int d, int hdist)
{
    btree* nn = (btree*)malloc(sizeof(btree));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    nn->hd = hdist;
    return nn;
}

btree* createTree(btree* root, int d, int hd)
{
    if( root == NULL)
    {
        return initializeNode(d, hd);
    }

    if( d  < root-> data)
    {

        root->left  = createTree(root->left, d, hd-1);
    }
    else
        root->right  = createTree(root->right, d,hd+1);

    return root;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int height(btree *root)
{
    if(root==NULL)
        return 0;
    else
        return (1+max(height(root->left),height(root->right)));
}

int diameter(btree * root,int *max)
{
    if(root==NULL)
        return 0;
    int x = height(root->left);
    int y = height(root->right);
    int ht = 1+x+y;
    if(ht>*max)
        *max = ht;
    diameter(root->left,max);
    diameter(root->right,max);
}

int main()
{
    btree* root = NULL;
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        root = createTree(root, arr[i],0);
    }
    int max = 0;
    diameter(root,&max);
    printf("%d",max);
}
