CC = g++ 
CFLAGS = -std=c++11
DEPS = board.h card.h goblin.h 
OBJ = main.o board.o card.o goblin.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)

Hearthstone_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o Hearthstone_test
	
