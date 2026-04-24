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
    "The Village Palm Dr Entrance",
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
    "UATC to LIB",
    "E 131st Ave to LIB",
    "N 22nd St at Vollmer Way",
    "N 22nd St at University Village",
    "HUB Tampa to Library",
    "The Standard to LIB",
    "Botanical Gardens to Library",
    "Magnolia Apartments",
    "Magnolia Fields Complex",
    "Botanical Gardens to Mall",
    "The Standard to MSC",
    "HUB Tampa to MSC",
    "N 22nd St at University Village to MSC",
    "N 22nd St at University Lake Dr",
    "E 131st Ave to MSC",
    "UATC to MSC",
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
    addRoute("Marshall Student Center", "North Campus Mail Center", 3, "Orange");
    addRoute("North Campus Mail Center", "Holly Dr at Maple Suites", 1, "Orange");
    addRoute("Holly Dr at Maple Suites", "Parking Lot 35", 2, "Orange");
    addRoute("Parking Lot 35", "Holly Dr at 50th St", 1, "Orange");
    addRoute("Holly Dr at 50th St", "N 50th St at Bordeaux Village Pl", 2, "Orange");
    addRoute("N 50th St at Bordeaux Village Pl", "N 50th St at Elm Dr", 1, "Orange");
    addRoute("N 50th St at Elm Dr", "Lee Roy Selmon Athletics Center", 3, "Orange");
    addRoute("Lee Roy Selmon Athletics Center", "Yuengling Center East Entrance", 1, "Orange");
    addRoute("Yuengling Center East Entrance", "Muma College of Business South Entrance", 3, "Orange");
    addRoute("Muma College of Business South Entrance", "Library", 2, "Orange");
    addRoute("Library", "Math & Engineering", 1, "Orange");
    addRoute("Math & Engineering", "Alumni Center", 2, "Orange");
    addRoute("Alumni Center", "Patel Center", 2, "Orange");
    addRoute("Patel Center", "Softball Stadium", 1, "Orange");
    addRoute("Softball Stadium", "Baseball Field", 1, "Orange");
    addRoute("Baseball Field", "Sycamore Dr at Elm Dr", 1, "Orange");
    addRoute("Sycamore Dr at Elm Dr", "Sycamore Dr at Stadium", 1, "Orange");
    addRoute("Sycamore Dr at Stadium", "Sycamore Dr at Holly Dr", 1, "Orange");
    addRoute("Sycamore Dr at Holly Dr", "Greek Park", 1, "Orange");
    addRoute("Greek Park", "Holly Drive Apartments", 2, "Orange");
    addRoute("Holly Drive Apartments", "The Village Holly Dr Entrance", 2, "Orange");
    addRoute("The Village Holly Dr Entrance", "The Village Palm Dr Entrance", 2, "Orange");
    addRoute("The Village Palm Dr Entrance", "The Hub", 2, "Orange");
    addRoute("The Hub", "Parking Lot 56", 1, "Orange");
    addRoute("Parking Lot 56", "Publix", 1, "Orange");
    addRoute("Publix", "Park and Ride Lot 43 East", 2, "Orange");
    addRoute("Park and Ride Lot 43 East", "Park and Ride Lot 43 West", 1, "Orange");
    addRoute("Park and Ride Lot 43 West", "Laurel Dr Parking Garage", 1, "Orange");
    addRoute("Laurel Dr Parking Garage", "School of Music", 2, "Orange");
    addRoute("School of Music", "Fine Arts Studio", 1, "Orange");
    addRoute("Fine Arts Studio", "Theater Centre", 1, "Orange");
    addRoute("Theater Centre", "Marshall Student Center", 1, "Orange");

    //PURPLE route
    addRoute("Marshall Student Center", "North Campus Mail Center", 3, "Purple");
    addRoute("North Campus Mail Center", "Holly Dr at Maple Suites", 1, "Purple");
    addRoute("Holly Dr at Maple Suites", "Genshaft Dr at Maple Suites", 1, "Purple");
    addRoute("Genshaft Dr at Maple Suites", "Sessums Mall", 2, "Purple");
    addRoute("Sessums Mall", "Muma College of Business", 1, "Purple");
    addRoute("Muma College of Business", "Muma College of Business South Entrance", 2, "Purple");
    addRoute("Muma College of Business South Entrance", "Library", 2, "Purple");
    addRoute("Library", "Math & Engineering", 1, "Purple");
    addRoute("Math & Engineering", "Alumni Center", 1, "Purple");
    addRoute("Alumni Center", "Yuengling Center West Entrance", 2, "Purple");
    addRoute("Yuengling Center West Entrance", "Genshaft Dr at Parking Lot 35", 2, "Purple");
    addRoute("Genshaft Dr at Parking Lot 35", "Holly Drive Apartments", 2, "Purple");
    addRoute("Holly Drive Apartments", "The Village Holly Dr Entrance", 2, "Purple");
    addRoute("The Village Holly Dr Entrance", "The Village Palm Dr Entrance", 2, "Purple");
    addRoute("The Village Palm Dr Entrance", "The Hub", 2, "Purple");
    addRoute("The Hub", "Parking Lot 56", 1, "Purple");
    addRoute("Parking Lot 56", "N 46th St at Fletcher District North", 3, "Purple");
    addRoute("N 46th St at Fletcher District North", "N 46th St at Shadow Moss Ln", 1, "Purple");
    addRoute("N 46th St at Shadow Moss Ln", "N 46th St at USF Golf Center", 1, "Purple");
    addRoute("N 46th St at USF Golf Center", "Skipper Rd at 43rd St", 1, "Purple");
    addRoute("Skipper Rd at 43rd St", "N 42nd St at Hellenic Dr", 2, "Purple");
    addRoute("N 42nd St at Hellenic Dr", "N 42nd St at Cambridge Woods Dr", 1, "Purple");
    addRoute("N 42nd St at Cambridge Woods Dr", "N 42nd St at Rocky Circle", 1, "Purple");
    addRoute("N 42nd St at Rocky Circle", "Palm Dr at Laurel Dr", 3, "Purple");
    addRoute("Palm Dr at Laurel Dr", "Marshall Student Center", 3, "Purple");

    //RED route
    addRoute("Marshall Student Center", "Post Office", 3, "Red");
    addRoute("Post Office", "Parking and Transportation Services", 1, "Red");
    addRoute("Parking and Transportation Services", "USF Health Faculty Office Building", 2, "Red");
    addRoute("USF Health Faculty Office Building", "Holly Dr at Magnolia Dr", 2, "Red");
    addRoute("Holly Dr at Magnolia Dr", "Children's Medical Services", 1, "Red");
    addRoute("Children's Medical Services", "UATC to LIB", 2, "Red");
    addRoute("UATC to LIB", "E 131st Ave to LIB", 2, "Red");
    addRoute("E 131st Ave to LIB", "N 22nd St at Vollmer Way", 3, "Red");
    addRoute("N 22nd St at Vollmer Way", "N 22nd St at University Village", 1, "Red");
    addRoute("N 22nd St at University Village", "HUB Tampa to Library", 4, "Red");
    addRoute("HUB Tampa to Library", "The Standard to LIB", 2, "Red");
    addRoute("The Standard to LIB", "Botanical Gardens to Library", 3, "Red");
    addRoute("Botanical Gardens to Library", "University Technology Center", 2, "Red");
    addRoute("University Technology Center", "Research Park", 1, "Red");
    addRoute("Research Park", "Library", 2, "Red");
    addRoute("Library", "Math & Engineering", 1, "Red");
    addRoute("Math & Engineering", "Center for Urban Transportation Research", 2, "Red");
    addRoute("Center for Urban Transportation Research", "Magnolia Apartments", 2, "Red");
    addRoute("Magnolia Apartments", "Magnolia Fields Complex", 2, "Red");
    addRoute("Magnolia Fields Complex", "Botanical Gardens to Mall", 1, "Red");
    addRoute("Botanical Gardens to Mall", "The Standard to MSC", 2, "Red");
    addRoute("The Standard to MSC", "HUB Tampa to MSC", 2, "Red");
    addRoute("HUB Tampa to MSC", "N 22nd St at University Village to MSC", 4, "Red");
    addRoute("N 22nd St at University Village to MSC", "N 22nd St at University Lake Dr", 1, "Red");
    addRoute("N 22nd St at University Lake Dr", "E 131st Ave to MSC", 2, "Red");
    addRoute("E 131st Ave to MSC", "UATC to MSC", 1, "Red");
    addRoute("UATC to MSC", "Holly Dr at MDA", 3, "Red");
    addRoute("Holly Dr at MDA", "Holly Dr at Health Dr", 1, "Red");
    addRoute("Holly Dr at Health Dr", "Stabile Research Building", 1, "Red");
    addRoute("Stabile Research Building", "Moffitt Research Center", 2, "Red");
    addRoute("Moffitt Research Center", "School of Music", 2, "Red");
    addRoute("School of Music", "Fine Arts Studio", 1, "Red");
    addRoute("Fine Arts Studio", "Theater Centre", 1, "Red");
    addRoute("Theater Centre", "Marshall Student Center", 1, "Red");
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