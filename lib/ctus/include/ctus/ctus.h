#ifndef INCLUDE_LIBTUSCLIENT_H_
#define INCLUDE_LIBTUSCLIENT_H_
#include <string>

constexpr auto TUS_PROTOCOL_VERSION = "1.0.0";
#if defined(CTUS_SHARED)
  #if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef CTUS_EXPORTS
      #define EXPORT_CTUS __declspec(dllexport)
    #else
      #define EXPORT_CTUS __declspec(dllimport)
    #endif
  #else
    #ifdef CTUS_EXPORTS
      #define EXPORT_CTUS __attribute__((visibility("default")))
    #else
      #define EXPORT_CTUS
    #endif
  #endif
  #else
    #define EXPORT_CTUS
  #endif
#endif // INCLUDE_LIBTUSCLIENT_H_