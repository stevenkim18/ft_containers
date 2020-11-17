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
			typedef const T&				const_reference;
			typedef T*						pointer;
			typedef ft::VectorIterator<T>	iterator;
			typedef size_t					size_type;

		private:
			pointer							_arr;
			size_type						_length;
			size_type						_capacity;
			allocator_type					_allocator;

		public:
			// defalut constructor
			explicit Vector(const allocator_type &allocator = allocator_type())
				: _arr(nullptr), _length(0), _capacity(0), _allocator(allocator)
			{
				_arr = _allocator.allocate(0);
			};
			// fill constructor
			// range constructor
			// copy constructor

			// destructor
			~Vector() { _allocator.deallocate(_arr, _capacity); }
			// operator=
			// begin
			// end
			// rbegin
			// rend

			size_type size() const { return (_length); }

			size_type max_size() const
			{
				return (std::numeric_limits<size_t>::max() / sizeof(value_type));
			}

			// resize
			void resize (size_type n, value_type val = value_type())
			{
				while (n > _length)
					push_back(val);
				while (n < _length)
					pop_back();
			}

			// capacity
			size_type capacity() const { return (_capacity); }

			// empty
			bool empty() const { return (_length == 0);}

			// reserve
			void reserve(size_type n)
			{
				if (_capacity < n)
				{
					pointer	tmp = _allocator.allocate(n);	// 새로운 사이즈 메모리를 할당
					_capacity = n;
					for (size_type i = 0; i < _length; i++)
						tmp[i] = _arr[i];
					_allocator.deallocate(_arr, _capacity);
					_arr = tmp;
				}
			}

			// operator[]
			reference operator[](size_type n) { return _arr[n]; }
			const_reference operator[](size_type n) const { return _arr[n]; }

			// at
			reference at(size_type n)
			{
				if (n < 0 || n >= _length)
					throw std::out_of_range("out_of_range: vector");
				return (_arr[n]);
			}

			const_reference at(size_type n) const
			{
				if (n < 0 || n >= _length)
					throw std::out_of_range("out_of_range: vector");
				return (_arr[n]);
			}

			// front
			reference front() { return (_arr[0]);}
			const_reference front() const { return (_arr[0]);}

			// back
			reference back() { return (_arr[_length - 1]);}
			const_reference back() const { return (_arr[_length - 1]);}
			// assign

			// push_back
			void push_back(const value_type &val)
			{
				if (_capacity == 0)
					reserve(1);
				else if (_length >= _capacity)
					reserve(_capacity * 2);
				_arr[_length] = val;
				_length++;
			}
			// pop_back
			void pop_back()
			{
				if (_length != 0)
					_length--;
			}

			// insert

			// erase

			// swap

			// clear
	};
};

#endif
