#include "SMOrand.h"

SMOrand::SMOrand(int laValue, int miValue, int tValue, int nValue, int lValue) :SMO()
{
	La = laValue;
	Mi = miValue;

	if (tValue < 1)
		throw exception("T value too small");
	else if (tValue>23)
		throw exception("T value too large");
	else
		T = tValue;

	if (nValue < 1)
		throw exception("N value too small");
	else if (nValue > 6)
		throw exception("N value is too large");
	else
		N = nValue;

	queue = new Queue(lValue);

	event_handler = new EventHandler();

	for (int i = 0; i < N; i++)
	{
		channels.push_back(Channel());
	}

	event_handler->push(getT0Time(), 0);

	report = new Report(T);
}

SMOrand::~SMOrand()
{
}

double SMOrand::getT0Time() const
{
	return ((-1.0 / La) * log(generate()));
}

double SMOrand::getTnTime() const
{
	return ((-1.0 / Mi) * log(generate()));
}
