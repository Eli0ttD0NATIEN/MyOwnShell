#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#define ENTER_KEY 0x0D
#define true 1
#define false 0
typedef unsigned BOULEAN;

void loopInput();
int readUserInput(char* strArray);
void* keyEventProc(KEY_EVENT_RECORD key, char* charBuffer);
VOID eventDispatcher(INPUT_RECORD* buffer, DWORD nbOfEvent, void* charBuffer);
int errHandler(LPTSTR err);
BOULEAN isEnterKeyPressed(KEY_EVENT_RECORD keyPressed);