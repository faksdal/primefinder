#
#
#	Makefile
#	
#	target: prerequisites prerequisites ...
#		<tab>command
#		<tab>command
#
#	$@	=	target name
#	$?	=	all prerequisites newer than target
#	$<	=	first prerequisites
#	$^	=	all prerequisites
#
#	The @ in front of the echo command, prevents the actual command from being printed to screen
#
#	$(patsubst PATTERN,REPLACEMENT,TEXT)
####################################################################################################


#$(TARGET): $(OBJFILES)
#	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJFILES)

#$(OBJDIR)/%.o: $(SRCDIR)/%.cpp	
#	$(CXX) $(CPPFLAGS) -c -o $@ $^
TARGET=raw
CC=g++
CFLAGS=-I.

$(TARGET): primefinder.o	
	$(CC) $(CFLAGS) -o $(TARGET) primefinder.cpp

clean:
	rm *.o
	rm $(TARGET)

