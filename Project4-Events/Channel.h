#pragma once

#include <ostream>

class Channel
{
	bool busy;
public:
	Channel();
	void setBusy();
	void setFree();
	bool isBusy() const;
	friend std::ostream& operator<<(std::ostream& os, const Channel& mp);
};