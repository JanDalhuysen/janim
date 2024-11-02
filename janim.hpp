#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string janim_version = "Janim Version 0.0.1 (g++ 13.2.0)";
string janim_mode = "Document";
string janim_page_orientation = "Landscape";
string janim_page_height = "108mm";
string janim_page_width = "192mm";
string janim_top_margin = "20mm";
string janim_left_margin = "20mm";
string janim_page_color = "black";
string janim_text_color = "white";

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

#pragma endregion

int janim_create_document()
{
    ofstream document("document.tex");

    document << "\\documentclass{article}" << endl;
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
    document << "\\setmainfont{jan.ttf}" << endl;
    document << "\\pagenumbering{gobble}" << endl;
    document << "\\pagecolor{" << janim_page_color << "}" << endl;
    document << "\\hyphenpenalty 10000" << endl;
    document << "\\exhyphenpenalty 10000" << endl;
    document << "\\begin{document}" << endl;

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
    document << "\\noindent \\textcolor{white}" << endl;
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

int janim_render()
{
    if (janim_mode == "Document")
    {
        cout << "Rendering document" << endl;
        system("lualatex -quiet document.tex");
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
