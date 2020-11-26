/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:59:43 by seunkim           #+#    #+#             */
/*   Updated: 2020/11/26 17:06:54 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <limits>              // for maxsize()
# include "ListIterator.hpp"
# include "../utils.hpp"

namespace ft
{
    template <class T, class Alloc=std::allocator<T> >
    class List
    {
        public:
            typedef T                           value_type;
            typedef Alloc                       allocator_type;
            typedef T&                          reference;
            typedef const T&                    const_reference;
            typedef T*                          pointer;
            typedef const T*                    const_pointer;
            typedef ft::ListIterator<T>         iterator;
            // typedef ConstListIterator           const_iterator;
            typedef ft::ReverseListIterator<T>  reverse_iterator;
            // typedef ConstReverseListIterator    const_reverse_iterator;
            typedef size_t                      size_type;
        
        private:
            Node<T>*            _first;
            Node<T>*            _last;
            allocator_type      _allocator;
            size_type           _length;
            // 새로운 노드를 할당하기
            Node<T>*            _make_new_node(Node<T> *prev, value_type value, Node<T> *next)
            {
                Node<T>* node = new Node<T>;
                node->prev = prev;
                node->data = value;
                node->next = next;
                return (node);
            }
            void                _init_list()
            {
                _first = _make_new_node(nullptr, value_type(), nullptr);
                _last = _make_new_node(_first, value_type(), nullptr);
                _first->next = _last;
            }
            void                _set_first_last_node()
            {
                if (_length == 0)
                {
                     _first->data = value_type();
                    _last->data = value_type();
                }
                else if (_length == 1)                  // 이해 할 수 없음..
                {
                    _last->data = 1;
                    _first->data = _last->data;        
                }
                else
                {
                    _last->data = _last->prev->data;    // end를 위해서!
                    _first->data = _last->data;         // rend
                }
            }
        
        public:
            explicit List(const allocator_type& alloc = allocator_type())
                : _length(0)
            {
                (void)alloc;
                _init_list();
            }
            // fill constructor
            // range constructor
            // copy constructor
            // destructor
            ~List() { delete _first; delete _last; }
            // operator=
            
            // begin
            iterator begin() { return (iterator(_first->next)); }
            // end
            iterator end() { return (iterator(_last)); }
            // rbegin
            reverse_iterator rbegin() { return (reverse_iterator(_last->prev)); }
            // rend
            reverse_iterator rend() { return (reverse_iterator(_first)); }
            // empty
            // size
            size_type size() const { return (_length); }
            // max_size
            size_type max_size() const { return (std::numeric_limits<size_type>::max() / (sizeof(Node<T>))); }
            // front
            reference front() { return (_first->next->data); }
            // back
            reference back() { return (_last->prev->data); }
            // assign
            // push_front
            void    push_front(const value_type& val)
            {
                Node<T>* new_node = _make_new_node(_first, val, _first->next);
                _first->next->prev = new_node;
                _first->next = new_node;
                _length++;
                _set_first_last_node();
            }
            // pop_front
            void    pop_front()
            {
                Node<T>* after = _first->next->next;
                delete _first->next;
                after->prev = _first;
                _first->next = after;
                _length--;
                 _set_first_last_node();
            }
            // push_back
            void    push_back(const value_type& val)
            {
                Node<T>* new_node = _make_new_node(_last->prev, val, _last);
                _last->prev->next = new_node;
                _last->prev = new_node;
                _length++;
                _set_first_last_node();
            }
            // pop_back
            void    pop_back()
            {
                Node<T>* before = _last->prev->prev;
                delete _last->prev;
                before->next = _last;
                _last->prev = before;
                _length--;
                _set_first_last_node();
            }
            // insert
            // erase
            // swap
            // resize
            // clear
            
            // splice
            // remove
            // remove_if
            // unique
            // merge
            // sort
            // reverse
            
            // ==
            // !=
            // <
            // <=
            // >
            // >=
            // swap
            
    };
};

#endif