#pragma once
#ifndef _HEAH_H_
#define _HEAD_H_
#include<iostream>
#include<string>

struct DATA
{
	std::string Str;
	int Weight;//ШЈжи
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
	HFMT Data;
	MinHeap Left;
	MinHeap Right;
};

//
MinHeap MinHeap_New();
MinHeap MinHeap_Insert(HFMT D, MinHeap MH);
MinHeap MinHeap_WriteIn(HFMT* D);
HFMT MinHeap_Pop(MinHeap MH);
//
HFMT CreateHT(MinHeap MH);
//HFMT 
//HFMT HaffmanTree_Insert(HFMT HT, DATA D);


#endif // !_HEAH_H_
