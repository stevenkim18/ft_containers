/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:59:43 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/01 02:36:03 by seunkim          ###   ########.fr       */
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
            typedef T                               value_type;
            typedef Alloc                           allocator_type;
            typedef T&                              reference;
            typedef const T&                        const_reference;
            typedef T*                              pointer;
            typedef const T*                        const_pointer;
            typedef ft::ListIterator<T>             iterator;
            typedef ft::ConstListIterator<T>        const_iterator;
            typedef ft::ReverseListIterator<T>      reverse_iterator;
            typedef ft::ConstReverseListIterator<T> const_reverse_iterator;
            typedef size_t                          size_type;
        
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
            template <typename N>                       // for unique void
            bool                _eqaul(const N& a, const N& b)  { return (a == b); }
            
        public:
            explicit List(const allocator_type& alloc = allocator_type())
                : _length(0)
            {
                (void)alloc;
                _init_list();
            }
            // fill constructor
            explicit List(size_type n, const value_type& val, const allocator_type& alloc = allocator_type())
                : _length(0)
            {
                (void)alloc;
                _init_list();
                assign(n, val);
            }
            // range constructor
            template <class InputIterator>
            List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
                : _length(0)
            {
                (void)alloc;
                _init_list();
                assign(first, last);
            }
            // copy constructor
            List (const List& x)
                : _length(0)
            {
                _init_list();
                assign(x.begin(), x.end());
                _length = x._length;
            }
            // destructor
            ~List() { clear(); delete _first; delete _last; }
            // operator=
            List &operator=(const List &x)
            {
                clear();
                assign(x.begin(), x.end());
                _length = x._length;
                return (*this);
            }
            // begin
            iterator                begin() { return (iterator(_first->next)); }
            const_iterator          begin() const { return (const_iterator(_first->next)); }
            // end
            iterator                end() { return (iterator(_last)); }
            const_iterator          end() const { return (const_iterator(_last)); }
            // rbegin
            reverse_iterator        rbegin() { return (reverse_iterator(_last->prev)); }
            const_reverse_iterator  rbegin() const { return (const_reverse_iterator(_last->prev)); }
            // rend
            reverse_iterator        rend() { return (reverse_iterator(_first)); }
            const_reverse_iterator  rend() const { return (const_reverse_iterator(_first)); }
            // empty
            bool                    empty() const { return (_length == 0); }
            // size
            size_type               size() const { return (_length); }
            // max_size
            size_type               max_size() const { return (std::numeric_limits<size_type>::max() / (sizeof(Node<T>))); }
            // front
            reference               front() { return (_first->next->data); }
            const_reference         front() const { return (_first->next->data); }
            // back
            reference               back() { return (_last->prev->data); }
            const_reference         back() const { return (_last->prev->data); }
            // assign
            template <class InputIterator>
            void    assign(InputIterator first, InputIterator last)
            {
                clear();
                while (first != last)
                {
                    push_back(*first);
                    first++;
                }
            }
            void    assign(size_type n, const value_type& val)
            {
                clear();
                while (n--)
                    push_back(val);
            }
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
            iterator    insert(iterator position, const value_type& val)
            {
                if (position == begin())
                {
                    push_front(val);
                    return (begin());
                }
                else if (position == end())
                {
                    push_back(val);
                    return (end());
                }
                Node<T>* after = position.getNode();
                Node<T>* before = after->prev;
                Node<T>* inserted_node = _make_new_node(before, val, after);
                before->next = inserted_node;
                after->prev = inserted_node;
                _length++;
                return (iterator(inserted_node));
            }
            void        insert(iterator position, size_type n, const value_type& val)
            {
                while (n--)
                    position = insert(position, val);
            }
            template <class InputIterator>
            void        insert(iterator position, InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    position = insert(position, *first);
                    first++;
                    if (position != end())
                        ++position;
                }
            }
            // erase
            iterator    erase(iterator position)
            {
                if (position == begin())
                {
                    pop_front();
                    return (begin());
                }
                else if (position == end())
                {
                    pop_back();
                    return (end());
                }
                Node<T>* before = position.getNode()->prev;
                Node<T>* after = position.getNode()->next;
                delete position.getNode();
                before->next = after;
                after->prev = before;
                _length--;
                _set_first_last_node();             // 안해주면 insert(begin, end) 했을 떄 이상 한 값 나옴
                return (iterator(after));
            }
            iterator    erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    erase(first);
                    first++;
                }
                return (first);
            }
            // swap
            void        swap(List &x)
            {
                ft::swap(x._length, _length);
                ft::swap(x._first, _first);
                ft::swap(x._last, _last);
            }
            // resize
            void        resize(size_type n, value_type val = value_type())
            {
                while (_length > n)
                    pop_back();
                while (_length < n)
                    push_back(val);
            }
            // clear
            void        clear()
            {
                Node<T>* node = _first->next;
                while (node != _last)
                {
                    Node<T>* next = node->next;
                    delete node;
                    node = next;
                }
                _first->next = _last;
                _last->prev = _first;
                _length = 0;
                _set_first_last_node();
            }
            
            // splice
            void        splice(iterator position, List& x)
            {
                splice(position, x, x.begin(), x.end());
            }
            void        splice(iterator position, List& x, iterator i)
            {
                insert(position, *i);
                x.erase(i);
            }
            void        splice(iterator position, List& x, iterator first, iterator last)
            {
                insert(position, first, last);
                x.erase(first, last);
            }
            // remove
            void remove(const value_type& val)
            {
                iterator iter = begin();
                while (iter != end())
                {
                    if (*iter == val)
                        iter = erase(iter);
                    else
                        iter++;
                }
            }
            // remove_if
            template <class Predicate>
            void        remove_if (Predicate pred)
            {
                iterator iter = begin();
                while (iter != end())
                {
                    if (pred(*iter))
                        iter = erase(iter);
                    else 
                        iter++;
                }
            }
            // unique
            void        unique()
            {
                unique(this->_eqaul);
            }
            template <class BinaryPredicate>
            void        unique(BinaryPredicate binary_pred)
            {
                iterator iter = begin();
                iterator next_iter = ++begin();
                while (iter != --end())
                {
                    if (binary_pred(*iter, *next_iter))
                        next_iter = erase(next_iter);
                    else
                    {
                        iter = next_iter;
                        next_iter++;
                    }
                }
            }
            // merge
            void        merge(List& x)
            {
                if (&x == this)
                    return ;
                insert(begin(), x.begin(), x.end());
                x.clear();
                sort();
            }
            template <class Compare>
            void        merge(List& x, Compare comp)
            {
                if (&x == this)
                    return ;
                insert(end(), x.begin(), x.end());
                x.clear();
                sort(comp);
            }
            // sort
            void        sort()
            {
                for (iterator it = begin(); it != --end(); it++)
                {
                    for (iterator next_it = it; next_it != end(); next_it++)
                    {
                        if (*it > *next_it)
                            ft::swap(*it, *next_it);
                    }
                }
            }
            template <class Compare>
            void        sort(Compare comp)
            {
                for (iterator it = begin(); it != --end(); it++)
                {
                    for (iterator next_it = it; next_it != end(); next_it++)
                    {
                        if (!comp(*it, *next_it))
                            ft::swap(*it, *next_it);
                    }
                }
            }
            // reverse
            void        reverse()
            {
                size_type i = 0;
                iterator first = begin();
                iterator last = --end();
                while (i != _length / 2)
                {
                    ft::swap(*first, *last);
                    first++;
                    last--;
                    i++;
                }
            }
    };
    // ==
    template <typename T>
    bool operator==(List<T>& lhs, List<T>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename List<T>::iterator l_iter = lhs.begin();
        typename List<T>::iterator r_iter = rhs.begin();
        while (l_iter != lhs.end())
        {
            if (*l_iter != *r_iter)
                return (false);
            l_iter++;
            r_iter++;
        }
        return (true);
    };
    // !=
    template <typename T>
    bool operator!=(List<T>& lhs, List<T>& rhs) { return (!(lhs == rhs)); }
    // <
    template <typename T>
    bool operator<(List<T>& lhs, List<T>& rhs)
    {
        if (lhs.size() < rhs.size())
            return (true);
        if (lhs.size() > rhs.size())
            return (false);
        typename List<T>::iterator l_iter = lhs.begin();
        typename List<T>::iterator r_iter = rhs.begin();
        while (l_iter != lhs.end())
        {
            if (*l_iter != *r_iter)
                return (*l_iter < *r_iter);
            l_iter++;
            r_iter++;
        }
        return (false);
    }
    // <=
    template <typename T>
    bool operator<=(List<T> &lhs, List<T> &rhs) { return (!(rhs < lhs)); }
    // >
    template <typename T>
    bool operator>(List<T> &lhs, List<T> &rhs) { return (rhs < lhs); }
    // >=
    template <typename T>
    bool operator>=(List<T> &lhs, List<T> &rhs) { return (!(lhs < rhs)); }
    // swap
    template <typename T>
    void swap(List<T> &x, List<T> &y) { x.swap(y); }    
};

#endif