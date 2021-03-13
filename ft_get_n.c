/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:40:56 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/09 13:06:03 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_n(char *flags, va_list args, int a)
{
	char	*flt;
	int		*va_arg;

	if (ft_strlen(flags) == 0)
	{
		va_arg = va_arg(args, int *);
		*va_arg = a;
		flt = ft_calloc(sizeof(flt), 1);
		flt = ft_index(flt, flags); // TEST FOR FLAGS
		return (flt);
	}
	return (NULL);
}
