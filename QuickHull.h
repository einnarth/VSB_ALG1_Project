//
// Created by Zachariáš Juriš on 07/05/2026.
//

/**
 * @mainpage ALG_Hull - Lesná karanténa
 *
 * @section popis Popis projektu
 * Tento program bol vytvorený pre projekt z predmetu Algoritmy I.
 * Jeho úlohou je načítať súradnice stromov zo súboru a následne pomocou vhodného argumentu nájsť konvexný obal.
 *
 * @section algoritmus Algoritmus
 * Zvolil som si algoritmus QuickHull, ktorý spĺňal podmienky zadania.
 * QuickHull je algoritmus typu rozdeľ a panuj .
 * Funguje na základe rozdelenia pomocou dvoch krajných bodov a následneho riešenia dvoch menších častí rekurziou
 *
 * @section zlozitost Časová zložitosť
 * - Priemerný prípad: O(n log n)
 * - Najhorší prípad: O(n²) - nastane ak sú všetky body na hranici obalu
 */

#ifndef ALG_HULL_QUICKHULL_H
#define ALG_HULL_QUICKHULL_H
#include <vector>
#include "Tree.h"

using namespace std;

/// @brief Trieda ktorá reprezentuje algoritmus QuickHull
class QuickHull {
private:
    /// @brief Vektor, ktorý obsahuje všetky načítané stromy
    vector<Tree> forest;
    /// @brief Vektor, ktorý obsahujé stromy, ktoré sú výsledkom algoritmu
    vector<Tree> borderTrees;

    /**
    * @brief Zistí či je bod vľavo alebo vpravo od priamky
    * @details Čím väčšie číslo vráti, tým ďalej vľavo bod je.
    * Ak vráti záporné číslo, bod je vpravo. Ak nulu, leží priamo na priamke.
    * @param x Prvý bod priamky
    * @param y Druhý bod priamky
    * @param p Bod ktorý testujeme
    * @return Vzdialenosť bodu od priamky, kladná ak je vľavo
    */
    double getSide(Tree x, Tree y, Tree p);
    /**
    * @brief Hľadá stromy ktoré tvoria výslednu hranicu
    * @details Je to rekurzívna funkcia, ktorá vždy nájde najvzdialenejší strom od priamky, ten určite patrí na hranicu, a potom pokračuje ďalej pre body vľavo od nových priamok. Skončí keď už žiadne stromy naľavo nezostanú.
    * @param x Začiatok priamky
    * @param y Koniec priamky
    * @param trees Stromy ktoré sú vonku od tejto priamky
    */
    void findBorder(Tree x, Tree y, vector<Tree> &trees);
public:
    /**
    * @brief Načíta stromy zo súboru
    * @details Každý riadok súboru obsahuje súradnice a dostane priradené svoje vlastné ID.
    * @param inputName Cesta k súboru so stromami
    */
    void loadData(string inputName);
    /**
    * @brief Spustí výpočet algoritmu
    * @details Najprv hľadá strom najviac vľavo a strom najviac vpravo, ktoré patria do výsledku. Potom rozdelí zvyšné stromy na tie čo sú nad a pod priamkou medzi nimi a pre každú skupinu spustí rekurzívne hľadanie pomocou funckie findBorder.
    */
    void run();
    /**
    * @brief Vypíše výsledok do súboru a na obrazovku
    * @param outputName Cesta k výstupnému súboru
    */
    void result(string outputName);
};


#endif //ALG_HULL_QUICKHULL_H