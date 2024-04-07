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
	char* button1Label;
	char* button1Url;
	char* button2Label;
	char* button2Url;
public:

	std::string field_id;
	std::string field_state;
	std::string field_details;
	std::string field_largeIconKey;
	std::string field_largeIconText;
	std::string field_smallIconKey;
	std::string field_smallIconText;
	std::string field_button1Label;
	std::string field_button1Url;
	std::string field_button2Label;
	std::string field_button2Url;

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

	void setButton1Label(const char* s_button1Label) {
		button1Label = _strdup(s_button1Label);
	}
	void setButton1Url(const char* s_button1Url) {
		button1Url = _strdup(s_button1Url);
	}
	void setButton2Label(const char* s_button2Label) {
		button2Label = _strdup(s_button2Label);
	}
	void setButton2Url(const char* s_button2Url) {
		button2Url = _strdup(s_button2Url);
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

	char* getButton1Label() {
		return button1Label;
	}

	char* getButton1Url() {
		return button1Url;
	}

	char* getButton2Label() {
		return button2Label;
	}

	char* getButton2Url() {
		return button2Url;
	}


	void UpdateDiscordPresence(
		const char* _state, const char* _details,
		const char* _largeIconKey, const char* _largeIconText,
		const char* _smallIconKey, const char* _smallIconText,
		const char* _button1Label, const char* _button1Url,
		const char* _button2Label, const char* _button2Url
	);

	void UpdateDiscordHandler(const char* _id);
};

