/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 02:34:18 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/07 02:50:36 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include <iostream>
# include "BST.hpp"

namespace ft
{
    template <class Key, class T>
    class MapIterator
    {
        public:
            typedef std::pair<Key, T>           value_type;
            typedef std::pair<Key, T>&          reference;
            typedef Bnode<std::pair<Key, T> >*  pointer;
        
        protected:
            pointer _ptr;
        
        public:
            MapIterator() : _ptr(nullptr) {}
            MapIterator(pointer ptr) : _ptr(ptr) {}
            MapIterator(const MapIterator &ref) { *this = ref; }
            MapIterator &operator=(const MapIterator &ref) { _ptr = ref._ptr; return (*this); }
            ~MapIterator() {}
            value_type  &operator*() { return (_ptr->data); }
            value_type  *operator->() { return (&_ptr->data); }
            
    };
};  // ft

#endif
