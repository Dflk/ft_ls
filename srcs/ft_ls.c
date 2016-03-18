/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:28:39 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/18 15:48:23 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

static void			ft_printtypeoffile(t_entry *entry)
{
	if (S_ISBLK(entry->stats.st_mode))
		printf("b\t");
	else if (S_ISCHR(entry->stats.st_mode))
		printf("c\t");
	else if (S_ISFIFO(entry->stats.st_mode))
		printf("s\t");
	else if (S_ISREG(entry->stats.st_mode))
		printf("-\t");
	else if (S_ISDIR(entry->stats.st_mode))
		printf("d\t");
	else if (S_ISLNK(entry->stats.st_mode))
		printf("l\t");
	else if (S_ISSOCK(entry->stats.st_mode))
		printf("s\t");
}

void			ft_ls(char **paths, unsigned char params)
{
	t_entry	*entrys;

	if ((entrys = ft_fillentry(paths)))
	{
		while (entrys)
		{
			if (CHECK_BIT(params, PARAM_L_POS))
				ft_printtypeoffile(entrys);
			if (entrys->file)
			{
				if (entrys->error != 0)
					printf("TEST\n");
				printf("%s\n", entrys->file->d_name);
			}
			else
				printf("%s\n", entrys->path);
			entrys = entrys->next;
		}
	}
}
