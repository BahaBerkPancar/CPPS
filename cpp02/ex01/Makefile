NAME = ex01
G++ = g++
Flags = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp 
OBJDIR = .obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(G++) $(Flags) $(OBJS) -o $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(G++) $(Flags) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
