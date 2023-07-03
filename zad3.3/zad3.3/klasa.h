#ifndef KLASA_H
#define KLASA_H
class Tzespol {
private:
	double Re, Im, Mod, Arg;

public:
	Tzespol() {
		Re = 0;
		Im = 0;
		Mod = 0;
		Arg = 0;
	}
	Tzespol(double Re, double Im) {
		this->Re = Re;
		this->Im = Im;
		Mod = 0;
		Arg = 0;
	}
	void dodaj(Tzespol z);
	void odej(Tzespol z);
	void mnoz(Tzespol z);
	void dziel(Tzespol z);
	void mod();
	void arg();
	double potêga(int x);
	void wyœwietl();
	void wyniki();
};
#endif
