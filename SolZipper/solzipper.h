#pragma once
#include "pch.h"

namespace fs = std::experimental::filesystem;

const std::wstring badFolders[] = { L"Release", L"Debug", L"ipch", L"x64", L"x86", L"Obj", L"Releases", L"Bin", L"Log", L"IPCH", L".git" };
const std::wstring badExtensions[] = { L".db", L".pch", L".obj", L".pdb", L".tmp", L".opendb", L".opensdf", L".VC", L".zip", L".exe", L".dll" };
const std::wstring badFilenames[] = { L"Browse.VC.db" };

const fs::path installPath = "C:\\Program Files (x86)\\SolZipper";
const fs::path file = "C:\\Program Files (x86)\\SolZipper\\SolZipper.exe";
const std::wstring cmd = L"C:\\Program Files (x86)\\SolZipper\\SolZipper.exe %1";

void TO_WCHAR_T(const char* in, wchar_t* out);

void TO_CHAR(const wchar_t* in, char* out);

void PrintMenu(fs::path dropped);

void CopyRecursive(fs::path src, fs::path dst);

bool IsBadDir(fs::path path);

bool IsBadPath(fs::path path);

void CopyGoodFiles(fs::path src, fs::path dst);

void ZipItUp(fs::path path);

void Install(fs::path thisExe);

void Uninstall();

void UnHideFiles(fs::path path);