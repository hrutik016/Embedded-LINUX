# which compiler 

CC= gcc

# compiler flags 
CFLAGS= -c -g -O2

# include files
INCLUDE = -I.

#where to install
INSTALL_PATH= /usr/bin

#name of application
TAR_NAME= program

#path of source files
SRC_DIR=.

#path to current directory 
CUR_DIR=.

#target=main.o (creating the application)
program: main.o pr.o add.o
	$(CC) ${SRC_DIR}/main.o ${SRC_DIR}/pr.o ${SRC_DIR}/add.o -o ${TAR_NAME}
	@echo "Application created successfully"

main.o: main.c
	$(CC) ${INCLUDE} $(CFLAGS) $(SRC_DIR)/main.c
	@echo "Relocation main.o generated"

pr.o: pr.c
	$(CC) ${INCLUDE} $(CFLAGS) $(SRC_DIR)/pr.c
	@echo "Relocation pr.o generated"

add.o: add.c
	$(CC) ${INCLUDE} $(CFLAGS) $(SRC_DIR)/add.c
	@echo "Relocation add.o generated"

install: $(TAR_NAME)
	cp -f $(CUR_DIR)/$(TAR_NAME) $(INSTALL_PATH)/$(TAR_NAME)
	@echo "Application Installed Successfully at $(INSTALL_PATH)"

clean:
	rm -f $(CUR_DIR)/*.o $(CUR_DIR)/$(TAR_NAME) $(INSTALL_PATH)/$(TAR_NAME)
	@wcho "Application removed successfully"


