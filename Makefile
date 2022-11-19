# VARIABLES

NAME		= miniRT
#NAME_BONUS	= pipex_bonus

LIB_DIR	 	= libft
LIB			= libft/libft.a

SRC_DIR		= 	src/
OBJ_DIR		= 	obj/
SUBDIR		=	obj/class \
				obj/utils \
				obj/render\
				obj/objects\
#BONUS_DIR	= src_bonus/

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -I./srcs/includes -Imlx_linux -MMD -MP
ADDFLAGS	=  #-L -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM			= rm -rf
AR			= ar rcs
SAN			= -fsanitize=address

# SOURCES

SRC_FILES = 	main \
				class/vector_class \
				class/vector_utility \
				class/vector_utility2 \
				class/ray_class \
				class/cam_class \
				objects/hittable_list \
				objects/init_objects \
				objects/loop_objects \
				objects/lexeur \
				objects/lexeur_object \
				#render/render_loop \
				#render/object_renderer \
				#render/display \
				#render/render_sphere \
				#utils/mlx_fonction \
				#utils/move \


C_FILES		=	$(addsuffix .c, $(SRC_FILES))
SRCS		=	$(addprefix $(SRC_DIR), $(C_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))
DEPS		=	$(OBJS:.o=.d)

#SRC_FILES_BONUS	=	main child pipes get_files get_cmd free heredoc error
C_BONUS			=	$(addsuffix _bonus.c, $(SRC_FILES_BONUS))
SRCS_BONUS		=	$(addprefix $(BONUS_DIR), $(C_BONUS))
OBJS_BONUS		=	$(addprefix $(OBJ_DIR), $(C_BONUS:.c=.o))
DEPS_BONUS		=	$(OBJS_BONUS:.o=.d)

#	LOAD BAR

COUNT	:= $(words $(SRC_FILES))
LOAD	= 0
DIVIDE	= 0
SPACE = $(COUNT)

#	 MANDATORY
all:		 $(LIB) obj $(NAME)
			

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $^ -o $@ $(LIB) $(ADDFLAGS) 
			@echo "\e[1A\e[K$(FONT_BOLD)FILES LOAD ! $(FONT_RESET)    $(COUNT)/($(COUNT))"
			@echo " " 
			@echo "$(RED)$(NAME) compiled !$(DEF_COLOR)"

$(OBJ_DIR)%.o:	 $(SRC_DIR)%.c 
			@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $< 
			@$(eval LOAD=$(shell echo $$(($(LOAD)+1))))
			@$(eval SPACE=$(shell echo $$(($(SPACE)-1)))) 
			@echo "\e[2A\e[K$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"
			@/bin/echo -n "$(FONT_BOLD)Load Files |$(FONT_RESET)" 
			@load=$(LOAD) ; while [ $${load} -gt 0 ] ; do\
				/bin/echo -n "=" ;\
				load=`expr $$load - 1`; \
			done; \
			true
			@space=$(SPACE) ; while [ $${space} -gt 0 ] ; do\
				/bin/echo -n " " ;\
				space=`expr $$space - 1`; \
			done; \
			true
			@/bin/echo -n "$(FONT_BOLD)|$(FONT_RESET)"
			@echo "    $(RED)$(LOAD)/($(COUNT))"

#	BONUS
bonus:		obj $(LIB) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
			@$(CC) $(CFLAGS) $(ADDFLAGS) $^ -o $(NAME_BONUS) $(LIB)
			@echo "$(RED)$(NAME_BONUS) BONUS compiled !$(CYAN)"

$(OBJ_DIR)%.o:	 $(BONUS_DIR)%.c 
			@$(CC) $(CFLAGS) -c -o $@ $< 
			@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

$(LIB):
			@echo "$(MAGENTA)Creating libft files...$(CYAN)"
			@echo " "
			@echo " "
			@echo " "
			@make --no-print-directory -s -C ./libft

#	 RULES
obj:
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(SUBDIR)

clean:
			@make --no-print-directory clean -C $(LIB_DIR)
			@$(RM) $(OBJ_DIR) $(DEPS_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME_BONUS)
			@$(RM) -f $(LIB_DIR)/libft.a

re:			fclean
			@make --no-print-directory all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

.PHONY: all clean fclean re	

.SILENT: lib

-include $(DEPS)

# COLORS

NOC = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
FONT_BOLD := $(shell tput bold)
FONT_RED := $(shell tput setaf 1)
FONT_RESET := $(shell tput sgr0)
FONT_CYAN := $(shell tput setaf 6)
