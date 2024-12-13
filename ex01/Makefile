CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -g -pedantic -std=c++11 -fsanitize=address
# CPPFLAGS = -Wall -Wextra -Werror -g -pedantic -std=c++11 
SRCS = $(wildcard *.cpp) 
OBJS = $(patsubst %.cpp,obj/%.o,$(SRCS))

TARGET = Serializer

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(TARGET)
	@echo "$(GREEN)Compiled Serializer!$(DEFAULT)"

obj/%.o: %.cpp | obj
	@$(CPP) $(CPPFLAGS) -c $< -o $@

obj:
	@mkdir -p obj

clean:
	@$(RM) -r obj/
	@echo "$(YELLOW)Removed all objects!$(DEFAULT)"

fclean: clean
	@$(RM) $(TARGET)
	@echo "$(RED)Removed Serializer!$(DEFAULT)"

re: fclean all

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
