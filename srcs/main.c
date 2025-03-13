/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:51 by jow               #+#    #+#             */
/*   Updated: 2025/03/13 13:22:42 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	parser(ac, av, &table);
	printf("philo_count: %d\n", table.philo_count);
	init(ac, av, &table);
	// for (int i = 0; i < table.philo_count; i++)
	// {
	// 	printf("id: %d\n", table.philos[i].id);
	// 	printf("meals: %d\n", table.philos[i].meals);
	// 	printf("address: %p\n", &table.philos[i]);
	// }
	//start_simulation(&table);
	return (0);
}
