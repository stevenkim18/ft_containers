#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "VectorIterator.hpp"

namespace ft
{
	template<typename T>
	class Vector
	{
		public:
			typedef T						value_type;
			typedef T&						reference;
			typedef T*						pointer;
			typedef ft::VectorIterator<T>	iterator;
			typedef size_t					size_type;

		private:
			pointer							_ptr;
			size_type						_length;
			size_type						_capacity;

		public:
			Vector() _ptr(nullptr), _length(0), _capacity(0) {}

	};
};

#endif
