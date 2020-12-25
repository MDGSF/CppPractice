# CC = qcc -V 5.4.0,gcc_ntoaarch64le
CC = qcc -V 5.4.0,gcc_ntox86_64


#add your CFLAGS, LDFLAGS and LIBS here
CFLAGS += -DBUILD_DATE="\"$(BUILD_DATE)\"" -Wall -Wextra -O2 -Iinc
LDFLAGS += -lm -Llibs 
LIBS += 
TARGET = helloworld

DIRS = src  .
FILES = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c, %.o, $(FILES))


$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(LDFLAGS) $(LIBS) $(OBJS)

all:$(TARGET)
	

clean:
	-$(RM) $(TARGET)
	-$(RM) $(OBJS)
