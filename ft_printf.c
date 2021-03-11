/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:20:39 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/11 06:51:23 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
 
static char		*ft_get_convert(char *str, char *convert)
{
	int i;

	i = 1;
	if (!(convert = ft_calloc(sizeof(convert), 1)))
		return (NULL);
	convert[0] = '%';
	while (str[i])
	{
		if (ft_is_convert(str[i]) == 1)
		{
			convert[1] = str[i];
			return (convert);
		}
		i++;
	}
	return (convert);
} 

static char		*ft_get_flags(char *str, char *final_flags, va_list args, int **flag_len)
{
	int i;
	int j;
	int len;
	char *flags;

	len = 0;
	j = 0;
	i = 0; 
	if (str[i] == '%')
		i++;
	while (str[i + len])
		len++;
	if (!(flags = ft_calloc(sizeof(flags), len++)))
		return (NULL);
	while (ft_is_convert(str[i]) == 0)
	{
		flags[j] = str[i];
		j++;
		i++;
	}
	**flag_len += j + 2;
	flags[j] = '\0';
	final_flags = ft_star_value(flags, args);
	free(flags);
	return (final_flags);
}

void	ft_free_main(char *temp, char *convert, char *flags, char *content)
{
	free (temp);
	free (convert);
	free (flags);
	free (content);
}


char	*ft_percent_management(va_list args, char *str, char *final, int *i)
{
	static char *flags; /* 5.4 */
	static char *convert;  /* %s %d */  
    static char *content; /* toto, 18 */
 
	int a;
 
	
	a = ft_strlen(final);
	flags = ft_get_flags((char *)str, flags, args, &i);
	convert = ft_get_convert((char *)str, convert);
	content = ft_get_content(flags, convert, args, a);
	 
	final = ft_strjoin(final, content); 
 	free (convert);
	free (flags);
	free (content);
	 
	return (final);
}

char	*ft_else_management(char c, char *final, int *i)
{
 
	char		save_char[2];
	
	save_char[0] = c;
	save_char[1] = '\0';
	final = ft_strjoin(final, save_char);
	*i += 1; 
	return (final);
}
 
int     ft_printf(const char *str, ...)
{
    int i;
	int a = 0;
    va_list args;
    static char *final = NULL;
	static 	char	*ptr = NULL;
	char *p = NULL;
    i = 0; 
    va_start(args, str);
	if (!(final = (char *)ft_calloc(sizeof(final), 1)))
			return (0);
    while (str[i])
    {
		
   		if (str[i] == '%')
			ptr = ft_percent_management(args, (char *)str + i, final, &i);
		else
			ptr = ft_else_management(str[i], final, &i); 
		p = (char *)ft_calloc(sizeof(p), ft_strlen(ptr) + 1);
		ft_strcpy(p, ptr);
		free(final);
		final = (char *)ft_calloc(sizeof(final), ft_strlen(p) + 1);
		strcpy(final, p);
		free(p);
		free(ptr);
		
    }
	a = ft_strlen(final);
	ft_putstr_fd(final, 1);
	free (final);
	va_end(args);
    return (a);
}
/*
int main()
{
	printf("%p", NULL);
	ft_printf("%p", NULL);
	*ft_printf(" %x ", 0);
	ft_printf(" %.x ", 0);
	ft_printf(" %-.2x ", 0);
	ft_printf(" %-2.2x ", 0);
	ft_printf(" %-3.2x ", 0);
	ft_printf(" %-3.2x %10.42x ", 0, 0);
	ft_printf(" %-3.2x %10.42x ", 1, -1);
 	ft_printf(" %-3.2x %10.42x ", 10, -10);
 	ft_printf(" *%-*.*x* *%*.*x* ", 4, 5, 10, 10, 21, -10);
	ft_printf(" *%-*.*x* *%*.*x* ", 6, 2, 102, 10, 21, -101);
	ft_printf(" *%*.*x* *%*.*x* ", -6, 2, 102, 10, 21, 101);
	ft_printf(" 0*%0-*.*x*0 0*%0*.*x*0 ", 6, 2, 102, 10, 21, -101);
	ft_printf(" 0*%0-*.*x*0 0*%0*.*x*0 ", 2, 6, 102, 21, 10, -101);
	ft_printf(" 0*%0-*x*0 0*%0*x*0 ", 21, 1021, 21, -1011);
	ft_printf(" 0*%-0*.10x*0 0*%-0*.0x*0 ", 21, 1021, 21, -1011);
	ft_printf(" --0*%0*.0x*0 0*%0*.10x*0-- ", -2, 0, 21, 1);
	ft_printf(" --0*%0*.0x*0 0*%0*.10x*0-- ", -21, INT_MAX, 21, INT_MIN);
	ft_printf(" --0*%0*.0x*0 0*%0*.10x*0-- ", -21, LONG_MAX, 21, LONG_MIN);
	ft_printf(" --0*%-0*.20x*0 0*%-0*.10x*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);
	ft_printf(" --0*%-0*.2x*0 0*%-0*.2x*0-- ", -21, UINT_MAX, 21, UINT_MAX + 1);
	ft_printf("%9.0u", UINT_MAX);
	ft_printf("%9.1u", UINT_MAX);
 	ft_printf("%9.2u", UINT_MAX);
	ft_printf("%9.10u", UINT_MAX);
	ft_printf("%10.0u", UINT_MAX);
	ft_printf("%10.1u", UINT_MAX);
	ft_printf("%10.2u", UINT_MAX);
	ft_printf("%10.10u", UINT_MAX);
	ft_printf("%11.0u", UINT_MAX);
	ft_printf("%11.1u", UINT_MAX);
	ft_printf("%11.2u", UINT_MAX);
	ft_printf("%11.10u", UINT_MAX);
	ft_printf("%-9.0u", UINT_MAX);
	ft_printf("%-9.1u", UINT_MAX);
	ft_printf("%-9.2u", UINT_MAX);
	ft_printf("%-9.10u", UINT_MAX);
	ft_printf("%-10.0u", UINT_MAX);
	ft_printf("%-10.1u", UINT_MAX);
	ft_printf("%-10.2u", UINT_MAX);
	ft_printf("%-10.10u", UINT_MAX);
	ft_printf("%-11.0u", UINT_MAX);
	ft_printf("%-11.1u", UINT_MAX);
	ft_printf("%-11.2u", UINT_MAX);
	ft_printf("%-11.10u", UINT_MAX);
	ft_printf("%09.0u", UINT_MAX);
	ft_printf("%09.1u", UINT_MAX);
	ft_printf("%09.2u", UINT_MAX);
	ft_printf("%09.10u", UINT_MAX);
	ft_printf("%010.0u", UINT_MAX);
	ft_printf("%010.1u", UINT_MAX);
	ft_printf("%010.2u", UINT_MAX);
	ft_printf("%010.10u", UINT_MAX);
	ft_printf("%011.0u", UINT_MAX);
	ft_printf("%011.1u", UINT_MAX);
	ft_printf("%011.2u", UINT_MAX);
	ft_printf("%011.10u", UINT_MAX);
	ft_printf("%09.0u", UINT_MAX + 1);
	ft_printf("%09.1u", UINT_MAX + 1);
	ft_printf("%09.2u", UINT_MAX + 1);
	ft_printf("%09.10u", UINT_MAX + 1);
	ft_printf("%010.0u", UINT_MAX + 1);
	ft_printf("%010.1u", UINT_MAX + 1);
	ft_printf("%010.2u", UINT_MAX + 1);
	ft_printf("%010.10u", UINT_MAX + 1);
	ft_printf("%011.0u", UINT_MAX + 1);
	ft_printf("%011.1u", UINT_MAX + 1);
	ft_printf("%011.2u", UINT_MAX + 1);
	ft_printf("%011.10u", UINT_MAX + 1);
	ft_printf("%.0u", 0);
	ft_printf("%.0u", 5);
	ft_printf("%.0u", 10);
	ft_printf("%1.u", 0);
	ft_printf("%2.u", 0);
	ft_printf("%3.u", 0);
	ft_printf("%1.1u", 0);
	ft_printf("%1.2u", 0);
	ft_printf("%1.3u", 0);
	ft_printf("%1.1u", 0);
	ft_printf("%2.2u", 0);
	ft_printf("%3.3u", 0);
}*/