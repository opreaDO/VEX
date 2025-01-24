#include "main.h"

sylib::Addrled ledStrip1(22, 2, 20);
sylib::Addrled ledStrip2(22, 3, 20);

void rgb (void) {
	ledStrip1.gradient(0xFF0000, 0xFF0005, 0, 0, true, true);
	ledStrip1.cycle(*ledStrip1, 4, true);
	ledStrip2.gradient(0xFF0000, 0xFF0005, 0, 0, true, true);
	ledStrip2.cycle(*ledStrip2, 4, true);}
