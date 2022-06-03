#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class ShipPart {
public:
    int y;
    int x;
    bool hit = false;
};

class Ship
{
public:
    std::vector<ShipPart> ShipPart;
    int size;
    std::string typeOfShip;

    Ship(int p_size, std::string p_typeOfShip) : size(p_size), typeOfShip(p_typeOfShip) {

    }
};


class Board {
public:
   
    std::vector<std::vector<char>> vec =
    {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //1
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //2
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //3
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //4
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //5
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //6
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //7
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //8
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //9
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, //10
    };


    std::vector<char> collumn { 'a','b','c','d','e','f','g','h','i','j' };
    std::vector<int> row { 0,1,2,3,4,5,6,7,8,9 };



    void printBoard() {
        std::cout << std::endl;
        std::cout << "Players board: " << std::endl;
        for (int i = 0; i < row.size(); ++i) {
            std::cout << "  " << collumn[i] << " ";
        }

        std::cout << std::endl;

        for (int i = 0; i < vec.size(); ++i) {
            std::cout << row[i];
            for (int j = 0; j < vec[i].size(); ++j) {
                std::cout << '|' << vec[i][j] << "| ";
            }

            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};


class Player
{
public:
    std::string name;
    Board board;
    std::vector<Ship> shipSet;

    Player(std::string p_name, Board &p_board, std::vector<Ship> p_shipSet) : name(p_name), board(p_board), shipSet(p_shipSet) {}
};

class GamePlay {
public:
    
    Board board_2;

    void settingUpShips(Player& player) {
        std::cout << player.name << " is setting his ships" << std::endl;

        int queue = 0;

        std::string coord;

        char shipSign = 'x';
        std::string vertical = "v";
        std::string horizontal = "h";
        
        std::string numExtrcted = "";
        std::string letterExtracted = "";
        std::string axis = "";


        // 3 bo sa trzy statki
        while (queue != 3) {

            std::getline(std::cin, coord);

            numExtrcted = "";
            letterExtracted = "";
            axis = "";

            std::string partOfShip;
            partOfShip = coord[0] + coord[1];

            numExtrcted = coord[1];
            letterExtracted = coord[0];
            axis = coord[2];


            bool isNumber = isdigit(coord[1]);
            bool isLetter = (coord[0] >= 'a') && (coord[0] <= 'j');

            int xCoord = 0;
            int yCoord = 0;

            if (coord.size() <= 3 && isNumber && isLetter) {

                yCoord = stoi(numExtrcted);

                for (int i = 0; i < 10; ++i) {
                    if (letterExtracted[0] == board_2.collumn[i]) {
                        xCoord = i;
                        break;
                    }
                }
            }

            //kolejka gracza ustawiajacego statki trwa tyle iteracji ile jest statkow w jego zestawie, dlatego shipSet[queue]
            for (int i = 0; i < player.shipSet[queue].size; ++i) {
                if (axis == vertical) {
                    if (player.board.vec[yCoord + i][xCoord] != shipSign) {

                        player.board.vec[yCoord + i][xCoord] = shipSign;
                        //przypisywanie kazdej czesci statku wpolzedne
                        player.shipSet[queue].ShipPart.push_back({yCoord + i , xCoord});
                        
                    } else {
                        wrongInputInformation();
                    }

                   
                }
                else if (axis == horizontal) {
                    if (player.board.vec[yCoord][xCoord + i] != shipSign) {

                        player.board.vec[yCoord][xCoord + i] = shipSign;
                        //przypisywanie kazdej czesci statku wpolzedne
                        player.shipSet[queue].ShipPart.push_back({ yCoord , xCoord +i});
                    } else {
                        wrongInputInformation();
                    }
                }
                else {
                    if (player.board.vec[yCoord + i][xCoord] != shipSign) {

                        player.board.vec[yCoord][xCoord] = shipSign;
                        //przypisywanie kazdej czesci statku wpolzedne
                    }
                    else {
                        wrongInputInformation();
                    }
                }
            }

            coord = "";
            partOfShip = "";

            queue++;
        }
    }

    void wrongInputInformation() {
        std::cout << "Wrong input" << std::endl;
        exit(1);
    }
};


int main() {
    auto firstSetOfShips = std::vector<Ship>{};
    auto secondSetOfShips = std::vector<Ship>{};

    Ship twoSailsShip_1(2, "Dwumasztowiec");
    Ship oneSailsShip_1(1, "jednomasztowiec");
    Ship threeSailsShip_1(3, "trzymasztowiec");
    
    
    Ship twoSailsShip_2(2, "Dwumasztowiec");
    Ship oneSailsShip_2(1, "jednomasztowiec");
    Ship threeSailsShip_2(3, "trzymasztowiec");

    firstSetOfShips.push_back(twoSailsShip_1);
    firstSetOfShips.push_back(oneSailsShip_1);
    firstSetOfShips.push_back(threeSailsShip_1);

    secondSetOfShips.push_back(twoSailsShip_2);
    secondSetOfShips.push_back(oneSailsShip_2);
    secondSetOfShips.push_back(threeSailsShip_2);
    
    
    Board board_1;
    Board board_2;
        
    
    Player p1("Player one", board_1, firstSetOfShips);
    Player p2("Player two", board_2, secondSetOfShips);
    
    GamePlay game;

    game.settingUpShips(p1);
    p1.board.printBoard();

   
       std::cout << p1.shipSet[2].ShipPart[0].x;
    
    std::cout << std::endl;
    
      std::cout << p1.shipSet[2].ShipPart[0].y;
    
   // game.settingUpShips(p2);
   // p2.board.printBoard();


    
 
}