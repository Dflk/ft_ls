/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:00:56 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/18 10:25:37 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <libft.h>
# define PARAM_A_POS 1
# define PARAM_L_POS 2
# define PARAM_T_POS 3
# define PARAM_R_MAX_POS 4
# define PARAM_R_MIN_POS 5
# define USAGE 255
# define CHECK_BIT(BYTE, POS) (BYTE & (1 << POS))

typedef struct	s_entry
{
	struct dirent	*file;
	struct stat		stats;
	char			*path;
	int				error;
	struct s_entry	*next;
}				t_entry;
void			ft_error(int flag, int exit);
unsigned char	ft_parseparams(int argc, char **argv);
void			ft_ls(char **paths, unsigned char params);
t_entry			*ft_fillentry(char **paths);
char			*ft_strsj(char *path, char *name, unsigned int size_name);
char			**ft_parseargs(int argc, char **argv);

#endif
