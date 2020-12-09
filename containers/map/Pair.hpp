/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:22:29 by seunkim           #+#    #+#             */
/*   Updated: 2020/12/10 01:30:00 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{
    template<class K, class V>
    struct Pair
    {
        public:
            K       _key;
            V       _value;
            
            Pair() {}
            Pair(K key, V value) : _key(key), _value(value) {}
            
            bool operator<(Pair& ref) { return (_key < ref._key); }
            bool operator<=(Pair& ref) { return (_key <=ref._key); }
            bool operator>(Pair& ref) { return (_key > ref._key); }
            bool operator>=(Pair& ref) { return (_key >= ref._key); }
            bool operator==(Pair& ref) { return (_key == ref._key); }
            bool operator!=(Pair& ref) { return (_key != ref._key); }
            // K&  getKey()  { return (_key); }
            // V&  getValue()  { return (_value); }
    };
}; // namespace ft

#endif