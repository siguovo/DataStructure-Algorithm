#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/*
*实参双向链表创建、删除，以及实现数据的随机查找，插入，删除
*author: sigu
*time  : 2021.05.16
*/

/*构建结点*/
typedef struct double_link_node *d_node;
struct double_link_node
{
	d_node prev;    //指向前驱结点
	d_node next;	//指向后继结点
	void* p;		//结点值的存放(方便多种类型值的存放)
};
/*初始化头结点，头结点不存放任何值*/
static d_node phead = NULL;

/*双向链表结点个数,初始化为0*/
static int count = 0;

/*新建结点，成功返回结点，失败返回NULL*/
d_node Create_node(void* pval)
{
	d_node pnode = NULL;
	pnode = (struct double_link_node*)malloc(sizeof(struct double_link_node));
	if (pnode == NULL)
	{
		printf("Create dlink node error!");
		return NULL;
	}
	//初始化结点的前驱和后继都指向自己
	pnode->prev = pnode->next = pnode;
	//初始化结点的值为传入的参数
	pnode->p = pval;

	return pnode;
}

/*新建双向链表，成功返回0，失败返回-1*/
int Create_dlink()
{
	d_node phead = Create_node(NULL);
	if (phead == NULL)
		return -1;

	count = 0;//第一个结点计数为0
	return phead;//存放的NULL（不会改变）
}
/*检查链表是否为空，是，返回true，否，返回false*/
bool dlink_is_Empty()
{
	return count == 0;//count为0，也就是说此时双向链表只有头结点，头结点存放的NULL
}

/*计算双向链表的长度*/
int dlink_Size()
{
	return count;//从零开始计数，每次加一个结点，count就加一
}

/*获取链表的Index位置的元素，成功，返回结点，失败，返回NULL*/
d_node dlink_get(int Index)
{	//当Index的值小于0和大于链表的长度的时候，一定不存在
	if (Index<0 || Index>=count)
	{
		printf("Index is out of bound!\n");
		return NULL;
	}
	/*根据双向链表的性质，可以分两组查找，正向查找，反向查找*/
	/*当在前半部分的时候，正向查找*/
	if (Index <= (count / 2))//包含了0和1/2的位置
	{
		d_node pnode = phead->next;
		int i = 0;
		/*我们的节点是从零开始计数的，也就是第一个结点，count=0，也就是说第Index位置在Index-1处*/
		for (i = 0; i < Index; i++)//
		{
			pnode = pnode->next;
		}
		return pnode;
	}
	/*当在后一半部分的时候，反向查找*/
	int len = count - Index;
	d_node rnode = phead->prev;//令开始查找的位置变成最后一个结点
	while (len != 0)//当len==0，说明找到Index结点
	{
		rnode = rnode->prev;
		len--;
	}
	return rnode;
}

/*获取第一个结点*/
d_node dlink_get_first()
{
	return 	dlink_get(0);
}

/*获取最后一个结点，成功，返回该节点，失败返回NULL*/
d_node dlink_get_last()
{
	return dlink_get(count - 1);
}

/*将value插入Index位置，成功返回1，失败返回0*/
