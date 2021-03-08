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

char	*ft_int_minus(int total_size, int i, char *itoa, int c)
{
	char	*temp;
	char	*start;
	char	*end;
	int		nbr;
	temp = ft_calloc(sizeof(temp), total_size + 1);
	nbr = ft_atoi(itoa);

	if (nbr < 0 && i == 1)
	{ 
		total_size++;
		temp = ft_memset(temp, c, total_size);
		start = ft_calloc(sizeof(start), 2);
		start[0] = '-';
		start[1] = '\0';
		end = ft_strjoin(temp, itoa + 1);
		start = ft_strjoin(start, end);
		free(end);
		return (start);
	}
	temp = ft_memset(temp, c, total_size);
	end = ft_strjoin(temp, itoa);
	free(itoa);
	free(temp);
	return (end);	
}

char	*ft_int_add_space(char *flag, char *itoa, char c, int i)
{
	char	*temp;
	int		space_nbr;
	int 	total_size;
	char	*end;

	space_nbr = ft_atoi(flag);
	space_nbr < 0 ? space_nbr *= -1 : space_nbr;
	total_size = (space_nbr) - ft_strlen(itoa); 
	if (space_nbr > 0)
	{   
		total_size < 0 ? total_size = 0 : total_size; 
		end = ft_int_minus(total_size, i, itoa, c);
		return (end);	
	}	
	else
	{	
		temp = ft_calloc(sizeof(temp), total_size + 1);
		temp = ft_memset(temp, c, total_size);
		end = ft_strjoin(itoa, temp);
	}
	free(temp);
	free(itoa); 
	return (end);
}

char	*ft_int_flags(char **parsed_flags, char *itoa)
{
	int 	i; 

	i = 0; 
	while (parsed_flags[i] != 0)
		i++;
	i--;
	while (i  >= 0)
	{	
		if (i == 1)
			itoa = ft_int_add_space(parsed_flags[i], itoa, '0', i); 
		else
			itoa = ft_int_add_space(parsed_flags[i], itoa, ' ', i);
		i--;

	}	
	return(itoa);
}

char	*ft_get_int(char *flags, va_list args, char **parsed_flags)
{
	char *itoa;
	int va_arg; 

	va_arg = va_arg(args, int);
	itoa = ft_itoa((long long int)va_arg);
	if ((ft_strlen(flags)) > 0) 
		itoa = ft_int_flags(parsed_flags, itoa);	
	return (itoa);
}