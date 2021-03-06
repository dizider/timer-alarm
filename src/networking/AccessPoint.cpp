#include <ESP8266WiFi.h>

#include <Constants.h>
#include "AccessPoint.h"

void AccessPoint::begin(char *ssid, char *password) {
    WiFi.disconnect(true); // for case it was configured as wifi client  in last run...

    IPAddress apIP(8, 8, 8, 8);
    IPAddress netMsk(255, 255, 255, 0);

    Serial.print(F("Configuring access point…"));
    WiFi.softAPConfig(apIP, apIP, netMsk);
    WiFi.softAP(ssid, password);

    /* Setup the DNS server redirecting all the domains to the apIP */
    dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
    dnsServer.start(DNS_PORT, "*", apIP);

    DefaultLooper.add([] { dnsServer.processNextRequest(); });

    delay(500);
    Serial.print(F("AP IP address: "));
    Serial.println(WiFi.softAPIP());
}
