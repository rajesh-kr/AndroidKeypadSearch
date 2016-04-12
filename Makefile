CC := g++ 
SRCDIR := src
BUILDDIR := build
TESTDIR := test
TARGET := bin/runner
TESTER := bin/tester

CFLAGS := -g -Wall
LIB :=
INC := -I include

tester:
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILDDIR)/char_to_digit.o $(SRCDIR)/char_to_digit.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILDDIR)/contact.o $(SRCDIR)/contact.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILDDIR)/trie.o $(SRCDIR)/trie.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILDDIR)/trie_node.o $(SRCDIR)/trie_node.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILDDIR)/tester.o $(TESTDIR)/tester.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILDDIR)/test_char_to_digit.o $(TESTDIR)/test_char_to_digit.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $(BUILDDIR)/test_trie.o $(TESTDIR)/test_trie.cpp
	$(CC) $(BUILDDIR)/char_to_digit.o $(BUILDDIR)/contact.o $(BUILDDIR)/trie.o $(BUILDDIR)/trie_node.o $(BUILDDIR)/test_char_to_digit.o $(BUILDDIR)/tester.o $(BUILDDIR)/test_trie.o -o $(TESTER) $(LIB)

clean:
	@echo "Cleaning..."
	$(RM) -r $(BUILDDIR) $(TARGET) $(TESTER)

.PHONY: clean
