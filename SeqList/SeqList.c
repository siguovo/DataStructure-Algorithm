
#include "SeqList.h"

//初始化
void SeqListInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}

	ps->size = 0;
	ps->capacity = 4;
}
//打印数组
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//动态扩容
void SeqListCheckCaapacity(SL* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
}

//尾插尾删，头插头删
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//如果满了需要增容
	SeqListCheckCaapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	assert(ps);

	//ps->a[ps->size - 1] = 0;
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	int end = ps->size - 1;
	//如果满了需要增容
	SeqListCheckCaapacity(ps);
	//每一个数往后挪动
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	//最后在头部插入
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps);

	int start = 0;
	while (start < ps->size)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}
//任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	SeqListCheckCaapacity(ps);
	//(pos一定要在0到size之间)
	if (pos > ps->size - 1 || pos < 0)
	{
		printf("插入位置%d不在数组范围内，插入失败\n",pos);
		exit(-1);
	}
	int end = ps->size - 1;
	//每一个数往后挪动
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	//最后在pos处插入
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	if (pos > ps->size - 1 || pos < 0)
	{
		printf("删除位置%d不在数组范围内，删除失败\n", pos);
		exit(-1);
	}

	int start = pos;
	while (start < ps->size)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}

//查找 
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;//找到就返回下标
		}
	}
	return -1;//没找到
}

//排序  Bubble Sort
void SeqListSort(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		int flag = 0;
		for (int j = 0; j < ps->size - i - 1; j++)
		{
			if (ps->a[j] > ps->a[j + 1])
			{
				int tmp = ps->a[j];
				ps->a[j] = ps->a[j + 1];
				ps->a[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

//排序后进行二分查找
int SeqListBubaryFind(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->a[0] > x || ps->a[ps->size-1] < x)
	{
		printf("%d不在数组中\n",x);
		return -1;
	}

	int left = 0;
	int right = ps->size - 1;
	int mid = (left + right) / 2;
	if (ps->a[mid] > x)
	{
		right = mid;
	}
	else if (ps->a[mid] < x)
	{
		left = mid;
	}
	else if (ps->a[mid] == x)
	{
		return mid;
	}
	printf("%d不存在，未在数组中找到,返回", x);
	return -1;
}