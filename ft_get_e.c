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
	while (count > 1)
	{
		result = result * 10;
		count--;
	}
	return (result);
}

char	*ft_get_e(double nbr)
{
	char 	*end; //e+0x
	char	*start;//2.
	char	*final;//final result
	int pow;

	pow = ft_pow_float(nbr);
	final = ft_putnbr_float((long double)nbr / pow);
	return (final);
}

int main()
{
	char *str;
	
	long double  d = 0120.006775;
 	str  = ft_get_e(0120.006775);
	
	
 	printf("%s\n", str);
	printf("%s\n", ft_putnbr_float(0120.0067799999 / 100));
	printf("le vrai %e\n", 0120.006775);
	return(0);
}