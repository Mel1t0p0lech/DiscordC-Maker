#include <iostream>

#include "imgui.h"
#include "raylib.h"
#include "rlImGui.h"
#include "imgui_impl_raylib.h"

#include "app_config.h"
#include "app_interface.h"

app_config config;
app_interface interface;

int main()
{
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	
	InitWindow(config.width, config.height, "test");
	SetTargetFPS(144);

	rlImGuiSetup(true);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		rlImGuiBegin();
		
		interface.Draw();

		rlImGuiEnd();
		EndDrawing();
	}
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}
