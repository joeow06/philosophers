/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:51 by jow               #+#    #+#             */
/*   Updated: 2025/02/05 11:27:45 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (!check_valid_args(ac, av))
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	printf("Arguments are valid\n");
	//init_table(table, ac, av);
	//start_simulation(table);
	return (0);
}
