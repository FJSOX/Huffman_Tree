#pragma once
#ifndef _HEAH_H_
#define _HEAD_H_
#include<iostream>
#include<string>

//typedef struct DATA* DA;
struct DATA
{
	std::string Str;
	int Weight;//权重
};

typedef struct HFMTNode* HFMT;
struct HFMTNode
{
	DATA Data;
	HFMTNode* Left;
	HFMTNode* Right;
}; 

typedef struct HNode* MinHeap;
struct HNode
{
	HFMTNode* Data;
	int Size;
	int Capacity;
};

//
MinHeap CreateHeap(int Maxlayer);//Maxlayer为最大层数
bool IsFullHeap(MinHeap H);
bool IsEmptyHeap(MinHeap H);
MinHeap InsertMinHeap(MinHeap H, DATA D);//不能用零作为数据
void Pr_Heap(MinHeap H);
HFMTNode Minab(HFMTNode a, HFMTNode b);
HFMTNode DeleteMinHeap(MinHeap H);
MinHeap WriteToMinHeap(int Maxlayer, DATA a[], int lentha);//lentha为数组a[]的长度
HFMTNode NewHFNode();

//HFMTNode MinHeap_Pop(MinHeap MH);

//
MinHeap Insert_HFMTNode_To_MinHeap(MinHeap H, HFMTNode HF);
HFMTNode NewHFNode();
HFMTNode ABC(HFMTNode A, HFMTNode B, HFMTNode C);
HFMTNode CreateHT(MinHeap MH);
//HFMTNode 
//HFMTNode HaffmanTree_Insert(HFMTNode HT, DATA D);


//遍历打印树
struct Array
{
	HFMT* A;
	int Front;
	int Rear;
};

void Print_HT(HFMT HF);
HFMT Delete_Fornt_Of_Array(Array& Ar);
Array Insert_HF_To_Array(HFMT HF, Array Ar, int Ar_Size);

#endif // !_HEAH_H_
