#include "User.h"

User::User(const std::string& username)
{
	this->username = username;

	FILE* fp = fopen(username.c_str(), "r");
	bool exists = fp != nullptr;

	if (exists) fclose(fp);

	if (exists) 
	{
		putStringOnPosition(6, 5, "����ڰ� �����մϴ�. �ҷ����� ��...");
		load();
		putStringOnPosition(6, 6, "����Ϸ���  Enter�� �Է��� �ּ���.");
		fseek(stdin, 0, SEEK_END);
		fgetc(stdin);
	}
	else
	{
		putStringOnPosition(6, 5, "����ڰ� �������� �ʽ��ϴ�. ����ڸ� �߰��մϴ�");
		save();
		putStringOnPosition(6, 6, "����Ϸ���  Enter�� �Է��� �ּ���.");
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
	sprintf(avgSpeed, "\t\t��� Ÿ�� : %f", this->avgSpeed);

	char count[50];
	sprintf(count, "\t\tŸ���� Ƚ�� : %d", this->typingCount);
	putStringOnPosition(6, 6, avgSpeed);
	putStringOnPosition(6, 7, count);
	putStringOnPosition(6, 8, "\t\t����Ϸ��� Enter Ű�� �����ּ���.");
	fseek(stdin, 0, SEEK_END);
	fgetc(stdin);
}
