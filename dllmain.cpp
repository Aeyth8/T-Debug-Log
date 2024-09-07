// dllmain.cpp : Defines the entry point for the DLL application.

#include "Debugger/Debugger.h"


uintptr_t GBA = 0;
std::wstring LOG_Path = L" ";

bool Initialized = false;

// Converts a wide string into a normal string
std::string Revertion(const std::wstring& wideStr) {
	std::string WideString;
	WideString.assign(wideStr.begin(), wideStr.end());
	return WideString;
}

void Initialize() {
	WCHAR EXEPath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, EXEPath, MAX_PATH);

	std::wstring DirectoryPath(EXEPath);
	size_t EndDL = DirectoryPath.find_last_of(L"\\/");
	std::wstring ShippingEXE;

	if (EndDL != std::wstring::npos) {
		// Remove the filename part to get the directory path
		DirectoryPath = DirectoryPath.substr(0, EndDL + 1); // Keep the backslash
		ShippingEXE = EXEPath + EndDL + 1;
	}

	GBA = uintptr_t(GetModuleHandleW(ShippingEXE.c_str()));
	LOG_Path = DirectoryPath + L"Debug.log";

	InitLog(LOG_Path);
	DebugLog("INFO", Revertion(ShippingEXE));
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

