SRC =		src/malloc.c \
			src/free.c \
			src/calloc.c \
			src/realloc.c \
			src/reallocarray.c \

CXX =		gcc

INC = 		-I ./include/

CFLAGS =	-fpic -Wall -Wextra

NAME =		libmy_malloc.so

OBJ =		$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(INC) -shared -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) *.o* vgcore*

re: fclean all
