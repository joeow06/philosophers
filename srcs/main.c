/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:51 by jow               #+#    #+#             */
/*   Updated: 2025/03/21 17:28:56 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork_assignments(t_table *table)
{
	int i;

	printf("\n===== Philosopher Fork Assignments =====\n");
	for (i = 0; i < table->philo_count; i++)
	{
		t_philo *philo = &table->philo[i];

		printf("Philosopher %d:\n", philo->id);
		printf("  Left Fork Address:  %p (Fork ID: %d)\n",
			   (void *)philo->left_fork, philo->left_fork->fork_id);
		printf("  Right Fork Address: %p (Fork ID: %d)\n",
			   (void *)philo->right_fork, philo->right_fork->fork_id);
		printf("--------------------------------------\n");
	}
}

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
		printf("  Left Fork Address:  %p (Fork ID: %d)\n",
			(void *)philo->left_fork, philo->left_fork->fork_id);
		printf("  Right Fork Address: %p (Fork ID: %d)\n\n",
			(void *)philo->right_fork, philo->right_fork->fork_id);
		i++;
	}
}

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
	//print_fork_assignments(&table);
	print_data(&table);
	simulation(&table);
	printf("start_time: %ld\n", table.start_time);
	return (0);
}
