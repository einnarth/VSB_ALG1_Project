#include "QuickHull.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


double QuickHull::getSide(Tree x, Tree y, Tree p) {
    double result = (y.x - x.x) * (p.y - x.y) - (y.y - x.y) * (p.x - x.x);
    return result;
}

void QuickHull::loadData(string inputName) {
    ifstream file(inputName);
    double x;
    double y;
    int treeID = 0;
    while (file >> x >> y) {
        this->forest.push_back(Tree(treeID, x, y));
        treeID++;
    }
    file.close();
}

void QuickHull::run() {
    int min_x_index = 0;
    int max_x_index = 0;

    for (int i = 0; i < this->forest.size(); i++) {
        if (this->forest[i].x < this->forest[min_x_index].x) {
            min_x_index = i;
        }
        if (this->forest[i].x > this->forest[max_x_index].x) {
            max_x_index = i;
        }
    }
    vector<Tree> topTrees;
    vector<Tree> bottomTrees;

    Tree leftmostTree = this->forest[min_x_index];
    Tree rightmostTree = this->forest[max_x_index];

    this->borderTrees.clear();

    for (int i = 0; i < this->forest.size(); i++) {
        Tree current = this->forest[i];
        if (current.isEqual(leftmostTree) || current.isEqual(rightmostTree)) {
            continue;
        }
        if (getSide(leftmostTree, rightmostTree, current) > 0) {
            topTrees.push_back(current);
        }
        if (getSide(rightmostTree, leftmostTree, current) > 0) {
            bottomTrees.push_back(current);
        }
    }
    this->borderTrees.push_back(leftmostTree);
    findBorder(leftmostTree, rightmostTree, topTrees);
    this->borderTrees.push_back(rightmostTree);
    findBorder(rightmostTree, leftmostTree, bottomTrees);
}

void QuickHull::findBorder(Tree x, Tree y, vector<Tree> &trees) {
    if (trees.empty()) {
        return;
    }
    int furthestIndex = 0;
    double maxDistance = -1.0;
    for (int i = 0; i < trees.size(); i++) {
        double distance = getSide(x, y, trees[i]);
        if (distance > maxDistance) {
            maxDistance = distance;
            furthestIndex = i;
        }
    }
    Tree furthestTree = trees[furthestIndex];

    vector<Tree> left;
    vector<Tree> right;
    for (int i = 0; i < trees.size(); i++) {
        Tree currentTree = trees[i];
        if (currentTree.isEqual(furthestTree) || currentTree.isEqual(x) || currentTree.isEqual(y)) {
            continue;
        }
        if (getSide(x, furthestTree, currentTree) > 0) {
            left.push_back(currentTree);
        }
        else if (getSide(furthestTree, y, currentTree) > 0) {
            right.push_back(currentTree);
        }
    }
    findBorder(x, furthestTree, left);
    this->borderTrees.push_back(furthestTree);
    findBorder(furthestTree, y, right);
}

void QuickHull::result(string outputName) {
    ofstream file(outputName);
    double totalDistance = 0.0;
    int n = this->borderTrees.size();
    for (int i = n - 1; i >= 0; i--) {
        Tree current = this->borderTrees[i];
        Tree next = this->borderTrees[(i + 1) % borderTrees.size()];
        double distance_x = next.x - current.x;
        double distance_y = next.y - current.y;
        totalDistance += sqrt(distance_x * distance_x + distance_y * distance_y);
        cout << current.id << " " << current.x << " " << current.y << endl;
        file << current.id << " " << current.x << " " << current.y << endl;
    }
    cout << "Dĺžka oplotenia: " << totalDistance << endl;
}