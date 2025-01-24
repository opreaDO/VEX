#include "main.h"

sylib::Addrled ledStrip1(9, 1, 20);
sylib::Addrled ledStrip2(9, 8, 20);

void rgb (void) {
	ledStrip1.gradient(0xFF0000, 0xFF0005, 0, 0, true, true);
	ledStrip1.cycle(*ledStrip1, 4, true);
	ledStrip2.gradient(0xFF0000, 0xFF0005, 0, 0, true, true);
	ledStrip2.cycle(*ledStrip2, 4, true);}
