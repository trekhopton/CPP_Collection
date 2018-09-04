#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>

typedef std::pair<int, int> coord;

struct cell {

    coord pos;
    bool occupied;
    //direction parent took to get here
    char dir;
    int f, g, h;
    coord parent;

    cell(int x, int y, bool o){
        pos.first = x;
        pos.second = y;
        occupied = o;
        f = INT_MAX;
        g = INT_MAX;
        h = INT_MAX;
        parent = coord(x, y);
        dir = 'n';
    }

};

class Environment {
public:
    //vector to contain environment
    std::vector<std::vector<cell> > cellGrid;
    //environment dimensions   
    int width;
    int height;
    
    Environment(char* fileName){
        //initialise game state

        std::ifstream input;
        input.open(fileName);

        if (input.is_open()){

            std::string line;
            getline(input, line);
            std::stringstream dStream;
            dStream << line;
            //parse w and h
            dStream >> width >> height;
            //parse cells
            for(int y = 0; y < height; y++){
                std::stringstream eStream;
                getline(input, line);
                std::vector<cell> lineVec;
                eStream << line;
                // parsing line by line
                bool tempOcc;
                int xCount = 0;
                while(eStream >> tempOcc){
                    cell nCell(xCount,y,tempOcc);
                    lineVec.push_back(nCell);
                    xCount++;
                }
                cellGrid.push_back(lineVec);
            }
            input.close();
        } else {
            std::cerr << "unable to open file" << std::endl;
        }
    }

    void display() {
        std::cout << "w: " << width << " h: " << height << std::endl;
        if(cellGrid.size() != 0){
            std::cout << "  ";
            for(int x = 0; x < cellGrid[0].size(); x++){
                std::cout << std::setw(2) << x;
            }
            std::cout << std::endl;
        }
        

        for(int y = 0; y < cellGrid.size(); y++){
            std::cout << std::setw(2) << y;
            for(int x = 0; x < cellGrid[y].size(); x++){
                if(cellGrid[y][x].occupied){
                    std::cout << "[]";
                } else {
                    std::cout << "__";
                }
            }
            std::cout << std::endl;
        }
    }

    bool isInRange(coord c){
        return (c.second >= 0) && (c.second < height) && (c.first >= 0) && (c.first < width);
    }
};

int manDist(coord start, coord stop){
    return abs(start.first - stop.first) + abs(start.second - stop.second);
}

std::string aStar(coord start, coord goal, Environment *env){
    // error if the start is out of range
    if(env->isInRange(start) != true){
        std::cerr << "start is not within environment bounds" << std::endl;
        return "error";
    }

    // error if the goal is out of range
    if(env->isInRange(goal) != true){
        std::cerr << "goal is not within environment bounds" << std::endl;
        return "error";
    }

    // the start or the goal is occupied
    if (env->cellGrid[start.second][start.first].occupied == 1 
    || env->cellGrid[goal.second][goal.first].occupied == 1){
        std::cout << "start or goal is occupied" << std::endl;
        return "error";
    }

    // if start is goal, no moves required
    if(start == goal){
        return "";
    }

    //make open <f, coord>, ... , <> set sorted by f
    std::set<std::pair<int, coord> > open;

    //make closed
    std::vector<std::vector<cell> > closed;
    for(int y = 0; y < env->height; y++){
        std::vector<cell> tCells;
        for(int x = 0; x < env->width; x++){
            cell tCell(x, y, 0);
            tCells.push_back(tCell);
        }
        closed.push_back(tCells);
    }

    //add start to open, just so the first loop can take it out and put it in closed
    open.insert(std::make_pair(0, start));

    while(!open.empty()){
        
        //cut cell from open
        std::pair<int, coord> cCell = *open.begin();
        open.erase(open.begin());

        // current x and y
        int cx = cCell.second.first;
        int cy = cCell.second.second;
        // std::cout << "CURRENT CELL: " << cx << ", " << cy << std::endl;

        //add cell to closed by setting state to 1
        closed[cy][cx].occupied = 1;

        // if the current cell is the goal, trace the path back and return the results
        if(closed[cy][cx].pos == goal){
            
            // //display directions to parents
            // for(int y = 0; y < closed.size(); y++){
            //     for(int x = 0; x < closed[0].size(); x++){
            //         std::cout << "[" << closed[y][x].dir << "]";
            //     }
            //     std::cout << std::endl;
            // }

            // //display parents
            // for(int y = 0; y < closed.size(); y++){
            //     for(int x = 0; x < closed[0].size(); x++){
            //         std::cout << "[" << closed[y][x].parent.first << "," << closed[y][x].parent.second << "]";
            //     }
            //     std::cout << std::endl;
            // }
            // std::cout << std::endl;

            // //display positions
            // for(int y = 0; y < closed.size(); y++){
            //     for(int x = 0; x < closed[0].size(); x++){
            //             std::cout << "[" << closed[y][x].pos.first << "," << closed[y][x].pos.second << "]";
                
            //     }
            //     std::cout << std::endl;
            // }
            
            //create variables to hold path string and grid
            std::vector<std::vector<cell>> pathGrid;
            for(int y = 0; y < env->height; y++){
                std::vector<cell> tCells;
                for(int x = 0; x < env->width; x++){
                    cell tCell(x, y, 0);
                    tCells.push_back(tCell);
                }
                pathGrid.push_back(tCells);
            }
            std::string path;
            int tempX = cx;
            int tempY = cy;
            //add first direction to path outside of loop, without a space
            path = closed[tempY][tempX].dir;
            pathGrid[tempY][tempX].occupied = 1;
            int holdX = tempX;
            int holdY = tempY;
            tempX = closed[holdY][holdX].parent.first;
            tempY = closed[holdY][holdX].parent.second;
            //add rest of directions to path with spaces before them
            while(closed[tempY][tempX].pos != start){
                pathGrid[tempY][tempX].occupied = 1;
                path = " " + path; 
                path = closed[tempY][tempX].dir + path;
                int holdX = tempX;
                int holdY = tempY;
                tempX = closed[holdY][holdX].parent.first;
                tempY = closed[holdY][holdX].parent.second;
            }

            // //display the resulting path
            // std::cout << "w: " << env->width << " h: " << env->height << std::endl;
            // if(env->cellGrid.size() != 0){
            //     std::cout << "  ";
            //     for(int x = 0; x < env->cellGrid[0].size(); x++){
            //         std::cout << std::setw(2) << x;
            //     }
            //     std::cout << std::endl;
            // }
            // for(int y = 0; y < env->cellGrid.size(); y++){
            //     std::cout << std::setw(2) << y;
            //     for(int x = 0; x < env->cellGrid[y].size(); x++){
            //         if(env->cellGrid[y][x].occupied){
            //             std::cout << "  ";
            //         } else if(start == coord(x, y)){
            //             std::cout << "\u2588\u2588";
            //         } else {
            //             if(closed[y][x].occupied){
            //                 if(pathGrid[y][x].occupied){
            //                     std::cout << "\u2588\u2588";
            //                 } else {
            //                     std::cout << "\u2592\u2592";
            //                 }
            //             } else {
            //                 std::cout << "\u2591\u2591";
            //             }
            //         }
            //     }
            //     std::cout << std::endl;
            // }

            return path;
        }

        //add adjacents to open
        //Left
        //if it's within the bounds of the environment
        if(env->isInRange(std::make_pair(cx-1, cy))){
            //if it's not a wall
            if(env->cellGrid[cy][cx-1].occupied != 1){
                //if it's not in the closed list
                if(closed[cy][cx-1].occupied != 1){
                    //calculate the g, h and f
                    int cg = env->cellGrid[cy][cx].g + 1;
                    int ch = manDist(std::make_pair(cx-1, cy), goal);
                    int cf = cg + ch;
                    //if it's never been in the open list or if the f is better than it was
                    if (env->cellGrid[cy][cx-1].f == INT_MAX || env->cellGrid[cy][cx-1].f > cf){
                        //update details and add to open list
                        env->cellGrid[cy][cx-1].g = cg;
                        env->cellGrid[cy][cx-1].h = ch;
                        env->cellGrid[cy][cx-1].f = cf;
                        closed[cy][cx-1].parent = coord(cx, cy);
                        closed[cy][cx-1].dir = 'L';
                        open.insert(std::make_pair(cf, std::make_pair(cx-1,cy)));
                        // std::cout << cx-1 << " : " << cy << std::endl;
                        // std::cout << "parent: " << closed[cy][cx-1].parent->pos.first << ", " << closed[cy][cx-1].parent->pos.second <<std::endl;
                    } else {
                        // std::cout << "left cell does not need updating" << std::endl;
                    }
                } else {
                    // std::cout << "left cell is in the closed list" << std::endl;
                }
            } else {
                // std::cout << "left cell is a wall" << std::endl;
            }
        } else {
            // std::cout << "left cell is not in range" << std::endl;
        }
        //Right
        if(env->isInRange(std::make_pair(cx+1, cy))){
            if(env->cellGrid[cy][cx+1].occupied != 1){
                if(closed[cy][cx+1].occupied != 1){
                    int cg = env->cellGrid[cy][cx].g + 1;
                    int ch = manDist(std::make_pair(cx+1, cy), goal);
                    int cf = cg + ch;
                    if (env->cellGrid[cy][cx+1].f == INT_MAX || env->cellGrid[cy][cx+1].f > cf){
                        env->cellGrid[cy][cx+1].g = cg;
                        env->cellGrid[cy][cx+1].h = ch;
                        env->cellGrid[cy][cx+1].f = cf;
                        closed[cy][cx+1].parent = coord(cx, cy);
                        closed[cy][cx+1].dir = 'R';
                        open.insert(std::make_pair(cf, std::make_pair(cx+1,cy)));
                        // std::cout << cx+1 << " : " << cy << std::endl;
                        // std::cout << "parent: " << closed[cy][cx+1].parent->pos.first << ", " << closed[cy][cx+1].parent->pos.second <<std::endl;
                    } else {
                        // std::cout << "right cell does not need updating" << std::endl;
                    }
                } else {
                    // std::cout << "right cell is in the closed list" << std::endl;
                }
            } else {
                // std::cout << "right cell is a wall" << std::endl;
            }
        } else {
            // std::cout << "right cell is not in range" << std::endl;
        }
        //Up
        if(env->isInRange(std::make_pair(cx, cy-1))){
            if(env->cellGrid[cy-1][cx].occupied != 1){
                if(closed[cy-1][cx].occupied != 1){
                    int cg = env->cellGrid[cy][cx].g + 1;
                    int ch = manDist(std::make_pair(cx, cy-1), goal);
                    int cf = cg + ch;
                    if (env->cellGrid[cy-1][cx].f == INT_MAX || env->cellGrid[cy-1][cx].f > cf){
                        env->cellGrid[cy-1][cx].g = cg;
                        env->cellGrid[cy-1][cx].h = ch;
                        env->cellGrid[cy-1][cx].f = cf;
                        closed[cy-1][cx].parent = coord(cx, cy);
                        closed[cy-1][cx].dir = 'U';
                        open.insert(std::make_pair(cf, std::make_pair(cx,cy-1)));
                        // std::cout << cx << " : " << cy-1 << std::endl;
                        // std::cout << "parent: " << closed[cy-1][cx].parent->pos.first << ", " << closed[cy-1][cx].parent->pos.second <<std::endl;
                    } else {
                        // std::cout << "up cell does not need updating" << std::endl;
                    }
                } else {
                    // std::cout << "up cell is in the closed list" << std::endl;
                }
            } else {
                // std::cout << "up cell is a wall" << std::endl;
            }
        } else {
            // std::cout << "up cell is not in range" << std::endl;
        }
        //Down
        if(env->isInRange(std::make_pair(cx, cy+1))){
            if(env->cellGrid[cy+1][cx].occupied != 1){
                if(closed[cy+1][cx].occupied != 1){
                    int cg = env->cellGrid[cy][cx].g + 1;
                    int ch = manDist(std::make_pair(cx, cy+1), goal);
                    int cf = cg + ch;
                    if (env->cellGrid[cy+1][cx].f == INT_MAX || env->cellGrid[cy+1][cx].f > cf){
                        env->cellGrid[cy+1][cx].g = cg;
                        env->cellGrid[cy+1][cx].h = ch;
                        env->cellGrid[cy+1][cx].f = cf;
                        closed[cy+1][cx].parent = coord(cx, cy);
                        closed[cy+1][cx].dir = 'D';
                        open.insert(std::make_pair(cf, std::make_pair(cx,cy+1)));
                        // std::cout << cx << " : " << cy+1 << std::endl;
                        // std::cout << "parent: " << closed[cy+1][cx].parent->pos.first << ", " << closed[cy+1][cx].parent->pos.second <<std::endl;
                    } else {
                        // std::cout << "down cell does not need updating" << std::endl;
                    }
                } else {
                    // std::cout << "down cell is in the closed list" << std::endl;
                }
            } else {
                // std::cout << "down cell is a wall" << std::endl;
            }
        } else {
            // std::cout << "down cell is not in range" << std::endl;
        }
        // std::set<std::pair<int, coord>>::iterator it;
        // for(it = open.begin(); it != open.end(); ++it){
        //     std::cout << "(" << (*it).second.first << ", " << (*it).second.second << ")";
        // }
        // std::cout << std::endl;
    }

    // //display directions to parents
    // for(int y = 0; y < closed.size(); y++){
    //     for(int x = 0; x < closed[0].size(); x++){
    //         std::cout << "[" << closed[y][x].dir << "]";
    //     }
    //     std::cout << std::endl;
    // }

    // //display parents
    // for(int y = 0; y < closed.size(); y++){
    //     for(int x = 0; x < closed[0].size(); x++){
    //         std::cout << "[" << closed[y][x].parent.first << "," << closed[y][x].parent.second << "]";
    //     }
    //     std::cout << std::endl;
    // }

    return "goal not found";
}

int main (int argc, char* argv[]){
    // -- check if right input --
    if(argc != 6){
        std::cerr << "wrong number of arguments" << std::endl;
        return 1;
    }

    coord start(atoi(argv[2]), atoi(argv[3]));
    coord goal(atoi(argv[4]), atoi(argv[5]));
    Environment *env = new Environment(argv[1]);

    std::cout << aStar(start, goal, env) << std::endl;

    delete env;

    return 0;

}

