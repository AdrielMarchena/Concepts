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

		~List() { clear(); }

		void insert(T p_Element)
		{
			/* I need to clear this things here */
			Data<T>* newData = new Data<T>;
			/* Oh God oh no this up here is a memory leak */
			newData->m_data = p_Element;
			newData->m_next = nullptr;
			if (isEmpty())
			{
				m_List = *newData;
				delete newData;
			}
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
			if (isEmpty())
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
			if (isEmpty()) return;

			Data<T>* temp = &m_List;
			Data<T>* aux = nullptr;
			while (m_List.m_next != nullptr)
			{
				while (temp->m_next != nullptr)
				{
					aux = temp;
					temp = temp->m_next;
				}
				std::cout << "Cleared " << temp->m_data << std::endl;
				aux->m_next = nullptr;
				delete temp;
				
				if(m_List.m_next != nullptr)
					temp = &m_List;
			}
			std::cout << "Cleared " << m_List.m_data << std::endl;
			m_List.m_data = NULL;
			m_List.m_next = nullptr;
		}

		bool isEmpty()
		{
			return m_List.m_next == nullptr && m_List.m_data == NULL;
		}
	};
}