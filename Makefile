# Project
NAME        := matrix

# Compiler & Flags
CXX         := g++
CXXFLAGS    := -std=c++17 -O3 -Wall -Wextra -Werror
LDFLAGS     := -lglfw

# Directories and file
SRCDIR      := src
OBJDIR      := .obj
INCDIRS     := src src/vectors src/matrix src/test src/utils
TEST_FILE   := maft_test

# Source files
SRCFILES    := main.cpp
SRC         := $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJ         := $(addprefix $(OBJDIR)/, $(SRCFILES:.cpp=.o))
DEPS        := $(OBJ:.o=.d)

# Include flags
INCFLAGS    := $(addprefix -I, $(INCDIRS))

# Colors
GREEN       := \033[32m
GRAY        := \033[2;37m
YELLOW      := \033[1;33m
RESET       := \033[0m

MAKEFLAGS  += --no-print-directory

.PHONY: all clean fclean re run leaks

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GRAY)[Linking] $(NAME)$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCFLAGS) $^ -o $@
	@echo "$(GREEN)✓ Build successful$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)[Compiling] $<$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCFLAGS) -MMD -MP -c $< -o $@

run: $(NAME)
	@./$(NAME)

test:
	@./$(NAME) > $(TEST_FILE)

leaks: $(NAME)
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@rm -rf $(OBJDIR)
	@echo "$(GRAY)✗ Object files cleaned$(RESET)"

fclean: clean
	@rm -f  $(TEST_FILE)
	@rm -f $(NAME)
	@echo "$(GRAY)✗ Binary cleaned$(RESET)"

re: fclean all

-include $(DEPS)
