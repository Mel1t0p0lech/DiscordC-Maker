#include "Discord.h"
#include <time.h>
#include <chrono>
#include <iostream>

//Таймер
static int64_t st_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

void Discord::Initialize()
{
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));

	//Мусор
	std::string hstate;
	std::string hdetails;
	std::string hlargeIconKey;
	std::string hlargeIconText;
	std::string hsmallIconKey;
	std::string hsmallIconText;

	//Тут все понятно
	std::cout << "Введите название" << std::endl;
	std::cin >> hstate;
	std::cout << "Введите описание" << std::endl;
	std::cin >> hdetails;
	std::cout << "Введите ключ большой картинки" << std::endl;
	std::cin >> hlargeIconKey;
	std::cout << "Введите текст большой картинки" << std::endl;
	std::cin >> hlargeIconText;
	std::cout << "Введите ключ маленькой картинки" << std::endl;
	std::cin >> hsmallIconKey;
	std::cout << "Введите текст маленькой картинки" << std::endl;
	std::cin >> hsmallIconText;

	//Задаем значение сеттерам
	setState(hstate.c_str());
	setDetails(hdetails.c_str());
	setLargeIconKey(hlargeIconKey.c_str());
	setLargeIconText(hlargeIconText.c_str());
	setSmallIconKey(hsmallIconKey.c_str());
	setSmallIconText(hsmallIconText.c_str());
	
	//Time stop для консоли.
	std::cout << "Press any key to exit..." << std::endl;
	std::cin.get();
	
	// Инициализируем дискорд RPC {client id, тут хендер, авторегистрация, стим айди}
	Discord_Initialize("1217341804962381914", &handlers, 1, NULL);
}

void UpdateDiscordPresence(const char* state, const char* detail, const char* largeIconKey, const char* largeIconText, const char* smallIconKey, const char* smallIconText) {
	DiscordRichPresence discordPresence;
	//Даём ячейку памяти для нашего RPC
	memset(&discordPresence, 0, sizeof(discordPresence));

	//Говнокодец
	char* c_state = _strdup(state);
	char* c_details = _strdup(detail);
	char* c_largeIconKey = _strdup(largeIconKey);
	char* c_largeIconText = _strdup(largeIconText);
	char* c_smallIconKey = _strdup(smallIconKey);
	char* c_smallIconText = _strdup(smallIconText);

	//Настройка Discord RPC
	discordPresence.state = c_state;
	discordPresence.details = c_details;
	discordPresence.startTimestamp = st_time;
	discordPresence.largeImageKey = c_largeIconKey;
	discordPresence.largeImageText = c_largeIconText;
	discordPresence.smallImageKey = c_smallIconKey;
	discordPresence.smallImageText = c_smallIconText;

	//Обновляем наш RPC
	Discord_UpdatePresence(&discordPresence);

	//Удаляем мусор
	free(c_state);
	free(c_details);
	//timer не трогаем
	free(c_largeIconKey);
	free(c_largeIconText);
	free(c_smallIconKey);
	free(c_smallIconText);
}

void Discord::Update()
{
	//Получаем значения с геттеров и педаем их в нашу функцию UpdateDiscordPresence;
	UpdateDiscordPresence(getState(), getDetails(), getLargeIconKey(), getLargeIconText(), getSmallIconKey(), getSmallIconText());
	//ХЗ (не шарю).
	std::cin.get();
	//Выгрузка РПЦ на помойку 
	Discord_ClearPresence();
	Discord_Shutdown();
}
