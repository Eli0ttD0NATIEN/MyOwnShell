#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include <Windows.h>


HANDLE stdinHandler; //liens vers stdin
DWORD oldMode;
size_t nbOfChar = 0;

void loopInput() {
	for (;;) {
		readUserInput();
	}
}

int readUserInput(VOID) {
	DWORD nbOfEvRead;
	INPUT_RECORD irInBuff[128]; //Pointer vers le buffer qui va recevoir les input
	char* strArray;
	stdinHandler = GetStdHandle(STD_INPUT_HANDLE);
	if (stdinHandler == INVALID_HANDLE_VALUE) {
		errHandler("GetStdHandle");
	}
	if (!GetConsoleMode(stdinHandler, &oldMode)) {
		errHandler("GetConsoleMode");
	}
	ReadConsoleInput(stdinHandler, irInBuff, 128, &nbOfEvRead);
	strArray = malloc(128 * sizeof(char));
	if (strArray == NULL) {
		errHandler("Malloc");
		free(strArray);
		exit(EXIT_FAILURE);
	}
	eventDispatcher(irInBuff, nbOfEvRead, strArray);
	if (!SetConsoleMode(stdinHandler, oldMode)) {
		errHandler("SetConsoleMode");
		free(strArray);
	}
	return 0;
}

VOID eventDispatcher(INPUT_RECORD* buffer, DWORD nbOfEvent, void* charBuffer) {
	DWORD i = 0;
	for (size_t i = 0; i < nbOfEvent; i++) {
		if (buffer[i].EventType == KEY_EVENT) {
			keyEventProc(buffer[i].Event.KeyEvent, charBuffer);
		}
	}
}

void* keyEventProc(KEY_EVENT_RECORD key, void* charBuffer) {
	char* tempBuffer = (char*)charBuffer;
	if (key.bKeyDown && !isEnterKeyPressed(key)){
		*(tempBuffer + nbOfChar) = key.uChar.AsciiChar;
		printf("%c", *(tempBuffer + nbOfChar));
		nbOfChar++;
	}
	else if(isEnterKeyPressed(key)){
		*(tempBuffer + nbOfChar) = '\0';
		printf("\n");
		for (size_t i = 0; i < nbOfChar; i++) {
			printf("%c", *(tempBuffer + nbOfChar));
		}
		nbOfChar = 0;
		return tempBuffer;
	}
	else {
		free(tempBuffer);
	}
}

int errHandler(LPTSTR err) {
	fprintf(stderr, "%s \n", err);
	SetConsoleMode(stdinHandler, oldMode);
	ExitProcess(0);
}

BOULEAN isEnterKeyPressed(KEY_EVENT_RECORD keyPressed) {
	return (keyPressed.wVirtualKeyCode == ENTER_KEY) ? true : false;
}