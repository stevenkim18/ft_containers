/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:09:48 by seunkim           #+#    #+#             */
/*   Updated: 2021/02/05 22:53:10 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <limits>
# include "BST.hpp"
# include "MapIterator.hpp"
# include "Pair.hpp"
# include "../utils.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::Pair<Key, T> 				value_type;
			typedef Compare							key_compare;
			typedef Alloc							allocator_type;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;
			typedef ft::MapIterator<Key, T>			iterator;
			typedef	ft::ConstMapIterator<Key, T>	const_iterator;
			typedef ft::ReverseMapIterator<Key, T>	reverse_iterator;
			typedef	ft::ConstReverseMapIterator<Key, T>	const_reverse_iterator;
			typedef	size_t							size_type;
			class value_compare
			{
				friend class Map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x._key, y._key);
					};
			};

		private:
			typedef	Bnode<value_type>*		Node;

			BST<ft::Pair<Key, T> >			_bst;
			allocator_type					_allocator;
			key_compare						_comp;
			// value_compare					_value_compare;

		public:
			explicit Map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _comp(comp)  {}
			template <class InputIterator>
			Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _comp(comp) 
			{
				insert(first, last);
			}
			Map (Map& x)
			{
				*this = x;
			}
			~Map() {}
			// operator=
			Map &operator= (Map &ref)
			{
				clear();
				insert(ref.begin(), ref.end());
				return (*this);
			}
			// begin
			iterator		begin()	{ return (iterator(_bst.find_min())); }
			const_iterator	begin() const { return (const_iterator(_bst.find_min())); }
			// end
			iterator		end() { return (iterator(_bst.find_max())); }
			const_iterator	end() const { return (const_iterator(_bst.find_max())); }
			// rbegin
			reverse_iterator        rbegin() { return (--reverse_iterator(_bst.find_max())); }
			const_reverse_iterator  rbegin() const { return (--reverse_iterator(_bst.find_max())); }
			// rend
			reverse_iterator		rend() { return (reverse_iterator(_bst.find_min())); }
			const_reverse_iterator	rend() const { return (--reverse_iterator(_bst.find_min())); }
			
			// empty
			bool empty() const { return (_bst.get_size() == 0); }
			// size'
			size_type size() const { return (_bst.get_size()); }
			// max_size
			size_type max_size() const { return (std::numeric_limits<size_type>::max() / (sizeof(Bnode<value_type>))); }
			// operator[]
			mapped_type& operator[] (const key_type& k)
			{
				Node tmp = _bst.search(k);
				if (tmp)
					return(tmp->data._value);
				else
				{
					value_type new_pair = ft::Pair<Key, T>(k, mapped_type());
					_bst.insert(new_pair);
					return (_bst.search(k)->data._value);
				}
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
			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				Node tmp = _bst.search(val);
				if (tmp)
					return (iterator(tmp));
				_bst.insert(val);
				return (iterator(_bst.search(val)));
			}
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}
			// erase
			void 	   erase(iterator position)
			{
				_bst.remove(*position);
			}
			size_type 	erase(const key_type& k)
			{
				Node tmp = _bst.search(k);
				// std::cout << tmp->data._value << std::endl;
				if (tmp)
				{
					// std::cout << "11k = " << tmp->data._key << " v = " << tmp->data._value << std::endl;
					_bst.remove(tmp->data);
					return (1);
				}
				else
					return (0);
			}
			void		erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
			}
			// swap
			void		swap(Map &x)
			{
				Map<Key, T> tmp;
				tmp.insert(begin(), end());
				
				// std::cout << "tmp";
				// tmp.print_all();

				clear();
				insert(x.begin(), x.end());
				// print_all();
				
				x.clear();
				x.insert(tmp.begin(), tmp.end());
				// std::cout << "x";
				// x.print_all();
			}
			// clear
			void		clear()
			{
				_bst.remove_all();
			}
			
			// key_comp
			key_compare		key_comp() const { return (_comp); }
			// value_comp
			value_compare	value_comp() const { return (value_compare(_comp)); }
			
			// find
			iterator		find(const key_type& k)
			{
				if (empty())
					return (end());
				Node tmp = _bst.search(k);
				if (tmp)
					return (iterator(tmp));
				return (end());
			}

			const_iterator	find(const key_type& k) const
			{
				if (empty())
					return (end());
				Node tmp = _bst.search(k);
				if (tmp)
					return (const_iterator(tmp));
				return (end());
			}

			// count 0 or 1
			size_type count(const key_type& k)
			{
				if (find(k) != end())
					return (1);
				else
					return (0);
					
			}
			// lower_bound
			iterator		lower_bound(const key_type& k)
			{
				iterator it = begin();
				for (; it != end(); it++)
				{
					if (k <= it->_key)
						break;
				}
				return (it);
			}

			const_iterator	lower_bound(const key_type& k) const
			{
				const_iterator it = begin();
				for (; it != end(); it++)
				{
					if (k <= it->_key)
						break;
				}
				return (it);
			}
			// upper_bound
			iterator		upper_bound(const key_type& k)
			{
				iterator it = begin();
				for (;it != end(); it++)
				{
					if (k < it->_key)
						break;
				}
				return (it);
			}
			const_iterator	upper_bound(const key_type& k) const
			{
				const_iterator it = begin();
				for (; it != end(); it++)
				{
					if (k < it->_key)
						break;
				}
				return (it);
			}
			// equal_range
			ft::Pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			{
				return (ft::Pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}

			ft::Pair<iterator, iterator>	equal_range(const key_type& k)
			{
				return (ft::Pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}

			void		print_all()
			{
				_bst.print_in_order();
			}
	};
}; // ft

#endif
