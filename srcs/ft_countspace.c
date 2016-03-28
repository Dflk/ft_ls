/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:19:36 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/27 19:02:36 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

size_t		ft_countnb(unsigned int nb)
{
	size_t	res;

	res = 1;
	if (nb == 0)
		res++;
	else
		while (nb)
		{
			res++;
			nb /= 10;
		}
	return (res);
}

size_t		*ft_countspace(t_entry *entries)
{
	struct stat		stats;
	static size_t	spaces[5] = {0, 0, 0, 0, 0};
	size_t			nb;

	while (entries)
	{
		stat(entries->path, &stats);
		if ((nb = ft_countnb(stats.st_nlink)) > spaces[0])
			spaces[0] = nb;
		if ((nb = ft_strlen(getpwuid(stats.st_uid)->pw_name)) > spaces[1])
			spaces[1] = nb;
		if ((nb = ft_strlen(getgrgid(stats.st_gid)->gr_name)) > spaces[2])
			spaces[2] = nb;
		if ((nb = ft_countnb(stats.st_size)) > spaces[3])
			spaces[3] = nb;
		entries = entries->next;
	}
	return ((size_t*)spaces);
}
