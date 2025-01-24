#include "main.h"

bool lightDirec = true;
sylib::Addrled ledStrip1(22, 1, 25);
sylib::Addrled ledStrip2(22, 2, 25);

void rgb (void) {
    ledStrip1.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
	ledStrip1.cycle(*ledStrip1, 4, lightDirec);
	ledStrip2.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
	ledStrip2.cycle(*ledStrip2, 4, lightDirec);}