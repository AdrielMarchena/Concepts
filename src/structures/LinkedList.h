#pragma once
#include <iostream>
namespace structures {
	template<typename T>
	/*
		Core
	*/
	struct Data
	{
		T m_data = NULL;
		Data* m_next = nullptr;
	};
	template<typename T>
	class List
	{
	private:
		Data<T> m_List;
	public:
		List()
		{
		}

		~List(){}

		void insert(T p_Element)
		{
			/* I need to clear this things here */
			Data<T>* newData = new Data<T>;
			/* Oh God oh no this up here is a memory leak */
			newData->m_data = p_Element;
			newData->m_next = NULL;
			if (m_List.m_next == nullptr && m_List.m_data == NULL)
				m_List = *newData;
			else
			{
				Data<T>* temp = &m_List;
				while (temp->m_next != nullptr)
				{
					temp = temp->m_next;
				}
				temp->m_next = newData;
			}
		}

		void list()
		{
			if (m_List.m_next == nullptr && m_List.m_data == NULL)
			{
				std::cout << "empty List" << std::endl;
			}
			else
			{
				Data<T>* aux = &m_List;
				while (aux != NULL)
				{
					std::cout << "Element: " << aux->m_data << std::endl;
					aux = aux->m_next;
				}
			}
		}

		void clear()
		{
			int count = 0;
			Data<T>* temp = &m_List;
			while (temp->m_next != nullptr)
			{
				temp = temp->m_next;
				if (temp->m_next == nullptr)
				{
					delete temp->m_next;
					temp = &m_List;
				}
			}
		}

		bool isEmpty()
		{
			return m_List.m_next == nullptr && m_List.m_data == NULL;
		}
	};
}