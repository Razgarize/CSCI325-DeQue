CC = g++
CFLAGS = -g -Wall -Wextra
TARGET = deque
BONUS = bonus

default: BONUS


# Bonus
BONUS: main_bonus.o
	$(RM) $(BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) main_bonus.o
	$(RM) *.o

main_bonus.o: main_bonus.cpp
	$(CC) $(CFLAGS) -c main_bonus.cpp

# Standard
TARGET: main.o deque.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o deque.o
	$(RM) *.o

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) -c deque.cpp

clean:
	$(RM) $(TARGET) *.o *~ *# $(BONUS) 