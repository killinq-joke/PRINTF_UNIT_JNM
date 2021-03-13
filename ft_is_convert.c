/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:12:59 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 13:42:03 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_convert(char str) /* Return 1 if char is convert, 0 if not */
{
	if ((str == 'c' || str == 'd' || str == 's' || \
		str == 'p' || str == 'i' || \
		str == 'u' || str == 'x' || \
		str == 'X' || str == 'n' || \
		str == 'f' || str == 'g' || \
		str == 'e' || str == '%') && str != '\0')
		return (1);
	return (0);
}
