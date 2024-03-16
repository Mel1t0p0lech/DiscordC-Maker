#pragma once
#include <iostream>
#include "Discord.h"

class ConsoleInterface
{
private:
	int choose;
	Discord discord;
public:
	void Initialize();
	void Close();
	void Menu();
	void AcceptRPCStatus();
	void UpdateRPC();
};

