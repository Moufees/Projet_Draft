CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= wculteam.exe



all: $(EXEC)


$(EXEC): $(OBJ)
	echo $(SRC)
	$(CC) $(LIBFLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $< -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

.depends:
	g++ -MM $(SRC) > .depends

-include .depends

test : $(EXEC)
	./$(EXEC)
clean:
	rm -f $(OBJ) $(EXEC) .depends *.*~
