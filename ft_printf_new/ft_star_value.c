/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:24:06 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 16:02:17 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_malloc(char *str, va_list args)
{
	int i;
	int y;
	va_list copy;
	char *itoa;
	int va_arg;

	i = 0;
	y = 0;
	va_copy(copy, args);
	while (str[i])
	{
		if (str[i] == '*')
		{
			va_arg = va_arg(copy, int);
			itoa = ft_itoa((long long int)va_arg);
			y += ft_strlen(itoa);
			free(itoa);
		}
		else
			y++;
		i++;
	}
	return (y);
}

char	*ft_star_value(char *str, va_list args)
{
	char *end;
	int i;
	int y;
	char *itoa;
	int va_arg;
	
	y = 0;
	i = 0;
	if (!(end = ft_calloc(sizeof(end), ft_get_malloc(str, args) + 1)))
		return (NULL);
	while (str[i] && ft_is_convert(str[i]) == 0)
	{
		if (str[i] == '*')
		{
			va_arg = va_arg(args, int);
			itoa = ft_itoa((long long int)va_arg);
			ft_strcat(end, itoa);
			y += ft_strlen(itoa);
			free(itoa);
		}
		else
		{ 
			end[y] = str[i];
			y++;
		}
		i++;
	} 
	return (end);
}