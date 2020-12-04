/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:16:17 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/04 13:40:46 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <iostream>
# include "../vector/Vector.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Queue
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type		_con;

		public:
			explicit Queue (const container_type& ctnr = container_type()) : _con(ctnr) {}
			bool				empty() const { return (_con.empty()); }
			size_type			size() const { return (_con.size()); }
			value_type&			front() { return (_con.front()); }
			const value_type&	front() const { return (_con.front()); }
			value_type&			back() { return (_con.back()); }
			const value_type&	back() const { return (_con.back()); }
			void 				push(const value_type& val) { _con.push_back(val); }
			void				pop() { _con.erase(_con.begin()); }

		private:
			template <class A, class B>
			friend bool	operator==(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
			template <class A, class B>
			friend bool	operator!=(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
			template <class A, class B>
			friend bool	operator<(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
			template <class A, class B>
			friend bool	operator<=(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
			template <class A, class B>
			friend bool	operator>(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
			template <class A, class B>
			friend bool	operator>=(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
	};
	template <class T, class Container>
	bool operator==(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) { return (lhs.c == rhs.c); };
	template <class T, class Container>
	bool operator!=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) { return (lhs.c != rhs.c); };
	template <class T, class Container>
	bool operator>(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) { return (lhs.c > rhs.c); };
	template <class T, class Container>
	bool operator<(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) { return (lhs.c < rhs.c); };
	template <class T, class Container>
	bool operator>=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) { return (lhs.c >= rhs.c); };
	template <class T, class Container>
	bool operator<=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) { return (lhs.c <= rhs.c); };
};

#endif
