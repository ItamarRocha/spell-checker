CC = gcc

TARGET = spellChkr

LIBS = -lm

SRCDIR = src/main.c

$(TARGET): $(OBJS) 
	@echo  "\033[31mAssembling executable...\033[0m"
	$(CC) $(SRCDIR) $(LIBS) -o $@

clean:
	@echo "\033[31mCleaning up...\033[0m"
	@rm $(TARGET)

rebuild: clean $(TARGET)

