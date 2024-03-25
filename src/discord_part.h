#pragma once

#include "discord_register.h"
#include "discord_rpc.h"
#include <string>

class discord_part 
{
public:

	DiscordEventHandlers handlers;

	char* id;
	char* state;
	char* details;
	char* largeIconKey;
	char* largeIconText;
	char* smallIconKey;
	char* smallIconText;

public:

	std::string field_id;
	std::string field_state;
	std::string field_details;
	std::string field_largeIconKey;
	std::string field_largeIconText;
	std::string field_smallIconKey;
	std::string field_smallIconText;

	void setId(const char* s_id) {
		id = _strdup(s_id);
	}
	void setState(const char* s_state) {
		state = _strdup(s_state);
	}
	void setDetails(const char* s_details) {
		details = _strdup(s_details);
	}
	void setLargeIconKey(const char* s_largeIconKey) {
		largeIconKey = _strdup(s_largeIconKey);
	}
	void setLargeIconText(const char* s_largeIconText) {
		largeIconText = _strdup(s_largeIconText);
	}
	void setSmallIconKey(const char* s_smallIconKey) {
		smallIconKey = _strdup(s_smallIconKey);
	}
	void setSmallIconText(const char* s_smallIconText) {
		smallIconText = _strdup(s_smallIconText);
	}

	char* getId() {
		return id;
	}
	char* getState() {
		return state;
	}
	char* getDetails() {
		return details;
	}
	char* getLargeIconKey() {
		return largeIconKey;
	}
	char* getLargeIconText() {
		return largeIconText;
	}
	char* getSmallIconKey() const {
		return smallIconKey;
	}
	char* getSmallIconText() {
		return smallIconText;
	}

	void Initialize();
	void UpdateDiscordPresence(
		const char* _state, const char* _details,
		const char* _largeIconKey, const char* _largeIconText,
		const char* _smallIconKey, const char* _smallIconText
	);
	void UpdateDiscordHandler(const char* _id);
};

