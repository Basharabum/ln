#include "stdafx.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	
	if (argc < 3) {
		cerr << "Переданы не все параметры!" << endl;
		cerr << "Передайте параметры:" << endl;
		cerr << "1. Имя жесткой ссылки" << endl;
		cerr << "2. Имя файла, на который будет указывать ссылка" << endl;
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
				cerr << "Ошибка! Файл не найден!" << endl;
				break;
			case 5:
				cerr << "Ошибка! Нельзя создавать жесткую ссылку на директорию или отсутствуют права доступа! " << endl;
				break;
			case 183:
				cerr << "Ошибка! Ссылка с таким именем уже существует!" << endl;
				break;
			case 123:
				cerr << "Ошибка! Имя ссылки или файла содержат недопустимые символы!" << endl;
				break;
			}
		}

	}

	return 0;
}

