/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:13:17 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/04 11:50:47 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include "../vector/Vector.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type		_con;

		public:
			explicit Stack (const container_type& ctnr = container_type()) : _con(ctnr) {}
			bool				empty() const { return (_con.empty()); }
			size_type			size() const { return (_con.size()); }
			value_type			top() { return (_con.back()); }
			const value_type 	top() const { return (_con.back()); }
			void 				push(const value_type& val) { _con.push_back(val); }
			void				pop() {	_con.pop_back(); }

		private:
			template <class A, class B>
			friend bool	operator==(const Stack<A, B> &lhs, const Stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator!=(const Stack<A, B> &lhs, const Stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator<(const Stack<A, B> &lhs, const Stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator<=(const Stack<A, B> &lhs, const Stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator>(const Stack<A, B> &lhs, const Stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator>=(const Stack<A, B> &lhs, const Stack<A, B> &rhs);
	};
	template <class T, class Container>
	bool operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) { return (lhs.c == rhs.c); };
	template <class T, class Container>
	bool operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) { return (lhs.c != rhs.c); };
	template <class T, class Container>
	bool operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) { return (lhs.c > rhs.c); };
	template <class T, class Container>
	bool operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) { return (lhs.c < rhs.c); };
	template <class T, class Container>
	bool operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) { return (lhs.c >= rhs.c); };
	template <class T, class Container>
	bool operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) { return (lhs.c <= rhs.c); };
}; // namespace ft

#endif
