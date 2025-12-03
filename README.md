# Geometric Collision Detection System

This project is a geometric collision test simulation developed using C++ and Object-Oriented Programming (OOP) principles for the **Introduction to Programming** course at **Sakarya University, Department of Computer Engineering**.

## 🎯 Project Objective
The main goal is to define 2D (Square, Rectangle, Circle) and 3D (Sphere, Cylinder) geometric objects and detect whether they collide with each other using mathematical formulas (Euclidean distance, Clamping method, etc.).

## 🚀 Features
* **Object-Oriented Design:** Utilizes Inheritance, Operator Overloading, and Static Classes.
* **Geometric Shapes:**
    * **2D:** Point, Square, Rectangle, Circle
    * **3D:** Point3D, Sphere, Cylinder
* **Collision Algorithms:**
    * Square - Square / Rectangle - Rectangle
    * Circle - Circle / Sphere - Sphere
    * Rectangle - Circle (Closest point detection / Clamp)
    * Cylinder - Cylinder / Sphere - Cylinder
* **Dynamic Menu:** The user can run random test scenarios or input custom values manually.

## 🛠️ Tech Stack
* **Language:** C++
* **Libraries:** Standard Libraries (`<cmath>`, `<iostream>`, `<vector>`, `<ctime>`)

## 💻 How to Run
You can compile and run this project with any standard C++ compiler (GCC, Clang, MSVC).

1.  Clone the repository:
    ```bash
    git clone [https://github.com/KULLANICI_ADIN/Geometrik-Carpisma-Testi-CPP.git](https://github.com/KULLANICI_ADIN/Geometrik-Carpisma-Testi-CPP.git)
    ```
2.  Compile the code:
    ```bash
    g++ Odev2.cpp -o CollisionTest
    ```
3.  Run the executable:
    ```bash
    ./CollisionTest
    ```

## 📝 Author
* **Name:** Emre Zorlu
* **Department:** Computer Engineering
* **University:** Sakarya University
