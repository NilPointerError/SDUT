#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max1(a,b) ((a)>(b)?(a):(b))
typedef struct node{
    int data;
    struct node *lc,*rc;
}Bnode,*Btree;
int getdepth(Btree T)
{
    if(!T) return 0;
    else{
        int ld=getdepth(T->lc);
        int rd=getdepth(T->rc);
        return (ld>rd?ld:rd)+1;
    }
}
void LL(Btree *ptr)
{
    Btree p=*ptr;
    Btree q=p->lc;
    p->lc=q->rc;
    q->rc=p;
    *ptr=q;
}
void RR(Btree *ptr)
{
    Btree p=*ptr;
    Btree q=p->rc;
    p->rc=q->lc;
    q->lc=p;
    *ptr=q;
}
void LR(Btree *ptr)
{
    RR(&(*ptr)->lc);
    LL(ptr);
}
void RL(Btree *ptr)
{
    LL(&(*ptr)->rc);
    RR(ptr);
}
void AVL_insert(Btree *ptr,int e)
{
    if(*ptr==NULL)
    {
        *ptr=malloc(sizeof(Bnode));
        (*ptr)->data=e;
        (*ptr)->lc=NULL;
        (*ptr)->rc=NULL;
    }
    else if(e<(*ptr)->data){
        AVL_insert(&(*ptr)->lc,e);
        if(getdepth((*ptr)->lc)-getdepth((*ptr)->rc)>1)
        {
            if(e<(*ptr)->lc->data)
                LL(ptr);
            else LR(ptr);
        }
    }
    else 
    {
        AVL_insert(&(*ptr)->rc,e);
        if(getdepth((*ptr)->lc)-getdepth((*ptr)->rc)<-1)
        {
            if(e>(*ptr)->rc->data)
                RR(ptr);
            else RL(ptr);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    Btree T=NULL;
    for(int i=0;i<n;++i)
    {
        int e;
        scanf("%d",&e);
        AVL_insert(&T,e);
    }
    printf("%d\n",T->data);    
    return 0;
}
