#pragma once
#ifndef _HEAH_H_
#define _HEAD_H_
#include<iostream>
#include<string>

typedef struct HFMTNode* HFMT;
struct HFMTNode
{
	std::string Data;
	int Weight;//ШЈжи
	HFMT Left;
	HFMT Right;
}; 

HFMT CreateHT();
HFMT Insert(HFMT H, )

#endif // !_HEAH_H_
