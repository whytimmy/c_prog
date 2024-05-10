#include "vector.hpp"
#include <stdexcept>
#include <iostream>


template <typename T>
whytimmy::Vector<T>::~Vector() noexcept{

	delete[] arr;
    arr = nullptr;
    size = 0;
	capacity = 0;

}


template <typename T>
void whytimmy::Vector<T>::push_back(const T& value) noexcept{
	if (capacity == size)
    {
		T* new_arr = new T[capacity * 2];

		for (std::size_t i = 0; i < capacity; ++i)
        {
			new_arr[i] = arr[i];
		}

		delete[] arr;
        arr = new_arr;
        capacity = capacity * 2;

	}
	arr[size] = value;
    ++size;
}


template <typename T>
bool whytimmy::Vector<T>::has_item(const T& value) const noexcept{

	for (std::size_t i = 0; i < size; ++i)
    {
		if (arr[i] == value)
        {
			return true;
		}
	}
	return false;
}



template <typename T>
bool whytimmy::Vector<T>::insert(const int position, const T& value){

	if (position > size)
    {
        throw std::out_of_range("Position is out of bounds");
    }

	if (capacity == size)
    {
		T* new_arr = new T[2 * capacity];

		for (std::size_t i = 0; i < capacity; ++i)
        {
			new_arr[i] = arr[i];
		}

		delete[] arr;
		arr = new_arr;	
		capacity *= 2;

	}

	for (std::size_t i = size; i > position; --i)
    {
		arr[i] = arr[i - 1];
	}

	++size;
	arr[position] = value;
	return true;
}


template <typename T>
void whytimmy::Vector<T>::print() const noexcept{

	for (std::size_t i = 0; i < size; ++i)
    {
		std::cout << arr[i] << " ";
	}
    std::cout << "\n";

}


template <typename T>
bool whytimmy::Vector<T>::remove_first(const T& value) noexcept{

	T* new_arr = new T[--capacity];

	for (std::size_t i = 0; i < size; ++i)
    {
		if (arr[i] == value)
        {
			for (std::size_t j = i; j < --size; ++j)
            {
				new_arr[j] = arr[j + 1];
			}

			delete[] arr;
            capacity--;
            size--;
			arr = new_arr;

			return true;
		}

		new_arr[i] = arr[i];

	}

	return false;
}



template <typename T>
std::size_t whytimmy::Vector<T>::get_size() const noexcept{

	return size;
}
