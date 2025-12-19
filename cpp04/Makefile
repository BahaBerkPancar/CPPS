G++ = g++
Flags = -Wall -Wextra -Werror -std=c++98

# Exercise targets
EX00 = cpp04_ex00
EX01 = cpp04_ex01

# All exercises
EXERCISES = $(EX00) $(EX01)

# Source files for each exercise
EX00_SRCS = ex00/main.cpp ex00/Animal.cpp ex00/Cat.cpp ex00/Dog.cpp
EX01_SRCS = ex01/main.cpp ex01/Animal.cpp ex01/Cat.cpp ex01/Dog.cpp ex01/Brain.cpp

# Object files
OBJDIR = .obj
EX00_OBJS = $(EX00_SRCS:%.cpp=$(OBJDIR)/%.o)
EX01_OBJS = $(EX01_SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(EXERCISES)

$(EX00): $(EX00_OBJS)
	@$(G++) $(Flags) $(EX00_OBJS) -o $(EX00)
	@echo "✓ Built $(EX00)"

$(EX01): $(EX01_OBJS)
	@$(G++) $(Flags) $(EX01_OBJS) -o $(EX01)
	@echo "✓ Built $(EX01)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(G++) $(Flags) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "✓ Cleaned object files"

fclean: clean
	@rm -f $(EXERCISES)
	@echo "✓ Cleaned executables"

re: fclean all

# Individual exercise targets
ex00: $(EX00)
ex01: $(EX01)

.PHONY: all clean fclean re ex00 ex01
