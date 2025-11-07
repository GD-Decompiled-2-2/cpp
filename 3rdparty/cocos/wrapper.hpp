#pragma once
#include <windows.h>

// Wrapper for calling the original Cocos2d DLL functions
namespace CocosWrapper {

    class AppDelegate {
    public:
        AppDelegate(const char* dllPath = "cocos2d-x.dll");
        ~AppDelegate();

        bool loadDLL();  // Loads the DLL
        void* create();  // Calls AppDelegate_create
        void launch(void* app); // Calls AppDelegate_applicationDidFinishLaunching

    private:
        HMODULE dllHandle = nullptr;
        const char* dllPath;

        // Function pointers
        typedef void* (*CreateFn)();
        typedef void  (*LaunchFn)(void*);

        CreateFn  createFn = nullptr;
        LaunchFn  launchFn = nullptr;
    };
}
