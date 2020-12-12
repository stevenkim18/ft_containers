/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:09:48 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/12 11:28:18 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <limits>
# include "BST.hpp"
# include "MapIterator.hpp"
# include "Pair.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{
		public:
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::Pair<Key, T> 		value_type;
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
			typedef	Bnode<value_type>*		Node;

			BST<ft::Pair<Key, T> >			_bst;
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
			iterator		end() { return (iterator(_bst.find_max())); }
			// rbegin
			// rend
			
			// empty
			bool empty() const { return (_bst.get_size() == 0); }
			// size'
			size_type size() const { return (_bst.get_size()); }
			// max_size
			size_type max_size() const { return (std::numeric_limits<size_type>::max() / (sizeof(Bnode<value_type>))); }
			// operator[]
			mapped_type& operator[] (const key_type& k)
			{
				
			}
			// insert
			std::pair<iterator, bool>		insert(const value_type& val)
			{	
				Node tmp= _bst.search(val);
				// 이미 있는 값이면 
				if (tmp)
					return (std::make_pair(iterator(tmp), false));
				_bst.insert(val);
				return (std::make_pair(iterator(_bst.search(val)), true));
			}
			// erase
			// swap
			// clear
			
			// key_comp
			// value_comp
			
			// find
			// iterator		find(const key_type& k)
			// {
			// 	if (_bst.search(k))
					
			// }
			// count 0 or 1
			// lower_bound
			// upper_bound
			// equal_range
	};
}; // ft

#endif
