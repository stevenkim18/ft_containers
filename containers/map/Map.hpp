/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:09:48 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/04 19:44:29 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>

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
			// typedef 						iterator;
			// typedef							const_iterator;
			// typedef							reverse_iterator;
			// typedef							const_reverse_iterator;
			typedef	size_t					size_type;

		

	};
}; // ft

#endif
