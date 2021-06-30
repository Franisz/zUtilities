// Supported with union (c) 2018 Union team

#ifndef __ZSPY_TYPES_H__VER3__
#define __ZSPY_TYPES_H__VER3__

namespace Gothic_II_Addon {

  struct zTErrorMessage {
    char username[20];
    bool command;
    int level;
    char type[10];
    char message[255];
    char position[100];

    zTErrorMessage() {}

    // user API
    #include "zTErrorMessage.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZSPY_TYPES_H__VER3__