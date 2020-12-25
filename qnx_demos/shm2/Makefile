# CC = qcc -V 5.4.0,gcc_ntoaarch64le
CC = qcc -V 5.4.0,gcc_ntox86_64
RM = rm

#add your CFLAGS, LDFLAGS and LIBS here
CFLAGS += -DBUILD_DATE="\"$(BUILD_DATE)\"" -Wall -Wextra -O2 -Iinc
LDFLAGS += -lm -Llibs -lc
LIBS += 
TARGET = shm2

DIRS = .
FILES = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c, %.o, $(FILES))

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(LDFLAGS) $(LIBS) $(OBJS)

all:$(TARGET)

clean:
	-$(RM) $(TARGET)
	-$(RM) $(OBJS)
