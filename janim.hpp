// Janim Version 0.0.1 (g++ 13.2.0)

// Jan Maths animation library, inspired by Manim

// Jan Dalhuysen

#include <iostream>
#include <string>
#include <vector>
#include <ctime> // For time and localtime_s

#include <fstream>

// Moved below to avoid circular dependency
#include "janim_automata.hpp"

using namespace std;

string janim_version = "Janim Version 0.0.1 (g++ 13.2.0)";

string janim_mode = "Document";

string janim_page_orientation = "Landscape";

string janim_title = "";
string janim_author = "";

string janim_page_height = "108mm";
string janim_page_width = "192mm";

string janim_top_margin = "20mm";
string janim_left_margin = "20mm";

string janim_page_color = "black";
string janim_text_color = "white";

string janim_main_font = "CascadiaMono.ttf";

int janim_print_version()
{
    cout << janim_version << endl;
    return 0;
}

#pragma region page_settings

int janim_set_mode(string mode)
{
    if (mode != "Document" && mode != "Presentation" && mode != "Video")
    {
        cout << "Invalid mode" << endl;
        cout << "Valid modes are: Document, Presentation, Video" << endl;
        return 1;
    }
    janim_mode = mode;
    return 0;
}

int janim_set_page_orientation(string orientation)
{
    if (orientation != "Landscape" && orientation != "Portrait")
    {
        cout << "Invalid orientation" << endl;
        cout << "Valid orientations are: Landscape, Portrait" << endl;
        return 1;
    }
    janim_page_orientation = orientation;
    return 0;
}

int janim_set_page_height(string height)
{
    janim_page_height = height;
    return 0;
}

int janim_set_page_width(string width)
{
    janim_page_width = width;
    return 0;
}

int janim_set_top_margin(string margin)
{
    janim_top_margin = margin;
    return 0;
}

int janim_set_left_margin(string margin)
{
    janim_left_margin = margin;
    return 0;
}

int janim_set_page_color(string color)
{
    janim_page_color = color;
    return 0;
}

int janim_set_main_font(string font)
{
    janim_main_font = font;
    return 0;
}

int janim_set_title(string title)
{
    janim_title = title;
    return 0;
}

int janim_make_title(string title, string subtitle = "", string author = "", string date = "")
{
    // Update global variables for title, author, and date
    janim_title = title;
    janim_author = author;

    // If date is empty, use current date
    if (date.empty())
    {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);
        date = to_string(1900 + ltm.tm_year) + "-" +
               to_string(1 + ltm.tm_mon) + "-" +
               to_string(ltm.tm_mday);
    }

    // Store subtitle and date in global variables if needed
    // (You may want to add global variables for subtitle and date if you want to use them in the document)
    // For now, just update the title and author, and rely on \maketitle in janim_create_document

    // Optionally, you could add subtitle/date handling here if you extend the LaTeX preamble
    return 0;
}

int janim_set_author(string author)
{
    janim_author = author;
    return 0;
}

#pragma endregion

int janim_create_document()
{
    ofstream document("document.tex");

    document << "\\documentclass{article}" << endl;

    if (!janim_title.empty())
    {
        document << "\\title{" << janim_title << "}" << endl;
    }
    if (!janim_author.empty())
    {
        document << "\\author{" << janim_author << "}" << endl;
    }
    // Optionally, add date if you want to support it
    // document << "\\date{" << janim_date << "}" << endl;
    document << "\\usepackage{tikz}" << endl;
    document << "\\usepackage{geometry}" << endl;
    document << "\\geometry{" << endl;

    if (janim_page_orientation == "Landscape")
    {
        document << "paperheight=" << janim_page_height << ",paperwidth=" << janim_page_width << "," << endl;
    }
    else if (janim_page_orientation == "Portrait")
    {
        document << "paperheight=" << janim_page_width << ",paperwidth=" << janim_page_height << "," << endl;
    }

    string total_width = to_string(stoi(janim_page_width.substr(0, janim_page_width.size() - 2)) - 40) + "mm";
    string total_height = to_string(stoi(janim_page_height.substr(0, janim_page_height.size() - 2)) - 40) + "mm";

    document << "total={" << total_width << "," << total_height << "}," << endl;
    document << "left=" << janim_left_margin << "," << endl;
    document << "top=" << janim_top_margin << "," << endl;
    document << "}" << endl;

    document << "\\usepackage{fontspec}" << endl;
    document << "\\usepackage{xcolor}" << endl;
    document << "\\setmainfont{" << janim_main_font << "}" << endl;
    document << "\\pagenumbering{gobble}" << endl;
    document << "\\pagecolor{" << janim_page_color << "}" << endl;
    document << "\\hyphenpenalty 10000" << endl;
    document << "\\exhyphenpenalty 10000" << endl;
    document << "\\begin{document}" << endl;
    if (!janim_title.empty())
    {
        document << "\\maketitle" << endl;
    }
    document.close();
    return 0;
}

int janim_end_document()
{
    ofstream document("document.tex", ios::app);
    document << "\\end{document}" << endl;
    document.close();
    return 0;
}

int janim_text(string text)
{
    ofstream document("document.tex", ios::app);
    string text_color = (janim_page_color == "black") ? "white" : "black";
    document << "\\noindent \\textcolor{" << text_color << "}" << endl;
    document << "{" << text << "}" << endl;
    document.close();
    return 0;
}

int janim_line(string start_x, string start_y, string end_x, string end_y, string color = "white", string thickness = "very thick")
{
    ofstream document("document.tex", ios::app);
    document << "\\begin{tikzpicture}" << endl;
    document << "\\draw[color=" << color << ", " << thickness << "] (" << start_x << "," << start_y << ")--(" << end_x << "," << end_y << ");" << endl;
    document << "\\end{tikzpicture}" << endl;
    document.close();
    return 0;
}

int janim_circle(string x = "10mm", string y = "10mm", string radius = "10mm", string outline_color = "white", string outline_color_percentage = "60", string fill_color = "black", string fill_color_percentage = "20")
{
    ofstream document("document.tex", ios::app);
    document << "\\begin{tikzpicture}" << endl;
    document << "\\filldraw[color=" << outline_color << "!" << outline_color_percentage << ", fill=" << fill_color << "!" << fill_color_percentage << ", very thick](" << x << "," << y << ") circle (" << radius << ");" << endl;
    document << "\\end{tikzpicture}" << endl;
    document.close();
    return 0;
}

int janim_square(string x = "10mm", string y = "10mm", string side_length = "10mm", string outline_color = "white", string outline_color_percentage = "60", string fill_color = "black", string fill_color_percentage = "20")
{
    ofstream document("document.tex", ios::app);
    document << "\\begin{tikzpicture}" << endl;
    document << "\\filldraw[color=" << outline_color << "!" << outline_color_percentage << ", fill=" << fill_color << "!" << fill_color_percentage << ", very thick](" << x << "," << y << ") rectangle (" << x << "+" << side_length << "," << y << "+" << side_length << ");" << endl;
    document << "\\end{tikzpicture}" << endl;
    document.close();
    return 0;
}

int janim_rectangle(string x = "10mm", string y = "10mm", string width = "20mm", string height = "10mm", string outline_color = "white", string outline_color_percentage = "60", string fill_color = "black", string fill_color_percentage = "20")
{
    ofstream document("document.tex", ios::app);
    document << "\\begin{tikzpicture}" << endl;
    document << "\\filldraw[color=" << outline_color << "!" << outline_color_percentage << ", fill=" << fill_color << "!" << fill_color_percentage << ", very thick](" << x << "," << y << ") rectangle (" << x << "+" << width << "," << y << "+" << height << ");" << endl;
    document << "\\end{tikzpicture}" << endl;
    document.close();
    return 0;
}

int janim_triangle(string x = "10mm", string y = "10mm", string side_length = "10mm", string outline_color = "white", string outline_color_percentage = "60", string fill_color = "black", string fill_color_percentage = "20")
{
    ofstream document("document.tex", ios::app);
    document << "\\begin{tikzpicture}" << endl;
    document << "\\filldraw[color=" << outline_color << "!" << outline_color_percentage << ", fill=" << fill_color << "!" << fill_color_percentage << ", very thick](" << x << "," << y << ") -- (" << x << "+" << side_length << "," << y << ") -- (" << x << "+" << side_length << "/2," << y << "+" << side_length << ") -- cycle;" << endl;
    document << "\\end{tikzpicture}" << endl;
    document.close();
    return 0;
}

int janim_oval(string x = "10mm", string y = "10mm", string x_radius = "10mm", string y_radius = "5mm", string outline_color = "white", string outline_color_percentage = "60", string fill_color = "black", string fill_color_percentage = "20")
{
    ofstream document("document.tex", ios::app);
    document << "\\begin{tikzpicture}" << endl;
    document << "\\filldraw[color=" << outline_color << "!" << outline_color_percentage << ", fill=" << fill_color << "!" << fill_color_percentage << ", very thick](" << x << "," << y << ") ellipse (" << x_radius << " and " << y_radius << ");" << endl;
    document << "\\end{tikzpicture}" << endl;
    document.close();
    return 0;
}

int janim_render()
{
    if (janim_mode == "Document")
    {
        cout << "Rendering document" << endl;
        system("lualatex document.tex");
    }
    else if (janim_mode == "Presentation")
    {
        cout << "Rendering presentation" << endl;
    }
    else if (janim_mode == "Video")
    {
        cout << "Rendering video" << endl;
    }
    return 0;
}

int janim_export(string filetype = "png", int dpi = 300)
{
    // Export the rendered document to various file formats using Ghostscript
    cout << "Exporting to " << filetype << " with DPI: " << dpi << endl;
    
    string input_file = "document.pdf";
    string output_file = "document." + filetype;
    string device;
    string command;
    
    // Determine the Ghostscript device based on the requested file type
    if (filetype == "png")
    {
        device = "png16m";  // 24-bit PNG
    }
    else if (filetype == "jpeg" || filetype == "jpg")
    {
        device = "jpeg";    // JPEG format
        if (filetype == "jpg") output_file = "document.jpg";
    }
    else if (filetype == "tiff" || filetype == "tif")
    {
        device = "tiff24nc"; // Uncompressed 24-bit TIFF
        if (filetype == "tif") output_file = "document.tif";
    }
    else if (filetype == "bmp")
    {
        device = "bmp16m";  // 24-bit BMP
    }
    else if (filetype == "ps")
    {
        device = "pswrite"; // PostScript
    }
    else if (filetype == "eps")
    {
        device = "epswrite"; // Encapsulated PostScript
    }
    else if (filetype == "pdf")
    {
        // PDF to PDF copy - just copy the file
        cout << "Copying PDF file" << endl;
        command = "copy " + input_file + " " + output_file;
        system(command.c_str());
        return 0;
    }
    else
    {
        cout << "Unsupported file type for export: " << filetype << endl;
        cout << "Supported formats: png, jpeg/jpg, tiff/tif, bmp, ps, eps, pdf" << endl;
        return 1;
    }
    
    // For image formats, use Ghostscript with the specified DPI
    if (filetype != "pdf") {
        command = "gswin64.exe -sDEVICE=" + device + 
                  " -dTextAlphaBits=4 -dGraphicsAlphaBits=4" +
                  " -r" + to_string(dpi) + 
                  " -o " + output_file + 
                  " " + input_file;
    }
    
    // Execute the command
    int result = system(command.c_str());
    
    if (result == 0)
    {
        cout << "Successfully exported to " << output_file << endl;
    }
    else
    {
        cout << "Export failed" << endl;
        return 1;
    }
    
    return 0;
}

// Automata layout functions - forward declarations only
