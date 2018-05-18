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
	//需要经历的步骤：                                \
	1.判断合法的条件                                    \
	2.插入新节点                                           \
	3.更新链表                                              \
	4.链表长度加一
	//void指针可以复制给其他任意类型的指针，其他任意类型的指针也可以复制给void指针，他们之间复制不需要强制类型转换。当然任何地址也可以复制给void型指针。
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
	//需要进行的步骤：
	//1.移动指针pos次到相应的位置
	//2.当前位置的下一元素就是要删除的元素
	//3.删除元素
	//4.长度减一
	//5.更新链表
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