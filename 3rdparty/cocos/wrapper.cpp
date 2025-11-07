// Implementations for the header `wrapper.hpp`.
#include "wrapper.hpp"
#include <stdexcept>

namespace CocosWrapper {

    AppDelegate::AppDelegate(const char* path)
        : dllHandle(nullptr), dllPath(path) {}

    AppDelegate::~AppDelegate() {
        if (dllHandle) FreeLibrary(dllHandle);
    }

    bool AppDelegate::loadDLL() {
        dllHandle = LoadLibraryA(dllPath);
        if (!dllHandle) return false;

        createFn = (CreateFn)GetProcAddress(dllHandle, "AppDelegate_create");
        launchFn = (LaunchFn)GetProcAddress(dllHandle, "AppDelegate_applicationDidFinishLaunching");

        return (createFn != nullptr) && (launchFn != nullptr);
    }

    void* AppDelegate::create() {
        if (!createFn) throw std::runtime_error("createFn not loaded");
        return createFn();
    }

    void AppDelegate::launch(void* app) {
        if (!launchFn) throw std::runtime_error("launchFn not loaded");
        launchFn(app);
    }

} // namespace CocosWrapper