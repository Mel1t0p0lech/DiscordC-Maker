#include <iostream>
#include "Discord.h"
Discord discord;

int main() {
    setlocale(LC_ALL, "Russian");
    discord.Initialize();
    discord.Update();
    return 0;
}