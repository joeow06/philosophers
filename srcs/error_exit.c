/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:35:59 by jow               #+#    #+#             */
/*   Updated: 2025/03/30 14:06:09 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error_exit(char *str)
{
	printf("Error: %s\n", str);
	exit(EXIT_FAILURE);
}

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		ft_mutex(&table->philo[i].ph_mtx, DESTROY);
		i++;
	}
	ft_mutex(&table->write_mutex, DESTROY);
	ft_mutex(&table->read_mutex, DESTROY);
	free(table->philo);
	free(table->forks);
}
