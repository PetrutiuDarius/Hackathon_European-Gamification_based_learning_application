#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>
#include <algorithm>
#include <windows.h>

using namespace std;

int score = 0;

namespace consoleforeground
{
    enum
    {
        BLACK = 0,
        WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    };
}
namespace consolebackground
{
    enum
    {
        BLACK = 0,
        GREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
        CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
        RED = BACKGROUND_INTENSITY | BACKGROUND_RED,
        WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    };
}

vector<int> snake;
bool kids = 0, self_hit = 1, reverse_snake = 0;
int width = 27, lenght = 118, food_x = -1, food_y = -2, hsc, time1 = 50;

class Board
{
public:
    void setConsoleColour(unsigned short colour)
    {
        static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        cout.flush();
        SetConsoleTextAttribute(hOut, colour);
    }

    void setcursor(int x, int y)
    {
        static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        cout.flush();
        COORD coord = {(SHORT)x, (SHORT)y};
        SetConsoleCursorPosition(hOut, coord);
    }

    void print_title()
    {
        setcursor(0, 0);
        setConsoleColour(consoleforeground::WHITE);
        cout << "YOUR SCORE:                     ";
        cout << "\n";
        // printing walls
        setConsoleColour(consolebackground::CYAN);
        for (int i = 0; i < lenght + 2; i++)
            cout << " ";
        cout << "\n";
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < lenght + 2; j++)
            {
                if (j == 0 || j == lenght + 1)
                    setConsoleColour(consolebackground::CYAN);
                else
                    setConsoleColour(consolebackground::BLACK);
                cout << " ";
            }
            cout << "\n";
        }
        setConsoleColour(consolebackground::CYAN);
        for (int i = 0; i < lenght + 2; i++)
            cout << " ";
    }

    void print_highscore()
    {
        int i, j;
        setcursor(11, 0);
        setConsoleColour(consoleforeground::WHITE);
        cout << snake.size() / 2 - 3 << "  ";
    }

    void welcome_to(int &score)
    {
        system("cls");
        setConsoleColour(consoleforeground::WHITE);
        int a;
        bool t = 1;
        cout << "\n\n\n\n\n\n\n\n\n                                      Your final score was: " << "  " << score << "\n\n";
        cout << "                                      WELCOME TO THE SNAKE GAME\n\n";
        cout << "                                          press any key to start the game..";
        a = getch();
    }

    int print_final_message()
    {
        setConsoleColour(consoleforeground::BLACK);
        system("cls");
        setConsoleColour(consoleforeground::WHITE);
        int a = snake.size() / 2 - 3, k;
        if (a > hsc)
            hsc = a;
        cout << "\n\n\n\n\n               GAME OVER\n";
        cout << "               YOUR SCORE: " << snake.size() / 2 - 3 << endl;
        cout << "               HIGH SCORE: " << hsc;
        cout << endl
             << endl
             << endl;
        cout << "               PRESS ANY KEY TO RESTART\n";
        cout << "               esc to EXIT\n\n\n\n\n\n";
        setConsoleColour(consoleforeground::WHITE);

        a = getch();
        return a;
    }
};

class Snake : public Board
{

public:
    void initialise_snake(int &score)
    {
        snake.clear();
        for (int i = 0; i < score; i++)
        {
            snake.push_back(0);
            snake.push_back(i);
        }
    }

    void move_snake(int move, char direction)
    {
        int i, j;
        if (direction == 'v')
        {
            snake.push_back(snake[snake.end() - 2 - snake.begin()] + move);
            snake.push_back(snake[snake.end() - 2 - snake.begin()]);
        }
        else
        {
            snake.push_back(snake[snake.end() - 2 - snake.begin()]);
            snake.push_back(snake[snake.end() - 2 - snake.begin()] + move);
        }
        setcursor(snake[1] + 1, snake[0] + 2);
        setConsoleColour(consolebackground::BLACK);
        cout << " ";
        snake.erase(snake.begin());
        snake.erase(snake.begin());

        if (snake.back() == lenght && kids)
            snake.back() -= lenght;
        else if (snake.back() == -1 && kids)
            snake.back() += lenght;
        else if (snake[snake.end() - snake.begin() - 2] == -1 && kids)
            snake[snake.end() - snake.begin() - 2] += width;
        else if (snake[snake.end() - snake.begin() - 2] == width && kids)
            snake[snake.end() - snake.begin() - 2] -= width;

        setcursor(snake.back() + 1, snake[snake.end() - snake.begin() - 2] + 2); // printing snake

        setConsoleColour(consolebackground::RED);
        cout << " ";

        setcursor(snake[snake.end() - snake.begin() - 3] + 1, snake[snake.end() - snake.begin() - 4] + 2); // body of snake
        setConsoleColour(consolebackground::GREEN);
        cout << " ";
    }
    void eat_food()
    {
        food_x = rand() % (width);
        food_y = rand() % (lenght);
        setcursor(food_y + 1, food_x + 2);
        setConsoleColour(consolebackground::WHITE);
        cout << " ";

        snake.insert(snake.begin(), snake[1]);
        snake.insert(snake.begin(), snake[1]);
    }

    bool check_interbody_death()
    {
        int x, y, i;
        bool j = 0;
        x = snake[snake.end() - snake.begin() - 2];
        y = snake.back();
        for (i = 0; i < snake.size() - 2; i = i + 2)
        {
            if (x == snake[i] && y == snake[i + 1])
            {
                j = 1;
                break;
            }
        }
        return j;
    }
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(0));

    Board brd;
    Snake snk;

Quiz:

    // Întrebarea 1
    cout << "1. What Climate neutrality, a pivotal concept of EU politics in connection with CLIMATE CHANGE, refers to?\n";
    cout << "A1. Climate neutrality refers to the control of climate evolution for maintaining it in a condition most favorable to life. (F)\n";
    cout << "A2. Climate neutrality refers to the mitigation of carbon dioxide concentration into the atmosphere. (F)\n";
    cout << "A3. Climate neutrality refers to the mitigation of all the greenhouse gases (GHG) into the atmosphere. (T)\n";
    cout << "A4. Climate neutrality refers to the emission of as much greenhouse gas (GHG) into the atmosphere as can be absorbed by nature, that is forests, oceans and soil. (T)\n";

    char response1;
    cout << "Enter your choice (1, 2, 3, 4): ";
    cin >> response1;
    if (response1 == '3' || response1 == '4')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 2
    cout << "\n2. What is the EU target regarding climate neutrality, in accordance to Green Deal objectives?\n";
    cout << "A1. The EU target regarding climate neutrality is 55% emissions reduction by 2050. (F)\n";
    cout << "A2. The EU target regarding climate neutrality is zero net emissions by 2040. (F)\n";
    cout << "A3. The EU target regarding climate neutrality is gradual reduction of emissions until zero emissions by the end of the century. (F)\n";
    cout << "A4. The EU target regarding climate neutrality is zero net emissions by 2050. (T)\n";

    char response2;
    cout << "Enter your choice (1, 2, 3, 4): ";
    cin >> response2;
    if (response2 == '4')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 3
    cout << "\n3. Is the climate neutrality the same concept as the carbon neutrality? Please answer and give short explanation\n";
    cout << "A1. Yes, they are the same and both refer to the limitation of greenhouse gases (GHG)' emission into the atmosphere to that quantity which can be naturally absorbed into nature or due to human activities. (F)\n";
    cout << "A2. No, only the concept of climate neutrality is used referring to the limitation of greenhouse gases (GHG)' emission into the atmosphere to that quantity which can be naturally absorbed into nature or due to human activities; but carbon neutrality is neither used, nor explained. (F)\n";
    cout << "A3. No, the climate neutrality refers to the limitation of greenhouse gases (GHG)' emission into the atmosphere to that quantity which can be naturally absorbed into nature or due to human activities, but carbon neutrality refers only to the carbon dioxide emissions decrease until the equal balance with its absorption into environment or due to human activities (T)\n";
    cout << "A4. No, these concepts are not the same, as the climate neutrality refers to the equal balance between the GSG emission into atmosphere and its absorption by nature and human activities, and the carbon neutrality refers to the carbon cycle into the nature. (F)\n";

    char response3;
    cout << "Enter your choice (1, 2, 3, 4): ";
    cin >> response3;
    if (response3 == '3')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 4
    cout << "\n4. Which are the greenhouse gases (GHG) and name the most abundant among them?\n";
    cout << "A1. The greenhouse gases (GHG) comprise carbon dioxide and ozone, with the carbon dioxide the most abundant. (F)\n";
    cout << "A2. GHGs include carbon dioxide, methane, nitrous oxide, chlorofluorocarbons, ozone, and water vapor, with carbon dioxide of about 80% of the total (T).\n";
    cout << "A3. Beside the determination of carbon dioxide, ozone and water vapor, there are not precise information about other gases and one cannot appreciate the GHGs quantitative composition. (F)\n";
    cout << "A4. The GHGs composition varies so much function of weather, environment, human activity and other situations and consequently beside the abundant presence of carbon dioxide, there is not a general evaluation. (F)\n";

    char response4;
    cout << "Enter your choice (1, 2, 3, 4): ";
    cin >> response4;
    if (response4 == '2')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 5
    cout << "\n5. Has the transition towards climate neutrality economic and social benefices or it brings only higher economic costs?\n";
    cout << "A1. Beside the higher economic costs, the transition towards climate neutrality brings significant opportunities for economic growth, markets and jobs, technological development. (T)\n";
    cout << "A2. There are not economic or social opportunities due to transition towards climate neutrality, it brings only higher economic costs. (F)\n";
    cout << "A3. The transition towards climate neutrality does not involve higher economic costs, but brings only economic and social benefices (F)\n";
    cout << "A4. The transition towards climate neutrality has no economic or social consequences, either positive or negative (F)\n";

    char response5;
    cout << "Enter your choice (1, 2, 3, 4): ";
    cin >> response5;
    if (response5 == '1')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 6
    cout << "\n6. The carbon dioxide utilization by chemical / biochemical transformation into useful products was studied?\n";
    cout << "A1. There are not technological researches regarding chemical / biochemical transformation of carbon dioxide into useful products (F).\n";
    cout << "A2. Ther are many technological studies regarding chemical / biochemical transformation of carbon dioxide into useful products, but not economically developed due to still technical challenges. (T).\n";
    cout << "A3. Ther are already new industrial developments to use the carbon dioxide emissions for practical applications (F).\n";
    cout << "A4. Due to huge technological and economical difficulties there is no interest to develop technologies for using the carbon dioxide (F).\n";

    char response6;
    cout << "Enter your choice (1, 2, 3, 4): ";
    cin >> response6;
    if (response6 == '2')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 7
    cout << "\n7. The progress target and the needed actions towards achieving climate neutrality is comprised into an existing specific EU law?\n";
    cout << "A1. The European Union Commission adopted the EU Climate Law in 2021 dedicated to the tasks of achieving climate neutrality (T).\n";
    cout << "A2. There is not an EU Climate Law, as the topic was defined in other EU Commission laws and documents in connection with the actions for climate change stopping. (F)\n";
    cout << "A3. There is a proposal of EU Climate Law still in public debate (F).\n";
    cout << "A4. There is the EU Climate Law, but the EU Commission decided to replace this existing law with a new one more appropriate for the climate changing and socio-economic needed transformations (F).\n";

    char response7;
    cout << "Enter your choice (1, 2, 3, 4): ";
    cin >> response7;
    if (response7 == '1')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Afisează scorul final și salvează-l în fișierul de ieșire

    cout << "\nFinal score: " << score << "/35\n";

    if (score == 0)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n                          Try again, all answers are wrong. \n\n\n";
        goto Quiz;
    }

    brd.welcome_to(score);
restart_game:

    system("cls");
    brd.print_title();
    snk.initialise_snake(score);
    snk.eat_food();
    int i1 = 80, i2 = 80;
    while (i1 != 99)
    {
        if (kbhit())
        {
            i1 = getch();
            if (i1 == 72 && (i2 != 80 || reverse_snake))
                i2 = i1, snk.move_snake(-1, 'v');
            else if (i1 == 80 && (i2 != 72 || reverse_snake))
                i2 = i1, snk.move_snake(1, 'v');
            else if (i1 == 75 && (i2 != 77 || reverse_snake))
                i2 = i1, snk.move_snake(-1, 'h');
            else if (i1 == 77 && (i2 != 75 || reverse_snake))
                i2 = i1, snk.move_snake(1, 'h');
            else if (i1 == 112)
            { // 112- p

                while (1)
                {
                    i1 = getch();
                    if (i1 == 112)
                        break;
                }
            }
            else
                goto congo;
        }
        else
        {
        congo:
            if (i2 == 72)
                snk.move_snake(-1, 'v');
            else if (i2 == 80)
                snk.move_snake(1, 'v');
            else if (i2 == 75)
                snk.move_snake(-1, 'h');
            else if (i2 == 77)
                snk.move_snake(1, 'h');
        }
        if (snk.check_interbody_death() && !reverse_snake && self_hit)
            break; // body collision
        if (snake.back() > lenght - 1 || snake.back() < 0 || snake[snake.end() - snake.begin() - 2] < 0 || snake[snake.end() - snake.begin() - 2] > width - 1)
            break; // wall collision
        if (snake.back() == score)
            break;
        if (food_y == snake.back() && food_x == snake[snake.end() - 2 - snake.begin()])
            snk.eat_food();
        brd.print_highscore();
        Sleep(time1);
    }
    int result;

    result = brd.print_final_message();

    if (result != 27)
        goto restart_game;
}
