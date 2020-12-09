/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 02:34:18 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/10 02:23:59 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include <iostream>
# include "BST.hpp"
# include "Pair.hpp"

namespace ft
{
    template <class Key, class T>
    class MapIterator
    {
        public:
            typedef ft::Pair<Key, T>           value_type;
            typedef ft::Pair<Key, T>&          reference;
            typedef Bnode<ft::Pair<Key, T> >*  pointer;
        
        protected:
            pointer                 _ptr;

        private:
	    	pointer	find_min_node(pointer node)
	    	{
	    		if (node == nullptr)
	    			return (nullptr);
	    		else if (node->left == nullptr)
	    			return (node);
	    		else
	    			return (find_min_node(node->left));
	    	}
	    	pointer	find_max_node(pointer node)
	    	{
	    		if (node == nullptr)
	    			return (nullptr);
	    		else if (node->right == nullptr)
	    			return (node);
	    		else
	    			return find_max_node(node->right);
	    	}
	    	pointer	successor_node(pointer node)
	    	{	
	    		if (node->right != nullptr)
	    			return find_min_node(node->right);
	    		else
	    		{
	    			pointer	parent = node->parent;
	    			pointer	current = node;
    
    				while ((parent != nullptr) && (current == parent->right))
    				{
    					current = parent;
    					parent = current->parent;
    				}
    				return (parent);
    			}
    		}
    		pointer	predecessor_node(pointer node)
    		{
    			if (node->left != nullptr)
    				return (find_max_node(node->left));
    			else
    			{
    				pointer	parent = node->parent;
    				pointer	current = node;
    
    				while ((parent != nullptr) && (current == parent->left))
    				{
    					current = parent;
    					parent = current->parent;
    				}
    				return (parent);
    			}
    		}
            
        public:
            MapIterator() : _ptr(nullptr) {}
            MapIterator(pointer ptr) : _ptr(ptr) {}
            MapIterator(const MapIterator &ref) { *this = ref; }
            MapIterator &operator=(const MapIterator &ref) { _ptr = ref._ptr; return (*this); }
            ~MapIterator() {}
            value_type  &operator*() { return (_ptr->data); }
            value_type  *operator->() { return (&_ptr->data); }
            MapIterator &operator++() { _ptr = successor_node(_ptr); return (*this); }
            bool        operator==(const MapIterator<Key, T> &ref) 
            {
                return (_ptr->data == ref._ptr->data);
            }
            bool        operator!=(const MapIterator<Key, T> &ref) 
            {
                return (_ptr->data != ref._ptr->data);
            }
    };
};  // ft

#endif
