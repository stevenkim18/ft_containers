/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:20:20 by seunkim           #+#    #+#             */
/*   Updated: 2020/11/25 14:33:22 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	template <typename T>
	void		swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
	template <typename T>
	struct 		Node
	{
		Node	*prev;
		T		data;
		Node	*next;
	};
};

#endif
