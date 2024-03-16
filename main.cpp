#include <iostream>
#include "Discord.h"
#include "ConsoleInterface.h"

Discord discord;
ConsoleInterface consoleInterface;

int main() {
    setlocale(LC_ALL, "Russian");
    discord.Initialize();
    consoleInterface.Menu();
    return 0;
}