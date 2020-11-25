/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:59:43 by seunkim           #+#    #+#             */
/*   Updated: 2020/11/26 00:08:21 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
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
            // typedef ReverseListIterator         reverse_iterator;
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
        
        public:
            explicit List(const allocator_type& alloc = allocator_type())
                : _length(0)
            {
                (void)alloc;
                _last = _make_new_node(nullptr, value_type(), nullptr);
                _last->prev = _last;
                _first = _last;
            }
            // fill constructor
            // range constructor
            // copy constructor
            // destructor
            // operator=
            
            // begin
            iterator begin() { return (iterator(_first)); }
            // end
            iterator end() { return (iterator(_last->prev)); }
            // rbegin
            // rend
            
            // empty
            // size
            size_type size() const { return (_length); }
            // max_size

            // front
            reference front() { return (_first->data); }
            // back
            reference back() { return (_last->prev->data); }
            // assign
            // push_front
            // pop_front
            // push_back
            void    push_back(const value_type& val)
            {
                Node<T>* new_node = _make_new_node(_last->prev, val, _last);
                _last->prev->next = new_node;
                _last->prev = new_node;
                if (_length == 0)               // 맨 처음 노드의 prev는 nullptr이어야 함.
                {
                    _first = new_node;
                    new_node->prev = nullptr;
                }
                _length++;
            }
            // pop_back
            void    pop_back()
            {
                Node<T>* before = _last->prev->prev;
                delete _last->prev;
                if (before == nullptr)  // 지운 후에 List에 원소가 한개도 없을 때
                {
                    before = _last;
                    _first = _last;
                }
                before->next = _last;
                _last->prev = before;
                _length--;
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