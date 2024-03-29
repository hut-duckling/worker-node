#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <Arduino.h>
#include <ArduinoJson.h>
#include <Ntp.h>
#include <ConfigTypes.hpp>
#include <WifiManager.hpp>

class _ConfigManager
{
public:
	void load();
	void setup();
	void setupNTP();
	void restart();
	void save();

	NetworkConfig network = {
		.mode = WifiMode_AP,
		.ssid = WifiManager.getDefaultHostname(),
		.password = "12345678",
		.apip = "192.168.4.1",
		.apsubnet = "255.255.255.0",
		.dns = "8.8.8.8",
		.failedConnectCountFallback=50};
	HardwareConfig hardware;
	GeneralConfig general = {
		.password = "admin",
		.hostname=WifiManager.getDefaultHostname()};
	MqttConfig mqtt={};
	NtpConfig ntp = {
		.server = "pool.ntp.org", // currently, WiFi.hostByName SUCKS! use IP instead.
		.interval = 1000,
		.timezone = 12600};
	NtpClient *ntpClient;
	unsigned short wifiStatusMonitorIntervalId = 0;
};

extern _ConfigManager ConfigManager;

#endif