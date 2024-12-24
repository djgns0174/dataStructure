#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE
{
	char szData[64];
	struct NODE* next;
}NODE;

NODE g_head = { 0 };
NODE* g_tail = 0;

NODE* findData(char* pszData) {

	NODE* pCur = g_head.next;
	NODE* pPrev = &g_head;

	while (pCur != NULL) {

		if (strcmp(pCur->szData, pszData) == 0) {
			return pPrev;
		}

		pPrev = pCur;
		pCur = pCur->next;
	}

	return NULL;
}

int isEmpty() {
	if (g_head.next != NULL)
		return 0;
	else
		return 1;
}

void printList() {
	NODE* tmp = g_head.next;
	while (tmp != NULL)
	{
		printf("[%p] %s, next[%p]\n", tmp, tmp->szData, tmp->next);
		tmp = tmp->next;
	}
}

int insertHead(char* s) 
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	memset(new_node, 0, sizeof(NODE));
	strcpy_s(new_node->szData, sizeof(new_node->szData), s);

	if (isEmpty()) {
		g_head.next = new_node;
		g_tail = new_node;
	}
	else {
		new_node->next = g_head.next;
		g_head.next = new_node;
	}

	return 1;
}

int insertTail(char* s) {
	
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	strcpy_s(new_node->szData, sizeof(new_node->szData), s);
	new_node->next = NULL;

	if (isEmpty())
		g_head.next = new_node;
	else
		g_tail->next = new_node;

	g_tail = new_node;

	return 1;
}


void releaseList() {
	NODE* pTmp = g_head.next;
	while (pTmp != NULL) {
		NODE* deleteTmp = pTmp;
		pTmp = pTmp->next;

		printf("release : %s\n", deleteTmp->szData);
		free(deleteTmp);
	}
	
	g_head.next= NULL;
	g_tail = NULL;
}

void deleteData(char *s) {
	NODE* pPrev = findData(s);
	NODE* pCur = pPrev->next;
	if (pPrev == 0 && pPrev != NULL)
		g_head.next = pCur->next;
	
	else if (pPrev != 0 && pPrev != NULL)
		pPrev->next = pCur->next;

	printf("delete : %s\n", pCur->szData);
	free(pCur);
}

void pushData(char* pszData) {
	insertHead(pszData);
}

int popData(NODE* pPopNode) {
	NODE* sp = g_head.next;

	memcpy(pPopNode, sp, sizeof(NODE));
	g_head.next = sp->next;
	free(sp);

	return 1;
}

int dequeue(NODE* pGetNode) {
	popData(pGetNode);
}

int inqueue(char* pszData) {
	insertTail(pszData);
}

int main()
{
	//stack test
	//pushData("test1");
	//pushData("test2");
	//pushData("test3");

	//NODE node = { 0 };
	//popData(&node);
	//printf("pop node : %s\n", node.szData);

	//popData(&node);
	//printf("pop node : %s\n", node.szData);

	//popData(&node);
	//printf("pop node : %s\n", node.szData);

	//queue test
	inqueue("test1");
	inqueue("test2");
	inqueue("test3");
	
	NODE node = { 0 };
	dequeue(&node);
	printf("queue get node : %s\n", node.szData);

	dequeue(&node);
	printf("queue get node : %s\n", node.szData);

	dequeue(&node);
	printf("queue get node : %s\n", node.szData);

	//linked list test
	//insertHead("test1");
	//insertHead("test2");
	//insertHead("test3");
	//printList();

	//releaseList();
	////printList();

	//insertTail("test1");
	//insertTail("test2");
	//insertTail("test3");
	//printList();

	//releaseList();

	/*deleteData("test3");
	deleteData("test2");
	deleteData("test1");
	printList();*/
	return 0;
} 
//isempty, inserttail