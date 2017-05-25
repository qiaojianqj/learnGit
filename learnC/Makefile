all:
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
.phony:clean
clean:
	-rm cstrcpy misteryC getopt_long linuxCSkill mmapread mmapwrite 
	-rm pthread threadCleanUp threadProducerConsumer threadProducerConsumer2 threadSpecDat
