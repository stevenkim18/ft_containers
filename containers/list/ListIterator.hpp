/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:47:24 by seunkim           #+#    #+#             */
/*   Updated: 2020/11/27 15:28:53 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include "../utils.hpp"

namespace ft
{
    template <typename T>
    class ListIterator
    {
        public:
            typedef T           value_type;
            typedef Node<T>*    pointer;
            typedef T&          reference;

        protected:
            pointer             _ptr;

        public:
            ListIterator() {}
            ListIterator(pointer ptr) : _ptr(ptr) {}
            ListIterator(const ListIterator &ref) { *this = ref; }
            ListIterator &operator=(const ListIterator &ref) { _ptr = ref._ptr; return (*this); }
            ~ListIterator() {}

            pointer getNode() const { return (_ptr); }      // for insert
            
            // ==
            bool operator==(const ListIterator &ref) const { return (_ptr == ref._ptr); } 
            // !=
            bool operator!=(const ListIterator &ref) const { return (_ptr != ref._ptr); }
            // * 
            value_type &operator*() { return (_ptr->data); };
            // ->
            // ++
            ListIterator &operator++() { _ptr = _ptr->next; return (*this); }                       // ++a
            ListIterator operator++(int) { ListIterator tmp(*this); operator++(); return (tmp); }   // a++
            // --
            ListIterator &operator--() { _ptr = _ptr->prev; return (*this); }                       // --a
            ListIterator operator--(int) { ListIterator tmp(*this); operator--(); return (tmp); }   // a--
        
    };
    template <typename T>
    class ReverseListIterator
    {
         public:
            typedef T           value_type;
            typedef Node<T>*    pointer;
            typedef T&          reference;

        protected:
            pointer             _ptr;

        public:
            ReverseListIterator() {}
            ReverseListIterator(pointer ptr) : _ptr(ptr) {}
            ReverseListIterator(const ReverseListIterator &ref) { *this = ref; } 
            ReverseListIterator &operator=(const ReverseListIterator &ref) { _ptr = ref._ptr; return (*this); }
            ~ReverseListIterator() {}

            // ==
            bool operator==(const ReverseListIterator &ref) const { return (_ptr == ref._ptr); } 
            // !=
            bool operator!=(const ReverseListIterator &ref) const { return (_ptr != ref._ptr); }
            // * 
            value_type &operator*() { return (_ptr->data); };
            // ->
            // ++
            ReverseListIterator &operator++() { _ptr = _ptr->next; return (*this); }    // ++a
            // --
            
    };
};

#endif