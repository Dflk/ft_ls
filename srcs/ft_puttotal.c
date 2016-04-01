/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttotal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 11:48:40 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/29 15:47:16 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_puttotal(t_entry *entries)
{
	struct stat		stats;
	unsigned int	blocks;
	char			*path;

	blocks = 0;
	if (entries)
	{
		path = entries->path;
		while (entries && entries->path == path)
		{
			stat(entries->path, &stats);
			blocks += stats.st_blocks;
			entries = entries->next;
		}
		ft_putstr("total ");
		ft_putnbr((int)blocks);
		ft_putchar('\n');
	}
}
