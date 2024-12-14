#include "pch.h"
#include "Definitions/Nexus.h"
#include <Windows.h>

AddonAPI* g_api = nullptr;

struct {
    bool enabled = false;
} g_state;

void HandleKeybind(const char* identifier, bool isRelease) {
    if (!isRelease && g_state.enabled) {
        POINT currentPos;
        GetCursorPos(&currentPos);

        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        int centerX = screenWidth / 2;
        int centerY = screenHeight / 2;

        // Centra il cursore solo se non è già al centro
        if (currentPos.x != centerX || currentPos.y != centerY) {
            BlockInput(TRUE);
            SetCursorPos(centerX, centerY);
            Sleep(1);
            BlockInput(FALSE);
        }

        // Invia il comando per toggleare l'action camera
        if (g_api) {
            g_api->GameBinds.InvokeAsync(EGameBinds_CameraActionMode, 50);
        }
    }
}

void Load(AddonAPI* api) {
    g_api = api;
    g_state.enabled = true;

    if (g_api) {
        g_api->Log(ELogLevel_INFO, "CursorAnchor", "Loading addon...");

        // Keybind di default (verrà sovrascritto dalle impostazioni dell'utente in Nexus)
        Keybind kb;
        kb.Key = 0;  // Nessun tasto di default
        kb.Alt = false;
        kb.Ctrl = false;
        kb.Shift = false;

        // Registra il keybind
        g_api->InputBinds.RegisterWithStruct("CursorAnchor.Center", HandleKeybind, kb);

        g_api->Log(ELogLevel_INFO, "CursorAnchor", "Addon loaded successfully");
    }
}

void Unload() {
    if (g_api) {
        g_api->InputBinds.Deregister("CursorAnchor.Center");
        g_api->Log(ELogLevel_INFO, "CursorAnchor", "Addon unloaded successfully");
        g_api = nullptr;
    }
    g_state.enabled = false;
}

extern "C" __declspec(dllexport) AddonDefinition* GetAddonDef() {
    static AddonDefinition def;
    def.Signature = -424242;
    def.APIVersion = NEXUS_API_VERSION;
    def.Name = "CursorAnchor";
    def.Version.Major = 1;
    def.Version.Minor = 0;
    def.Version.Build = 0;
    def.Version.Revision = 0;
    def.Author = "Azrub";
    def.Description = "Centers cursor when toggling action camera";
    def.Load = Load;
    def.Unload = Unload;
    def.Flags = EAddonFlags_None;
    def.Provider = EUpdateProvider_None;
    def.UpdateLink = nullptr;
    return &def;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}