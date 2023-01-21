#include "Ballon.hh"
#include "Milieu.hh"
#include "Gardien.hh"

int main()
{
    Gardien g("Yassine Bounou", 10, 99,99, 99);
    Milieu m1("Sofyan Amrabat", 5, 85, 80, 93, 80, 75, 99);
    Milieu m2("Neymar Jr", 5, 93, 85, 65, 99, 93, 65);
    Attaquant a1("Sofiane Bouffal", 1, 75, 82, 80, 95, 85);
    Attaquant a2("Kylian Mbappe", 1, 80, 99, 80, 91, 90);
    Attaquant a3("Hakim Ziyech", 3, 97, 85, 82, 90, 90);
    Defenseur d("Virgil Van Dijk", 8, 88, 65, 99, 88);
    std::cout << a1.poste() << std::endl;
    std::cout << g.poste() << std::endl;
    std::cout << m1.poste() << std::endl;
    std::cout << m2.poste() << std::endl;
    std::cout << m2.getVitesse() << std::endl;
    std::cout << d.poste() << std::endl;
    std::cout << a1.dribbler(d) << std::endl;
    std::cout << a2.dribbler(d) << std::endl;
    std::cout << a3.dribbler(d) << std::endl;
    std::cout << a1.dribbler(g) << std::endl;
    std::cout << a1.tirer(g) << std::endl;
    std::cout << a2.tirer(g) << std::endl;
    std::cout << a3.tirer(g) << std::endl;
    std::cout << a1.dribbler(static_cast<Defenseur&>(m1)) << std::endl;
    std::cout << m2.dribbler(static_cast<Defenseur&>(m1)) << std::endl;

    return 0;
}
