#include <cstdint>
#include "stub/steam/header.hpp"

namespace SteamUtils {
    
    void createSteamInterface23(void** interface)
    {
        uint32_t steamUser;
        void* userInterface;
        
        steamUser = SteamAPI_GetHSteamUser();
        userInterface = SteamInternal_FindOrCreateUserInterface(steamUser,"SteamUser023");
        *interface = userInterface;
        return;
    }

    
    void createSteamUtils010(void** util)
    {
        void* utils;
        
        utils = SteamInternal_FindOrCreateUserInterface(0,"SteamUtils010");
        *util = utils;
        return;
    }

    
    void createSteamInterface12(void** interface)
    {
        uint32_t steamUser;
        void* userInterface;
        
        steamUser = SteamAPI_GetHSteamUser();
        userInterface =
            SteamInternal_FindOrCreateUserInterface(steamUser,"STEAMUSERSTATS_INTERFACE_VERSION012");
        *interface = userInterface;
        return;
    }


}