#Tyler Forrester
#MakeFile Lab Fa
#7/27/2016

CXX = g++
OBJSSUM = queue.o
SRCSSUM = queue.cpp
OBJSAVG = Stack.o
SRCSAVG = Stack.cpp
OBJSL1 = InputValid.o
SRCSL1 = InputValid.cpp
OBJSL2 = main1.o
SRCSL2 = main1.cpp
HEADERS = Queue.hpp
HEADERA = Stack.hpp
HEADERI = InputValid.hpp
HEADERN = Node.hpp
PROG = LabFa
all: $(PROG)

$(PROG): $(OBJSL2) $(OBJSL1) $(OBJSAVG) $(OBJSSUM) $(HEADERI) $(HEADERA) $(HEADERN) $(HEADERS) 
	$(CXX) $(OBJSL2) $(OBJSL1) $(OBJSAVG) $(OBJSSUM) -o $(PROG)
$(OBJSL2): $(SRCSL2) $(HEADERI) 
	$(CXX) -c $(SRCSL2)
$(OBJSAVG): $(SCRSAVG) $(HEADERA) $(HEADERN)
	$(CXX) -c $(SRCSAVG)
$(OBJSL1): $(SRCSL1) $(HEADERI)
	$(CXX) -c $(SRCSL1)
$(OBJSSUM): $(SRCSSUM) $(HEADERS) $(HEADERN)
	$(CXX) -c $(SRCSSUM)
clean:
	rm -rf *.o $(PROG) 
