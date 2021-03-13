/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_second_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 06:43:32 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/11 06:43:37 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_second_value(char *flags) // GET FLAGS SECOND VALUE
{
	int			i;
	int			a;
	char		*second_value;

	i = 0;
	a = 0;
	while (flags[i] != '.' && flags[i + 1] != '\0')
		i++;
	if (flags[i] == '.')
		i++;
	second_value = ft_calloc(sizeof(second_value), 10);
	while (flags[i])
	{
		second_value[a] = flags[i];
		a++;
		i++;
	}
	a = ft_atoi(second_value);
	free (second_value);
	return (a);
}
