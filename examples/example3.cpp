// Janim Example 3: Complex Layout and Styling
// This example demonstrates advanced layout options and styling

#include <iostream>
#include <string>
#include "janim.hpp"

using namespace std;

int main()
{
    cout << janim_version << endl;
    
    // Set up document with custom styling
    janim_set_mode("Document");
    janim_set_page_color("navy");
    janim_set_page_orientation("Portrait");
    janim_make_title("Janim Example 3", "Advanced Layout and Styling", "John Doe", "2025-07-04");
    janim_set_page_height("432mm");
    janim_set_page_width("384mm");
    janim_set_main_font("CascadiaMono.ttf");
    janim_set_top_margin("30mm");
    janim_set_left_margin("30mm");
    
    // Create document
    janim_create_document();
    
    // Add colorful title
    janim_text("\\Huge \\textcolor{cyan}{Advanced \\textcolor{magenta}{Layout} \\textcolor{yellow}{and} \\textcolor{green}{Styling}}");
    janim_text("\\vspace{5mm}");
    
    // Create a decorative border pattern
    // Corner ornaments
    janim_circle("15mm", "15mm", "5mm", "cyan", "80", "transparent", "0");
    janim_circle("15mm", "402mm", "5mm", "magenta", "80", "transparent", "0");
    janim_circle("354mm", "15mm", "5mm", "yellow", "80", "transparent", "0");
    janim_circle("354mm", "402mm", "5mm", "lime", "80", "transparent", "0");
    
    // Side decorations
    for (int i = 0; i < 8; i++) {
        janim_triangle(to_string(10 + i * 45) + "mm", "10mm", "8mm", "cyan");
        janim_triangle(to_string(10 + i * 45) + "mm", "407mm", "8mm", "cyan");
    }
    
    for (int i = 0; i < 8; i++) {
        janim_square("10mm", to_string(30 + i * 45) + "mm", "6mm", "magenta");
        janim_square("359mm", to_string(30 + i * 45) + "mm", "6mm", "magenta");
    }
    
    // Create a color palette demonstration
    janim_text("\\vspace{10mm}");
    janim_text("\\textbf{\\textcolor{white}{Color Palette Demonstration}}");
    janim_text("\\vspace{3mm}");
    
    // Color swatches
    string colors[] = {"red", "green", "blue", "cyan", "magenta", "yellow", "orange", "purple", "pink", "lime"};
    for (int i = 0; i < 10; i++) {
        string x_pos = to_string(30 + (i % 5) * 60);
        string y_pos = to_string(60 + (i / 5) * 40);
        janim_rectangle(x_pos + "mm", y_pos + "mm", "50mm", "30mm", colors[i], "100", colors[i], "30");
        janim_text("\\textcolor{white}{\\small \\hspace{" + x_pos + "mm}\\vspace{-" + to_string(70 + (i / 5) * 40) + "mm}" + colors[i] + "}");
    }
    
    // Create an overlapping shapes pattern
    janim_text("\\vspace{60mm}");
    janim_text("\\textbf{\\textcolor{white}{Overlapping Shapes Pattern}}");
    janim_text("\\vspace{3mm}");
    
    // Concentric circles with different colors
    string base_x = "200";
    string base_y = "250";
    string radii[] = {"40mm", "35mm", "30mm", "25mm", "20mm", "15mm", "10mm"};
    string colors2[] = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};
    
    for (int i = 0; i < 7; i++) {
        janim_circle(base_x + "mm", base_y + "mm", radii[i], colors2[i], "80", "transparent", "0");
    }
    
    // Add some intersecting lines
    janim_line("160mm", "210mm", "240mm", "290mm", "white", "thin");
    janim_line("240mm", "210mm", "160mm", "290mm", "white", "thin");
    janim_line("160mm", "250mm", "240mm", "250mm", "white", "thin");
    janim_line("200mm", "210mm", "200mm", "290mm", "white", "thin");
    
    // Final description
    janim_text("\\vspace{80mm}");
    janim_text("\\textcolor{white}{This document demonstrates advanced features of Janim:}");
    janim_text("\\begin{itemize}");
    janim_text("\\item Custom page styling with navy background and colored elements");
    janim_text("\\item Decorative borders and corner ornaments");
    janim_text("\\item Color palette visualization");
    janim_text("\\item Overlapping shapes and patterns");
    janim_text("\\item Precise positioning of elements");
    janim_text("\\end{itemize}");
    
    // Finalize document
    janim_end_document();
    janim_render();
    
    return 0;
}
