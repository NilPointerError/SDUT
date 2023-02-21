#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max1(a,b) ((a)>(b)?(a):(b))
#define LIST_BACK 1
#define LIST_FRONT 0
typedef struct {
	struct node* head;
	int size;
}linklist;
void init_list(linklist *ptr,int size)
{
	ptr->size = size;
	ptr->head = malloc(sizeof(struct node));
	ptr->head->prev = ptr->head->next = ptr->head;
}
int list_insert(linklist* ptr, void* data, int mode)
{
	struct node* newnode = malloc(sizeof(struct node)+ptr->size);
	if (!newnode)
		return 0;
	memcpy(newnode->data, data, ptr->size);
	if (mode == LIST_FRONT) {
		newnode->next = ptr->head->next;
		newnode->prev = ptr->head;
	}
	else if (mode == LIST_BACK) {
		newnode->prev = ptr->head->prev;
		newnode->next = ptr->head;
	}
	newnode->next->prev = newnode;
	newnode->prev->next = newnode;
	return 1;
}
struct node* _find(linklist L,void *key,int (*cmp)(void*,void*))
{
	struct node* cur;
	for (cur = L.head->next; cur != L.head; cur = cur->next)
	{
		if (cmp(cur->data, key) == 0)
			break;
	}
	return cur;
}
void list_travel(linklist L,void (*op)(void *))
{
	struct node* pos=L.head;
	for (pos = L.head->next; pos != L.head; pos = pos->next)
	{
		op(pos->data);
	}
}
void list_destroy(linklist* ptr)
{
	struct node* cur, * save;
	for (cur = ptr->head->next; cur != ptr->head; cur = save) {
		save = cur->next;
		free(cur);
	}
}


typedef struct node {
	int data;
	struct node* prev, * next;
}LNode;
void init_list(LNode *ptr)
{
	ptr->prev = ptr->next = ptr;
}
void list_insert(LNode* ptr, int e, int mode)
{
	LNode* newnode = malloc(sizeof(LNode));
	newnode->data = e;
	if (mode == LIST_FRONT) {
		newnode->next = ptr->next;
		newnode->prev = ptr;
	}
	else if (mode == LIST_BACK) {
		newnode->prev = ptr->prev;
		newnode->next = ptr;
	}
	newnode->next->prev = newnode;
	newnode->prev->next = newnode;
}
void list_reverse(LNode* ptr)
{
	LNode* p, * q;
	for (p = ptr->next, q = ptr->prev; p != q&&p->prev != q; p = p->next, q = q->prev)
	{
		int tmp = p->data;
		p->data = q->data;
		q->data = tmp;
	}
}
void list_sort(LNode *L)
{
	for (LNode* i = L->next;i->next!=L;i=i->next)
	{
		for (LNode* j = i->next; j != L; j = j->next)
		{
			if (i->data > j->data)
			{
				int tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
		}
	}
}
}
LNode* _find(LNode* ptr, int e,int (*cmp)(int,int))
{
	LNode* cur;
	for (cur = ptr->next; cur != ptr; cur = cur->next)
	{
		if (cmp(cur->data,e)==0)
			break;
	}
	return cur;
}
void list_delete(LNode* ptr,int e)
{
	LNode* cur;
	cur = _find(ptr, e);
	if (cur == ptr)
		return;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
}
void list_print(LNode *ptr)
{
	LNode* pos;
	for (pos = ptr->next; pos != ptr; pos = pos->next)
	{
		if (pos->next != ptr)
			printf("%d ", pos->data);
		else printf("%d\n", pos->data);
	}
}
void list_destroy(LNode* ptr)
{
	LNode* cur, *save;
	for (cur = ptr->next; cur != ptr; cur = save) {
		save = cur->next;
		free(cur);		
	}
}