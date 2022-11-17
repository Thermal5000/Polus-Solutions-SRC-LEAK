
#include "../Include/Includefiles.h"
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment (lib, "d3d9.lib")


int main()
{
	SetConsoleTitleA("Polus Solutions | Slotted External 2.0 ");
   //cout << "Hello World!\n";
	
	const int result = MessageBox(NULL, "Load Driver [ONE TIME]", "ASK", MB_YESNO);

	switch (result)
	{
	case IDYES:
		physmeme::map_driver(udriverudumb);
		system(("cls"));
		break;
	case IDNO:

		system(("cls"));
		break;
	}
	std::cout << "waiting for fortnite";
   while (hwnd == NULL)
   {
	   
	   hwnd = FindWindowA(0, ("Fortnite  "));


	   Sleep(300);
   }
   system(("cls"));

   std::cout << "Fortnite found ";
   system(("cls"));
  
   xCreateWindow();
   xInitD3d();
   HANDLE handle = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(drawLoop), nullptr, NULL, nullptr);
   CloseHandle(handle);
	   xMainLoop();
 

   
  
   return 0;
}

