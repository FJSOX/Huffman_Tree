#include"head.h"


MinHeap CreateHeap(int Maxlayer)
{
	//�����ݻ�Ϊ2^Maxlayer-1������(Maxlayer >= 1)
	int Maxsize = (int)pow(2, Maxlayer);
	MinHeap h = new HNode();
	h->Data = new HFMTNode[Maxsize]();
	h->Capacity = Maxsize - 1;
	h->Size = 0;
	h->Data[0].Data = {"Guard", 0};//�ڱ������壿

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


MinHeap InsertMinHeap(MinHeap H, DATA D)//DΪDATA*���͵�����
{
	if (D.Weight > 0) {
		//Ȩֵ����С�ڵ���0
		//���HΪ�գ�ֱ�Ӳ���
		if (IsEmptyHeap(H)) {
			H->Data[1].Data = D;
			H->Size++;
		}
		else if (IsFullHeap(H))
		{
			std::cout << "The MaxHeap is full!" << std::endl;
		}
		else {
			HFMTNode emp;
			int i = H->Size + 1;
			H->Data[i].Data = D;
			H->Size++;
			while (H->Data[i].Data.Weight > H->Data[i / 2].Data.Weight && i / 2 >= 1) {
				//��Ҷ�ڵ��ֵ���ڸ��ڵ㣬������ֵ
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


HFMTNode Maxab(HFMTNode a, HFMTNode b)
{
	return a.Data.Weight > b.Data.Weight ? a : b;
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

	while (H->Data[i * 2].Data != {"", 0})
	{
		//��i,i*2,i*2+1��������Data֮��Ƚϴ�С
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