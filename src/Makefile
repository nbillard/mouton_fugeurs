##
# Mouton fugeurs
#
# @file
# @version 0.1

CC = g++
CFLAGS = -Wall
TARGET = main
OBJS = obj/$(TARGET).o obj/link.o obj/math.o
COMPILE = $(CC) -c $(CFLAGS) $<

.PHONY: clear run

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o debug/$@

obj/$(TARGET).o: $(TARGET).cpp $(OBJS)
	$(COMPILE) -o $@

obj/%.o: lib/%.cpp
	$(COMPILE) -o $@

clear:
	rm obj/*.o debug/$(TARGET)

run:
	./debug/$(TARGET)

# end
