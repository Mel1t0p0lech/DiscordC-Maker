#pragma once
#include "discord_register.h"
#include "discord_rpc.h"
#include <Windows.h>
#include "Config.h"
#include <string>

class Discord
{
private:
	char* State;
	char* details;
	char* largeIconKey;
	char* largeIconText;
	char* smallIconKey;
	char* smallIconText;

public:


	void setState(const char* s_State) { State = _strdup(s_State); };
	void setDetails(const char* s_details) { details = _strdup(s_details); };
	void setLargeIconKey(const char* s_largeIconKey) { largeIconKey = _strdup(s_largeIconKey); };
	void setLargeIconText(const char* s_largeIconText) { largeIconText = _strdup(s_largeIconText); };
	void setSmallIconKey(const char* s_smallIconKey) { smallIconKey = _strdup(s_smallIconKey); };
	void setSmallIconText(const char* s_smallIconText) { smallIconText = _strdup(s_smallIconText); };

	char* getState() { return State; };
	char* getDetails() { return details; };
	char* getLargeIconKey() { return largeIconKey; };
	char* getLargeIconText() { return largeIconText; };
	char* getSmallIconKey() { return smallIconKey; };
	char* getSmallIconText() { return smallIconText; };

	void Initialize();
	void Update();
};

