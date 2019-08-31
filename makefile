CC = gcc

TARGET = spellChkr

LIBS = -lm

SRCDIR = src
OBJDIR = obj

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

$(TARGET): $(OBJS) 
	@echo  "\033[31m \nMaking executable\033[0m"
	$(CC) $(OBJDIR)/main.o $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo  "\033[31m \nCompiling $<: \033[0m"
	$(CC) -c $< -o $@

clean:
	@echo "\033[31mCleaning obj directory...\033[0m"
	@rm $(TARGET) -f $(OBJDIR)/*.o $(OBJDIR)/*.d

rebuild: clean $(TARGET)

