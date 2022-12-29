#include "Milieu.hh"
#include "Gardien.hh"

int main()
{
    Gardien g("Gardien", 1, 2, 3, 4);
    Milieu m("Milieu", 1, 2, 3, 4, 6, 6, 7);
    Attaquant a("Attaquant", 1, 2, 3, 4, 8, 6);
    Defenseur d("Defenseur", 1, 2, 3, 4, 5);
    std::cout << a.poste() << std::endl;
    std::cout << g.poste() << std::endl;
    std::cout << m.poste() << std::endl;
    std::cout << m.getVitesse() << std::endl;
    std::cout << d.poste() << std::endl;
    std::cout << a.dribbler(d) << std::endl;
    std::cout << a.dribbler(g) << std::endl;
    std::cout << a.dribbler(static_cast<Defenseur&>(m)) << std::endl;

    //i = a.dribbler(m);
    return 0;
}