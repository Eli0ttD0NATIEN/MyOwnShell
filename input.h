#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#define ENTER_KEY 0x0D
#define true 1
#define false 0
typedef unsigned BOULEAN;

void loopInput();
int readUserInput(VOID);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID eventDispatcher(INPUT_RECORD* buffer, DWORD nbOfEvent);
int errHandler(LPTSTR err);
BOULEAN isEnterKeyPressed(KEY_EVENT_RECORD keyPressed);