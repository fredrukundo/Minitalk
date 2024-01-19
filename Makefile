GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m

LIBFT = ft_libft/libft.a
PRINTF = ft_printf/libftprintf.a

CC = cc
CCFLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) minitalk.h
	@echo "$(YELLOW)Building $(SERVER)$(NC)"
	@$(CC) $(CCFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER)
	@echo "$(GREEN)$(SERVER) built successfully$(NC)"

$(CLIENT): $(OBJS_CLIENT) minitalk.h
	@echo "$(YELLOW)Building $(CLIENT)$(NC)"
	@$(CC) $(CCFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT)
	@echo "$(GREEN)$(CLIENT) built successfully$(NC)"

$(SERVER_BONUS): $(OBJS_SERVER_BONUS) minitalk_bonus.h
	@echo "$(YELLOW)Building $(SERVER_BONUS)$(NC)"
	@$(CC) $(CCFLAGS) $(OBJS_SERVER_BONUS) $(LIBFT) $(PRINTF) -o $(SERVER_BONUS)
	@echo "$(GREEN)$(SERVER_BONUS) built successfully$(NC)"

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS) minitalk_bonus.h
	@echo "$(YELLOW)Building $(CLIENT_BONUS)$(NC)"
	@$(CC) $(CCFLAGS) $(OBJS_CLIENT_BONUS) $(LIBFT) $(PRINTF) -o $(CLIENT_BONUS)
	@echo "$(GREEN)$(CLIENT_BONUS) built successfully$(NC)"

$(LIBFT):
	@echo "$(YELLOW)Building libft$(NC)"
	@$(MAKE) -C ft_libft
	@echo "$(GREEN)libft built successfully$(NC)"

$(PRINTF):
	@echo "$(YELLOW)Building printf$(NC)"
	@$(MAKE) -C ft_printf
	@echo "$(GREEN)printf built successfully$(NC)"

bonus: $(LIBFT) $(PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)

clean:
	@$(MAKE) clean -C ft_libft
	@$(MAKE) clean -C ft_printf
	@echo "$(YELLOW)Cleaning object files$(NC)"
	@rm -rf $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	@echo "$(GREEN)Object files cleaned successfully$(NC)"

fclean: clean
	@$(MAKE) fclean -C ft_libft
	@$(MAKE) fclean -C ft_printf
	@echo "$(YELLOW)Cleaning binaries$(NC)"
	@rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "$(GREEN)Binaries cleaned successfully$(NC)"

re: fclean all

.PHONY: all clean fclean re
