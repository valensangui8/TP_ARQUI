
#define ZERO_EXCEPTION_ID 0

static void zero_division();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
}

void zero_division() {
	//funcion de screenshots de registros
	drawWord("ERROR: division by zero");
	enter();
}

void invalid_op() {
	//funcion de screenshots de registros
	drawWord("ERROR: invalid operation");
	enter();
}