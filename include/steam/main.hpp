#pragma once
#include <cstdint>

namespace SteamUtils {

    void createSteamInterface23(void** interface);

    void createSteamUtils010(void** util);

    void createSteamInterface12(void** interface);
    void applicationDidFinishLaunching(); // Convenience: load DLL, create and launch

}
