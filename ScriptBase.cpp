#include "ScriptBase.hpp"


ScriptBase::~ScriptBase()
{
  if (_L != nullptr) lua_close( _L );
    _L = NULL;
}

bool ScriptBase::defaultInti( const char *path )
{
    _L = luaL_newstate();
    if (_L == NULL)
      return false;
    luaL_openlibs( _L );

    lua_tinker::init(_L); //support 64
    _path = path;
    dofile(path);

    return true;
}


void ScriptBase::regFunc(const char *funcName, lua_CFunction func)
{
  lua_register(_L, funcName, func);
}

void ScriptBase::dofile(const char *filename)
{
  lua_tinker::dofile( _L, filename);

}
