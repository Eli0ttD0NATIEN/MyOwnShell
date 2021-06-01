#include <stdlib.h>
#include <stdio.h>
#include "stringED.h"
#include "input.h"
#include "parser.h"
#include <Windows.h>

#define USER_INPUT_RETURN_EXIT 1 //Faire en sorte de fair
#define USER_LINE_END 2
HANDLE stdinHandle; //liens vers stdin
DWORD oldMode;
size_t nbOfChar = 0;
BOULEAN lineEnd = false;

void loopInput() {
	stdinHandle = GetStdHandle(STD_INPUT_HANDLE);
	if (stdinHandle == INVALID_HANDLE_VALUE) {
		errHandler("GetStdHandle");
	}
	char* strArray = malloc(128 * sizeof(char));
	if (strArray == NULL) {
		errHandler("Malloc");
	}
	for (;;) {
		if (readUserInput(strArray) == USER_INPUT_RETURN_EXIT) {
			break;
		}
		if (lineEnd) {
			char* userLine = malloc(nbOfChar+1 * sizeof(char));
			memmoveED(userLine, strArray, nbOfChar+1);
			resetInput(strArray);
			parserMain(userLine);
		}
	}
	free(strArray);
	ExitProcess(-1);
}

int readUserInput(char* strArray) {
	DWORD nbOfEvRead;
	INPUT_RECORD irInBuff[128]; //Pointer vers le buffer qui va recevoir les input
	if (!GetConsoleMode(stdinHandle, &oldMode)) {
		errHandler("GetConsoleMode");
		return USER_INPUT_RETURN_EXIT;
	}
	ReadConsoleInput(stdinHandle, irInBuff, 128, &nbOfEvRead);
	eventDispatcher(irInBuff, nbOfEvRead, strArray);
	if (!SetConsoleMode(stdinHandle, oldMode)) {
		errHandler("SetConsoleMode");
		return USER_INPUT_RETURN_EXIT;
	}
	return 0;
}

VOID eventDispatcher(INPUT_RECORD* buffer, DWORD nbOfEvent, char* charBuffer) {
	for (size_t i = 0; i < nbOfEvent; i++) {
		if (buffer[i].EventType == KEY_EVENT) {
			keyEventProc(buffer[i].Event.KeyEvent, charBuffer);
		}
	}
}

void* keyEventProc(KEY_EVENT_RECORD key, char* charBuffer) {
	if (key.bKeyDown && !isEnterKeyPressed(key)){
		charBuffer[nbOfChar] = key.uChar.AsciiChar;
		printf("%c", charBuffer[nbOfChar]);
		nbOfChar++;
	}
	else if(isEnterKeyPressed(key)){
		charBuffer[nbOfChar] = '\0';
		lineEnd = true;
		return charBuffer;
	}
}

int errHandler(LPTSTR err) {
	fprintf(stderr, "%s \n", err);
	SetConsoleMode(stdinHandle, oldMode);
}

BOULEAN isEnterKeyPressed(KEY_EVENT_RECORD keyPressed) {
	return (keyPressed.wVirtualKeyCode == ENTER_KEY) ? true : false;
}

void resetInput() {
	nbOfChar = 0;
	lineEnd = false;
}