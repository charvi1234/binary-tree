#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct btree
{
    int data;
    int hd; /*horizontal distance*/
    struct btree* left;
    struct btree* right;
}btree;

typedef struct queue
{
    btree* node[100];
    int front;
    int rear;
}queue;

void initializeQueue(queue* q)
{
    int i;
    for(i=0;i<100;i++)
    {

        q->node[i] = NULL;
    }
    q->front=-1;
    q->rear=-1;
}


int isEmpty(queue* q)
{
            if(q->front == -1 && q->rear==-1)
            {
                return 1;
            }
            return 0;
}
void addElement(queue* q, btree* root)
{

        q->rear = (q->rear +1)%100;
        q->node[q->rear] = root;
        if(q->front ==-1)
        {
            q->front = q->rear;
        }
}

btree* poll(queue* q)
{
   btree* root = q->node[q->front];

        if(q->front== q->rear)
        {
           q->front= q->rear=-1;

        }
        else
            {

            q->front = (q->front +1)%100;
            }


    return root;
}

int peek(queue *q)
{
    btree * x = q->node[q->front];
    return x->data;
}

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


void right( btree* root)
{
  queue *q = (queue*)malloc(sizeof(queue));
  initializeQueue(q);
  btree * t = NULL;
  addElement(q,t);
  addElement(q,root);
  while(!isEmpty(q))
  {
      btree *k = poll(q);
      if(k==NULL)
      {
      addElement(q,k);
      printf("%d ",peek(q));
      }
      else
      {
          if(k->right)
            addElement(q,k->right);
          if(k->left)
            addElement(q,k->left);
      }
  }
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
    right(root);
}
