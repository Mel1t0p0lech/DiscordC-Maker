#include "Discord.h"
#include <time.h>
#include <chrono>
static int64_t st_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

void Discord::Initialize()
{
	DiscordEventHandlers handle;
	memset(&handle, 0, sizeof(handle));
	Discord_Initialize("1217341804962381914", &handle, 1, NULL);
}

void Discord::Update()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "Test RPC";
	discordPresence.details = "In Process";
	discordPresence.startTimestamp = st_time;
	discordPresence.largeImageKey = "bruh";
	discordPresence.largeImageText = "Loren impsum";
	discordPresence.smallImageKey = "bruh";
	Discord_UpdatePresence(&discordPresence);
}
