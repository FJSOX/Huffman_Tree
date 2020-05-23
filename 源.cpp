#include"head.h"
//using namespace std;

int main()
{
	std::string str = "Hello world!";
	std::cout << str << std::endl;
	//MinHeap h=CreateHeap(3);
	//DATA d[10] = { { "c", 1}, { "a", 1}, { "d", 1}, { "b", 1}, { "f", 1}, { "e", 1}, };
	//h=WriteToMinHeap(4, d, 6);
	//InsertMinHeap(h, { "a",1 });
	//Pr_Heap(h);
	DATA d[10];
	d[0] = { "h",1 };
	//MinHeap h= (MinHeap)malloc(sizeof(struct HNode));
	//h->Data = (HFMT*)malloc(10 * sizeof(HFMT));
	//h->Data[0]->Data.Weight = 1;
	typedef struct hnode* minHeap;
	struct hnode
	{
		HFMTNode* Data;
		int Size;
		int Capacity;
	};

	minHeap hh= (minHeap)malloc(sizeof(struct hnode));
	hh->Data = new HFMTNode[10]();
	hh->Data[0].Data.Weight = d[0].Weight;
	//hh->Data[0].Data.Str = d[0].Str;
	hh->Data[1].Data.Weight = 1;
	hh->Data[0].Data.Str= "h";
	std::cout <<  hh->Data[1].Data.Weight<<std::endl;
	
	std::cout << "Program is over!";
	system("pause");
	return 0;
}