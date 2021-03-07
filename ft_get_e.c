/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:44:01 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/07 01:51:56 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pow_float(long double nbr)
{
	int i;
	int count;
	int result;

	result = 1;
	count = 0;
	i = nbr;
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	while (--count > 0)
		result = result * 10;
	return (result);
}

char	*ft_get_e(double nbr)
{
	char 	*end;
	char	*start;
	char	*final;
	int 	pow;

	pow = ft_pow_float(nbr);
	final = ft_putnbr_float(((long double)nbr / pow));
	return (final);
}

int main()
{
	char *str; 
 	str  = ft_get_e(0120.02);
	
	
 	printf("%s\n", str); 
	printf("le vrai %e\n", 0120.02);
	return(0);
}