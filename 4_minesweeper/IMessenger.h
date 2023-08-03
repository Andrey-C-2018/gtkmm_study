#pragma once

struct IMessenger {

	virtual void sendMessage(const char *text) = 0;
	virtual ~IMessenger() { }
};
