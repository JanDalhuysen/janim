// Janim Version 0.0.1 (g++ 13.2.0)

// Fibonacci Facts and Formulas Example
// This program demonstrates mathematical concepts related to the Fibonacci sequence
// using the Janim library for visual presentation

#include <iostream>
#include <string>
#include <cmath>

#include "janim.hpp"

using namespace std;

// Function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Function to calculate golden ratio approximation
double golden_ratio(int n) {
    return (double)fibonacci(n+1) / fibonacci(n);
}

int main()
{
    // Display the current version of Janim
    cout << janim_version << endl;

    // Set the document mode and basic page properties
    janim_set_mode("Document");
    janim_set_page_color("white");
    janim_set_page_orientation("Portrait");

    // Create a title page with document metadata
    janim_make_title("Fibonacci Facts and Formulas", 
                     "Mathematical Properties of the Golden Sequence", 
                     "Janim Library", "2025-07-04");

    // Set the document dimensions for better layout
    janim_set_page_height("432mm");
    janim_set_page_width("768mm");

    // Set the main font for the document
    janim_set_main_font("CascadiaMono.ttf");

    // Initialize the document creation process
    janim_create_document();

    // Introduction to Fibonacci sequence
    janim_text("The Fibonacci Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144...");
    janim_text("Each number is the sum of the two preceding ones: F(n) = F(n-1) + F(n-2)");

    // Visual representation of Fibonacci squares
    janim_text("Fibonacci Squares - The Golden Spiral:");
    
    // Draw squares with Fibonacci dimensions
    janim_square("10mm", "10mm", "10mm", "blue", "80", "lightblue", "30");
    janim_text("1×1");
    
    janim_square("20mm", "10mm", "10mm", "green", "80", "lightgreen", "30");
    janim_text("1×1");
    
    janim_square("10mm", "20mm", "20mm", "red", "80", "pink", "30");
    janim_text("2×2");
    
    janim_square("30mm", "20mm", "30mm", "purple", "80", "lavender", "30");
    janim_text("3×3");

    // Golden Ratio approximation
    janim_text("Golden Ratio Approximation:");
    janim_text("φ = (1 + √5) / 2 ≈ 1.6180339887...");
    
    // Draw a golden rectangle
    janim_rectangle("50mm", "50mm", "61.8mm", "38.2mm", "gold", "90", "yellow", "20");
    janim_text("Golden Rectangle (1:φ ratio)");

    // Fibonacci Formula - Binet's Formula
    janim_text("Binet's Formula for nth Fibonacci number:");
    janim_text("F(n) = (φⁿ - ψⁿ) / √5");
    janim_text("where φ = (1+√5)/2 and ψ = (1-√5)/2");

    // Sum of Fibonacci numbers
    janim_text("Sum of first n Fibonacci numbers:");
    janim_text("Σ F(k) from k=0 to n = F(n+2) - 1");

    // Sum of squares
    janim_text("Sum of squares of first n Fibonacci numbers:");
    janim_text("Σ F(k)² from k=0 to n = F(n) × F(n+1)");

    // Cassini's Identity
    janim_text("Cassini's Identity:");
    janim_text("F(n-1) × F(n+1) - F(n)² = (-1)ⁿ");

    // Draw a triangle to illustrate the relationship
    janim_triangle("100mm", "100mm", "40mm", "orange", "80", "yellow", "30");
    janim_text("Fibonacci Triangle Properties");

    // Fibonacci in nature - spiral approximation
    janim_text("Fibonacci Spiral in Nature:");
    janim_oval("150mm", "100mm", "30mm", "18.5mm", "brown", "80", "orange", "20");
    janim_oval("150mm", "100mm", "18.5mm", "11.4mm", "brown", "80", "orange", "20");
    janim_text("Approximating the Golden Spiral");

    // Matrix representation
    janim_text("Matrix Representation:");
    janim_text("|F(n+1)  F(n)  | = |1 1|ⁿ");
    janim_text("|F(n)    F(n-1)|   |1 0|");

    // Draw connecting lines to show relationships
    janim_line("50mm", "80mm", "100mm", "100mm", "blue");
    janim_line("100mm", "100mm", "150mm", "100mm", "green");

    // Final interesting fact
    janim_text("Interesting Fact:");
    janim_text("The ratio of consecutive Fibonacci numbers approaches φ as n → ∞");
    
    // Display the approximation
    string ratio_text = "F(10)/F(9) = " + to_string(fibonacci(10)) + "/" + 
                       to_string(fibonacci(9)) + " ≈ " + 
                       to_string(golden_ratio(9));
    janim_text(ratio_text);

    // Finalize the document
    janim_end_document();
    janim_render();
    
    return 0;
}
