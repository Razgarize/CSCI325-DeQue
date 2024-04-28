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

clean:
	$(RM) $(TARGET) *.o *~ *# $(BONUS) 