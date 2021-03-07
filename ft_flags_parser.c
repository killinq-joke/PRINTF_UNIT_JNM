/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:17:06 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 22:26:06 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_point_fetcher(char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

char 	**ft_flags_parser(char *flags)
{
	int i;
	char **all_flags;
 
	if (ft_point_fetcher(flags) == 1)
		all_flags = ft_split(flags, '.');
	else
	{
		if (!(all_flags = ft_calloc(sizeof(all_flags), 2)))
			return (NULL);
		all_flags[0] = ft_strdup(flags);
		all_flags[1] = 0;
	} 
	return (all_flags);
}