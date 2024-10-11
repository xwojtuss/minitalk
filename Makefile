COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -std=gnu99 -fPIC

CLIENT_NAME = client

SERVER_NAME = server

LIBFT_REPO = https://github.com/xwojtuss/Libft.git
LIBFT_NAME = libft.a
LIBFT_DIR = Libft

CLIENT_SRCS = client.c

CLIENT_SRCS_FOLDER = ${addprefix srcs/,${CLIENT_SRCS}}

SERVER_SRCS = server.c

SERVER_SRCS_FOLDER = ${addprefix srcs/,${SERVER_SRCS}}

all: ${CLIENT_NAME} ${SERVER_NAME}

${CLIENT_NAME}: ${LIBFT_DIR}/${LIBFT_NAME} ${CLIENT_SRCS_FOLDER}
	${COMPILER} ${CFLAGS} ${CLIENT_SRCS_FOLDER} -o ${CLIENT_NAME} ${LIBFT_DIR}/${LIBFT_NAME} -I${LIBFT_DIR} -Iincludes

${SERVER_NAME}: ${LIBFT_DIR}/${LIBFT_NAME} ${SERVER_SRCS_FOLDER}
	${COMPILER} ${CFLAGS} ${SERVER_SRCS_FOLDER} -o ${SERVER_NAME} ${LIBFT_DIR}/${LIBFT_NAME} -I${LIBFT_DIR} -Iincludes

${LIBFT_DIR}/${LIBFT_NAME}:
	@if [ ! -d ./${LIBFT_DIR} ]; then \
		git clone ${LIBFT_REPO} ${LIBFT_DIR}; \
		echo "Cloning Libft repository"; \
	fi
	@if [ ! -f ./${LIBFT_DIR}/${LIBFT_NAME} ]; then \
		make -C ${LIBFT_DIR}; \
		echo "Running make for Libft"; \
	fi

clean:
	@if [ -d ./${LIBFT_DIR} ]; then \
		make clean -C ${LIBFT_DIR}; \
	fi

fclean: clean
	rm -f ${CLIENT_NAME} ${SERVER_NAME}
	@if [ -d ./${LIBFT_DIR} ]; then \
		make fclean -C ${LIBFT_DIR}; \
	fi

fullclean: fclean
	rm -rf ${LIBFT_DIR}

re: fclean all

rebuild: fullclean all

.PHONY: all clean fclean fullclean re rebuild 
