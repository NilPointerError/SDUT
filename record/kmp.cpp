#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1000005],t[1000005];
int next[1000005];
void getnext(char *t)
{
    int k=-1,j=0;
    int len2=strlen(t);
    next[0]=-1;
    while(j<len2)
    {
        if(k==-1||t[k]==t[j])
        {
            k++;
            j++;
            next[j]=k;
        }
        else
        {
            k=next[k];
        }
    }
}
int kmp(char *s,char *t)
{
    getnext(t);
    int i=0,j=0;
    int len1=strlen(s),len2=strlen(t);
    while(i<len1&&j<len2)
    {
        if(s[i]==t[j]||j==-1)
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j>=len2)
        return 1;
    else return 0;
}
int main()
{
   while(gets(s))
   {
       gets(t);
       int f=kmp(s,t);
       printf("%d\n",f);
   }
   return 0;
}


/*
 a  b a b c
-1 0 0 1 2*/