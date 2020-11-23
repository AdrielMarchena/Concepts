#pragma once
#include <exception>
namespace structures
{
	template <typename T>
	class Queue
	{
	private:
		int size;
		T* m_elements;
		int first;
		int last;
		int total;
	public:
		Queue(int p_size)
			:size(p_size), first(0),last(0),total(0)
		{
			m_elements = new T[size];
		}
		~Queue() { delete m_elements; }

		void insert(T p_element)
		{
			if (isFull())
				throw std::exception("Queue is full");

			m_elements[last] = p_element;
			last = (last + 1) % (size);//% size Prevent go out of bounds
			total++;
		}

		T remove()
		{
			if (isEmpty())
				throw std::exception("Queue is empty");
			
			auto element = m_elements[first];
			first = (first + 1) % (size);
			total--;
			return element;
		}
		bool isFull()
		{
			return total == size;
		}
		bool isEmpty()
		{
			return total == 0;
		}
		int getSize() { return size; }
		int getTotal() { return total; }
	};
}