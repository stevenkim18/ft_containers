/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:09:48 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/07 03:07:25 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "BST.hpp"
# include "MapIterator.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{
		public:
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef std::pair<const Key, T> value_type;
			typedef Compare					key_compare;
			// value_compare
			typedef Alloc					allocator_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef value_type*				pointer;
			typedef const value_type*		const_pointer;
			typedef ft::MapIterator<Key, T>	iterator;
			// typedef							const_iterator;
			// typedef							reverse_iterator;
			// typedef							const_reverse_iterator;
			typedef	size_t					size_type;

		private:
			BST<std::pair<Key, T> >			_bst;
			allocator_type					_allocator;
			key_compare						_comp;

		public:
			explicit Map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _comp(comp) {}
			// range constructor
			// copy constructor
			~Map() {}
			// operator=
			// begin
			iterator		begin()	{ return (iterator(_bst.find_min())); }
			// end
			// rbegin
			// rend
			
			// empty
			// size
			// max_size

			// operator[]
			
			// insert
			// erase
			// swap
			// clear
			
			// key_comp
			// value_comp
			
			// find
			// count 0 or 1
			// lower_bound
			// upper_bound
			// equal_range
	};
}; // ft

#endif
