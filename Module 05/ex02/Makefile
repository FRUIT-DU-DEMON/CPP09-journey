#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 15:44:52 by hlabouit          #+#    #+#              #
#    Updated: 2024/02/16 16:41:52 by hlabouit         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = aform
CPPFILES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
           RobotomyRequestForm.cpp PresidentialPardonForm.cpp
CPPOFILES = $(CPPFILES:%.cpp=%.o)
CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-w -w -w -g c++98

all: $(NAME)

$(NAME) : $(CPPOFILES) Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp
	@$(CPPC) $(CPPOFILES) -o $(NAME)

%.o : %.cpp
	@$(CPPC) $(CPPFLAGS) $< -c

clean:
	@rm -rf $(CPPOFILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re