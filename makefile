CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp functions.cpp homeScreen.cpp correctnessCheckScreen.cpp printFormattedScreen.cpp dayOfWeekScreen.cpp printCalendarScreen.cpp addSubtractScreen.cpp descriptionScreen.cpp durationScreen.cpp easterScreen.cpp advancedModeScreen.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=dates
TESTS=tests.cpp functions.cpp

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

tests: $(TESTS)
	$(CC) $(TESTS) -o $@