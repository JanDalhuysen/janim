// Janim Automata Layout Version 0.0.1 (g++ 13.2.0)

// Implementation of a tool for automatically laying out automata graphs
// Inspired by Graphviz DOT but with a simpler syntax specifically for automata

#include <string>
#include <vector>
#include <map>
#include <cmath>

// Forward declaration to break circular dependency
struct Automaton;

// Include janim.hpp only where needed later

using namespace std;

struct State {
    string name;
    bool is_initial;
    bool is_final;
    map<string, vector<string>> transitions; // input symbol -> list of target states
};

struct Automaton {
    vector<State> states;
    map<string, State*> state_map;
    string initial_state;
    
    // Layout parameters
    double radius = 15; // spacing radius for states
    double angle_step = M_PI / 4; // angle increment for placing states
};

int janim_parse_automaton(const string& description, Automaton& automaton)
{
    // Simple parser for a DOT-like automata description language
    // Format:
    // [initial:state_name]
    // state1 -> state2 [label=input_symbol];
    // state2 [final];
    
    // Clear existing automaton
    automaton.states.clear();
    automaton.state_map.clear();
    
    // Process each line
    size_t pos = 0;
    size_t next_pos = 0;
    
    while ((next_pos = description.find('\n', pos)) != string::npos) {
        string line = description.substr(pos, next_pos - pos);
        pos = next_pos + 1;
        
        // Skip empty lines
        if (line.find_first_not_of(" \t") == string::npos) continue;
        
        // Check for initial state declaration
        if (line.find("initial:") != string::npos) {
            size_t start = line.find("initial:") + 8;
            size_t end = line.find(']', start);
            string initial = line.substr(start, end - start);
            automaton.initial_state = initial;
            continue;
        }
        
        // Check for state declaration
        if (line.find("->") == string::npos) {
            size_t name_end = line.find(' ', 0);
            if (name_end == string::npos) name_end = line.find('[', 0);
            if (name_end == string::npos) name_end = line.size();
            
            string state_name = line.substr(0, name_end);
            
            State* state = new State();
            state->name = state_name;
            state->is_initial = false;
            state->is_final = false;
            
            // Check for final state marker
            if (line.find("final") != string::npos) {
                state->is_final = true;
            }
            
            automaton.states.push_back(*state);
            automaton.state_map[state_name] = state;
            continue;
        }
        
        // Process transition
        size_t from_start = 0;
        size_t from_end = line.find("->", 0);
        string from_state = line.substr(from_start, from_end - from_start);
        
        // Trim whitespace
        from_state.erase(0, from_state.find_first_not_of(" \t"));
        from_state.erase(from_state.find_last_not_of(" \t") + 1);
        
        size_t to_start = from_end + 2;
        size_t to_end = line.find(' ', to_start);
        if (to_end == string::npos) to_end = line.find('[', to_start);
        if (to_end == string::npos) to_end = line.size();
        
        string to_state = line.substr(to_start, to_end - to_start);
        
        // Trim whitespace
        to_state.erase(0, to_state.find_first_not_of(" \t"));
        to_state.erase(to_state.find_last_not_of(" \t") + 1);
        
        // Extract input symbol if present
        string input_symbol = "ε"; // default to empty symbol
        if (line.find("label=") != string::npos) {
            size_t label_start = line.find("label=") + 6;
            size_t label_end = line.find(';', label_start);
            if (label_end == string::npos) label_end = line.size();
            
            input_symbol = line.substr(label_start, label_end - label_start);
            
            // Remove quotes if present
            if (input_symbol.front() == '"') input_symbol.erase(0, 1);
            if (input_symbol.back() == '"') input_symbol.pop_back();
        }
        
        // Find or create states
        State* from_ptr = nullptr;
        if (automaton.state_map.find(from_state) != automaton.state_map.end()) {
            from_ptr = automaton.state_map[from_state];
        } else {
            from_ptr = new State();
            from_ptr->name = from_state;
            from_ptr->is_initial = (from_state == automaton.initial_state);
            from_ptr->is_final = false;
            automaton.states.push_back(*from_ptr);
            automaton.state_map[from_state] = from_ptr;
        }
        
        State* to_ptr = nullptr;
        if (automaton.state_map.find(to_state) != automaton.state_map.end()) {
            to_ptr = automaton.state_map[to_state];
        } else {
            to_ptr = new State();
            to_ptr->name = to_state;
            to_ptr->is_initial = false;
            to_ptr->is_final = false;
            automaton.states.push_back(*to_ptr);
            automaton.state_map[to_state] = to_ptr;
        }
        
        // Add transition
        from_ptr->transitions[input_symbol].push_back(to_state);
    }
    
    return 0;
}

int janim_layout_automaton(Automaton& automaton, double start_x = 0, double start_y = 0)
{
    // Simple radial layout algorithm for automata
    if (automaton.states.empty()) return 0;
    
    // Place initial state at the center
    if (!automaton.initial_state.empty() && automaton.state_map.find(automaton.initial_state) != automaton.state_map.end()) {
        State* initial = automaton.state_map[automaton.initial_state];
        initial->is_initial = true;
        
        // Find all states except initial
        vector<State*> other_states;
        for (auto& state : automaton.states) {
            if (state.name != automaton.initial_state) {
                other_states.push_back(&state);
            }
        }
        
        // Calculate positions for other states
        double current_angle = 0;
        double max_radius = 0;
        
        for (auto* state : other_states) {
            // Place state in radial position
            double x = start_x + automaton.radius * cos(current_angle);
            double y = start_y + automaton.radius * sin(current_angle);
            
            // TODO: In a full implementation, we would store these positions
            // and use them when drawing the states and transitions
            // For now, we just log the positions
            cout << "State " << state->name << " positioned at (" << x << "mm, " << y << "mm)" << endl;
            
            current_angle += automaton.angle_step;
            
            // Update max radius for potential bounding box calculation
            max_radius = max(max_radius, automaton.radius);
        }
        
        // Update automaton radius for better spacing in subsequent layouts
        automaton.radius = max_radius + 15;
    }
    
    return 0;
}

int janim_draw_automaton(Automaton& automaton)
{
    // Draw states and transitions using TikZ
    
    ofstream document("document.tex", ios::app);
    
    // Draw states
    for (auto& state : automaton.states) {
        // For a full implementation, we would store positions from layout
        // For now, we use placeholder positions
        string x = "10mm";
        string y = "10mm";
        
        // Draw state circle
        document << "\\begin{tikzpicture}" << endl;
        document << "\\filldraw[color=white!60, fill=black!20, very thick](" 
                  << x << "," << y << ") circle (5mm);" << endl;
        
        // Draw final state circle if needed
        if (state.is_final) {
            document << "\\filldraw[color=white!60, fill=none, very thick](" 
                     << x << "," << y << ") circle (4mm);" << endl;
        }
        
        // Label
        document << "\\node at (" << x << "," << y << ") {" << state.name << "};"
                 << endl;
        
        document << "\\end{tikzpicture}" << endl;
    }
    
    // Draw transitions
    for (auto& state : automaton.states) {
        for (auto& transition : state.transitions) {
            string input_symbol = transition.first;
            for (string& target : transition.second) {
                // For a full implementation, we would calculate proper paths
                // between state positions
                document << "\\begin{tikzpicture}" << endl;
                document << "\\draw[->, color=cyan!60, very thick] (0mm,0mm) arc (0:90:5mm);"
                         << endl;
                document << "\\end{tikzpicture}" << endl;
            }
        }
    }
    
    document.close();
    return 0;
}
