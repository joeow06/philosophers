/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:51 by jow               #+#    #+#             */
/*   Updated: 2025/02/27 13:23:29 by jow              ###   ########.fr       */
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
	init_table(ac, av, &table);
	//start_simulation(&table);
	return (0);
}
