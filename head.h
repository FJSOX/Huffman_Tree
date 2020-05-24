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

//typedef struct HFMTNode* HFMT;
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
HFMTNode Maxab(HFMTNode a, HFMTNode b);
HFMTNode DeleteMinHeap(MinHeap H);
MinHeap WriteToMinHeap(int Maxlayer, DATA a[], int lentha);//lentha为数组a[]的长度

MinHeap MinHeap_New();
MinHeap MinHeap_Insert(HFMTNode D, MinHeap MH);
MinHeap MinHeap_WriteIn(HFMTNode* D);
//HFMTNode MinHeap_Pop(MinHeap MH);

//
HFMTNode CreateHT(MinHeap MH);
//HFMTNode 
//HFMTNode HaffmanTree_Insert(HFMTNode HT, DATA D);


#endif // !_HEAH_H_
