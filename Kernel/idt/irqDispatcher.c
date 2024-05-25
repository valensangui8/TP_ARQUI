#include <time.h>
#include <stdint.h>

void int_00();
void int_01();

void irqDispatcher(uint64_t irq, uint64_t * registers) {
	switch (irq) {
		case 0:
			int_00();
			break;
		case 1:
			int_01(registers);
			break;
	}
	return;
}

void int_00() {
	timer_handler();
}

void int_01(uint64_t * registers) {
	keyboard_handler(registers);
}

