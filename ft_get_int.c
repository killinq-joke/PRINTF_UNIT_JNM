/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:31:00 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 22:26:20 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_int_zero(int total_size, int is_zero, int nbr, char *itoa)
{
	char	*start;
	char	*temp;
	char	*end;
	char	*final;

	(total_size > 0 && is_zero != 1) ? total_size++ : 0;
	(nbr < 0 && total_size == 0 && is_zero != 1) ? total_size ++ : 0;
	total_size < 0 ? total_size = 0 : total_size;
	temp = ft_calloc(sizeof(temp), total_size + 1);
	temp = ft_memset(temp, '0', total_size); 
	start = ft_calloc(sizeof(start), 2);
	start[0] = '-';
	start[1] = '\0';
	end = ft_strjoin(temp, itoa + 1); 
	final = ft_strjoin(start, end);
	free(temp);
	free(end);
	free(start);
	return (final);
}

char	*ft_int_minus(int total_size, int i, char *itoa, int is_zero, int is_neg)
{
	char	*temp;
	char	*end;
	int		nbr;
	char	*final;

	nbr = ft_atoi(itoa);
	if (nbr < 0 && i == 1)
	{   
		 final = ft_int_zero(total_size, is_zero, nbr, itoa);
		 return (final);
	}
	
	total_size < 0 ? total_size = 0 : total_size;
	temp = ft_calloc(sizeof(temp), total_size + 1);
	i == 1 ? temp = ft_memset(temp, '0', total_size) : (temp = ft_memset(temp, ' ', total_size));
 
	is_neg == 1 ? (end = ft_strjoin(itoa, temp)): (end = ft_strjoin(temp, itoa));
	free(temp);
	return (end);	
}

char	*ft_int_add_space(char *flag, char *itoa, int is_zero, int i)
{
	int		space_nbr;
	int 	total_size;
	char	*end;
	int 	is_neg;
 
	is_neg = 0;
	space_nbr = ft_atoi(flag);
	space_nbr < 0 ? (is_neg = 1) : (is_neg = 0);
	space_nbr < 0 ? space_nbr *= -1 : space_nbr;
	total_size = (space_nbr) - ft_strlen(itoa);
	if (flag[0] == '0' && is_zero == 0 && ft_strcmp(itoa, "0") == 0)
	{	 
		strcpy(itoa, "");
		return (itoa);
	}
	
	end = ft_int_minus(total_size, i, itoa, is_zero, is_neg);
	free(itoa);
	return (end);	
}

char	*ft_int_flags(char **parsed_flags, char *itoa)
{
	int 	i;
	int is_zero;
	int count;
	int j;

	count = 0;
	i = 0; 
	while (parsed_flags[i] != 0)
		i++;
	i--;
	j = i;
	while (i >= 0)
	{	 
		if (parsed_flags[0][0] == '0' && parsed_flags[0][1] == '-')
			ft_strcpy(parsed_flags[0], parsed_flags[0] + 1);
		if (parsed_flags[0][0] == '.' || i == 1 || (parsed_flags[0][0] == '0' && count == 0))
		{
			parsed_flags[0][0] == '0' && j == 0 ? (is_zero = 1) : (is_zero = 0);
			parsed_flags[0][0] == '.' ? ft_strcpy(parsed_flags[0], parsed_flags[0] + 1) : 0;
			itoa = ft_int_add_space(parsed_flags[i], itoa, is_zero, 1);
			count++;
		}
		else
			itoa = ft_int_add_space(parsed_flags[i], itoa, ' ', i);
		i--;
	}	
	return(itoa);
}

char	*ft_get_int(char *flags, va_list args, char **parsed_flags, char *ret)
{
	char 	*itoa; 
	char	*end;
	
	itoa = NULL;
	ret == NULL ? (itoa = ft_itoa((long long int)va_arg(args, int))) : (itoa = ft_strdup(ret));
	if ((ft_strlen(flags)) > 0) 
	{
		end = ft_int_flags(parsed_flags, itoa);
		return (end);
	}
	return (itoa);
}