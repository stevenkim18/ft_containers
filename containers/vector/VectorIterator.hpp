/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:30:12 by seunkim           #+#    #+#             */
/*   Updated: 2020/11/24 00:57:37 by seunkim          ###   ########.fr       */
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
			VectorIterator() {}
			VectorIterator(pointer ptr) : _ptr(ptr) {}
			VectorIterator(const VectorIterator &ref) { *this = ref; }
			VectorIterator& operator=(const VectorIterator &ref) { _ptr = ref._ptr; return (*this); }
			~VectorIterator() {}

			VectorIterator 	&operator++() { _ptr++; return (*this); }
			VectorIterator 	operator++(int){ VectorIterator tmp(*this); operator++(); return (tmp); }
			bool 			operator==(const VectorIterator &ref) const { return (_ptr == ref._ptr); }
			bool 			operator!=(const VectorIterator &ref) const { return (_ptr != ref._ptr); }
			value_type 		&operator*() { return (*_ptr); }
			value_type 		*operator->() { return (_ptr); }
			VectorIterator 	&operator--() { _ptr--; return (*this); }
			VectorIterator 	operator--(int) { VectorIterator tmp(*this); operator--(); return (tmp); }
			VectorIterator 	operator+(int n) const { VectorIterator tmp(*this); tmp._ptr += n; return (tmp); }
			VectorIterator 	operator-(int n) const { VectorIterator tmp(*this); tmp._ptr -= n; return (tmp); }
			bool 			operator<(const VectorIterator &ref) const { return (_ptr < ref._ptr); }
			bool 			operator>(const VectorIterator &ref) const { return (_ptr > ref._ptr); }
			bool 			operator<=(const VectorIterator &ref) const { return (_ptr <= ref._ptr); }
			bool 			operator>=(const VectorIterator &ref) const { return (_ptr >= ref._ptr); }
			VectorIterator	&operator+=(int n) { _ptr += n; return (*this); }
			VectorIterator 	&operator-=(int n) { _ptr -= n; return (*this); }
			value_type 		&operator[] (int n) { return (*(*this + n)); }
	};
	template<typename T>
	class ReverseVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T	value_type;
			typedef T&	references;
			typedef T*	pointer;

			ReverseVectorIterator() {}
			ReverseVectorIterator(pointer ptr) { this->_ptr = ptr; }
			ReverseVectorIterator(const ReverseVectorIterator &ref) { *this = ref; }
			ReverseVectorIterator &operator=(const ReverseVectorIterator &ref) { this->_ptr = ref._ptr; return (*this); }
			~ReverseVectorIterator() {}

			ReverseVectorIterator 	&operator++(void) { this->_ptr--; return (*this); }
			ReverseVectorIterator 	operator++(int) { ReverseVectorIterator tmp(*this); this->_ptr--; return (tmp); }
			ReverseVectorIterator 	operator+(int n) const { ReverseVectorIterator tmp(*this); tmp._ptr -= n; return (tmp); }
			ReverseVectorIterator 	operator-(int n) const { ReverseVectorIterator tmp(*this); tmp._ptr += n; return (tmp); }
			ReverseVectorIterator 	&operator--(void) { this->_ptr++; return (*this); }
			ReverseVectorIterator 	operator--(int) { ReverseVectorIterator tmp(*this); this->_ptr++; return (tmp); }
			ReverseVectorIterator 	&operator+=(int n) { this->_ptr -= n; return (*this); }
			ReverseVectorIterator 	&operator-=(int n) { this->_ptr += n; return (*this);}
			bool 					operator<(const ReverseVectorIterator &ref) const { return (this->_ptr > ref._ptr); }
			bool 					operator>(const ReverseVectorIterator &ref) const { return (this->_ptr < ref._ptr); }
			bool 					operator<=(const ReverseVectorIterator &ref) const { return (this->_ptr >= ref._ptr); }
			bool 					operator>=(const ReverseVectorIterator &ref) const { return (this->_ptr <= ref._ptr); }
			value_type 				&operator[](int n) const { return (*(*this + n)); }
	};
	template<typename T>
	class ConstVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T 	value_type;
			typedef T& 	reference;
			typedef T*	pointer;

			ConstVectorIterator() {}
			ConstVectorIterator(pointer ptr) { this->_ptr = ptr; }
			ConstVectorIterator(const ConstVectorIterator &ref) { *this = ref; }
			ConstVectorIterator &operator=(const ConstVectorIterator &ref) { this->_ptr = ref._ptr; return (*this); }
			~ConstVectorIterator(){}

			const value_type &operator*() { return (*this->_ptr); }
			const value_type &operator[](int n) const { return (*(*this + n));}
	};
	template<typename T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			ConstReverseVectorIterator() {}
			ConstReverseVectorIterator(pointer ptr) { this->_ptr = ptr; }
			ConstReverseVectorIterator(const ConstReverseVectorIterator &ref) { *this = ref; }
			ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &ref) { this->_ptr = ref._ptr; return (*this); }
			~ConstReverseVectorIterator() {}

			const value_type &operator*(void) { return (*this->_ptr); }
			const value_type &operator[](int n) const { return (*(*this - n)); }
	};
};

#endif
