#include"head.h"

MinHeap Insert_HFMTNode_To_MinHeap(MinHeap H, HFMTNode HF)
{
	if (HF.Data.Weight > 0) {
		//权值不能小于等于0
		//如果H为空，直接插入
		if (IsEmptyHeap(H)) {
			H->Data[1] = HF;
			H->Size++;
		}
		else if (IsFullHeap(H))
		{
			std::cout << "The MinHeap is full!" << std::endl;
		}
		else {
			HFMTNode emp;
			int i = H->Size + 1;
			H->Data[i] = HF;
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

HFMTNode NewHFNode()
{
	HFMTNode h;
	h.Data = { "", 0 };
	h.Left = NULL;
	h.Right = NULL;;
	return h;
}


HFMTNode ABC(HFMTNode A, HFMTNode B, HFMTNode C)
{
	C.Data = { "Node", A.Data.Weight + B.Data.Weight };
	C.Left = new HFMTNode();
	C.Right = new HFMTNode();
	//C.Left = A;
	//C.Right = B;
	C.Left->Data = A.Data;
	C.Left->Left = A.Left;
	C.Left->Right = A.Right;
	C.Right->Data = B.Data;
	C.Right->Left = B.Left;
	C.Right->Right = B.Right;

	return C;
}

HFMTNode CreateHT(MinHeap MH)
{
	
	while (MH->Size>1)
	{
		//每次运行都在同一位置新建a，b，因为引用是附地址的，所以导致循环出错-》解法：不附地址调用？尚未实施！
		HFMTNode c = NewHFNode();
		HFMTNode a = NewHFNode();
		HFMTNode b = NewHFNode();
		a = DeleteMinHeap(MH);
		b = DeleteMinHeap(MH);
		c = ABC(a, b, c);

		

		MH = Insert_HFMTNode_To_MinHeap(MH, c);
	}

	return MH->Data[1];
}

void Print_HT(HFMT HF)
{
	Array a;
	a.A = new HFMT()[];
	a.Front = 0;
	a.Rear = 1;
}