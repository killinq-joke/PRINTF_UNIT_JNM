/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 23:01:01 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/12 23:01:01 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

int				ft_printf(const char *str, ...);

#define tofunction(x, ...) function("%s\n", x, a, b)
int main()
{
	/*	===== E A S Y ===== */
	/*	===== C H E C K _ R E T U R N E D _ C O N T E N T _ O N L Y ===== */
	char *easy1 = "I am a little sneaky boy";
	char *easy2 = "Yo0";
	char *easy3 = "I am a really long and really annoying line, do you like what you see ? ";
	char *easy4 = "Et la il me dit, je ne viens pas, ah non non je ne viens pas, je vais faire gitteur";
	char *easy5 = "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEET salut a tous les amiiiiiiis c'est David lafarge pokemon, aujourd'hui booster de carte pokemon !";

	function("Hi\n");
	function("  My name\n");
	function(" is \n");
	function("  Thomas \n");
	function("%s\n", easy1);
	function("%s\n", easy2);
	function("%s\n", easy3);
	function("%s\n", easy4);
	function("%s\n", easy5);
	function("%s Hi i am\n", easy1);
	function("%s Youssef\n", easy2);
	function("%s a 0123456a\n", easy3);
	function("%s Hi !\n", easy4);
	function("aaaaa %s aaaaaaa\n", easy5);
	function("%5s\n", easy1);
	function("%16s\n", easy2);
	function("%32s\n", easy3);
	function("%56s\n", easy4);
	function("%165s\n", easy5);
	function("%s %s\n", easy1, "easy2");
	function("%s %s\n", easy2, "easy3");
	function("%s %s\n", easy3, "easy4");
	function("%s %s\n", easy4, "easy5");
	function("%s %s\n", easy5, "easy5");
	function("%10s, %s\n", easy1, easy2);
	function("%12s, %s\n", easy2, easy3);
	function("%65s, %s\n", easy3, easy4);
	function("%98s, %s\n", easy4, easy5);
	function("%1s, %s\n", easy5, easy5);
}