NAME_CLIENT			=	client
NAME_SERVER			=	server

NAME_CLIENT_BONUS	=	client_bonus
NAME_SERVER_BONUS	=	server_bonus

include config/srcs.mk
SRC_PATH			=	srcs/
DIR_BUILD			=	.build/

OBJS_CLIENT			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS_CLIENT))
OBJS_SERVER			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS_SERVER))

OBJS_CLIENT_BONUS	=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS_CLIENT_BONUS))
OBJS_SERVER_BONUS	=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS_SERVER_BONUS))

OBJS				= $(OBJS_CLIENT) \
						$(OBJS_SERVER)

OBJS_BONUS			= $(OBJS_CLIENT_BONUS) \
						$(OBJS_SERVER_BONUS)


DEPS_CLIENT			=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS_CLIENT))
DEPS_SERVER			=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS_SERVER))

DEPS				= $(DEPS_CLIENT) \
						$(DEPS_SERVER)


DEPS_FLAGS			=	-MMD -MP
BASE_CFLAGS			=	-Wall -Werror -Wextra -O2 -pipe
BASE_DEBUG_CFLAGS	=	-g3
DEBUG_CLFAGS		=	$(BASE_DEBUG_CFLAGS) #-fsanitize=address
# DEBUG_CLFAGS		=	$(BASE_DEBUG_CFLAGS) -fsanitize=memory -fsanitize-memory-track-origins
FLAGS				=	$(BASE_CFLAGS)
RM					=	rm -rf
AR					=	ar rcs
CC					=	cc

FTPRINTF_PATH		=	ft_printf/
FTPRINTF_INCLUDES	=	$(FTPRINTF_PATH)
FTPRINTF_L			=	$(FTPRINTF_PATH)/libftprintf.a
FTPRINTF_A			=	$(FTPRINTF_PATH)libftprintf.a
MAKE_FTPRINTF		=	$(MAKE) -C $(FTPRINTF_PATH)

DIR_INCS =\
	includes/			\
	$(FTPRINTF_INCLUDES)

INCLUDES =\
	$(addprefix -I , $(DIR_INCS))

LIBS =\
	$(FTPRINTF_L)

DEPENDENCIES =\
	$(FTPRINTF_A)

.PHONY:		all
all:
			$(MAKE_FTPRINTF)
			$(MAKE) $(NAME_CLIENT)
			$(MAKE) $(NAME_SERVER)

.PHONY:		bonus
bonus:
			$(MAKE_FTPRINTF)
			$(MAKE) $(NAME_CLIENT_BONUS)
			$(MAKE) $(NAME_SERVER_BONUS)

$(NAME_CLIENT):	$(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS_CLIENT) $(LIBS) -o $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS):	$(OBJS_BONUS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS_CLIENT_BONUS) $(LIBS) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS):	$(OBJS_BONUS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS_SERVER_BONUS) $(LIBS) -o $(NAME_SERVER_BONUS)

.PHONY:	clean
clean:
			$(MAKE_FTPRINTF) fclean
			$(RM) $(DIR_BUILD)

.PHONY:	fclean
fclean:	clean
			$(RM) $(NAME_CLIENT)
			$(RM) $(NAME_SERVER)
			$(RM) $(NAME_CLIENT_BONUS)
			$(RM) $(NAME_SERVER_BONUS)

.PHONY:	debug
debug:
			$(MAKE) -j FLAGS="$(DEBUG_CLFAGS)"

.PHONY:	re
re:		fclean
			$(MAKE) all

-include $(DEPS)
$(DIR_BUILD)%.o : $(SRC_PATH)%.c
			@mkdir -p $(shell dirname $@)
			$(CC) $(FLAGS) $(DEPS_FLAGS) $(INCLUDES) -c $< -o $@
