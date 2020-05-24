#include"head.h"

MinHeap Insert_HFMTNode_To_MinHeap(MinHeap H, HFMTNode HF)
{
	if (HF.Data.Weight > 0) {
		//Ȩֵ����С�ڵ���0
		//���HΪ�գ�ֱ�Ӳ���
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
				//��Ҷ�ڵ��ֵС�ڸ��ڵ㣬������ֵ
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

	return C;
}

HFMTNode CreateHT(MinHeap MH)
{
	
	while (MH->Size>1)
	{
		//ÿ�����ж���ͬһλ���½�a��b����Ϊ�����Ǹ���ַ�ģ����Ե���ѭ������-���ⷨ��������ַ���ã���δʵʩ��
		HFMTNode c = NewHFNode();
		HFMT a = new HFMTNode();
		HFMT b = new HFMTNode();
		a=&DeleteMinHeap(MH);
		b = &DeleteMinHeap(MH);
		c.Data = { "Node", a->Data.Weight+b->Data.Weight };
		c.Left = a;
		c.Right = b;
		MH = Insert_HFMTNode_To_MinHeap(MH, c);
	}

	return MH->Data[1];
}