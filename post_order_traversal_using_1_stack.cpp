#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newnode()
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    return newnode;
};
void posttraversal(struct Node* curr)
{
stack<struct Node*>s;
s.push(curr);
curr=curr->left;
  while(!s.empty())
  {
   if(curr)
   {
       s.push(curr);
       curr=curr->left;
   }
   else
    {
        if(s.top()->right==NULL)
        {
            cout<<s.top()->data;
            curr=s.top();
            s.pop();
            while(!s.empty()&&s.top()->right==curr)
            {
                curr=s.top();
                s.pop();
                cout<<curr->data;
            }
        }
        curr=s.top()->right;
    }
  }
}
struct Node *create(struct Node* root,int data)
{
    struct Node*nn=newnode();
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    if(root==NULL)
    {
        return nn;
    }
    else
    {
      queue<Node*> stk;
      stk.push(root);
      while(!stk.empty())
      {
          struct Node*s=stk.front();
          stk.pop();
          if(s->left)
            stk.push(s->left);
          else
          {
            s->left=nn;
            return root;
          }
          if(s->right)
          {
              stk.push(s->right);
          }
          else
          {
              s->right=nn;
              return root;
          }
      }
    }
}
void print(struct Node*nn,int n)
{
queue<struct Node*>q;
q.push(nn);
while(!q.empty())
{
    struct Node*s=q.front();
    cout<<s->data;
    q.pop();
    if(s->left)
    q.push(s->left);
    if(s->right)
    q.push(s->right);
}
}
int main()
{
int i;
int n;
cin>>n;
struct Node*head=NULL;
for(i=1;i<=n;i++)
{
 head=create(head,i);
}
//print(head,n);
posttraversal(head);
}


