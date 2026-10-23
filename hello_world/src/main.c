#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>

#include <stdio.h>

#include "debugScreen.h"

#define printf 			psvDebugScreenPrintf
#define TICKS_1000MS	1000000
#define CTRL_PORT_0 	0

SceCtrlPadInputMode pMode = {0};

SceCtrlData ctrlData;

int main(int argc, char *argv[]) {
	psvDebugScreenInit();

	if(sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG)) {
		printf("[ERROR]: Sampling Mode was not set!");
		return 1;
	}

	printf("Testing inputs:\n");

	do {
		sceCtrlPeekBufferPositive(CTRL_PORT_0, &ctrlData, 1);
		printf("[LOG] LX: %u, LY: %u, RX: %u, RY: %u\n", ctrlData.lx, ctrlData.ly, ctrlData.rx, ctrlData.ry);
		sceKernelDelayThread(TICKS_1000MS / 10);
	} while(ctrlData.buttons != SCE_CTRL_CIRCLE);
	
		
	sceKernelDelayThread(5 * TICKS_1000MS); // Wait for 3 seconds
	
}
