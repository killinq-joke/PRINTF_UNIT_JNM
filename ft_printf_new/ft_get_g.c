/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_g.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:48:41 by trofidal          #+#    #+#             */
/*   Updated: 2021/02/11 16:48:41 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_concat_string(double nbr)
{
	char *str;
	char **tab;
	
	str = ft_get_it_done(nbr);
	tab = ft_split(str, 'e');
	free(str);
	tab[0][ft_strlen(tab[0]) - 1] = '\0';
	if (!(str = ft_calloc(sizeof(char), ft_strlen(tab[0]) + ft_strlen(tab[1]) + 2)))
		return (NULL);
	ft_strcpy(str, tab[0]);
	str[ft_strlen(tab[0])] = 'e';
	ft_strcat(str, tab[1]);
	free(tab[0]);
	free(tab[1]);
	free(tab);
	return (str);
}

static char	*ft_del_zero_end(char *str)
{
	int i;
	int yes;

	i = 0;
	while(str[i])
	{
		if(str[i] == '0')
		{
			yes = 0;
			while(str[i + yes] == '0')
			{
				if (str[yes + i + 1] == '\0')
					str[i] = '\0';
				yes++;
			}
			i+=yes;
		}
		i++;
	}
	return (str);
}

static int ft_get_n_len(size_t dup)
{
	int len;
	len = 0;
		while (dup > 0)
		{
			dup /= 10;
			len++;
		}
		return (len);
}

char	*ft_get_g(char *flags, va_list args)
{
	char *flt;
	double va_arg;
	int len;
	if (ft_strlen(flags) == 0)
	{
		va_arg = va_arg(args, double);
		len = ft_get_n_len(va_arg);
		if(len <= 6)
		{
			flt = ft_putnbr_float(va_arg);
			flt = ft_del_zero_end(flt);
			if (len == 6)
				flt[6] = '\0';
			flt[7] = '\0';
		}
		else
			flt = ft_concat_string(va_arg);
		flt = ft_index(flt, flags); // TEST FOR FLAGS
		return (flt);
	}
	return (NULL);
}