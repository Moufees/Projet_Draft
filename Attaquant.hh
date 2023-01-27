#ifndef __ATTAQUANT_H__
#define __ATTAQUANT_H__
#include "JoueurDeChamp.hh"
#include "Gardien.hh"
#include "Milieu.hh"

class Attaquant : virtual public JoueurDeChamp{
public:
  Attaquant(std::string nom, int placement, int passe, std::string path, int vitesse, int physique, int dribble, int tir):JoueurDeChamp(nom, placement, passe, path, vitesse, physique), _dribble(dribble), _tir(tir){}
  ~Attaquant() {};
  std::string poste() const {return "Attaquant";};
  int getTir() const {return _tir;};
  int tirer(Gardien& gardien, Ballon& ballon);
  int getDribble() const {return _dribble;};
  int dribbler(Joueur& adversaire);
  std::string toCSV() const;

private :
    int _dribble;
    int _tir;
};

#endif
