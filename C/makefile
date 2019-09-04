CC = gcc

TARGET = spellChkr

LIBS = -lm

SRCDIR = src/spellChecker.c

CFLAGS = -g

$(TARGET): $(OBJS) 
	@echo  "\033[31mAssembling executable...\033[0m"
	$(CC) $(CFLAGS) $(SRCDIR) $(LIBS) -o $@

clean:
	@echo "\033[31mCleaning up...\033[0m"
	@rm $(TARGET)

rebuild: clean $(TARGET)

