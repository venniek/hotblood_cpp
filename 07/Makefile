SRCS = $(wildcard *.cpp)

CPP = c++

NAME = Account

$(NAME): $(SRCS)
	$(CPP) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re