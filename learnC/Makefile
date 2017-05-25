all: subdir1
	gcc cstrcpy.c -o cstrcpy	
	gcc misteryC.c -o misteryC
	gcc getopt_long.c -o getopt_long 
	gcc linuxCSkill.c -o linuxCSkill 
	gcc mmapread.c -o mmapread 
	gcc mmapwrite.c -o mmapwrite 
	gcc -lpthread pthread.c -o pthread 
	gcc -lpthread threadCleanUp.c -o threadCleanUp 
	gcc -lpthread threadProducerConsumer.c -o threadProducerConsumer 
	gcc -lpthread threadProducerConsumer2.c -o threadProducerConsumer2 
	gcc -lpthread threadSpecDat.c -o threadSpecDat
subdir1:
	make -C semaphore 
	make -C pipe 
	make -C msgqueue 
	make -C signal
subdir2:
	make clean -C semaphore 
	make clean -C pipe 
	make clean -C msgqueue 
	make clean -C signal
.phony:clean
clean:subdir2
	-rm cstrcpy misteryC getopt_long linuxCSkill mmapread mmapwrite 
	-rm pthread threadCleanUp threadProducerConsumer threadProducerConsumer2 threadSpecDat
