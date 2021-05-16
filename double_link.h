

#ifndef __DOUBLE_LINK_H__
#define __DOUBLE_LINK_H__

/*新建一个双向链表，成功，返回表头，否则返回NULL*/
extern void* Create_node();
/*撤销(销毁)双向链表，成功返回1，否则返回0*/
extern int Destory_dlink();
/*判断双向链表是否为空，是，返回1，否则返回0*/
extern int dlink_is_Empty();

/*返回双向链表的大小*/
extern int dlink_Size();

/*获取双向链表第Index位置的元素，成功，返回结点，否则返回NULL*/
extern void* dlink_get(int Index);
/*获取双向链表第1个元素，成功，返回结点，否则返回NULL*/
extern void* dlink_get_first();
/*获取双向链表最后一个元素，成功，返回结点，否则返回NULL*/
extern void* dlink_get_last();

/*将value插入到Index位置，成功，返回1，失败返回-1*/
extern int dlink_insert(int Index, void* pval);
/*将value插入到表头位置，成功，返回1，失败返回-1*/
extern int dlink_insert_first(void* pval);
/*将value插入到链表尾部，成功，返回1，失败返回-1*/
extern int dlink_insert_last(void *pval);

/*删除双向链表Index位置的结点，成功返回0，失败返回-1*/
extern int dlink_delete(int Index);
/*删除双向链表第一个结点，成功返回0，失败返回-1*/
extern int dlink_delete_first();
/*删除双向链表最后一个结点，成功返回0，失败返回-1*/
extern int dlink_delete_last();


#endif  //__DOUBLE_LINK_H__