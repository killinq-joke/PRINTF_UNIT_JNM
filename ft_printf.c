/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:20:39 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/09 12:05:58 by trofidal         ###   ########.fr       */
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
	printf("%-18sa\n", "goes over");
	ft_printf("%-18sa\n", "goes over");
}

/*
static char     *ft_get_flags_values(char *flags, char *end)
{
    char *spaces;
    char *ptr;
    int isneg;
    int totlen;
    int isalone;
    int len;
    int i;

    i = 0;
    isalone = 0;
    totlen = 0;
    isneg = 0;
    spaces = ft_calloc(sizeof(spaces), 10);
    if ((flags[0] == '.' || flags[0] == '-') && ft_isalnum(flags[1]) == 0)
        return (end);
    spaces = ft_calloc(sizeof(spaces), 10);
    while (flags[i] != '.' && flags[i] != '\0')
    {
        spaces[i] = flags[i];
        i++;
    }
    if (ft_strlen(flags) == ft_strlen(spaces))
        isalone++;
    i++;
    if (flags[i])
        totlen = ft_atoi(flags + i);
    len = ft_atoi(spaces);
    free (spaces);
    if (len < 0)
    {
        len = -len;
        isneg++;
    }
    if (len >= totlen&& isalone == 0)
    {
        spaces = ft_calloc(sizeof(spaces), len);
        if (((int)ft_strlen(end) < totlen) && isneg == 0)
            ft_memset(spaces, ' ', len - ft_strlen(end));
        else if (isneg == 1 && len > totlen)
            return (end);
        else
            ft_memset(spaces, ' ', len - totlen);
        end[totlen] = '\0';
        ptr = end;
        end = ft_strcat(spaces, end);
        free (ptr);
    }
    else if (isalone > 0)
    {
        spaces = ft_calloc(sizeof(spaces), len);
        ft_memset(spaces, ' ', len - ft_strlen(end));
        end[len - totlen] = '\0';
        ptr = end;
        if (len < (int)ft_strlen(end))
        {
            end = ft_strcat(spaces, end);
            free (ptr);
        }
        else
            end = ft_strcat(end, spaces);
    }
    else
    {
        end[totlen] = '\0';
    }
    return (end);
}*/