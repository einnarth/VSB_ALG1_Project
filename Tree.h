//
// Created by Zachariáš Juriš on 07/05/2026.
//

#ifndef ALG_HULL_SPOT_H
#define ALG_HULL_SPOT_H
/**
 * @brief Trieda ktorá reprezentuje daný strom
 */
class Tree {
public:
    /**
     * @brief ID stromu, ktoré sa automaticky prideľuje
     */
    int id;

    /**
     * @brief X-ová súradnica
     */
    double x;

    /**
     * @brief Y-ová súradninca
     */
    double y;

    /**
     * @brief Konštruktor stromu
     * @param id Identifikátor stromu
     * @param x Súradnica x
     * @param y Súradnica y
     */
    Tree(int id, double x, double y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    /**
     * @brief Metóda ktorá porovnáva dva stromy
     * @param other Strom s ktorým porovnávame
     * @return true ak majú rovnaké súradnice, inak false
     */
    bool isEqual(Tree other) {
        return (this->x == other.x && this->y == other.y);
    }
};

#endif //ALG_HULL_SPOT_H