// dllmain.cpp : Defines the entry point for the DLL application.

#include "Debugger/Debugger.h"


uintptr_t GBA = 0;
std::wstring LOG_Path = L" ";

bool Initialized = false;

void Initialize() {
	WCHAR EXEPath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, EXEPath, MAX_PATH);

	std::wstring DirectoryPath(EXEPath);
	GBA = uintptr_t(GetModuleHandleW(NULL));
	size_t EndDL = DirectoryPath.find_last_of(L"\\/");


	if (EndDL != std::wstring::npos) {
		// Remove the filename part to get the directory path
		DirectoryPath = DirectoryPath.substr(0, EndDL + 1); // Keep the backslash
	}

	LOG_Path = DirectoryPath + L"Debug.log";

	InitLog(LOG_Path);
	DebugLog("INFO", "The Global Base Address [GBA] is " + std::to_string(GBA) + "\n\n");
}


BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{

	DisableThreadLibraryCalls(hModule);

	HANDLE Thread1 = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Initialize, nullptr, 0, 0);
	if (Thread1 != nullptr)
		CloseHandle(Thread1);
	

    return TRUE;
}

