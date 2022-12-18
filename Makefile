####### MAKEFILE #######

### Variables

SRCS_PATH		=	./srcs/
OBJS_PATH		=	./objs/
HEAD_PATH		=	./srcs/vector/

FILES			=	tests_vector.cpp
HEAD_FILES		=	vector.hpp

SRCS			=	${addprefix ${SRCS_PATH}, ${FILES}}
OBJS			=	${addprefix ${OBJS_PATH}, ${FILES:.cpp=.o}}
DEPS			=	${addprefix ${OBJS_PATH}, ${FILES:.cpp=.d}}
HEAD			=	${addprefix ${HEAD_PATH}, ${HEAD_FILES}}

NAME			=	ft_containers

CLEAR			=	clear
CC				=	clang++
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -std=c++98


### Commandes

all:			${NAME}
				${CLEAR} && ./${NAME}

${NAME}:		${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJS_PATH}%.o:	${SRCS_PATH}%.cpp
				mkdir -p ${dir $@}
				${CC} -c ${CFLAGS} -MMD -MP -I${HEAD_PATH} $< -o $@

clean:
				${RM} ${OBJS_PATH}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

-include : ${DEPS}

.PHONY:			all clean fclean re
