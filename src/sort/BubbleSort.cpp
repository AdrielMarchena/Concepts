#include "BubbleSort.h"

namespace sort {

	BubbleSort::BubbleSort(int p_size, int* data = {})
		:size(p_size)
	{
		members = new int[size];
		members = data;
	}

	BubbleSort::~BubbleSort()
	{
		delete members;
	}

	int* BubbleSort::execute()
	{
		bool swap = true;
		int* temp = members;
		while (swap)
		{
			swap = false;
			for (int i = 0; i < size-1; i++)
			{
				if (members[i] > members[i + 1])
				{
					int aux = temp[i];
					temp[i] = temp[i + 1];
					temp[i + 1] = aux;
					swap = true;
				}
			}
		}
		return temp;
	}
}