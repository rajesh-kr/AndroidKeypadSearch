# TODO
CC:=g++ 
SRCDIR:=src
BUILDDIR:=build
TARGET:=

SRCEXT:=cpp
SOURCES:=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS:=
CFLAGS := -g # -Wall
LIB:=
INC:= -I include

.PHONY: clean

clean:
	@echo "Cleaning..."
	$(RM) -r $(BUILDDIR) $(TARGET)
