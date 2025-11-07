#pragma once
#include <cstdint>
#include <cstddef>

#ifdef _WIN32
using HSteamUser_t = uint32_t;
#else
using HSteamUser_t = uint32_t;
#endif

extern "C" {

// Basic Steam init / context functions used in decomp
int SteamAPI_Init(); // returns 1 on success in real SDK, but we can choose 0/1 semantics
HSteamUser_t SteamAPI_GetHSteamUser();
void* SteamInternal_FindOrCreateUserInterface(uint32_t hSteamUser, const char* name);
void* SteamInternal_ContextInit(void* vtablePtr);
int SteamInternal_SteamAPI_Init(const char* name, int unknown);

}
