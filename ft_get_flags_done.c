/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_done.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:01:53 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/09 13:25:12 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      ft_flags_numbers(char *flags) // GIVE FLAGS AMOUNT
{
    int i;
    int numbers;

    i = 0;
    numbers = 0;
    if (ft_strlen(flags) == 0)
        return (numbers);
    if (flags[0] == '.' && ft_isalnum(flags[1]) == 1)
        return (2);
    while (flags[i] != '.' && flags[i + 1] != '\0')
        i++;
    if (i > 0) 
    {
        numbers++;
        i++;
    }
    if (flags[i])
    {
        i++;
        numbers++;
    }
    return (numbers);
}

static int      ft_get_first_value(char *flags) // GET FLAGS FIRST VALUE
{
    int i;
    char *first_value;

    i = 0;
    if (ft_strlen(flags) == 0)
        return (i);
    first_value = ft_calloc(sizeof(first_value), 10);
    if (flags[0] == '.')
        first_value[0] = '0';
    else
    {
        while (flags[i] != '.' && flags[i] != '\0')
        {
            first_value[i] = flags[i];
            i++;
        }
    }
    i = ft_atoi(first_value);
    free (first_value);
    return (i);
}

static int      ft_get_second_value(char *flags) // GET FLAGS SECOND VALUE
{
    int i;
    int a;
    char *second_value;

    i = 0;
    a = 0;
    while (flags[i] != '.' && flags[i + 1] != '\0')
        i++;
    if (flags[i] == '.')
        i++;
    second_value = ft_calloc(sizeof(second_value), 10);
    while (flags[i])
    {
        second_value[a] = flags[i];
        a++;
        i++;
    }
    a = ft_atoi(second_value);
    return (a);
}

static char     *ft_is_one_value(char *flags, char *end)
{
    int i;
    int side;
    char *str;
    
    i = ft_get_first_value(flags);
    side = i;
    if (i < 0)
    {
        i = -i;
        str = ft_calloc(sizeof(str), i + ft_strlen(end));
    }
    else
        str = ft_calloc(sizeof(str), i + ft_strlen(end));
    if (i > 0 && i > (int)ft_strlen(end) && -side < 0)
    {
        ft_memset(str, ' ', i - (int)ft_strlen(end));
        str = ft_strcat(str, end);
        return (str);
    }
    else if (i > (int)ft_strlen(end) && -side > 0)
    {
        if (i < 0)
            i = -i;
        ft_strcpy(str, end);
        ft_memset(str + (int)ft_strlen(end), ' ', i - ft_strlen(end));
        ft_strclr(end);
        end = ft_strcat(end, str);
        free (str);
    }
    return (end);
}

static char     *ft_is_two_values(char *flags, char *end)
{
    int value;
    char *ptr;
    char *new_flags;

    value = ft_get_second_value(flags);
    end[value] = '\0';
    value = ft_get_first_value(flags);
    ptr = ft_itoa(value);
    new_flags = ft_calloc(sizeof(new_flags), ft_strlen(ptr));
    ft_strcpy(new_flags, ptr);
    end = ft_is_one_value(new_flags, end);
    free (ptr);
    return (end);
}

char     *ft_index(char *end, char *flags)
{
    //char *ptr;

    //ptr = end;
    //printf("%d\n", ft_flags_numbers(flags));
    if (ft_flags_numbers(flags) == 0)
        return (end);
    if (ft_flags_numbers(flags) == 1)
        end = ft_is_one_value(flags, end);
    if (ft_flags_numbers(flags) == 2)
        end = ft_is_two_values(flags, end);
    return (end);
}