all :
	gcc -o build/cink src/cink.c -lpthread
clean:
	rm build/*
