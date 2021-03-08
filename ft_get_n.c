/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:40:56 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/08 15:02:02 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_n(char *flags, va_list args, int a)
{
	char	*flt;
	int		*va_arg;

	if (ft_strlen(flags) == 0)
	{
		va_arg = va_arg(args, int*);
		*va_arg = a;
		flt = ft_calloc(sizeof(flt), 1);
		return (flt);
	}
	return (NULL);
}