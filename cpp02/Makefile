G++ = g++
Flags = -Wall -Wextra -Werror -std=c++98

# Exercise targets
EX00 = cpp02_ex00
EX01 = cpp02_ex01
EX02 = cpp02_ex02
EX03 = cpp02_ex03

# All exercises
EXERCISES = $(EX00) $(EX01) $(EX02)

# Source files for each exercise
EX00_SRCS = ex00/main.cpp ex00/Fixed.cpp
EX01_SRCS = ex01/main.cpp ex01/Fixed.cpp
EX02_SRCS = ex02/main.cpp ex02/Fixed.cpp
EX03_SRCS = ex03/main.cpp ex03/Fixed.cpp ex03/Point.cpp ex03/bsp.cpp

# Object files
OBJDIR = .obj
EX00_OBJS = $(EX00_SRCS:%.cpp=$(OBJDIR)/%.o)
EX01_OBJS = $(EX01_SRCS:%.cpp=$(OBJDIR)/%.o)
EX02_OBJS = $(EX02_SRCS:%.cpp=$(OBJDIR)/%.o)
EX03_OBJS = $(EX03_SRCS:%.cpp=$(OBJDIR)/%.o)

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

.PHONY: all clean fclean re ex00 ex01 ex02 ex03
