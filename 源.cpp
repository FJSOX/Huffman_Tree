#include"head.h"
//using namespace std;

//typedef struct hnode* minHeap;
//struct hnode
//{
//	HFMTNode* Data;
//	int Size;
//	int Capacity;
//};
//
//hnode change(hnode h)
//{
//	h.Data[0].Data.Str = "hello";
//	h.Data[0].Data.Weight = 2;
//	return h;
//}



int main()
{
	DATA a[] = { { "h", 5 }, { "e", 3 }, { "l", 4 }, {"o", 8 }, {"w", 9}, {"r", 6}, {"d", 1} };
	
	MinHeap h= WriteToMinHeap(3, a, sizeof(a)/sizeof(a[0]));
	Pr_Heap(h);
	HFMTNode hh= CreateHT(h);


	Print_HT(&hh);

	std::cout << "Program is over!";
	system("pause");
	return 0;
}