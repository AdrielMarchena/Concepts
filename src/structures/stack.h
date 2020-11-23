#pragma once
#include <vector>
namespace structures
{
	template<typename T>
	class Stack
	{
	private:

		T* m_elements;
		int top;
		int size;
	public:
		Stack(int p_initSize)
			:top(-1),
			size(p_initSize)
		{
			m_elements = new T[size];
		}
		~Stack() { delete m_elements; }

		void push(T p_newMember)
		{
			if (isFull())
				throw new std::exception("Stack is full");
			top++;
			m_elements[top] = p_newMember;
		}

		T pop()
		{
			if (isEmpty())
				throw new std::exception("Stack is empty");

			auto temp = m_elements[top];
			m_elements[top] = NULL;
			top--;
			return temp;
		}

		int indexOf(T p_searchMember)
		{
			for (int i = 0; i <= top; i++)
				if (m_elements[i] == p_searchMember)
					return i;
		}
		bool isFull()
		{
			return (top == size - 1);
		}

		bool isEmpty()
		{
			return (top < 0);
		}
	};
	
}


