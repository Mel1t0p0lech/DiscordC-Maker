#include <iostream>
#include "Discord.h";

Discord * g_discord;

int main()
{
	g_discord->Initialize();
	g_discord->Update();
	system("PAUSE");
	return 0;
}
