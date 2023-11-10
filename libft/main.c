/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:17:49 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 09:33:19 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	main_not_enough_args(void)
{
	log_error("Not enough arguments provided to the program");
	return (1);
}

int	main_test_indiv(char *name)
{
	TestGroup group;

	group = test_match_group(name);
	if (group == TEST_GROUP_NIL)
	{
		log_warning("test %s hasn't been implemented", name);
		return (0);
	}

	int (*func)(void) = testFuncs[group];
	int fails = func();
	if (fails == 0)
		log_success("test %s success", name);
	else
		log_error("%s had %d fail%s", name, fails, fails == 1 ? "" : "s");
	return (1);
}

int	main_test_combo(int count, char **test_names)
{
	int	error;

	error = 0;
	for (int i = 0; i < count; i++)
	{
		int	local_error;

		local_error = main_test_indiv(test_names[i]);
		error = error || local_error;
	}
	return (error);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (main_not_enough_args());
	else if (argc == 2 && strcmp(argv[1], "all") == 0)
		return (main_test_combo(testCount, (char**)testNames));
	else
		return (main_test_combo(argc - 1, &(argv[1])));
}
