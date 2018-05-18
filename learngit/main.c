#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"

int main(int argc,char *argv[])
{
	SeqStack *stack = SeqStack_Create(20);
	int a[10];
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		a[i] = i;

		SeqStack_Push(stack, a + i);
	}

	printf("top:%d\n", *(int *)SeqStack_Top(stack));
	printf("Capacity:%d\n", SeqStack_Capacity(stack));
	printf("length:%d\n", SeqStack_Size(stack));

	while (SeqStack_Size(stack)>0)
	{
		printf("Pop£º%d\n", *(int *)SeqStack_Pop(stack));
	}

	SeqStack_Destroy(stack);
	system("pause");
	return 0;
}