#include "discord_part.h"

#include <iostream>
#include <chrono>
#include <time.h>

static int64_t st_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

void discord_part::UpdateDiscordPresence(const char* _state, const char* _details, const char* _largeIconKey, const char* _largeIconText, const char* _smallIconKey, const char* _smallIconText)
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));

	discordPresence.state = _state;
	discordPresence.details = _details;
	discordPresence.startTimestamp = st_time;
	discordPresence.largeImageKey = _largeIconKey;
	discordPresence.largeImageText = _largeIconText;
	discordPresence.smallImageKey = _smallIconKey;
	discordPresence.smallImageText = _smallIconText;

	Discord_UpdatePresence(&discordPresence);
}

void discord_part::UpdateDiscordHandler(const char* _id)
{
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize(_id, &handlers, 1, NULL);
}

