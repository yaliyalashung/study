#include "TypingSystem.h"

void TypingSystem::loadData()
{
	FILE* infile = fopen("sentences.txt", "r");
	if (infile == nullptr) {
		perror("파일 열기 실패");
		return;
	}


	for (;;) {
		if (feof(infile) == 1) break; //파일 끝에 당도하면 break
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

void TypingSystem::start()
{
	this->loadData();
	for (;;) {
		clear();
		printMenu();
		char input = getChar();
		
		if (input == '1' && currentUser == nullptr) {

			//로그인 진행
			putStringOnPosition(6, 4, "아이디를 입력해 주세요. : ");
			std::string username = getString();
			currentUser = new User(username);
			
		}
		else if (input == '1' && currentUser != nullptr) {
			//로그아웃
			delete currentUser;
			currentUser = nullptr;
				 
		}
		else if (input == '2' && currentUser != nullptr)
		{
			typingStart();
		}
		else if (input == '3' && currentUser != nullptr)
		{
			currentUser->printUserInfo();
		}
		else if (input == 'x' || input == 'X') {
			//종료
			putStringOnPosition(6, 13, "프로그램을 종료합니다.");
			break;
		}
	}
}

void TypingSystem::printMenu()
{
	if (currentUser == nullptr) 
	{
		putStringOnPosition(6, 3, "1. 로그인");
	}
	else
	{
		putStringOnPosition(6, 3, "1. 로그아웃");	
		putStringOnPosition(6, 4, "2. 타자연습");
		putStringOnPosition(6, 5, "3. 연습 통계 보기");
	}

	putStringOnPosition(6, 12, "메뉴를 입력해 주세요 (종료 : X) : ");
}

char TypingSystem::getChar()
{
	fseek(stdin, 0, SEEK_END);
	char c;
	scanf("%c", &c);
	return c;
}

std::string TypingSystem::getString()
{
	char input[100];
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]", input);

	return input;
}

void TypingSystem::typingStart()
{
	float types_per_min = 0.0f;
	for (int i = 0; i < 5; i++) {
		clear();

		//sprintf를 위해 만들어둔 배열
		char buff[128];

		//상단에 분당 타수 출력
		sprintf(buff, "분당 타수 : %.2f / 평균 타수: %.2f", types_per_min, currentUser->avgSpeed);
		putStringOnPosition(6, 5, buff);

		float start = (float)clock() / CLOCKS_PER_SEC;


		int target = rand() % sentences.size();
		sprintf(buff, "문장 : %s", sentences[target].c_str());
		putStringOnPosition(6, 6, buff);

		putStringOnPosition(6, 7, "입력 : ");
		std::string input = getString();

		float end = (float)clock() / CLOCKS_PER_SEC;

		float delta = end - start;

		//분당 카운트 계산
		types_per_min = sentences[target].size() / delta * 60;
		
		int matches = compare(sentences[target], input);
		float match_ratio = (float)matches / sentences[target].size();

		types_per_min = types_per_min * match_ratio;

		//타이핑 카운트 계산
		currentUser->typingCount++;
		currentUser->avgSpeed = ((float)currentUser->avgSpeed * (currentUser->typingCount - 1.0) + types_per_min) / (float)currentUser->typingCount;

		//입력된 문자열과 해당 문자열의 일치율


	}

	currentUser->save();
	putStringOnPosition(6, 8, "연습이 종료되었습니다.");
	putStringOnPosition(6, 9, "계속하려면 Enter 키를 눌러주세요");
	fseek(stdin, 0, SEEK_END);
	fgetc(stdin);

}

int TypingSystem::compare(const std::string& original, const std::string& input)
{
	int count = 0;

	int size = original.size() < input.size() ? original.size() : input.size();

	for (int i = 0; i < size; i++) {
		if (original.at(i) == input.at(i)) {
			count++;
		}
	}
	return count;
}
