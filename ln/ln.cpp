#include "stdafx.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	
	if (argc < 3) {
		cerr << "�������� �� ��� ���������!" << endl;
		cerr << "��������� ���������:" << endl;
		cerr << "1. ��� ������� ������" << endl;
		cerr << "2. ��� �����, �� ������� ����� ��������� ������" << endl;
	}
	else {

		char* linkFileName = argv[1];
		char* fileName = argv[2];
		bool hardLink = CreateHardLinkA(linkFileName, fileName, NULL);

		if (!hardLink) {
			DWORD dw = GetLastError();
			int errorCode = (unsigned int)dw;
			cout << "error: " << errorCode << endl;

			switch (errorCode)
			{
			case 2:
				cerr << "������! ���� �� ������!" << endl;
				break;
			case 5:
				cerr << "������! ������ ��������� ������� ������ �� ���������� ��� ����������� ����� �������! " << endl;
				break;
			case 183:
				cerr << "������! ������ � ����� ������ ��� ����������!" << endl;
				break;
			case 123:
				cerr << "������! ��� ������ ��� ����� �������� ������������ �������!" << endl;
				break;
			}
		}

	}

	return 0;
}

