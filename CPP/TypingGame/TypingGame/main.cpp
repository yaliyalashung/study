#include "Header.h"
#include "TypingSystem.h"

int main() {
	TypingSystem* s = new TypingSystem();
	s->loadData();
	s->printData();

	return 0;
}