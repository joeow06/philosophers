#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all bonus clean fclean re
# .SILENT:

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC			=	gcc
CFLAGS		=	$(INCLUDES) $(TEMP)
TEMP		=	-Wall -Werror -Wextra -pthread
INCLUDES	=	-I$(INC_DIR)
DEBUG		=	-g3
FSAN_ADD	=	-fsanitize=address
FSAN_MEM	=	-fsanitize=memory
FSAN_THREAD	=	-fsanitize=thread
RM			=	rm -rf

# Output file name
NAME	=	philo

# Directories
INC_DIR			=	includes/
SRCS_DIR		=	srcs/
OBJS_DIR		=	bin/


SRCS_FILES		=	$(SRCS_DIR)main.c \
					$(SRCS_DIR)parser.c \
					$(SRCS_DIR)utils.c \
					$(SRCS_DIR)pthread_utils.c \
					$(SRCS_DIR)error_exit.c \
					$(SRCS_DIR)init.c \
					$(SRCS_DIR)simulation.c \
					$(SRCS_DIR)set_get.c \
					$(SRCS_DIR)print.c \
					$(SRCS_DIR)monitor.c

OBJS_FILES		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_FILES))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

bonus: all

# Generates output file
$(NAME): $(OBJS_FILES)
	$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME)

# Rule to compile the object files
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Removes objects
clean:
	$(RM) $(OBJS_DIR)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean $(OBJS_DIR) all
