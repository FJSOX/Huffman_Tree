#include"head.h"


MinHeap CreateHeap(int Maxlayer)
{
	//创建容积为2^Maxlayer-1的最大堆(Maxlayer >= 1)
	int Maxsize = (int)pow(2, Maxlayer);
	MinHeap h = new HNode();
	h->Data = new HFMTNode[Maxsize]();
	h->Capacity = Maxsize - 1;
	h->Size = 0;
	h->Data[0].Data = {"Guard", 0};//哨兵，意义？

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


MinHeap InsertMinHeap(MinHeap H, DATA D)//D为DATA类型的数据
{
	if (D.Weight > 0) {
		//权值不能小于等于0
		//如果H为空，直接插入
		if (IsEmptyHeap(H)) {
			H->Data[1].Data = D;
			H->Size++;
		}
		else if (IsFullHeap(H))
		{
			std::cout << "The MinHeap is full!" << std::endl;
		}
		else {
			HFMTNode emp;
			int i = H->Size + 1;
			H->Data[i].Data = D;
			H->Size++;
			while (H->Data[i].Data.Weight < H->Data[i / 2].Data.Weight && i / 2 >= 1) {
				//若叶节点的值小于根节点，交换两值
				emp = H->Data[i];
				H->Data[i] = H->Data[i / 2];
				i = i / 2;
				H->Data[i] = emp;
			}

		}
	}

	return H;
}

void Pr_Heap(MinHeap H)
{
	for (int i = 1; i <= H->Size; i++) {
		std::cout << H->Data[i].Data.Str << "\t";
	}
}


HFMTNode Minab(HFMTNode a, HFMTNode b)
{
	return a.Data.Weight < b.Data.Weight ? a : b;
}

HFMTNode DeleteMinHeap(MinHeap H)
{
	HFMTNode cmp;
	int i = 1;
	HFMTNode ret;

	ret = H->Data[1];
	H->Data[i] = H->Data[H->Size];
	H->Data[H->Size].Data = {"", 0};
	H->Size--;

	if (H->Size>1) {
		while (H->Data[i * 2].Data.Str != "" && H->Data[i * 2].Data.Weight != 0  && i<H->Size)
		{
			//在i,i*2,i*2+1三个数的Data之间比较大小
			cmp = Minab(H->Data[i * 2], H->Data[i * 2 + 1]);
			if (H->Data[i * 2].Data.Str == cmp.Data.Str && H->Data[i * 2].Data.Weight == cmp.Data.Weight) {

				cmp = Minab(cmp, H->Data[i]);
				if (i * 2 > H->Size)
				{
					break;
				}
				else if ( H->Data[i].Data.Str != cmp.Data.Str || H->Data[i].Data.Weight != cmp.Data.Weight ) {
					cmp = H->Data[i];
					H->Data[i] = H->Data[i * 2];
					H->Data[i * 2] = cmp;
					i = i * 2;
				}
				else {
					break;
				}
				
			}
			else {
				cmp = Minab(cmp, H->Data[i]);
				if (i * 2 + 1 > H->Size)
				{
					break;
				}
				else if ( H->Data[i].Data.Str != cmp.Data.Str || H->Data[i].Data.Weight != cmp.Data.Weight ) {
					cmp = H->Data[i];
					H->Data[i] = H->Data[i * 2 + 1];
					H->Data[i * 2 + 1] = cmp;
					i = i * 2 + 1;
				} 
				else {
					break;
				}
			}
		}
	}
	if (H->Size==2)
	{
		if (H->Data[1].Data.Weight > H->Data[2].Data.Weight) {
			cmp = H->Data[1];
			H->Data[1] = H->Data[2];
			H->Data[2] = cmp;
		}
	}

	return ret;
}

MinHeap WriteToMinHeap(int Maxlayer, DATA a[], int lentha)
{
	MinHeap h = CreateHeap(Maxlayer);
	int i = 0;

	for (i = 0;i < lentha;i++) {
		if (a[i].Weight > 0) {
			h=InsertMinHeap(h, a[i]);
		}
		else
		{
			break;
		}
	}

	return h;
}