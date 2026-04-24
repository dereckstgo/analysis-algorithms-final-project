#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

struct Edge{
    int to;
    int time;
    string routeName;
};

vector<string> stops = {
    //BLUE
    "Marshall Student Center",
    "The Village Palm Dr Entrace",
    "The Hub",
    "Parking Lot 56",
    "Publix",
    "Park and Ride Lot 43 East",
    "Park and Ride Lot 43 West",
    "Laurel Dr Parking Garage",
    "USF Health Faculty Office Building",
    "Holly Dr at Magnolia Dr",
    "USF Health at MDN",
    "Westside Conference Center",
    "College of Public Health",
    "Northwest Education Complex",
    "Chiles Center",
    "USF Health Therapy Building",
    "Child Development Center",
    "Morsani Advanced Healthcare",
    "School of Music",
    "Fine Arts Studio",
    "Theater Centre",

    //BROWN 
    "Library",
    "Math & Engineering",
    "The Retreat",
    "Busch Gardens Employee Entrance",
    "McKinley Dr at Bougainvillea Ave to LIB",
    "McKinley Dr to LIB",

    //GREEN - NEW
    "N 46th St at Fletcher District North",
    "N 46th St at Shadow Moss Ln",
    "N 46th St at USF Golf Center",
    "Skipper Rd at 43rd St",
    "N 42nd St at Hellenic Dr",
    "N 42nd St at Cambridge Woods Dr",
    "N 42nd St at Rocky Circle",
    "Palm Dr at Laurel Dr",
    "Post Office",
    "Parking and Transportation Services",
    "Moffitt Office Building",
    "Psychology to LIB",
    "Magnolia Dr at Parking Lot 19",
    "Juniper-Poplar",
    "University Technology Center",
    "Research Park",
    "Center for Urban Transportation Research",
    "Science Center",
    "Simmons Park",
    "Psychology to MSC",

    //ORANGE - NEW
    "North Campus Mail Center",
    "Holly Dr at Maple Suites",
    "Parking Lot 35",
    "Holly Dr at 50th St",
    "N 50th St at Bordeaux Village Pl",
    "N 50th St at Elm Dr",
    "Lee Roy Selmon Athletics Center",
    "Yuengling Center East Entrance",
    "Muma College of Business South Entrance",
    "Alumni Center",
    "Patel Center",
    "Softball Stadium",
    "Baseball Field",
    "Sycamore Dr at Elm Dr",
    "Sycamore Dr at Stadium",
    "Sycamore Dr at Holly Dr",
    "Greek Park",
    "Holly Drive Apartments",
    "The Village Holly Dr Entrance",

    //PURPLE - NEW
    "Genshaft Dr at Maple Suites",
    "Sessums Mall",
    "Muma College of Business",
    "Yuengling Center West Entrance",
    "Genshaft Dr at Parking Lot 35",

    //RED - NEW
    "Children's Medical Services",
    "N 22nd St at Vollmer Way",
    "N 22nd St at University Village",
    "Magnolia Apartments",
    "Magnolia Fields Complex",
    "HPC",
    "N 22nd St at University Lake Dr",
    "Holly Dr at MDA",
    "Holly Dr at Health Dr",
    "Stabile Research Building",
    "Moffitt Research Center"
};

vector<vector<Edge>> graph;
unordered_map<string, int> stopIndex;

void buildStopIndex(){
    stopIndex.clear();

    for (int i = 0; i< (int)stops.size(); i++){
        stopIndex[stops[i]] = i;
    }
}

void addRoute(string from, string to, int time, string routeName){
    int fromIndex = stopIndex[from];
    int toIndex  = stopIndex[to];

    graph[fromIndex].push_back({toIndex, time, routeName});
}

void buildGraph(){
    buildStopIndex();

    graph.clear();
    graph.resize(stops.size());

    //BLUE route
    addRoute("Marshall Student Center", "The Village Palm Dr Entrance", 2, "Blue");
    addRoute("The Village Palm Dr Entrance", "The Hub", 2, "Blue");
    addRoute("The Hub", "Parking Lot 56", 1, "Blue");
    addRoute("Parking Lot 56", "Publix", 1, "Blue");
    addRoute("Publix", "Park and Ride Lot 43 East", 2, "Blue");
    addRoute("Park and Ride Lot 43 East", "Park and Ride Lot 43 West", 1, "Blue");
    addRoute("Park and Ride Lot 43 West", "Laurel Dr Parking Garage", 2, "Blue");
    addRoute("Laurel Dr Parking Garage", "USF Health Faculty Office Building", 2, "Blue");
    addRoute("USF Health Faculty Office Building", "Holly Dr at Magnolia Dr", 2, "Blue");
    addRoute("Holly Dr at Magnolia Dr","USF Health at MDN", 2, "Blue");
    addRoute("USF Health at MDN", "Westside Conference Center", 2, "Blue");
    addRoute("Westside Conference Center", "College of Public Health", 1, "Blue");
    addRoute("College of Public Health", "Northwest Education Complex", 1, "Blue");
    addRoute("Northwest Education Complex", "Chiles Center", 1, "Blue");
    addRoute("Chiles Center", "USF Health Therapy Building", 3, "Blue");
    addRoute("USF Health Therapy Building", "Child Development Center", 1, "Blue");
    addRoute("Child Development Center", "Morsani Advanced Healthcare", 1, "Blue");
    addRoute("Morsani Advanced Healthcare", "School of Music", 2, "Blue");
    addRoute("School of Music", "Fine Arts Studio", 1, "Blue");
    addRoute("Fine Arts Studio", "Theater Centre", 1, "Blue");
    addRoute("Theater Centre", "Marshall Student Center", 1, "Blue");

    //BROWN route
    addRoute("Library", "Math & Engineering", 1, "Brown");
    addRoute("Math & Engineering", "The Retreat", 4, "Brown");
    addRoute("The Retreat", "Busch Gardens Employee Entrance", 5, "Brown");
    addRoute("Busch Gardens Employee Entrance", "McKinley Dr at Bougainvillea Ave to LIB", 3, "Brown");
    addRoute("McKinley Dr at Bougainvillea Ave to LIB", "McKinley Dr to LIB", 2, "Brown");
    addRoute("McKinley Dr to LIB", "Library", 4, "Brown");

    //GREEN route
    addRoute("Marshall Student Center", "The Village Palm Dr Entrance", 2, "Green");
    addRoute("The Village Palm Dr Entrance", "The Hub", 2, "Green");
    addRoute("The Hub", "Parking Lot 56", 1, "Green");
    addRoute("Parking Lot 56", "N 46th St at Fletcher District North", 3, "Green");
    addRoute("N 46th St at Fletcher District North", "N 46th St at Shadow Moss Ln", 1, "Green");
    addRoute("N 46th St at Shadow Moss Ln", "N 46th St at USF Golf Center", 1, "Green");
    addRoute("N 46th St at USF Golf Center", "Skipper Rd at 43rd St", 1, "Green");
    addRoute("Skipper Rd at 43rd St", "N 42nd St at Hellenic Dr", 2, "Green");
    addRoute("N 42nd St at Hellenic Dr", "N 42nd St at Cambridge Woods Dr", 1, "Green");
    addRoute("N 42nd St at Cambridge Woods Dr", "N 42nd St at Rocky Circle", 1, "Green");
    addRoute("N 42nd St at Rocky Circle", "Palm Dr at Laurel Dr", 3, "Green");
    addRoute("Palm Dr at Laurel Dr", "Post Office", 3, "Green");
    addRoute("Post Office", "Parking and Transportation Services", 1, "Green");
    addRoute("Parking and Transportation Services", "Moffitt Office Building", 2, "Green");
    addRoute("Moffitt Office Building", "Psychology to LIB", 1, "Green");
    addRoute("Psychology to LIB", "Magnolia Dr at Parking Lot 19", 2, "Green");
    addRoute("Magnolia Dr at Parking Lot 19", "Juniper-Poplar", 2, "Green");
    addRoute("Juniper-Poplar", "University Technology Center", 2, "Green");
    addRoute("University Technology Center", "Research Park", 1, "Green");
    addRoute("Research Park", "Library", 2, "Green");
    addRoute("Library", "Math & Engineering", 1, "Green");
    addRoute("Math & Engineering", "Center for Urban Transportation Research", 2, "Green");
    addRoute("Center for Urban Transportation Research", "Science Center", 2, "Green");
    addRoute("Science Center", "Simmons Park", 1, "Green");
    addRoute("Simmons Park", "Psychology to MSC", 2, "Green");
    addRoute("Psychology to MSC", "School of Music", 2, "Green");
    addRoute("School of Music", "Fine Arts Studio", 1, "Green");
    addRoute("Fine Arts Studio", "Theater Centre", 1, "Green");
    addRoute("Theater Centre", "Marshall Student Center", 1, "Green");

    //ORANGE route
}

void printStops() {
    cout << "Campus Shuttle Stops:\n";

    for (int i = 0; i < stops.size(); i++) {
        cout << i << " - " << stops[i] << endl;
    }

    cout << endl;
}

void printGraph() {
    cout << "Directed Campus Shuttle Graph:\n";

    for (int i = 0; i < graph.size(); i++) {
        cout << stops[i] << " -> ";

        for (Edge edge : graph[i]) {
            cout << stops[edge.to] << " (" << edge.time << " min) ";
        }

        cout << endl;
    }

    cout << endl;
}

vector<vector<Edge>>& getGraph() {
    return graph;
}

vector<string>& getStops() {
    return stops;
}