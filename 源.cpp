#include"head.h"
//using namespace std;

int main()
{
	std::string str = "Hello world!";
	std::cout << str << std::endl;
	MinHeap h=CreateHeap(3);
	//DATA d[10] = { { "c", 1}, { "a", 1}, { "d", 1}, { "b", 1}, { "f", 1}, { "e", 1}, };
	//h=WriteToMinHeap(4, d, 6);
	InsertMinHeap(h, { "a",1 });
	Pr_Heap(h);
	
	std::cout << "Program is over!";
	system("pause");
	return 0;
}