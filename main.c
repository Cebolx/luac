#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"
#include <stdlib.h>
#include <stdio.h>


void bail(lua_State *L, char *msg){
	fprintf(stderr, "\nFATAL ERROR:\n  %s: %s\n\n",
		msg, lua_tostring(L, -1));
	exit(1);
}

int main(void)
{
	int a = 100;
	
    lua_State *L;

    L = luaL_newstate();                        /* Create Lua state variable */
    luaL_openlibs(L);                           /* Load Lua libraries */

	luaL_dostring(L,"print(a)");

    if (luaL_loadfile(L, "script.lua"))    		/* Load but don't run the Lua script */
		bail(L, "luaL_loadfile() failed");     	 	/* Error out if file can't be read 	*/
    if (lua_pcall(L, 0, 0, 0))                  /* Run the loaded Lua script */
		bail(L, "lua_pcall() failed");          /* Error out if Lua file has an error */

    lua_close(L);                               /* Clean up, free the Lua state var */
	system( "pause" ); 
    return 0;
}