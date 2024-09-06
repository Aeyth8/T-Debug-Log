#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <windows.h>

extern bool Initialized;

extern std::string Timestamped;
extern std::string Timestamp;
extern std::wstring LOG_Path;

std::string RetrieveTime();
void InitLog(const std::wstring& Path);
void DebugLog(std::string LogType, std::string Text);
