#include "pch.h"
#include "solzipper.h"

std::wstring s2ws(const std::string& str)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

std::string ws2s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}

void PrintMenu(fs::path dropped)
{
	std::cout << "__...---=== SolZipper ===---...__\n";
	std::cout << "|                               |\n";
	std::cout << "|  Drop solution on exe to zip  |\n";
	std::cout << "|    Or Install & Right Click   |\n";
	std::cout << "|                               |\n";
	std::cout << "|        1.  Install            |\n";
	std::cout << "|        2.  Uninstall          |\n";
	if (!dropped.empty())
	{
		std::cout << "|        3.  Zip it up          |\n";
	}
	else
	{
		std::cout << "|                               |\n";
	}
	std::cout << "|        4.  Exit               |\n";
	std::cout << "|                               |\n";
	std::cout << "|         Input Selection       |\n";
	std::cout << "|===============================|\n\n";
}

void CopyRecursive(fs::path src, fs::path dst)
{
	//Loop through all the dirs
	for (auto dir : fs::recursive_directory_iterator(src))
	{
		//copy the path's string to store relative path string
		std::wstring relstr = dir.path().wstring();

		//remove the substring matching the src path
		//this leaves only the relative path
		relstr.erase(0, src.wstring().size());

		//combine the destination root path with relative path
		fs::path newFullPath = dst / relstr;

		//Create dir if it's a dir
		if (fs::is_directory(newFullPath))
		{
			fs::create_directory(newFullPath);
		}

		//copy the files
		fs::copy(dir.path(), newFullPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
	}
}

bool IsBadDir(fs::path path)
{
	if (fs::is_directory(path))
	{
		for (auto b : badFolders)
		{
			if (b == path.filename())
			{
				return true;
			}
		}
	}
	return false;
}

bool IsBadPath(fs::path path)
{
	if (!path.extension().empty())
	{
		for (auto b : badExtensions)
		{
			if (b == path.extension())
			{
				return true;
			}
		}
	}
	return false;
}

void CopyGoodFiles(fs::path src, fs::path dst)
{
	std::vector<fs::path> badPaths;

	//Loop through all the dirs
	for (auto dir : fs::recursive_directory_iterator(src))
	{
		if (dir.path().wstring().find(L".suo") != std::string::npos)
		{
			int x = 69;
		}

		//log all bad paths
		if (IsBadDir(dir.path()) || IsBadPath(dir.path()))
		{
			badPaths.push_back(dir.path());
			continue;
		}
	}

	for (auto dir : fs::recursive_directory_iterator(src))
	{
		bool bBadPath = false;

		//if path matches a logged bad path, skip
		for (auto bad : badPaths)
		{
			if (dir.path().wstring().find(L".suo") != std::string::npos)
			{
				int x = 69;
			}

			if (dir.path().wstring().find(bad) != std::string::npos)
			{
				bBadPath = true;
				break;
			}
		}

		if (!bBadPath)
		{
			//copy the path's string to store relative path string
			std::wstring relstr = dir.path().wstring();

			//remove the substring matching the src path
			//this leaves only the relative path
			relstr.erase(0, src.wstring().size());

			//combine the destination root path with relative path
			fs::path newFullPath = dst / relstr;

			//Create dir if it's a dir
			if (fs::is_directory(dir.path()))
			{
				fs::create_directory(newFullPath);
				continue;
			}

			//copy the files one at a time.  If done recursively it'll copy bad sub paths
			fs::copy(dir.path(), newFullPath, fs::copy_options::overwrite_existing);
		}
	}
}

void ZipItUp(fs::path path)
{
	if (path.empty()) { ShellExecute(0, 0, L"https://bit.ly/2Sa5Krt", 0, 0, SW_SHOW); return; }

	//Get solution parent path
	auto solParent = path.parent_path();

	//Create temp folder to store files to keep
	wchar_t randfolder[L_tmpnam_s];
	auto err = _wtmpnam_s(randfolder, L_tmpnam_s);

	//randomfolder\SolutionName
	fs::path randfolderFull = fs::path(randfolder) / fs::path(path.filename());

	//Create random temp folder & the subfolder with the solution name
	fs::create_directory(randfolder);
	fs::create_directory(randfolderFull);

	CopyGoodFiles(path, randfolderFull);

	UnHideFiles(randfolderFull); //Compress-Archive skips them if they're hidden

	std::wstring cmd = LR"(powershell.exe Compress-Archive -Force -path ')" + randfolderFull.wstring() + LR"(' -DestinationPath ')" + path.wstring() + LR"(.zip')";

	//convert cmd string to work in console and exec it
	//std::string smbcmd = ws2s(cmd);
	//system(smbcmd.c_str());
	std::string cmd_a = "powershell.exe Compress-Archive -Force -path  '" + randfolderFull.string() + "' -DestinationPath '" + path.string() + ".zip'";
	system(cmd_a.c_str());

	fs::remove_all(randfolder); //delete temp folder
	std::cout << "SolZip Completed\n";
}

void Install(fs::path thisExe)
{
	//copy to program files
	fs::create_directories(installPath);

	try
	{
		fs::copy_file(thisExe, file, fs::copy_options::overwrite_existing);
	}
	catch (fs::filesystem_error& e)
	{
		std::cout << "Error Could not " << e.what() << '\n';
		return;
	}

	//Add context menu handler
	HKEY result;
	DWORD result2;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Classes\\Folder\\shell\\SolZipper\\", 0, 0, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, &result, &result2);
	RegSetValue(result, 0, REG_SZ, L"SolZip", 0);
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Classes\\Folder\\shell\\SolZipper\\command", 0, 0, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, &result, &result2);
	RegSetValue(result, 0, REG_SZ, cmd.c_str(), 0);
	std::cout << "Installed\n";
}

void Uninstall()
{
	//remove context menu handler
	RegDeleteKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Classes\\Folder\\shell\\SolZipper\\command", KEY_WOW64_32KEY, 0);
	RegDeleteKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Classes\\Folder\\shell\\SolZipper", KEY_WOW64_32KEY, 0);
	//schedule file deletion
	MoveFileEx(file.c_str(), 0, MOVEFILE_DELAY_UNTIL_REBOOT);
	MoveFileEx(installPath.c_str(), 0, MOVEFILE_DELAY_UNTIL_REBOOT);
	std::cout << "Uninstalled\n";
}

void UnHideFiles(fs::path path)
{
	for (auto dir : fs::recursive_directory_iterator(path))
	{
		//Unhiding the file
		int attr = GetFileAttributes(dir.path().c_str());
		if ((attr & FILE_ATTRIBUTE_HIDDEN) == FILE_ATTRIBUTE_HIDDEN)
		{
			SetFileAttributes(dir.path().c_str(), attr & ~FILE_ATTRIBUTE_HIDDEN);
		}
	}
}