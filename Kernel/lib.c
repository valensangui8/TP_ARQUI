#include <stdint.h>
#include <lib.h>
#include <naiveConsole.h>

void * memset(void * destination, int32_t c, uint64_t length)
{
	uint8_t chr = (uint8_t)c;
	char * dst = (char*)destination;

	while(length--)
		dst[length] = chr;

	return destination;
}

void * memcpy(void * destination, const void * source, uint64_t length)
{
	/*
	* memcpy does not support overlapping buffers, so always do it
	* forwards. (Don't change this without adjusting memmove.)
	*
	* For speedy copying, optimize the common case where both pointers
	* and the length are word-aligned, and copy word-at-a-time instead
	* of byte-at-a-time. Otherwise, copy by bytes.
	*
	* The alignment logic below should be portable. We rely on
	* the compiler to be reasonably intelligent about optimizing
	* the divides and modulos out. Fortunately, it is.
	*/
	uint64_t i;

	if ((uint64_t)destination % sizeof(uint32_t) == 0 &&
		(uint64_t)source % sizeof(uint32_t) == 0 &&
		length % sizeof(uint32_t) == 0)
	{
		uint32_t *d = (uint32_t *) destination;
		const uint32_t *s = (const uint32_t *)source;

		for (i = 0; i < length / sizeof(uint32_t); i++)
			d[i] = s[i];
	}
	else
	{
		uint8_t * d = (uint8_t*)destination;
		const uint8_t * s = (const uint8_t*)source;

		for (i = 0; i < length; i++)
			d[i] = s[i];
	}

	return destination;
}



/// revisar minutos 
void time() {
	uint64_t hour = get_hour();
	hour -= 0011;
	uint64_t minute = get_minute();

	//pasar hour a char
	//pasar minute a char

	char *hourStr;
	char *minuteStr;
	uint64_to_char(hour, hourStr);
	uint64_to_char(minute, minuteStr);



	drawWord(hourStr, 10 + 16, 40, 1);
	drawChar(':', 10 + 32, 40, 1);
	drawWord(minuteStr, 10 + 40, 40, 1);

}

void uint64_to_char(uint64_t num, char* str) {
    int i = 0;
	int flag = 0;
	if(num < 10){
		flag++;
	}
    do {
        str[i++] = '0' + num % 10;
        num /= 10;
    } while (num != 0);

	if(flag){
		str[i++] = '0';
	}

    str[i] = '\0';
    // Invertir la cadena
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}
