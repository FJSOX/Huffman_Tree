#include"head.h"

HFMT CreateHT(MinHeap MH)
{
	HFMT a = MinHeap_Pop(MH);
	HFMT b = MinHeap_Pop(MH);
	HFMT h;
	h->Data.Weight = a->Data.Weight + b->Data.Weight;
	h->Left = a;
	h->Right = b;
	MinHeap
}