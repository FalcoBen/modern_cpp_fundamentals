CXX = c++
CXXFLAGS =  
SRCS = main.cpp Bureaucrat.cpp AForm.cpp RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp ShrubberyCreationForm.cpp
NAME = AForm
OBJS = $(SRCS:.cpp=.o) 
all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re 