#ifndef CSYNERGYHOOK_H
#define CSYNERGYHOOK_H

#include "BasicTypes.h"
#include <windows.h>

#if defined(CONFIG_PLATFORM_WIN32)
#if defined(SYNRGYHK_EXPORTS)
#define CSYNERGYHOOK_API __declspec(dllexport)
#else
#define CSYNERGYHOOK_API __declspec(dllimport)
#endif
#else
#define CSYNERGYHOOK_API
#endif

#define SYNERGY_MSG_MARK			WM_APP + 0x0001	// mark id; <unused>
#define SYNERGY_MSG_KEY				WM_APP + 0x0002	// vk code; key data
#define SYNERGY_MSG_MOUSE_BUTTON	WM_APP + 0x0003	// button msg; <unused>
#define SYNERGY_MSG_MOUSE_MOVE		WM_APP + 0x0004	// x; y

typedef int				(*InstallFunc)(HWND);
typedef int				(*UninstallFunc)(void);
typedef void			(*SetZoneFunc)(UInt32, SInt32, SInt32, SInt32);
typedef void			(*SetRelayFunc)(void);

extern "C" {

CSYNERGYHOOK_API int	install(HWND);
CSYNERGYHOOK_API int	uninstall(void);
CSYNERGYHOOK_API void	setZone(UInt32 sides,
								SInt32 w, SInt32 h, SInt32 jumpZoneSize);
CSYNERGYHOOK_API void	setRelay(void);

}

#endif
