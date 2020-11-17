/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:30:12 by seunkim           #+#    #+#             */
/*   Updated: 2020/11/17 23:15:08 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

namespace ft
{
	template<typename T>
	class VectorIterator
	{
		public:
			typedef T	value_type;
			typedef T&	references;
			typedef T*	pointer;
			// typedef Distance  difference_type;
			// typedef Category  iterator_category;

		protected:
			pointer		_ptr;

		public:
			VectorIterator() {};										// 기본 생성자
			VectorIterator(pointer ptr) : _ptr(ptr) {}
			VectorIterator(const VectorIterator &ref) { *this = ref; }	// 복사 생성자
			VectorIterator& operator=(const VectorIterator &ref)		// = 오버로딩
			{
				_ptr = ref._ptr;
				return (*this);
			}
			~VectorIterator() {};										// 소멸자

			// ++a
			VectorIterator &operator++() { _ptr++; return (*this); }
			// a++
			VectorIterator operator++(int)
			{
				VectorIterator tmp(*this);
				operator++();
				return (tmp);
			}
			// a == b
			bool operator==(const VectorIterator &ref) const { return (_ptr == ref._ptr); }
			// a != b
			bool operator!=(const VectorIterator &ref) const { return (_ptr != ref._ptr); }
			// *a
			value_type &operator*()	{ return (*_ptr); }
			// a->m
			value_type *operator->() { return (_ptr); }
			// *a = t
			// *a++ = t
			// --a
			VectorIterator &operator--() { _ptr--; return (*this); }
			// a--
			VectorIterator operator--(int)
			{
				VectorIterator tmp(*this);
				operator--();
				return (tmp);
			}
			// a + n, n + a
			VectorIterator operator+(int n) const
			{
				VectorIterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			}
			// a - n, a - b
			VectorIterator operator-(int n) const
			{
				VectorIterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			}

			// a < b

			// a > b

			// a <= b

			// a >= b

			// a += n

			// a -= n


	};
};

#endif
