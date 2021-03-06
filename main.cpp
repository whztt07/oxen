#include "OxenApp.h"

#if OGRE_PLATFORM == PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32
#include "windows.h"

/**
 * @brief This is the main entry point for the class
 */
INT WINAPI WinMain(HINSTANCE hInt, HINSTANCE, LPSTR strCmdLine, INT)
#else
int main(int argc, char **argv)
#endif
{
	OxenApp oxen;
	try {
		oxen.startApp();
	} catch (std::exception& e) {
#ifdef WIN32
		MessageBoxA(NULL, e.what(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
		fprintf(stderr, "An exception has occurred: %s\n", e.what());
#endif
	}

	return 0;
}
