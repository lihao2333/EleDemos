SRCS = $(wildcard *.c src/*.c)    #wildcard把 指定目录 ./ 和 ../lib 下的所有后缀是c的文件全部展开。

OBJS = $(SRCS:.c = .o)    #OBJS将$(SRCS)下的.c文件转化为.o文件

CC = msp430-gcc   #代表所使用的编译器

INCLUDES = -Isrc    #头文件查找路径

#LIBS = -L../lib \   #链接库查找地址

#CCFLAGS = -g -Wall -O0   #附加参数
CCFLAGS = -Os -mmcu=msp430g2553

OUTPUT = output.elf   #输出程序名称

all:$(OUTPUT)

$(OUTPUT) : $(SRCS)
	$(CC) $^ -o $@ $(INCLUDES) $(CCFLAGS)
clean:
	rm *.elf
