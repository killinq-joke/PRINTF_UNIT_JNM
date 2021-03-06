/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:25:24 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 23:42:07 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_ptr(char *flags, va_list args, int type)
{
	char *end;
	char *ptr;
	long long int va_arg;
	
	if (ft_strlen(flags) == 0)
	{
		va_arg = va_arg(args, long long int);
		if (type == 0) /* ABCDEF */
			ptr = ft_itoa_pointer(va_arg, "0123456789ABCDEF");
		if (type == 1) /* abcdef */
			ptr = ft_itoa_pointer(va_arg, "0123456789abcdef");
		if (type == 2) /* 0xABCDEF */
			ptr = ft_itoa_pointer(va_arg, "0123456789ABCDEF");
		end = ft_calloc(sizeof(end), ft_strlen(ptr));
		ft_strcpy(end, ptr);
		free (ptr);
		return (end);
	}
	return (NULL);
}