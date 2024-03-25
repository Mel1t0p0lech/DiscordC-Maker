#include "app_interface.h"

#include "imgui.h"
#include "raylib.h"
#include "imgui_stdlib.h"

void app_interface::Draw()
{
	ImGui::SetNextWindowPos(ImVec2(0, 0));

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(50, 50));
	ImGui::SetNextWindowSizeConstraints(ImVec2(config.width, config.height), ImVec2((float)GetScreenWidth(), (float)GetScreenHeight()));

	if (ImGui::Begin("MainMenu", &isOpened,
		ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize
		| ImGuiWindowFlags_NoMove)) {

		ImGui::InputText("#Id", &discord.field_id, ImGuiInputTextFlags_CharsNoBlank);
		ImGui::InputText("#State", &discord.field_state, ImGuiInputTextFlags_CharsNoBlank);
		ImGui::InputText("#Details", &discord.field_details, ImGuiInputTextFlags_CharsNoBlank);
		ImGui::InputText("#Large Image Key", &discord.field_largeIconKey, ImGuiInputTextFlags_CharsNoBlank);
		ImGui::InputText("#Large Image Text", &discord.field_largeIconText, ImGuiInputTextFlags_CharsNoBlank);
		ImGui::InputText("#Small Image Key", &discord.field_smallIconKey, ImGuiInputTextFlags_CharsNoBlank);
		ImGui::InputText("#Small Image Text", &discord.field_smallIconText, ImGuiInputTextFlags_CharsNoBlank);
		ImGui::NewLine();

		if (ImGui::Button("Accept RPC Status")) {
			discord.setId(discord.field_id.c_str());
			discord.setState(discord.field_state.c_str());
			discord.setDetails(discord.field_details.c_str());
			discord.setLargeIconKey(discord.field_largeIconKey.c_str());
			discord.setLargeIconText(discord.field_largeIconText.c_str());
			discord.setSmallIconKey(discord.field_smallIconKey.c_str());
			discord.setSmallIconText(discord.field_smallIconText.c_str());

			Discord_ClearPresence();
			Discord_Shutdown();

			discord.UpdateDiscordHandler(discord.getId());
			discord.UpdateDiscordPresence(discord.getState(), discord.getDetails(),
				discord.getLargeIconKey(), discord.getLargeIconText(), discord.getSmallIconKey(), discord.getSmallIconText());
		}


	}
	ImGui::End();
	ImGui::PopStyleVar();
}
