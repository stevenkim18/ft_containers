/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:30:12 by seunkim           #+#    #+#             */
/*   Updated: 2020/11/22 22:46:06 by seunkim          ###   ########.fr       */
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
			bool operator<(const VectorIterator &ref) const { return (_ptr < ref._ptr); }
			// a > b
			bool operator>(const VectorIterator &ref) const { return (_ptr > ref._ptr); }
			// a <= b
			bool operator<=(const VectorIterator &ref) const { return (_ptr <= ref._ptr); }
			// a >= b
			bool operator>=(const VectorIterator &ref) const { return (_ptr >= ref._ptr); }
			// a += n
			VectorIterator &operator+=(int n)
			{
				_ptr += n;
				return (*this);
			}
			// a -= n
			VectorIterator &operator-=(int n)
			{
				_ptr -= n;
				return (*this);
			}
			// []
			value_type &operator[] (int n) { return (*(*this + n)); }
	};
	template<typename T>
	class ReverseVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T	value_type;
			typedef T&	references;
			typedef T*	pointer;

			ReverseVectorIterator() {};
			ReverseVectorIterator(pointer ptr) { this->_ptr = ptr; }
			ReverseVectorIterator(const ReverseVectorIterator &ref) { *this = ref; }
			ReverseVectorIterator operator+(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			}
			ReverseVectorIterator operator-(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			}
			ReverseVectorIterator &operator=(const ReverseVectorIterator &ref)
			{
				this->_ptr = ref._ptr;
				return (*this);
			}
			ReverseVectorIterator &operator++(void)
			{
				this->_ptr--;
				return (*this);
			};
			ReverseVectorIterator operator++(int)
			{
				ReverseVectorIterator tmp(*this);
				this->_ptr--;
				return (tmp);
			};
			ReverseVectorIterator &operator--(void)
			{
				this->_ptr++;
				return (*this);
			};
			ReverseVectorIterator operator--(int)
			{
				ReverseVectorIterator tmp(*this);
				this->_ptr++;
				return (tmp);
			};
			ReverseVectorIterator &operator+=(int n)
			{
				this->_ptr -= n;
				return (*this);
			}
			ReverseVectorIterator &operator-=(int n)
			{
				this->_ptr += n;
				return (*this);
			}
			// a < b
			bool operator<(const ReverseVectorIterator &ref) const { return (this->_ptr > ref._ptr); }
			// a > b
			bool operator>(const ReverseVectorIterator &ref) const { return (this->_ptr < ref._ptr); }
			// a <= b
			bool operator<=(const ReverseVectorIterator &ref) const { return (this->_ptr >= ref._ptr); }
			// a >= b
			bool operator>=(const ReverseVectorIterator &ref) const { return (this->_ptr <= ref._ptr); }
			// 여기 이상함
			value_type &operator[](int n) const { return (*(*this + n)); }
	};
};

#endif
