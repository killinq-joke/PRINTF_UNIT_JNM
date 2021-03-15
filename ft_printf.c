/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:20:39 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/15 08:29:06 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static char	*ft_get_convert(char *str, char *convert)
{
	int	i;

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

void	ft_get_clean(char *flags)
{
	int			i;
	int			a;
	int			is_minus;
	char		*save;

	save = ft_calloc(sizeof(save), ft_strlen(flags) + 1);
	a = 0;
	i = 0;
	is_minus = 0;
	while (flags[i])
	{
		if (flags[i] == '-' && is_minus == 0)
		{
			save[a] = flags[i];
			a++;
			is_minus++;
		}
		else if (flags[i] != '-')
		{
			save[a] = flags[i];
			a++;
		}
		if (flags[i] == '.')
			is_minus = 0;
		i++;
	}
	ft_strcpy(flags, save);
	free(save);
}

static char	*ft_get_flags(char *str, char *final_flags, \
va_list args, int **flag_len)
{
	int			i;
	int			j;
	int			len;
	char		*flags;

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
	ft_get_clean(final_flags);
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


char	*ft_percent_management(va_list args, char *str, char *final, int *i, int *y)
{
	int				a;
	int				va_arg;
	va_list			copy;
	static char		*flags;
	static char		*convert;
	static char		*content;
	
	
	a = ft_strlen(final);
	flags = ft_get_flags((char *)str, flags, args, &i);
	va_copy(copy, args);
	va_arg = va_arg(copy, int);
	convert = ft_get_convert((char *)str, convert);
	content = ft_get_content(flags, convert, args, a);
	final = ft_strjoin(final, content);
	if (ft_strchr(convert, 'c') != NULL && (va_arg == 0 ||\
	(ft_isprint(va_arg) == 0 && ft_strlen(content) == 0)))
	{
		*y += 1;
		
		ft_putchar(va_arg); 
		ft_putstr_fd(content, 1);
	}	
	else
		ft_putstr_fd(content, 1);
	free(convert);
	free(flags);
	free(content);
	return (final);
}
 
char		*ft_else_management(char c, char *final, int *i)
{
	char		save_char[2];

	save_char[0] = c;
	save_char[1] = '\0';
	final = ft_strjoin(final, save_char);
	*i += 1;
	ft_putchar(c);
	return (final);
}

int     ft_printf(const char *str, ...)
{
	int				i;
	int				a;
	int				y;
	va_list			args;
	static char		*final = NULL;
	static char		*ptr = NULL;
	char			*p;

	a = 0;
	i = 0;
	y = 0;
	p = NULL;
	va_start(args, str);
	if (!(final = (char *)ft_calloc(sizeof(final), 1)))
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
			ptr = ft_percent_management(args, (char *)str + i, final, &i, &y);
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
	a = ft_strlen(final) + y;
	//ft_putstr_fd(final, 1);
	free (final);
	va_end(args);
	return (a);
}
 