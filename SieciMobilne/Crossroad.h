#pragma once
class Crossroad
{
public:
	double N;
	double E;
	double S;
	double W;

	Crossroad():N(-1),E(-1),S(-1),W(-1) {	}
	void Traffic(char);
private:

};
