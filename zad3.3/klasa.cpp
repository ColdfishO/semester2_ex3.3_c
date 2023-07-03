#include<iostream>
#include <math.h>
#include"klasa.h"
using namespace std;
void Tzespol::dodaj(Tzespol z) {
	this->Re = this->Re + z.Re;
	this->Im = this->Im + z.Im;
}
void Tzespol::odej(Tzespol z) {
	this->Re = this->Re - z.Re;
	this->Im = this->Im - z.Im;
}
void Tzespol::mnoz(Tzespol z) {
	double x;
	if (this->Re == 0) {
		this->Re = this->Im * z.Im * -1;
		this->Im = this->Im * z.Re;

	}
	else {
		if (z.Re == 0) {
			x = this->Im;
			this->Im = this->Re * z.Im;
			this->Re = x * z.Im * -1;
		}
		else {
			if (this->Im == 0) {
				this->Im = this->Re * z.Im;
				this->Re = this->Re * z.Re;

			}
			else {
				if (z.Im == 0) {
					this->Re = this->Re * z.Re;
					this->Im = this->Im * z.Re;
				}
				else {
					x = this->Im;
					this->Im = this->Re * z.Im + this->Im * z.Re;
					this->Re = this->Re * z.Re + (x * z.Im * -1);
				}
			}
		}
	}

}
void Tzespol::dziel(Tzespol z) {
	double x;
	if (z.Re == 0 && z.Im == 0) {
		cout << "Nie da siê dzieliæ przez 0!" << endl;
	}
	else {
		if (this->Re == 0) {
			this->Re = (this->Im * z.Im * -1) / (z.Re * z.Re - z.Im * z.Im * -1);
			this->Im = (this->Im * z.Re) / (z.Re * z.Re - z.Im * z.Im * -1);
		}
		else {
			if (this->Im == 0) {
				x = this->Re;
				this->Re = (this->Re * z.Re) / (z.Re * z.Re - z.Im * z.Im * -1);
				this->Im = (x * z.Im) / (z.Re * z.Re - z.Im * z.Im * -1);
			}
			else {
				if (z.Re == 0) {
					x = this->Re;
					this->Re = this->Im / z.Im;
					this->Im = x / z.Im * -1;
				}
				else {
					if (z.Im == 0) {
						this->Re = this->Re / z.Re;
						this->Im = this->Im / z.Re;
					}
					else {
						x = this->Re;
						this->Re = (this->Re * z.Re - this->Im * z.Im * -1) / (z.Re * z.Re - z.Im * z.Im * -1);
						this->Im = (z.Re * this->Im - x * z.Im) / (z.Re * z.Re - z.Im * z.Im * -1);
					}
				}
			}
		}
	}
}
void Tzespol::wyœwietl() {
	if (this->Re == 0 && this->Im == 0) {
		cout << "0\n\n";
	}
	else {
		if (this->Re == 0) {
			cout << this->Re << "\n\n";
		}
		else {
			if (this->Im == 0) {
				cout << this->Im << "i\n\n";
			}
			else {
				cout << this->Re << " " << this->Im << "i\n\n";
			}
		}
	}
}
void Tzespol::mod() {
	this->Mod = sqrt(this->Re * this->Re + this->Im * this->Im);
}
void Tzespol::arg() {
	if (this->Im >= 0) {
		this->Arg = acos(this->Re/this->Mod);
	}
	else {
		this->Arg = 2 * 3.14 - acos(this->Re/this->Mod);
	}
}
double Tzespol::potêga(int x) {
	double p;
	if (x == 0) {
		p = 1;
		return p;
	}
	else {
		if (x == 1) {
			p = this->Mod * (cos(x * this->Arg) + sin(x * this->Arg));
			return p;
		}
		else {
			if (x==-1) {
				p = 1/this->Mod * (cos(x * this->Arg) + sin(x * this->Arg));
				return p;
			}
			else {
				if (x < -1) {
					for (int i = -2; x <= i;i--) {
						this->Mod *= this->Mod;
					}
					p = 1/this->Mod * (cos(x * this->Arg) + sin(x * this->Arg));
					return p;
				}
				else {
					for (int i = 2;x >= i;i++) {
						this->Mod *= this->Mod;
					}
					p = this->Mod * (cos(x * this->Arg) + sin(x * this->Arg));
					return p;
				}
			}
		}
	}
}
void Tzespol::wyniki() {
	cout << "Modu³ liczby zespolonej: " << this->Mod << endl;
	cout << "Argument liczby zespolonej: " << this->Arg << "\n\n";
}