/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:25:24 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/10 02:41:12 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_get_no_ptr(char *end)
{
	char *str;

	str = ft_substr(end, 2, ft_strlen(end) - 2);
	free (end);
	return (str);
}
char	*ft_get_ptr(char *flags, va_list args, int type)
{
	char *end;
	char *ptr;
	long long int va_arg;
	int a;
	int b;

	a = ft_get_first_value(flags);
	b = ft_get_second_value(flags);
	a < 0 ? a = -a : a;
	b < 0 ? b = -b : b;
	va_arg = va_arg(args, long long int); 
	if ((type == 2 || type == 0) && va_arg == 0)
	{	
		//end = ft_calloc(sizeof(end), ft_strlen(ptr) + 1);
		end = ft_strdup("0");
		return(end);
	}
	if (type == 0)
		ptr = ft_itoa_pointer(va_arg, "0123456789ABCDEF");
	if (type == 1)
		ptr = ft_itoa_pointer(va_arg, "0123456789abcdef");
	if (type == 2)
		ptr = ft_itoa_pointer(va_arg, "0123456789abcdef");
	end = ft_calloc(sizeof(end), (ft_strlen(ptr) + 1 + a + b));
	ft_strcpy(end, ptr);
	free (ptr);
	if (ft_strchr(flags, '#') != NULL || type == 1)
	{
		end = ft_index(end, flags); // TEST FOR FLAGS
		return (end);
	}
	else
	{
		end = ft_get_no_ptr(end);
		return (end);
		//end = ft_index(end, flags); // TEST FOR FLAGS
		return (end);
	}
	return (NULL);
}