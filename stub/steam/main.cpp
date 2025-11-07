#include "header.hpp"
#include <cstring>
#include <string>
#include <mutex>
#include <map>

// Very small in-memory fake "interfaces" you can expand
static std::mutex g_steamMutex;
static std::map<std::string, void*> g_fakeInterfaces;
static uint32_t g_fakeUser = 1;

extern "C" {

int SteamAPI_Init()
{
    // Return non-zero on success to match some code expectations.
    return 1;
}

HSteamUser_t SteamAPI_GetHSteamUser()
{
    return g_fakeUser;
}

void* SteamInternal_FindOrCreateUserInterface(uint32_t hSteamUser, const char* name)
{
    std::lock_guard<std::mutex> lk(g_steamMutex);
    if (!name) return nullptr;
    std::string key = std::to_string(hSteamUser) + ":" + name;
    auto it = g_fakeInterfaces.find(key);
    if (it != g_fakeInterfaces.end()) return it->second;

    // create a tiny dummy object (caller will typically call function pointers off it)
    // we return a pointer to a static char buffer sized to hold a few pointers.
    // If you need to emulate vtables, allocate a struct with function pointers here.
    void* dummy = malloc(64);
    memset(dummy, 0, 64);
    g_fakeInterfaces.emplace(key, dummy);
    return dummy;
}

void* SteamInternal_ContextInit(void* vtablePtr)
{
    // return a pointer to a dummy context; many callers treat returned pointer as "context"
    void* ctx = malloc(32);
    memset(ctx, 0, 32);
    return ctx;
}

int SteamInternal_SteamAPI_Init(const char* name, int unknown)
{
    // real SDK returns 0 on success in your decomp patterns; adapt if needed.
    // return 0 to indicate success if your code expects that.
    (void)name; (void)unknown;
    return 0;
}

} // extern "C"
