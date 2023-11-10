# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aindjare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 14:29:00 by aindjare          #+#    #+#              #
#    Updated: 2023/11/04 14:34:48 by aindjare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#/bin/sh

OUTPUT=""

for f in ../../libft/*.c; do
	base_name=$(basename ${f})
	OUTPUT+="$base_name "
done

export SOURCES_LIBFT=$OUTPUT
