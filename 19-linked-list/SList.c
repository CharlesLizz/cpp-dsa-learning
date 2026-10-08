#include"SList.h"


//打印
void SLTPrint(SLTNode* phead)
{
	assert(phead != NULL);
	SLTNode* pCur = phead;
	while (pCur != NULL)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}

