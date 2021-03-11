/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:44:01 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/11 06:01:29 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_u(char *flags, va_list args)
{
	char *flt;
	unsigned long int va_arg;

	(void)flags;
	va_arg = va_arg(args, unsigned long int);
	flt = ft_itoa_unsigned(va_arg);
	return (flt);
}