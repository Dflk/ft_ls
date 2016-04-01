/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:58:21 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/30 12:49:15 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_error(int flag, int exit_flag, char *str)
{
	if (flag == USAGE)
		ft_putstr("usage: ls [-altrR] [file ...]\n");
	else
	{
		ft_putstr("ls: ");
		ft_putstr(str);
		ft_putstr(": ");
		ft_putstr(strerror(flag));
		ft_putchar('\n');
	}
	if (exit_flag == 1)
		exit(1);
}
