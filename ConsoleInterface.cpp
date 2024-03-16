#include "ConsoleInterface.h"

void ConsoleInterface::Initialize()
{
	choose = NULL;
}

void ConsoleInterface::Close()
{
	std::exit(0);
}

void ConsoleInterface::Menu()
{
	std::system("cls");
	std::cout << "МЕНЮ            " << std::endl;
	std::cout << "0.ОБНОВИТЬ СТАТУС      " << std::endl;
	std::cout << "1.ПРИМЕНИТЬ СТАТУС     " << std::endl;
	std::cout << "2.ЗАКРЫТЬ              " << std::endl;
	std::cin >> choose;
	switch (choose)
	{
	case 0:
		UpdateRPC();
	case 1:
		AcceptRPCStatus();
	case 2:
		Close();
	default:
		break;
	}
	choose = NULL;
}

void ConsoleInterface::AcceptRPCStatus()
{
	discord.Initialize();
	discord.Update();
	choose = NULL;
	Menu();
}

void ConsoleInterface::UpdateRPC()
{
	std::system("cls");

	//Тут все понятно
	std::cout << "Введите название" << std::endl;
	std::cin >> discord.hstate;
	std::cout << "Введите описание" << std::endl;
	std::cin >> discord.hdetails;
	std::cout << "Введите ключ большой картинки" << std::endl;
	std::cin >> discord.hlargeIconKey;
	std::cout << "Введите текст большой картинки" << std::endl;
	std::cin >> discord.hlargeIconText;
	std::cout << "Введите ключ маленькой картинки" << std::endl;
	std::cin >> discord.hsmallIconKey;
	std::cout << "Введите текст маленькой картинки" << std::endl;
	std::cin >> discord.hsmallIconText;

	//Задаем значение сеттерам
	discord.setState(discord.hstate.c_str());
	discord.setDetails(discord.hdetails.c_str());
	discord.setLargeIconKey(discord.hlargeIconKey.c_str());
	discord.setLargeIconText(discord.hlargeIconText.c_str());
	discord.setSmallIconKey(discord.hsmallIconKey.c_str());
	discord.setSmallIconText(discord.hsmallIconText.c_str());

	choose = NULL;
	Menu();
}
