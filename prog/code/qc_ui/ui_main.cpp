#include "../qcommon/q_shared.h"
#include "ui_public.h"
#include "ui_local.h"

#undef DotProduct
#include <RmlUi/Core.h>

Q_EXPORT intptr_t vmMain( intptr_t *args ) {
	switch ( args[0] ) {
		case UI_GETAPIVERSION:
			return UI_API_VERSION;

		case UI_INIT:
			UI_Init();
			return 0;

		case UI_SHUTDOWN:
			UI_Shutdown();
			return 0;

		case UI_KEY_EVENT:
			UI_KeyEvent( args[1], args[2] );
			return 0;

		case UI_MOUSE_EVENT:
			UI_MouseEvent( args[1], args[2] );
			return 0;

		case UI_REFRESH:
			UI_Refresh( args[1] );
			return 0;

		case UI_IS_FULLSCREEN:
			return UI_IsFullscreen();

		case UI_SET_ACTIVE_MENU:
			UI_SetActiveMenu( (uiMenuCommand_t)args[1] );
			return 0;

		case UI_CONSOLE_COMMAND:
			return UI_ConsoleCommand( args[1] );

		case UI_DRAW_CONNECT_SCREEN:
			UI_DrawConnectScreen( (qboolean)args[1] );
			return 0;

		case UI_HASUNIQUECDKEY:
			return qfalse;
	}

	return -1;
}

void UI_Init( void ) {
	Rml::Initialise();
}

void UI_Shutdown( void ) {
	Rml::Shutdown();
}

void UI_KeyEvent( int key, int down ) {
}

void UI_MouseEvent( int dx, int dy ) {
}

void UI_Refresh( int realtime ) {
}

qboolean UI_IsFullscreen( void ) {
	return qtrue;
}

void UI_SetActiveMenu( uiMenuCommand_t menu ) {
}

qboolean UI_ConsoleCommand( int realTime ) {
	return qtrue;
}

void UI_DrawConnectScreen( qboolean overlay ) {
}
