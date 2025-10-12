#include "User.h"

User::User(const std::string& username)
{
	this->username = username;

	FILE* fp = fopen(username.c_str(), "r");
	bool exists = fp != nullptr;

	if (exists) fclose(fp);

	if (exists) 
	{
		putStringOnPosition(6, 5, "사용자가 존재합니다. 불러오는 중...");
		load();
		putStringOnPosition(6, 6, "계속하려면  Enter를 입력해 주세요.");
		fseek(stdin, 0, SEEK_END);
		fgetc(stdin);
	}
	else
	{
		putStringOnPosition(6, 5, "사용자가 존재하지 않습니다. 사용자를 추가합니다");
		save();
		putStringOnPosition(6, 6, "계속하려면  Enter를 입력해 주세요.");
		fseek(stdin, 0, SEEK_END);
		fgetc(stdin);
	}

}

void User::save()
{
	FILE* outfile = fopen(username.c_str(), "w");
	if (outfile == nullptr) return;
	fprintf(outfile, "%f\n", avgSpeed);
	fprintf(outfile, "%d", typingCount);
	fclose(outfile);
}

void User::load()
{
	FILE* infile = fopen(username.c_str(), "r");
	if (infile == nullptr) return;
	fscanf(infile, "%f", &avgSpeed);
	fgetc(infile);
	fscanf(infile, "%d", &typingCount);
	fclose(infile);
}

void User::printUserInfo()
{
	char avgSpeed[50];
	sprintf(avgSpeed, "\t\t평균 타수 : %f", this->avgSpeed);

	char count[50];
	sprintf(count, "\t\t타이핑 횟수 : %d", this->typingCount);
	putStringOnPosition(6, 6, avgSpeed);
	putStringOnPosition(6, 7, count);
	putStringOnPosition(6, 8, "\t\t계속하려면 Enter 키를 눌러주세요.");
	fseek(stdin, 0, SEEK_END);
	fgetc(stdin);
}
