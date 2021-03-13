/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:28:35 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/09 13:05:38 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_float(char *flags, va_list args)
{
	char		*flt;
	double		va_arg;

	if (ft_strlen(flags) == 0)
	{
		va_arg = va_arg(args, double);
		flt = ft_putnbr_float(va_arg);
		flt = ft_index(flt, flags); // TEST FOR FLAGS
		return (flt);
	}
	return (NULL);
}
