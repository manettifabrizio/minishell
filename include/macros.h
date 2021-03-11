/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:16:41 by fmanetti          #+#    #+#             */
/*   Updated: 2021/03/11 14:24:22 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define CURSOR_UP			"\e[A"
# define CURSOR_DOWN		"\e[B"
# define CURSOR_LEFT		"\e[D"
# define CURSOR_RIGHT		"\e[C"
# define CLEAR_LINES		"\e[0J"

# define SEPARATOR			31

# define CTRL_C				3
# define CTRL_D				4
# define CTRL_Z				26
# define ESCAPE				27
# define CTRL_BSLASH		28
# define DELETE				51
# define ARR_UP				65
# define ARR_DOWN			66
# define ARR_RIGHT			67
# define ARR_LEFT			68
# define END				70
# define HOME				72
# define BACKSPACE			127

# define ERROR				"\e[0;31merror\e[0m"
# define ERRNO				0
# define NO_ERRNO			1
# define READING			0
# define NO_READING			1
# define BREAK				0
# define NO_BREAK			1

#endif
