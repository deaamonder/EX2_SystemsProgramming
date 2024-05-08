#COMPILER
CC = gcc

#Compiler Flags
CF = -Wall

#Source Files
SOURCE = my_graph.c 
SOURCE2 = my_mat.c 
SOURCE3 = my_Knapsack.c 

#Header File
HEADER = my_mat.h 

#Object Files
OBJECT = my_graph.o 
OBJECT2 = my_mat.o 
OBJECT3 = my_Knapsack.o 

#Targets
TARGET1 = mains

loops : $(OBJECT2) $(OBJECT3)
	ar rcs libclassloops.a $(OBJECT2) $(OBJECT3)

loopd : $(OBJECT2) $(OBJECT3)
	$(CC) -shared -o libclassloops.so $(OBJECT2) $(OBJECT3)

$(TARGET1) : libclassloops.a $(HEADER) $(SOURCE) $(SOURCE2) $(SOURCE3)
	$(CC) $(CF) -o mains $(SOURCE) $(SOURCE2) $(SOURCE3) -L. -lclassloops -lm

maindloop : libclassloops.so $(HEADER) $(SOURCE) $(SOURCE2) $(SOURCE3)
	$(CC) $(CF) -o maindloop $(SOURCE) $(SOURCE2) $(SOURCE3) -L. -lclassloops -lm

all : mains

.PHONY: all clean

clean:
	rm -f libclassloops.a libclassloops.so $(OBJECT) $(OBJECT2) $(OBJECT3) $(TARGET1)