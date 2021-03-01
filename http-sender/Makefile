CC=gcc
CFLAGS= -lcurl -lm -I. -DBBBW -DSHELLPRINT -DHTTP
DEPS = core/beaglebonebw/basics.h core/beaglebonebw/sensors/internal/internal.h core/beaglebonebw/protocols/http/http.h
OBJ = core/beaglebonebw/basics.o core/beaglebonebw/sensors/internal/internal.o core/beaglebonebw/protocols/http/http.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

BeagleboneBW: $(OBJ)
	@echo "\nCompiling..."
	$(CC) -o $@ $^ $(CFLAGS) 
	@echo "\nCompiled Finished, now you can run your code with: '$ ./BeagleboneBW-HTTP'\n"
	@$ find . -name "*.o" -type f -delete

help:
	@echo "\n'make' to compile"
	@echo "'make clean' to delete .o files\n"

.PHONY: clean
clean:
	@$ find . -name "*.o" -type f -delete
