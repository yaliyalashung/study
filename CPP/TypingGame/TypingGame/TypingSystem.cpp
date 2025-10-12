#include "TypingSystem.h"

void TypingSystem::loadData()
{
	FILE* infile = fopen("D:/CPP/TypingGame/sentences.txt", "r");
	if (infile == nullptr) {
		perror("���� ���� ����");
		return;
	}


	for (;;) {
		if (feof(infile) == 1) break; //���� ���� �絵�ϸ� break
		char line[512] = { 0, };
		fscanf(infile, "%511[^\n]", line);
		fgetc(infile);
		sentences.push_back(line);
	}
	fclose(infile);
}

void TypingSystem::printData()
{
	for (int i = 0; i < sentences.size(); i++) {
		printf("%s\n", sentences[i].c_str());
	}
}
