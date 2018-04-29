CC = g++ 
CFLAGS = -std=c++11
DEPS = board.h card.h direRabbit.h dragon.h evilEye.h goblin.h golem.h hobgoblin.h magicSword.h wargWolf.h wizard.h wraith.h
OBJ = main.o board.o card.o direRabbit.o dragon.o evilEye.o goblin.o golem.o hobgoblin.o magicSword.o wargWolf.o wizard.o wraith.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)

Hearthstone_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o Hearthstone_test
	
