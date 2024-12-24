#include<stdio.h>

typedef struct NODE
{
	int nData;
	struct NODE* next;
}NODE;

int main() 
{
	NODE list[5];
	for (int i = 0; i < 5; i++) 
	{
		list[i].nData = i * 100;
		list[i].next = &list[i + 1];
	}
	list[4].next = NULL;

	printf("for\n");
	for (int i = 0; i < 5; i++)
		printf("list %d : %d\n", i, list[i].nData);

	printf("head\n");
	NODE* head = &list[0];
	while (head->nData != NULL)
	{
		printf("%p: %d\n", head, head->nData);
		head = head->next;
	}
	return 0;
}