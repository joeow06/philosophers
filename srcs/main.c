/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:51 by jow               #+#    #+#             */
/*   Updated: 2025/03/31 17:06:30 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_table *table);

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	parser(ac, av, &table);
	init(ac, av, &table);
	simulation(&table);
	free_table(&table);
	return (0);
}
/*
void	print_data(t_table *table)
{
	int i;

	printf("\n===== Philosopher Data =====\n");
	printf("Philosopher Count: %d\n", table->philo_count);
	printf("Time to Die: %ld ms\n", table->time_to_die);
	printf("Time to Eat: %ld ms\n", table->time_to_eat);
	printf("Time to Sleep: %ld ms\n", table->time_to_sleep);
	printf("Meals Required: %d\n\n", table->meals);

	i = 0;
	while (i < table->philo_count)
	{
		t_philo *philo = &table->philo[i];
		printf("Philosopher %d:\n", table->philo[i].id);
		printf("  Meals: %d\n", table->philo[i].meals);
		printf("  Mutex Address: %p\n", (void *)&table->philo[i].ph_mtx);
		printf("  Left Fork Mtx Address:  %p (Fork ID: %d)\n",
			(void *)&philo->left_fork->fork_mtx, philo->left_fork->fork_id);
		printf("  Right Fork Mtx Address: %p (Fork ID: %d)\n\n",
			(void *)&philo->right_fork->fork_mtx, philo->right_fork->fork_id);
		i++;
	}
}
*/
