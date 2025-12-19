G++ = g++
Flags = -Wall -Wextra -Werror -std=c++98

# Exercise targets
EX00 = cpp01_ex00
EX01 = cpp01_ex01
EX02 = cpp01_ex02
EX03 = cpp01_ex03
EX04 = cpp01_ex04
EX05 = cpp01_ex05

# All exercises
EXERCISES = $(EX00) $(EX01) $(EX02) $(EX03) $(EX04) $(EX05) $(EX06)

# Source files for each exercise
EX00_SRCS = ex00/main.cpp ex00/Zombie.cpp ex00/randomChump.cpp ex00/newZombie.cpp
EX01_SRCS = ex01/main.cpp ex01/Zombie.cpp ex01/zombieHorde.cpp
EX02_SRCS = ex02/main.cpp
EX03_SRCS = ex03/main.cpp ex03/HumanA.cpp ex03/HumanB.cpp ex03/Weapon.cpp
EX04_SRCS = ex04/main.cpp ex04/Replace.cpp
EX05_SRCS = ex05/main.cpp ex05/Harl.cpp

# Object files
OBJDIR = obj
EX00_OBJS = $(EX00_SRCS:%.cpp=$(OBJDIR)/%.o)
EX01_OBJS = $(EX01_SRCS:%.cpp=$(OBJDIR)/%.o)
EX02_OBJS = $(EX02_SRCS:%.cpp=$(OBJDIR)/%.o)
EX03_OBJS = $(EX03_SRCS:%.cpp=$(OBJDIR)/%.o)
EX04_OBJS = $(EX04_SRCS:%.cpp=$(OBJDIR)/%.o)
EX05_OBJS = $(EX05_SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(EXERCISES)

$(EX00): $(EX00_OBJS)
	@$(G++) $(Flags) $(EX00_OBJS) -o $(EX00)
	@echo "✓ Built $(EX00)"

$(EX01): $(EX01_OBJS)
	@$(G++) $(Flags) $(EX01_OBJS) -o $(EX01)
	@echo "✓ Built $(EX01)"

$(EX02): $(EX02_OBJS)
	@$(G++) $(Flags) $(EX02_OBJS) -o $(EX02)
	@echo "✓ Built $(EX02)"

$(EX03): $(EX03_OBJS)
	@$(G++) $(Flags) $(EX03_OBJS) -o $(EX03)
	@echo "✓ Built $(EX03)"

$(EX04): $(EX04_OBJS)
	@$(G++) $(Flags) $(EX04_OBJS) -o $(EX04)
	@echo "✓ Built $(EX04)"

$(EX05): $(EX05_OBJS)
	@$(G++) $(Flags) $(EX05_OBJS) -o $(EX05)
	@echo "✓ Built $(EX05)"

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
ex02: $(EX02)
ex03: $(EX03)
ex04: $(EX04)
ex05: $(EX05)

.PHONY: all clean fclean re ex00 ex01 ex02 ex03 ex04 ex05
