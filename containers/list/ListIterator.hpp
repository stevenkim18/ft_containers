/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:47:24 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/01 02:12:43 by seunkim          ###   ########.fr       */
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
            
            bool operator==(const ListIterator &ref) const { return (_ptr == ref._ptr); }           // ==
            bool operator!=(const ListIterator &ref) const { return (_ptr != ref._ptr); }           // !=
            value_type &operator*() { return (_ptr->data); };                                       // *
            value_type operator->() { return (_ptr); }                                              // ->
            ListIterator &operator++() { _ptr = _ptr->next; return (*this); }                       // ++a
            ListIterator operator++(int) { ListIterator tmp(*this); operator++(); return (tmp); }   // a++
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

            bool                operator==(const ReverseListIterator &ref) const { return (_ptr == ref._ptr); } 
            bool                operator!=(const ReverseListIterator &ref) const { return (_ptr != ref._ptr); }
            value_type          &operator*() { return (_ptr->data); };
            value_type          operator->() { return (_ptr); }
            ReverseListIterator &operator++() { _ptr = _ptr->prev; return (*this); }    
            ReverseListIterator operator++(int) { ReverseListIterator tmp(*this); operator++(); return (tmp); }
            ReverseListIterator &operator--() { _ptr = _ptr->next; return (*this); }    
            ReverseListIterator operator--(int) { ReverseListIterator tmp(*this); operator--(); return (tmp); }
            
    };
    template <typename T>
    class ConstListIterator
    {
        public:
            typedef T           value_type;
            typedef Node<T>*    pointer;
            typedef T&          reference;

        protected:
            pointer             _ptr;

        public:
            ConstListIterator() {}
            ConstListIterator(pointer ptr) : _ptr(ptr) {}
            ConstListIterator(const ConstListIterator &ref) { *this = ref; }
            ConstListIterator &operator=(const ConstListIterator &ref) { _ptr = ref._ptr; return (*this); }
            ~ConstListIterator() {}

            pointer getNode() const { return (_ptr); }      // for insert
            
            bool                operator==(const ConstListIterator &ref) const { return (_ptr == ref._ptr); }    
            bool                operator!=(const ConstListIterator &ref) const { return (_ptr != ref._ptr); }          
            const value_type    &operator*() { return (_ptr->data); };                                        
            const value_type    operator->() { return (_ptr); }                                             
            ConstListIterator   &operator++() { _ptr = _ptr->next; return (*this); }                       
            ConstListIterator   operator++(int) { ConstListIterator tmp(*this); operator++(); return (tmp); }   
            ConstListIterator   &operator--() { _ptr = _ptr->prev; return (*this); }                      
            ConstListIterator   operator--(int) { ConstListIterator tmp(*this); operator--(); return (tmp); }   
    };
    template <typename T>
    class ConstReverseListIterator
    {
        public:
            typedef T           value_type;
            typedef Node<T>*    pointer;
            typedef T&          reference;

        protected:
            pointer             _ptr;

        public:
            ConstReverseListIterator() {}
            ConstReverseListIterator(pointer ptr) : _ptr(ptr) {}
            ConstReverseListIterator(const ConstReverseListIterator &ref) { *this = ref; }
            ConstReverseListIterator &operator=(const ConstReverseListIterator &ref) { _ptr = ref._ptr; return (*this); }
            ~ConstReverseListIterator() {}

            pointer getNode() const { return (_ptr); }      
            
            bool                operator==(const ConstReverseListIterator &ref) const { return (_ptr == ref._ptr); }    
            bool                operator!=(const ConstReverseListIterator &ref) const { return (_ptr != ref._ptr); }          
            const value_type    &operator*() { return (_ptr->data); };                                        
            const value_type    operator->() { return (_ptr); }                                             
            ConstReverseListIterator   &operator++() { _ptr = _ptr->prev; return (*this); }                       
            ConstReverseListIterator   operator++(int) { ConstReverseListIterator tmp(*this); operator++(); return (tmp); }   
            ConstReverseListIterator   &operator--() { _ptr = _ptr->next; return (*this); }                      
            ConstReverseListIterator   operator--(int) { ConstReverseListIterator tmp(*this); operator--(); return (tmp); }   
    };
};

#endif