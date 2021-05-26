#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include <Windows.h>


HANDLE hStdin; //liens vers stdin
DWORD oldMode;
char* strArray;
size_t nbOfChar = 0;

void loopInput() {
	while (1) {
		readUserInput();
	}
}

int readUserInput(VOID) {
	DWORD nbOfEvRead;
	INPUT_RECORD irInBuff[128]; //Pointer vers le buffer qui va recevoir les input
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE) {
		errHandler("GetStdHandle");
	}
	if (!GetConsoleMode(hStdin, &oldMode)) {
		errHandler("GetConsoleMode");
	}
	ReadConsoleInput(hStdin, irInBuff, 128, &nbOfEvRead);
	strArray = malloc(10 * sizeof(char));
	if (strArray == NULL) {
		errHandler("Malloc");
		free(strArray);
	}
	eventDispatcher(irInBuff, nbOfEvRead);
	if (!SetConsoleMode(hStdin, oldMode)) {
		errHandler("SetConsoleMode");
	}
	return 0;
}

VOID eventDispatcher(INPUT_RECORD* buffer, DWORD nbOfEvent) {
	DWORD i = 0;
	while (i < nbOfEvent) {
		if (buffer[i].EventType == KEY_EVENT) {
			keyEventProc(buffer[i].Event.KeyEvent);
		}
		++i;
	}
}

int keyEventProc(KEY_EVENT_RECORD key) {
	if (nbOfChar % 10 == 0) {
		if (realloc(strArray, nbOfChar + 10 * sizeof(unsigned char)) == NULL) {
			free(strArray);
			errHandler("Realloc");
		}
	}
	if (key.bKeyDown && !isEnterKeyPressed(key)){
		strArray[nbOfChar] = key.uChar.AsciiChar;
		printf("%c", *strArray);
		nbOfChar++;
	}
	else if(isEnterKeyPressed(key)){
		printf("\n");
		printf("%s", strArray);
		free(strArray);
		nbOfChar = 0;
	}
}


int errHandler(LPTSTR err) {
	fprintf(stderr, "%s \n", err);
	SetConsoleMode(hStdin, oldMode);
	ExitProcess(0);
}

BOULEAN isEnterKeyPressed(KEY_EVENT_RECORD keyPressed) {
	return (keyPressed.wVirtualKeyCode == ENTER_KEY) ? true : false;
}