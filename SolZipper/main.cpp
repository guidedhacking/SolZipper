#include "pch.h"
#include "solzipper.h"

fs::path dropped;
fs::path thisExe;

int wmain(int argc, wchar_t* argv[])
{
	//Get Path of this process
	thisExe = fs::path(argv[0]);

	fs::path dropped;
	dropped.clear();

	if (argv[1])
	{
		dropped = fs::path(argv[1]);
	}
	//put test project here if running from debugger
	//else dropped = L"F:\\Projects\\ACHack Framework";

	while (1)
	{
		PrintMenu(dropped);

		int x = 0;

		while (1)
		{
			std::cin >> x;

			if (x < 5 && x > 0)
			{
				switch (x)
				{
				case 1:
				{
					Install(thisExe); system("cls");  PrintMenu(dropped);  std::cout << "\nInstalled \n\nInput Next Selection\n\n"; break;
				}
				case 2:
				{
					Uninstall(); system("cls");  PrintMenu(dropped);  std::cout << "\nUninstalled \n\nInput Next Selection\n\n"; break;
				}
				case 3:
				{
					ZipItUp(dropped); system("cls");  PrintMenu(dropped); std::cout << "\nZipping complete! \n\nInput Next Selection\n\n"; break;
				}
				case 4: exit(0);
				default: break;
				}
			}

			else
			{
				system("cls");  PrintMenu(dropped); std::cout << "Invalid input.  Try again\n\n";
			}
		}
	}
}