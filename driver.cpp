#include "Campus.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;

struct node nodeArray[24];

void menu()
{
    cout << "1. Benson Earth Sciences" << endl;
    cout << "2. Center for Community" << endl;
    cout << "3. Clare Small Arts and Science" << endl;
    cout << "4. Colorado Law" << endl;
    cout << "5. Cristol Chemistry and Biochemistry" << endl;
    cout << "6. Duane Physics and Astrophysics" << endl;
    cout << "7. Eaton Humanities" << endl;
    cout << "8. Ekeley Science" << endl;
    cout << "9. Engineering Center" << endl;
    cout << "10. Environmental Design" << endl;
    cout << "11. Fiske Planetarium" << endl;
    cout << "12. Fleming Law" << endl;
    cout << "13. Folsom Field" << endl;
    cout << "14. Hellems Arts and Sciences" << endl;
    cout << "15. Imig Music Building" << endl;
    cout << "16. Ketchum Arts and Sciences" << endl;
    cout << "17. Koelbel Building (Leeds School of Business)" << endl;
    cout << "18. Macky Auditorium Concert Hall" << endl;
    cout << "19. Muenzinger Auditorium" << endl;
    cout << "20. Norlin Library" << endl;
    cout << "21. Sewall Dining Center" << endl;
    cout << "22. Student Recreation Center" << endl;
    cout << "23. University Memorial Center," << endl;
    cout << "24. Wardenburg Health Center" << endl;
}

int main(int argc, char const *argv[])
{
    hashtable h;
    
    string s_input;
    string input1;
    string input2;
    int n_input1 = 0;
    int n_input2 = 0;
    
    ifstream infile;
    infile.open("list.txt");
    
    int i = 0;
    
    string line;
    
    //menu1();
    
    while(getline(infile, line))
    {
        if(line.compare("") != 0)
        {
            stringstream ss(line);
            
            string name;
            getline(ss, name, ',');
            
            string distanceX;
            getline(ss, distanceX, ',');
            float x = stof(distanceX);

            string distanceY;
            getline(ss, distanceY);
            float y = stof(distanceY);

            nodeArray[i].addElement(name, x, y);
            i++;
        }
        else
            break;
    }
    
//    while(getline(infile, line))
//    {
//        if(line.compare("") != 0)
//        {
//            stringstream ss(line);
//
//            string name2;
//            getline(ss, name2, ',');
//
//            string distanceX2;
//            getline(ss, distanceX2, ',');
//            float x = stof(distanceX2);
//
//            string distanceY2;
//            getline(ss, distanceY2);
//            float y = stof(distanceY2);
//
//            h.addItem(name2, x2, y2);
//        }
//        else
//            break;
//    }
    
//    while (input1 != 24)
//    {
//        getline(cin, input1);
//        //n_input = stoi(input1);
//        input1);
//
//        getline(cin, input2);
//        //n_input = stoi(input1);
//        string place2 = h.getnth(NULL, input1);
//    }
    
//    graph g;
//    //Creating vertices
//    for (int i = 0; i < 24; i++)
//    {
//        g.addVertex(nodeArray[i].name);
//    }
//    //Adding edges
//    for (int j = 0; j < 24; j++) {
//        for (int k = j+1; k < 24; k++)
//        {
//            node v1 = nodeArray[j];
//            node v2 = nodeArray[k];
//            g.addEdge(v1, v2);
//        }
//    }
//    //Printing the graph
//    g.printGraph();
    
    //first input
    cout << "Choose your starting point:" << endl;
    menu();
    getline(cin, input1);
    n_input1 = stoi(input1);
    
    while((n_input1 >= 1 && n_input1 <= 24) != true)
    {
        cout << "Invalid! Please enter a value input from 1 to 24." << endl;
        menu();
        getline(cin, input1);
        n_input1 = stoi(input1);
    }
    
    string name1 = nodeArray[n_input1-1].name;
    float x1 = nodeArray[n_input1-1].distanceX;
    float y1 = nodeArray[n_input1-1].distanceY;
    
    while((n_input1 >= 1 && n_input1 <= 24) == true)
    {
        cout << "Your starting point is " << name1 << ", correct? (type 'y' for yes or 'n' for no)" << endl;
        getline(cin, s_input);
        if (s_input == "y")
            break;
        else if (s_input == "n")
        {
            cout << "Please reenter your starting point:" << endl;
            menu();
            getline(cin, input1);
            n_input1 = stoi(input1);
            name1 = nodeArray[n_input1-1].name;
            x1 = nodeArray[n_input1-1].distanceX;
            y1 = nodeArray[n_input1-1].distanceY;
        }
        else
        {
            cout << "Invalid! Please enter 'y' for yes or 'n' for no." << endl;
        }
            
    }
    
    //second input
    cout << "Choose your destination:" << endl;
    menu();
    getline(cin, input2);
    n_input2 = stoi(input2);
    
    while((n_input2 >= 1 && n_input2 <= 24) != true)
    {
        cout << "Invalid! Please enter a value input from 1 to 24." << endl;
        menu();
        getline(cin, input2);
        n_input2 = stoi(input2);
    }
    
    string name2 = nodeArray[n_input2-1].name;
    float x2 = nodeArray[n_input2-1].distanceX;
    float y2 = nodeArray[n_input2-1].distanceY;
    
    while((n_input2 >= 1 && n_input2 <= 24) == true)
    {
        cout << "Your destination is " << name2 << ", correct? (type 'y' for yes or 'n' for no)" << endl;
        getline(cin, s_input);
        if (s_input == "y")
            break;
        else if (s_input == "n")
        {
            cout << "Please reenter your destination:" << endl;
            menu();
            getline(cin, input2);
            n_input2 = stoi(input2);
            name2 = nodeArray[n_input2-1].name;
            x2 = nodeArray[n_input2-1].distanceX;
            y2 = nodeArray[n_input2-1].distanceY;
        }
        else
        {
            cout << "Invalid! Please enter 'y' for yes or 'n' for no." << endl;
        }
            
    }
    
    //the distances of longtitude and latitude
    float distX = distanceX(x1, x2);
    float distY = distanceY(y1, y2);
    
    //best distance and time
    float bestDist = diagonalDistance(distX, distY);
    float bestTime = distanceToTime(bestDist);
    
    //worst distance and time
    float worstDist = worstCaseDistance(distX, distY);
    float worstTime = distanceToTime(worstDist);
    
    //average distance and time
    float aveDist = averageCaseDistance(bestDist, worstDist);
    float aveTime = distanceToTime(aveDist);
    
//    cout << "Between " << name1 << " and " << name2 << ":" << endl;
//    cout << "Best case distance and time are " << bestDist << " miles and " << bestTime << " minutes" << endl;
//    cout << "Worst case distance and time are " << worstDist << " miles and " << worstTime << " minutes" << endl;
//    cout << "Average case distance and time are " << aveDist << " miles and " << aveTime << " minutes" << endl;

    infile.close();

    return 0;
}
