//#ifndef BOMBA_CONSTANTS_H
//#define BOMBA_CONSTANTS_H
#pragma once

#include <FS.h>
// #include "SPIFFS.h"

#include "Looper.h"

#define WIFI_SSID ""
#define WIFI_PASSWORD ""

#define STATIC_FILES_PREFIX "/w"
#define HTTP_PORT 80
#define DNS_PORT 53
#define WEBSOCKET_PATH "/ws"

static FS FileSystem = SPIFFS;
// #define FileSystem SPIFFS

const int8_t RST_PIN    = D2;
const int8_t CE_PIN     = D1;
const int8_t DC_PIN     = D6;
const int8_t DIN_PIN    = D7;
const int8_t CLK_PIN    = D5;
const int8_t BL_PIN     = D0;

//#endif //BOMBA_CONSTANTS_H
