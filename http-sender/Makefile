CC=gcc
CFLAGS= -lcurl -lm -I. -DRASPI -DSHELLPRINT -DHTTP
DEPS = core/raspi3-4/basics.h core/raspi3-4/protocols/http/http.h
OBJ = core/raspi3-4/basics.o core/raspi3-4/protocols/http/http.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Raspi-HTTP: $(OBJ)
	@echo "\nCompiling..."
	$(CC) -o $@ $^ $(CFLAGS) 
	@echo "\nCompiled Finished, now you can run your code with: '$ ./Raspi-HTTP'\n"
	@$ find . -name "*.o" -type f -delete

help:
	@echo "\n'make' to compile"
	@echo "'make clean' to delete .o files\n"

.PHONY: clean
clean:
	@$ find . -name "*.o" -type f -delete
