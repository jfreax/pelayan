#ifndef SETTINGS_H
#define SETTINGS_H

#include <netinet/in.h>

/**
 * Save all global server settings.
 */
struct Settings {
	char* path;
	char* standardfile;
	char* domain;
	
	int bufferSize;
	
	int port;
	int sockID;
	
	int timeout;
	
	struct sockaddr_in addr;

} settings;

// extern Settings Settings;

#endif // SETTINGS_H
