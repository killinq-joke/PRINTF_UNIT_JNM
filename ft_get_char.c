/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:17:06 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/09 00:43:22 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_get_flag_side(char *flags)
{
    int i;
    char *str;

    i = 0;
    while (ft_isalnum(flags[i]) == 1 || flags[i] == '-')
        i++;
    str = ft_calloc(sizeof(str), i);
    i = 0;
    while (ft_isalnum(flags[i]) == 1 || flags[i] == '-')
    {
        str[i] = flags[i];
        i++; 
    }
    i = ft_atoi(str);
    free (str);
    return (i);
}

char    *ft_get_char_flags(char *flags, char *end)
{
    char *space;
    char *ptr;
    int a;
    int i;
    int y;
    
    i = 0;
    if (ft_isalnum(flags[0]) == 1 || flags[0] == '-')
    {
        a = ft_get_flag_side(flags);
        y = a;
        if (y < 0)
            y =  -y;
        space = ft_calloc(sizeof(space), y + 1);
        while (y > 1)
        {
            space[i] = ' ';
            i++;
            y--;
        }
        ptr = end;
        if (a > 0)
        {
            ptr = end;
            end = ft_strcat(space, end);
            free (ptr);
        }
        else
        {
            end = ft_calloc(sizeof(end), -a + 1);
            end = ft_strcpy(end, ptr);
            end = ft_strcat(end, space);
            free (space);
            free (ptr);
        }
        return (end);
    }
    return (end);
}

char    *ft_get_char(char *flags, va_list args)
{
    char *end;
    int va_arg;
    
    va_arg = va_arg(args, int);
    if (!(end = ft_calloc(sizeof(end), 2)))
        return (NULL);
    end[0] = va_arg;
    end[1] = '\0';
    if ((flags[0] == '-' || flags[0] == '+' || flags[0] == '0') \
    && (flags[1] == '\0' || flags[1] == '.'))
        return (end);
    if (ft_strlen(flags) > 0)
        end = ft_get_char_flags(flags, end);
    return (end);
}

