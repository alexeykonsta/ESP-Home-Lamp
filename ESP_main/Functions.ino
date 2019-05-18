
//Configuration file read and write

/*refactoring*/
main_config readConfig(bool init) {
	main_config wifi_config;
	
	File configFile = SPIFFS.open("/config.json", "r");
  if (!configFile) {
		File configFile = SPIFFS.open("/config_default.json", "r");
		if (!configFile) {
			if (init) {
				printConfigNotFound();
			}
			while (1);
		}
  }
  size_t size = configFile.size();
  if (size > 1024) {
		if (init) {
			printConfigTooLarge();
		}
		while (1);
  }		
	
  StaticJsonBuffer<1024> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(configFile.readString());
	wifi_config.defconfig=false;
	wifi_config.ssid = root["ssidName"].as<String>();				// Для хранения SSID
	wifi_config.password = root["ssidPassword"].as<String>();		// Для хранения пароля сети
	wifi_config.ssidAP = root["ssidAPName"].as<String>();			// SSID AP точки доступа
	wifi_config.passwordAP = root["ssidAPPassword"].as<String>(); // пароль точки доступа
	
	if (init and wifi_config.ssidAP.length()>0) {
		printConfigReadOk();	
	} else {
		printConfigValidationError();
		File configFile = SPIFFS.open("/config_default.json", "r");
		
		size_t size = configFile.size();
		if (size > 1024) {
			if (init) {
				printConfigTooLarge();
			}
			while (1);
		}
		
		StaticJsonBuffer<1024> jsonBuffer;
		JsonObject& root = jsonBuffer.parseObject(configFile.readString());
		wifi_config.defconfig=true;
		wifi_config.ssidAP = root["ssidAPName"].as<String>();
		wifi_config.passwordAP = root["ssidAPPassword"].as<String>();	
		
		printDefaultConfigReadOk();
	}
	
	return wifi_config;
}

String readConfigArgument(String ArgumentName) {
	File configFile = SPIFFS.open("/config.json", "r");
  if (!configFile) {
		File configFile = SPIFFS.open("/config_default.json", "r");
  }
	
  size_t size = configFile.size();
	
	StaticJsonBuffer<1024> jsonBuffer;
	JsonObject& root = jsonBuffer.parseObject(configFile.readString());
	
	return root[ArgumentName].as<String>();
}


int scalePWM(int light) {
	if (light>300) {
		return (light-350)*2.5;
	} else {
		return (light-400)*2.2;
	}
}


