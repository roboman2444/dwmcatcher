CC = gcc
LDFLAGS =
CFLAGS = -Wall -Ofast -fstrict-aliasing -march=native
OBJECTS = dwmcatcher.o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

dwmcatcher: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
clean:
	@echo cleaning oop
	@rm -f $(OBJECTS)
purge:
	@echo purging oop
	@rm -f $(OBJECTS)
	@rm -f dwmcatcher

#install part of makefile uses dwm's makefile as a reference
install: dwmcatcher
	@cp -f dwmcatcher /usr/bin
	@chmod 755 dwmcatcher /usr/bin/dwmcatcher
