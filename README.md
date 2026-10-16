# Forest Quarantine (QuickHull Algorithm) 🌲

> A practical implementation of the QuickHull algorithm to compute the convex hull for a 2D spatial problem.

This project was developed as an algorithmic assignment to solve the "Forest Quarantine" problem. The goal is to enclose a set of infected trees with the shortest possible continuous fence, ensuring no infected tree remains outside. Mathematically, this is the classic **Convex Hull** problem, solved here using the **QuickHull** algorithm.

## ✨ The Problem & Solution
- **Input:** A text file containing 2D GPS coordinates of infected trees.
- **Algorithm:** The QuickHull algorithm efficiently finds the boundary points (corner posts of the fence).
- **Output:** The corner coordinates of the fence sorted in a **counter-clockwise direction**, representing the exact perimeter.
- **Edge Cases Handled:** The algorithm correctly manages collinear points (three or more trees on the same line) to ensure optimal fence segments.

## 🛠️ Tech Stack
* C++ *(uprav na Java alebo C#, podľa toho, v čom si to programoval)*
* Algorithms & Data Structures

* Developed as part of university algorithmic coursework.
