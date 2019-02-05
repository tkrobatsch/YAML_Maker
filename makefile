CC = g++
CFLAGS = -g -Wall
OBJFILES = MakeYAML.o yaml_data.o
TARGET = yaml_data

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
