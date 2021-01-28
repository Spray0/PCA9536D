#Spray0 2021-1-27

#目标
TARGET = pca9536
#优化等级
OPT = -Og
#编译器前缀
PREFIX = arm-linux-gnueabihf-
#编译器
CC = $(PREFIX)gcc
#删除命令
RM = rm -rf
#头文件目录
INCLUDES = -I PCA9536/


FLAGS = -pthread  $(INCLUDES) $(OPT) $(THREAD)
OBJECTS =  main.o PCA9536.o


all: obj out
out	:	$(OBJECTS)
	@$(CC)  -o $(TARGET)  $(OBJECTS) $(FLAGS)
obj :
	@$(CC) -c -o main.o main.c 
	@$(CC) -c -o PCA9536.o PCA9536/PCA9536.c 
clean : 
	@$(RM) $(OBJECTS) $(TARGET)