CC=gcc
AR=ar
OBJECTS_MAIN=main.o
// OBJECTS_LIB=mylib.o
OBJECTS_advancedClassificationLoop=advancedClassificationLoop.o;
OBJECTS_advancedClassificationRecursion=advancedClassificationRecursion.o;
OBJECTS_basicClassification=basicClassification.o;
FLAGS= -Wall -g

all: libclassrec.so libclassloops.so libclassloops.a libclassrec.a progmains progmaind	
progmains: $(OBJECTS_MAIN) libclassloops.a 
	$(CC) $(FLAGS) -o progmains $(OBJECTS_MAIN) libclassloops.a
progmaind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) ./libclassrec.so


progmains: $(OBJECTS_MAIN) libclassrec.a 
	$(CC) $(FLAGS) -o progmains $(OBJECTS_MAIN) libclassrec.a

progmaind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) ./libclassloops.so
	


libclassrec.so: $(OBJECTS_advancedClassificationRecursion) $(OBJECTS_basicClassification)
	$(CC) -shared -o libclassrec.so $(OBJECTS_advancedClassificationRecursion) $(OBJECTS_basicClassification)
libclassloops.a: $(OBJECTS_advancedClassificationLoop) $(OBJECTS_basicClassification)
	$(AR) -rcs libclassloops.a $(OBJECTS_advancedClassificationLoop) $(OBJECTS_basicClassification)	

libclassloops.so: $(OBJECTS_advancedClassificationRecursion) $(OBJECTS_basicClassification)
	$(CC) -shared -o libclassloops.so $(OBJECTS_advancedClassificationRecursion) $(OBJECTS_basicClassification)

libclassrec.a: $(OBJECTS_advancedClassificationRecursion) $(OBJECTS_basicClassification)
	$(AR) -rcs libclassrec.a $(OBJECTS_advancedClassificationLoop) $(OBJECTS_basicClassification)	





advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c
main.o: main.c mylib.h  
	$(CC) $(FLAGS) -c main.c 



.PHONY: clean all

clean:
	rm -f *.o *.a *.so progmains progmaind
