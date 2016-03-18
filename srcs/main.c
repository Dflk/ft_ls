/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:01:40 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/18 14:23:03 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	unsigned char	params;
	char			**paths;
	int				i;

	params = 0;
	i = 0;
	if (argc > 1)
		params = ft_parseparams(argc, argv);
	paths = ft_parseargs(argc, argv);
	ft_ls(paths, params);
}
