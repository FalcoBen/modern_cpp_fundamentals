CXX = c++
CXXFLAGS =  -g3 -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp AForm.cpp RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp ShrubberyCreationForm.cpp Intern.cpp
NAME = Intern
OBJS = $(SRCS:.cpp=.o) 
all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re 