#pragma once
#ifndef _HEAH_H_
#define _HEAD_H_
#include<iostream>
#include<string>

//typedef struct DATA* DA;
struct DATA
{
	std::string Str;
	int Weight;//Ȩ��
};

typedef struct HFMTNode* HFMT;
struct HFMTNode
{
	DATA Data;
	HFMT Left;
	HFMT Right;
}; 

typedef struct HNode* MinHeap;
struct HNode
{
	HFMT* Data;
	int Size;
	int Capacity;
};

//
MinHeap CreateHeap(int Maxlayer);//MaxlayerΪ������
bool IsFullHeap(MinHeap H);
bool IsEmptyHeap(MinHeap H);
MinHeap InsertMinHeap(MinHeap H, DATA D);//����������Ϊ����
void Pr_Heap(MinHeap H);
HFMT Maxab(HFMT a, HFMT b);
HFMT DeleteMinHeap(MinHeap H);
MinHeap WriteToMinHeap(int Maxlayer, DATA a[], int lentha);//lenthaΪ����a[]�ĳ���

MinHeap MinHeap_New();
MinHeap MinHeap_Insert(HFMT D, MinHeap MH);
MinHeap MinHeap_WriteIn(HFMT* D);
//HFMT MinHeap_Pop(MinHeap MH);

//
HFMT CreateHT(MinHeap MH);
//HFMT 
//HFMT HaffmanTree_Insert(HFMT HT, DATA D);


#endif // !_HEAH_H_
