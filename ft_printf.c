/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:20:39 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/08 19:43:25 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char		*temp;
	int a;
 
	a = ft_strlen(final);
	flags = ft_get_flags((char *)str, flags, args, &i);
	convert = ft_get_convert((char *)str, convert);
	content = ft_get_content(flags, convert, args, a);
	temp = final;
	final = ft_strjoin(temp, content);
	ft_free_main(temp, convert, flags, content);
	return (final);
}

char	*ft_else_management(char c, char *final, int *i)
{
	char		*temp;
	char		save_char[2];
	
	save_char[0] = c;
	save_char[1] = '\0';
	temp = final;
	final = ft_strjoin(temp, save_char);
	free (temp);
	*i += 1; 
	return (final);
}

int     ft_printf(const char *str, ...)
{
    int i;
    va_list args;
    static char *final = NULL;
	
    i = 0;
    va_start(args, str);
	if (!(final = (char *)ft_calloc(sizeof(final), 1)))
		return (0);
    while (str[i])
    {
    if (str[i] == '%')
			final = ft_percent_management(args, (char *)str + i, final, &i);
		else
			final = ft_else_management(str[i], final, &i);
    }
	ft_putstr_fd(final, 1);
	free (final);
	va_end(args);
    return (i);
}

int main()
{
	// ft_printf("%3.7d\n", -2375);
 	// printf("%3.7d\n", -2375);
	// ft_printf("%7.4d\n", -8473);
	// printf("%7.4d\n", -8473);

	// ft_printf("{%5.0d}\n",  42);
	//  printf("{%5.0d}\n",  42);
	//  ft_printf("%04d\n", -532);
	//  printf("%04d\n", -532);
	//  ft_printf("%07d\n", -54);
	//  printf("%07d\n", -54);
	//  ft_printf("%20.5d\n", -1024);
	//  printf("%20.5d\n", -1024);
	//  ft_printf("{%05.*d}\n", -15, 42);
	// //  printf("{%05.*d}\n", -15, 42);

	//  ft_printf("st13 %0d\n", 0);
	//  printf("st13 %0d\n",  0);
	//  ft_printf("%.0d\n", 0);
	//  printf("%.0d\n", 0);

	//  ft_printf("t3 %50.0x\n", 10);
	//  printf("t3 %50.0x\n", 10);
	//  ft_printf("t3 %.0d\n", 10);
	//  printf("t3 %.0d\n", 10);

	//  ft_printf("%-5.0da\n", 0);
	//  printf("%-5.0da\n", 0);
	printf("####XXXXXX#####\n");
	ft_printf("%-3xa\n", 0);
	printf("%-3xa\n", 0);
} 