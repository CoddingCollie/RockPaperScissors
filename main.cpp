#include <iostream>
#include <random>

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;

void playerWin(int playerPick, int computerPick, int& playerPts);
void computerWin(int playerPick, int computerPick, int& computerPts);
void compareResults(int playerPick, int computerPick, int& playerPts, int& computerPts);
void showScores(int computerPts, int playerPts);
void goodbyeMessage();

int main() {
    // Set the state of the gaming being played as true
    bool inGame{ true };

    // Initialize the scores of the computer and player as 0
    int computerPts{ 0 };
    int playerPts{ 0 };
    
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a uniform distribution
    std::uniform_int_distribution<> distrib(ROCK, SCISSORS);

    while (inGame) {
        // Generate the random number
        int computerPick{ distrib(gen) };
        std::cout << "Computer Pick: " << computerPick << std::endl;
        
        // Shows options to player
        std::cout << "Pick your play: \n-[1] Rock\n-[2] Paper\n-[3] Scissors" << std::endl;
        
        //Receive player pick
        int playerPick{0};
        std::cin >> playerPick;
        
        // Check the computer answer against the players
        compareResults(playerPick, computerPick, playerPts, computerPts);
    
        // Ask if the player wants to continue
        int playerAnswer{};
        std::cout << "Do you wish to keep on playing? \n-[1] YES\n-[2] NO" << std::endl;
        std::cin >> playerAnswer;

        // Check player's answer about continuing or not
        if (playerAnswer == 2) {
            inGame = false;
        }
        
    }

    // Call the method that shows the score
    showScores(computerPts, playerPts);

    // Call the method that shows the goodbye message
    goodbyeMessage();
    return 0;
}

void playerWin(int playerPick, int computerPick, int& playerPts) {
    std::cout << "You chose: " << playerPick << ". I chose: " << computerPick << ". You win!";
    playerPts++;
    }

void computerWin(int playerPick, int computerPick, int& computerPts) {
    std::cout << "You chose: " << playerPick << ". I chose: " << computerPick << ". You lose!";
    computerPts++;
    }

void compareResults(int playerPick, int computerPick, int& playerPts, int& computerPts) {
    if (computerPick == playerPick) {
        std::cout << "It's a draw.";
    } else {
        switch (computerPick) {
            case ROCK:
                if (playerPick == PAPER) 
                    playerWin(playerPick, computerPick, playerPts);
                else
                    computerWin(playerPick, computerPick, computerPts);
                break;

            case PAPER:
                if (playerPick == SCISSORS)
                    playerWin(playerPick, computerPick, playerPts);
                else
                    computerWin(playerPick, computerPick, computerPts);
                break;

            case SCISSORS:
                if (playerPick == ROCK)
                    playerWin(playerPick, computerPick, playerPts);
                else
                    computerWin(playerPick, computerPick, computerPts);
                break;
        }
    }

    std::cout << std::endl;
}

void showScores(int computerPts, int playerPts) {
    std::cout << "------------ SCORES ------------" << std::endl;
    std::cout << "- Computer Score: " << computerPts << std::endl;
    std::cout << "- Player Score: " << playerPts << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

void goodbyeMessage() {
    std::cout << "Good Bye! (owo)/" << std::endl;
}
//------------------------------------------ Planning ------------------------------------------//
/* - Start the game in a while loop
 *      - The computer picks (1)rock, (2) paper, or (3) scissors
 *      - Both start with 0 points
 *      - It asks the player if they want rock, paper or scisors
 *      - The player picks (1)rock, (2) paper, or (3) scissors
 *      - Compares both picks, if the comp and player chose the same it is a draw, if not we do the following
 *               - if computer pick = 1 and player pick = 2 | player wins, +1 to their pts, otherwise player loses and +1 to computer's pts
 *               - if computer pick = 2 and player pick = 3 | player wins, +1 to their pts, otherwise player loses and +1 to computer's pts
 *               - if computer pick = 3 and player pick = 1 | player wins, +1 to their pts, otherwise player loses and +1 to computer's pts
 * - Ask if the player wants to play again
 * - If player says (1)yes we loop back, if they say (2)no we get out of the loop
 * - Show final score
 * - Say goodbye
 * - Create a GUI
 */