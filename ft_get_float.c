/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:28:35 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/07 11:22:59 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_float(char *flags, va_list args)
{
	char *flt;
	double va_arg;

	if (ft_strlen(flags) == 0)
	{
		va_arg = va_arg(args, double);
		flt = ft_putnbr_float((long double) va_arg);
		return (flt);
	}
	return (NULL);
}