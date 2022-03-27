/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:43:20 by ftassada          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:48 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**ft_free_arr(char **arr, int ln)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (i < ln)
		{
			if (arr[i] != NULL)
			{
				ft_bzero(arr[i], ft_strlen(arr[i]));
				free(arr[i]);
			}
			i++;
		}
		ft_bzero(arr, sizeof(char *));
		free(arr);
	}
	return (NULL);
}

void	ft_free_game(t_game *game)
{
	int	i;

	if (game != NULL)
	{
		if (game->map != NULL)
			ft_free_arr(game->map, ft_arrlen(game->map));
		i = 0;
		while (i < 4)
		{
			if (game->nswe[i] != NULL)
				free(game->nswe[i]);
			i++;
		}
		ft_bzero(game->nswe, sizeof(char *) * 4);
		if (game->gnln != NULL)
		{
			if (*game->gnln != NULL)
				free(*game->gnln);
			free(game->gnln);
		}
		free_all_raycast(game);
		ft_bzero(game, sizeof(t_game));
		free(game);
	}
}

void	ft_context_free_err(t_game *game, char ***tmp, int aln, char *msg)
{
	ft_free_arr(*tmp, aln);
	free(tmp);
	ft_error(game, msg, 0);
}
