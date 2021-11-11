CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_advancedClassificationLoop=advancedClassificationLoop.o
OBJECTS_advancedClassificationRecursion=advancedClassificationRecursion.o
OBJECTS_basicClassification=basicClassification.o
FLAGS= -Wall -g

all: libclassrec.so libclassloops.so libclassrec.a libclassloops.a mains maindloop maindrec

mains: $(OBJECTS_MAIN) libclassrec.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a

maindloop: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so

maindrec:$(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so

loops: libclassloops.a
libclassloops.a: $(OBJECTS_advancedClassificationLoop) $(OBJECTS_basicClassification)
	$(AR) -rcs libclassloops.a $(OBJECTS_advancedClassificationLoop) $(OBJECTS_basicClassification)	

recursives: libclassrec.a
libclassrec.a: $(OBJECTS_advancedClassificationRecursion) $(OBJECTS_basicClassification)
	$(AR) -rcs libclassrec.a $(OBJECTS_advancedClassificationRecursion) $(OBJECTS_basicClassification)	

recursived: libclassrec.so
libclassrec.so: $(OBJECTS_advancedClassificationRecursion) $(OBJECTS_basicClassification)
	$(CC) -shared -o libclassrec.so $(OBJECTS_advancedClassificationRecursion) $(OBJECTS_basicClassification)

loopd: libclassloops.so
libclassloops.so: $(OBJECTS_advancedClassificationLoop) $(OBJECTS_basicClassification)
	$(CC) -shared -o libclassloops.so $(OBJECTS_advancedClassificationLoop) $(OBJECTS_basicClassification)



advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c
main.o: main.c NumClass.h  
	$(CC) $(FLAGS) -c main.c 



.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec
