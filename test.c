#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList *LinkList_Create()
{
	TLinkList *ret;
	(TLinkList*)ret = (TLinkList*)malloc(sizeof(TLinkList));
	if (ret != NULL)
	{
		ret->length = 0;
		ret->header.next= NULL;
	}
	return ret;
}

void LinkList_Destroy(LinkList*list)
{
	free(list);
}

void LinkList_Clear(LinkList *list)
{
	TLinkList *slist = (TLinkList*)list;
	slist->length = 0;
	slist->header.next = NULL;
}

int LinkList_Insert(LinkList *list, int pos, LinkListNode *node)
{
	//��Ҫ�����Ĳ��裺                                \
	1.�жϺϷ�������                                    \
	2.�����½ڵ�                                           \
	3.��������                                              \
	4.�����ȼ�һ
	//voidָ����Ը��Ƹ������������͵�ָ�룬�����������͵�ָ��Ҳ���Ը��Ƹ�voidָ�룬����֮�临�Ʋ���Ҫǿ������ת������Ȼ�κε�ַҲ���Ը��Ƹ�void��ָ�롣
	int i;
	TLinkList *slist = (TLinkList*)list;
	int ret = (slist != NULL) && (pos >= 0) && (node != NULL);
	if (ret)
	{
	/*	if ((pos > (LinkList_length(list) - 1))&& pos>0)
		{
			pos = LinkList_length(list) - 1;
		}
	*/
		LinkListNode *current = (LinkListNode *)slist;
		for (i = 0; (i<pos)&&(current->next!=NULL); i++)
		{
			current = current->next;
		}

		node->next = current->next;
		current->next = node;
		slist->length++;
	}
	return ret;
}

LinkListNode *LinkList_Delete(LinkList *list, int pos)
{
	//��Ҫ���еĲ��裺
	//1.�ƶ�ָ��pos�ε���Ӧ��λ��
	//2.��ǰλ�õ���һԪ�ؾ���Ҫɾ����Ԫ��
	//3.ɾ��Ԫ��
	//4.���ȼ�һ
	//5.��������
	TLinkList *slist = (TLinkList*)list;
	LinkListNode *ret = NULL;
	int i = 0;

	if ((slist != NULL) && (0 <= pos) && (pos < slist->length))
	{
		LinkListNode *current = (LinkListNode*)slist;

		for (i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
		current->next = ret->next;
		slist->length--;
	}
	return ret;
}

int LinkList_length(LinkList *list)
{
	TLinkList *slist = (TLinkList *)list;
	if (slist != NULL)
	{
		return slist->length;
	}
}

LinkListNode *LinkList_Get(LinkList *list, int pos)
{
	LinkListNode *ret=NULL;
	TLinkList *slist = (TLinkList *)list;
	int i;
	if ((slist != NULL)&&(0<=pos)&&(pos<slist->length))
	{
		LinkListNode *current = (LinkListNode*)slist;
		for (i = 0; i < pos; i++)
		{
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}