LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		sources/treatment.c \
		sources/treatment_char.c \
		sources/flags.c \
		sources/is_in_.c \
		sources/treatment_width.c \
		sources/treatment_string.c \
		sources/putstr.c \
		sources/treatment_int.c \
		sources/treatment_hex.c \
		sources/treatment_uint.c \
		sources/putnbr_base.c \
		sources/uitoa.c \
		sources/treatment_pointer.c \
		sources/treatment_percent.c \

SURPL_O = 	treatment.o \
			treatment_char.o \
			flags.o \
			is_in_.o \
			treatment_width.o \
			treatment_string.o \
			putstr.o \
			treatment_int.o \
			treatment_hex.o \
			treatment_uint.o \
			putnbr_base.o \
			uitoa.o \
			treatment_pointer.o \
			treatment_percent.o \

CC = @gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(MAKE) bonus -C ./libft
	@cp libft/libft.a $(NAME)
	@$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	@ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	@$(MAKE) clean -C ./libft
	@rm -rf $(SURPL_O)
	@rm -rf $(OBJS)

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re : fclean all
