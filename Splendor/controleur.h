#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED

 class Controleur {
	public:
		Controleur();
		void distribuer();
        ~Controleur() { delete pioche; }
		const Plateau& getPlateau() const { return plateau; }
        Plateau& getPlateau() { return plateau; }
        const Pioche& getPioche() const { return *pioche; }
		Controleur(const Controleur& c) = delete;
		Controleur& operator=(const Controleur& c) = delete;
	private:
		Pioche* pioche=nullptr;
		Plateau plateau;
	};

#endif
