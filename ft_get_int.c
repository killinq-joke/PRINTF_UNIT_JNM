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

char	*ft_int_add_space(char *flag, char *itoa)
{
	char	*temp;
	int		space_nbr;
	int 	total_size;
	char	*end;

	space_nbr = ft_atoi(flag);  
	if (space_nbr > 0)
	{
		total_size = (space_nbr) - ft_strlen(itoa);
		total_size < 0 ? total_size = 0 : total_size;
		temp = ft_calloc(sizeof(temp), total_size + 1);
		temp = ft_memset(temp, ' ', total_size);
		end = ft_strjoin(temp, itoa);
	}	
	else
	{	
		total_size = (space_nbr * -1) - ft_strlen(itoa);
		total_size < 0 ? total_size = 0 : total_size;
		temp = ft_calloc(sizeof(temp), total_size + 1);
		temp = ft_memset(temp, ' ', total_size);
		end = ft_strjoin(itoa, temp);
	}
	free(temp);
	free(itoa); 
	return (end);
}

char	*ft_int_flags(char **parsed_flags, char *itoa)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (parsed_flags[i] != 0)
		i++;
	while (j < i)
	{
		itoa = ft_int_add_space(parsed_flags[j], itoa);
		j++;
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