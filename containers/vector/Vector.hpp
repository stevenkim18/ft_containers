#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>		// allocator
# include <limits>		// for max_size()
# include "VectorIterator.hpp"

namespace ft
{
	template<typename T, typename A = std::allocator<T> >
	class Vector
	{
		public:
			typedef T						value_type;
			typedef A						allocator_type;
			typedef T&						reference;
			typedef T*						pointer;
			typedef ft::VectorIterator<T>	iterator;
			typedef size_t					size_type;

		private:
			pointer							_ptr;
			size_type						_length;
			size_type						_capacity;
			allocator_type					_allocator;

		public:
			// 기본 생성자
			explicit Vector(const allocator_type &allocator = allocator_type())
				: _ptr(nullptr), _length(0), _capacity(0), _allocator(allocator)
			{
				std::cout << "defalut constructor call" << std::endl;
				_ptr = _allocator.allocate(0);
			};

			// 소멸자
			// operator=
			// begin
			// end
			// rbegin
			// rend

			// size
			size_type size() const
			{
				return (this->_length);
			}

			size_type max_size() const
			{
				return (std::numeric_limits<size_t>::max() / sizeof(value_type));
			}
	};
};

#endif
