/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:20:16 by seunkim           #+#    #+#             */
/*   Updated: 2020/11/24 08:13:44 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>		// allocator
# include <limits>		// for max_size()
# include "VectorIterator.hpp"
# include "../utils.hpp"

namespace ft
{
	template<typename T, typename A = std::allocator<T> >
	class Vector
	{
		public:
			typedef T									value_type;
			typedef A									allocator_type;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef T*									pointer;
			typedef ft::VectorIterator<T>				iterator;
			typedef ft::ReverseVectorIterator<T> 		reverse_iterator;
			typedef ft::ConstVectorIterator<T>			const_iterator;
			typedef ft::ConstReverseVectorIterator<T>	const_reverse_iterator;
			typedef size_t								size_type;

		private:
			pointer							_arr;
			size_type						_length;
			size_type						_capacity;
			allocator_type					_allocator;

		public:
			explicit Vector(const allocator_type &allocator = allocator_type())
				: _arr(nullptr), _length(0), _capacity(0), _allocator(allocator)
			{
				_arr = _allocator.allocate(0);
			}
			// fill constructor
			// range constructor
			// copy constructor

			// destructor
			~Vector() { _allocator.deallocate(_arr, _capacity); }
			// operator=

			iterator 				begin() { return (iterator(_arr)); }
			const_iterator 			begin() const { return (const_iterator (_arr)); }
			iterator 				end() { return (iterator(_arr + _length)); }
			const_iterator			end() const { return (const_iterator(_arr + _length)); }
			reverse_iterator 		rbegin() { return (reverse_iterator(_arr + _length - 1)); }
			const_reverse_iterator 	rbegin() const { return (const_reverse_iterator(_arr + _length - 1)); }
			reverse_iterator		rend() { return (reverse_iterator(_arr - 1)); }
			const_reverse_iterator	rend() const { return (const_reverse_iterator(_arr - 1)); }

			size_type 				size() const { return (_length); }
			size_type 				max_size() const { return (std::numeric_limits<size_t>::max() / sizeof(value_type)); }
			void 					resize (size_type n, value_type val = value_type())
			{
				while (n > _length)
					push_back(val);
				while (n < _length)
					pop_back();
			}
			size_type 				capacity() const { return (_capacity); }
			bool 					empty() const { return (_length == 0);}
			void 					reserve(size_type n)
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

			reference				operator[](size_type n) { return _arr[n]; }
			const_reference 		operator[](size_type n) const { return _arr[n]; }
			reference 				at(size_type n)
			{
				if (n < 0 || n >= _length)
					throw std::out_of_range("out_of_range: vector");
				return (_arr[n]);
			}
			const_reference 		at(size_type n) const
			{
				if (n < 0 || n >= _length)
					throw std::out_of_range("out_of_range: vector");
				return (_arr[n]);
			}
			reference 				front() { return (_arr[0]);}
			const_reference 		front() const { return (_arr[0]);}
			reference 				back() { return (_arr[_length - 1]);}
			const_reference 		back() const { return (_arr[_length - 1]);}

			template <class InputIterator>
			void					assign(InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			}
			void					assign(size_type n, const value_type& val)
			{
				clear();
				insert(begin(), n, val);
			}
			void 					push_back(const value_type &val)
			{
				if (_capacity == 0)
					reserve(1);
				else if (_length >= _capacity)
					reserve(_capacity * 2);
				_arr[_length] = val;
				_length++;
			}
			void 					pop_back()
			{
				if (_length != 0)
					_length--;
			}
			iterator				insert(iterator position, const value_type& val)
			{
				size_type i = 0;
				iterator it = begin();
				while (it + i != position && i < _length)
					i++;
				if (_capacity == 0)
					reserve(1);
				else if (_length >= _capacity)
					reserve(_capacity * 2);
				size_type j = _capacity - 1;
				while (j > i)
				{
					_arr[j] = _arr[j - 1];
					j--;
				}
				_arr[i] = val;
				_length++;
				return (iterator(&_arr[i]));
			}
			void					insert(iterator position, size_type n, const value_type& val)
			{
				while (n--)
					position = insert(postion, val);
			}
			template<class InputIterator>
			void					insert(iterator position, InputIterator begin, InputIterator end)
			{
				while (begin != end)
				{
					position = insert(position, *begin) + 1;
					begin++;
				}
			}
			iterator				erase(iterator position)
			{
				iterator iter = position;
				while (iter + 1 != end())
				{
					*iter = *(iter + 1);
					iter++;
				}
				_length==;
				return (iterator(position));
			}
			iterator				erase(iterator begin, iterator end)
			{
				while (begin != end)
				{
					erase(begin);
					end--;
				}
				return (iterator(begin));
			}
			void					swap(Vector &ref)
			{
				ft::swap(_arr, ref._arr);
				ft::swap(_length, ref._length);
				ft::swap(_capacity, ref._capacity);
			}
			void					clear()
			{
				erase(begin(), end());
			}
	};
};

#endif
