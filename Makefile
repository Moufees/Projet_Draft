CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS=
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= test.exe



all: $(EXEC)


$(EXEC): $(OBJ)
	echo $(SRC)
	$(CC) $(LIBFLAGS) $^ -o $@

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
	g++ -MM $(SRC) > .depends

-include .depends

test : $(EXEC)
	./$(EXEC)
clean:
	del -f $(OBJ) $(EXEC) *.*~
