/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:12:59 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/09 15:37:01 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int	ft_memmove_test(void)
{
	int	failures = 0;

	const char	*strings_const[] = 
	{
		"memmove can be very useful......",
		"1234567890",
	};
	int	offsets[][3] = {
		{ 20, 15, 11 },
		{ 4, 3, 3 },
	};
	size_t	strings_len = (sizeof(strings_const)/sizeof(strings_const[0]));

	for (size_t i = 0; i < strings_len; i++)
	{
		char *string_out = ft_strdup(strings_const[i]);
		if (!string_out)
		{
			log_error("test %zu: could not allocate out string properly.", i);
			failures++;
			continue;
		}
		char *string_exp = ft_strdup(strings_const[i]);
		if (!string_exp)
		{
			free(string_out);
			log_error("test %zu: could not allocate exp string properly.", i);
			failures++;
			continue;
		}
		memmove(
			string_exp + offsets[i][0],
			string_exp + offsets[i][1],
			offsets[i][2]
		);
		ft_memmove(
			string_out + offsets[i][0],
			string_out + offsets[i][1],
			offsets[i][2]
		);
		if (strcmp(string_out, string_exp) != 0)
		{
			log_error(
				"test %zu: user: \"%s\", expected: \"%s\"",
				i, string_out, string_exp
			);
			failures++;
		}
		free(string_out);
		free(string_exp);
	}
	return (failures);
}
