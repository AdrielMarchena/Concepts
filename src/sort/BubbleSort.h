#pragma once

namespace sort
{
	struct BubbleSort
	{
	private:
		int size;
	public:
		int* members;
		BubbleSort(int size, int* data);
		~BubbleSort();
		int* execute();
	};
}


