#include"head.h"


MinHeap CreateHeap(int Maxlayer)
{
	//创建容积为2^Maxlayer-1的最大堆(Maxlayer >= 1)
	int Maxsize = (int)pow(2, Maxlayer);
	MinHeap h = (MinHeap)malloc(sizeof(struct HNode));
	h->Data = new HFMT[Maxsize]();
	h->Capacity = Maxsize - 1;
	h->Size = 0;
	h->Data[0]->Data->Str = "500";//哨兵，意义？

	return h;
}

bool IsFullHeap(MinHeap H)
{
	return (H->Capacity == H->Size);
}

bool IsEmptyHeap(MinHeap H)
{
	return (H->Size == 0);
}


MinHeap InsertMinHeap(MinHeap H, DA D)//D为DATA*类型的数据
{
	//如果H为空，直接插入
	if (IsEmptyHeap(H)) {
		H->Data[1]->Data=D;
		H->Size++;
	}
	else if (IsFullHeap(H))
	{
		std::cout << "The MaxHeap is full!" << std::endl;
	}
	else {
		HFMT emp;
		int i = H->Size + 1;
		H->Data[i]->Data = D;
		H->Size++;
		while (H->Data[i]->Data->Weight > H->Data[i / 2]->Data->Weight && i / 2 >= 1) {
			//若叶节点的值大于根节点，交换两值
			emp = H->Data[i];
			H->Data[i] = H->Data[i / 2];
			i = i / 2;
			H->Data[i] = emp;
		}

	}
	return H;
}

void Pr_Heap(MinHeap H)
{
	for (int i = 1; i <= H->Size; i++) {
		std::cout << H->Data[i] << "\t";
	}
}


HFMT Maxab(HFMT a, HFMT b)
{
	return a->Data->Weight > b->Data->Weight ? a : b;
}

HFMT DeleteMinHeap(MinHeap H)
{
	HFMT cmp;
	int i = 1;
	HFMT ret;

	ret = H->Data[1];
	H->Data[i] = H->Data[H->Size];
	H->Data[H->Size] = 0;
	H->Size--;

	while (H->Data[i * 2] != 0)
	{
		//在i,i*2,i*2+1三个数的Data之间比较大小
		cmp = Maxab(H->Data[i * 2], H->Data[i * 2 + 1]);
		if (cmp == H->Data[i * 2]) {
			cmp = Maxab(cmp, H->Data[i]);
			if (cmp != H->Data[i]) {
				cmp = H->Data[i];
				H->Data[i] = H->Data[i * 2];
				H->Data[i * 2] = cmp;
				i = i * 2;
			}
		}
		else {
			cmp = Maxab(cmp, H->Data[i]);
			if (cmp != H->Data[i]) {
				cmp = H->Data[i];
				H->Data[i] = H->Data[i * 2 + 1];
				H->Data[i * 2 + 1] = cmp;
				i = i * 2 + 1;
			}
		}

	}

	return ret;
}

MinHeap WriteToMaxHeap(int Maxlayer, DA a[], int lentha)
{
	MinHeap h = CreateHeap(Maxlayer);
	int i = 0;

	for (i = 0;i < lentha;i++) {
		InsertMinHeap(h, a[i]);
	}

	return h;
}