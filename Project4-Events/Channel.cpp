#include"Channel.h"

#include <iostream>

Channel::Channel()
{
	busy = false;
}

void Channel::setBusy()
{
	if (busy)
		std::cout << "Channel is already busy" << std::endl;
	else
		busy = true;
}

void Channel::setFree()
{
	if (!busy) {
		std::cout << "Channel is already free" << std::endl;
	}
	else
		busy = false;
}

bool Channel::isBusy() const
{
	if (busy)
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream& os, const Channel& mp)
{
	if (mp.isBusy())
		return os << "1 ";
	return os << "0 ";
}