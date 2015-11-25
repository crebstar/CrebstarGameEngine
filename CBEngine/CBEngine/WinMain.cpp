
#define WIN32_LEAN_AND_MEAN

#include<Windows.h>

#include "HashedString.h"
#include "CBGeneralMacros.h"


//-----------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE applicationInstanceHandle, HINSTANCE, LPSTR commandLineString, int)
{
	UNUSED( applicationInstanceHandle );
	UNUSED( commandLineString );

	HashedString testHashString( "TestString" );
	HashedString testHashStringTwo( "TestStringTwo" );
	
	unsigned int hashVal		= testHashString.GetStringHashValue();
	unsigned int hashValTwo		= testHashStringTwo.GetStringHashValue();

	bool areEq		= hashVal == hashValTwo;
	bool areLess	= hashVal < hashValTwo;

	return 0;

} // end WinMain