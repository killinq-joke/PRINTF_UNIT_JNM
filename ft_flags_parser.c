/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:17:06 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/11 08:49:17 by trofidal         ###   ########.fr       */
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

void	ft_clean_flags(char	**all_flags)
{
	int i;
	int j;
	int is_num;

	i = 0;
	while (all_flags[i] != 0)
	{
		j = 0;
		is_num = 0;
		while (all_flags[i][j])
		{
			if (all_flags[i][j] == '-' && is_num == 1)
				{
					ft_strcpy(all_flags[i], all_flags[i] + j);
					break;
				}
			if (ft_isdigit(all_flags[i][j]) == 1)
					is_num = 1;  
			j++;
		}
		i++;
	} 
}

char 	**ft_flags_parser(char *flags)
{
	char **all_flags;
	int i;

	i = 0;
	if (ft_strlen(flags) == 0)
	{	 
		if (!(all_flags = ft_calloc(sizeof(all_flags), 2)))
			return (NULL);
		all_flags[0] = ft_strdup("NULL");
		all_flags[1] = 0;
		return (all_flags);
	}	
	while (flags[i])
	{
		if(flags[i]=='.' && flags[i + 1] == '-')
		{ 
			ft_strlcpy(flags, flags, i+1);
			break;
		}
		i++;
	}
	if (flags[ft_strlen(flags) - 1] == '.')
	{
		flags[ft_strlen(flags)] = '0';
		flags[ft_strlen(flags) + 1]= '\0';
	}
	if (ft_point_fetcher(flags) != 1 || flags[0] == '.')
	{
		if (!(all_flags = ft_calloc(sizeof(all_flags), 2)))
			return (NULL);
		all_flags[0] = ft_strdup(flags);
		all_flags[1] = 0;
	}
	else
		all_flags = ft_split(flags, '.');
  	ft_clean_flags(all_flags);
	return (all_flags);
}