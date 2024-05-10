#include "linked_list.hpp"
#include <iostream>


template<typename T>
whytimmy::LinkedList<T>::~LinkedList() noexcept{

	Node* element = begin;

	while (element != end)
    {
		Node* next = element->next;  
		delete element;
		element = next;
	}

	delete end;
}


template<typename T>
void whytimmy::LinkedList<T>::push_back(const T& value) noexcept{

	Node* element = new Node(value);

    if (begin != nullptr)
    {
        end->next = element;
        element->prev = end;
        end = element;
    }

	else if (begin == nullptr)
    {
        end = element;
		begin = element;
	}

}


template<typename T>
bool whytimmy::LinkedList<T>::has_item(const T& value) const noexcept{

	if (end == nullptr)
    {
		return 0;
	}

    if (end->value == value)
    {
        return 1;
    }

	Node* element = begin;

	while (element != end)
    {
		if (element->value == value)
        {
			return 1;
		}
		element = element->next;
	}

	return 0;
}


template<typename T>
void whytimmy::LinkedList<T>::print() const noexcept{

	if (end == nullptr)
    {
		return;
	}

	Node* element = begin;

	while (element != end)
    {
		std::cout << element->value << " ";
		element = element->next;
	}

	std::cout << end->value;
    std::cout << "\n";
}



template<typename T>
bool whytimmy::LinkedList<T>::remove_first(const T& value) noexcept{

	if (end == nullptr)
    {
		return 0;
	}

	if (end == begin and end->value == value)
    {
		delete end;
        begin = nullptr;
		end = nullptr;

		return 1;
	}

	Node* element = begin;

	while (element != end)
    {
		if (element->value == value)
        {
			element->prev->next = element->next;
			element->next->prev = element->prev;
			delete element;
			return 1;
		}
		element = element->next;
	}

	if (end->value == value)
    {
		end = end->prev;
		delete end->next;
		end->next = nullptr;
		return 1;
	}

	return 0;
}


template<typename T>
std::size_t whytimmy::LinkedList<T>::size() const noexcept{

	if (end == nullptr)
    {
		return 0;
	}

	std::size_t count = 0;

	Node* element = begin;

	while (element != end)
    {
        element = element->next;
        ++count;
	}

	return ++count;
}
