#pragma once

#include "app_config.h"
#include "discord_part.h"

class app_interface
{
private:
	app_config config;
	discord_part discord;
	
	bool isOpened = false;
public:
	void Draw();
};

