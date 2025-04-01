#include <iostream>
#include <fstream>

int main()
{
    int score = 0; // Scorul începe de la zero

    // Deschide un fișier de ieșire pentru salvarea scorului
    std::ofstream outputFile("output.txt");

    // Întrebarea 1
    std::cout << "1. What Climate neutrality, a pivotal concept of EU politics in connection with CLIMATE CHANGE, refers to?\n";
    std::cout << "A1. Climate neutrality refers to the control of climate evolution for maintaining it in a condition most favorable to life. (F)\n";
    std::cout << "A2. Climate neutrality refers to the mitigation of carbon dioxide concentration into the atmosphere. (F)\n";
    std::cout << "A3. Climate neutrality refers to the mitigation of all the greenhouse gases (GHG) into the atmosphere. (T)\n";
    std::cout << "A4. Climate neutrality refers to the emission of as much greenhouse gas (GHG) into the atmosphere as can be absorbed by nature, that is forests, oceans and soil. (T)\n";

    char response1;
    std::cout << "Enter your choice (1, 2, 3, 4): ";
    std::cin >> response1;
    if (response1 == '3' || response1 == '4')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 2
    std::cout << "\n2. What is the EU target regarding climate neutrality, in accordance to Green Deal objectives?\n";
    std::cout << "A1. The EU target regarding climate neutrality is 55% emissions reduction by 2050. (F)\n";
    std::cout << "A2. The EU target regarding climate neutrality is zero net emissions by 2040. (F)\n";
    std::cout << "A3. The EU target regarding climate neutrality is gradual reduction of emissions until zero emissions by the end of the century. (F)\n";
    std::cout << "A4. The EU target regarding climate neutrality is zero net emissions by 2050. (T)\n";

    char response2;
    std::cout << "Enter your choice (1, 2, 3, 4): ";
    std::cin >> response2;
    if (response2 == '4')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 3
    std::cout << "\n3. Is the climate neutrality the same concept as the carbon neutrality? Please answer and give short explanation\n";
    std::cout << "A1. Yes, they are the same and both refer to the limitation of greenhouse gases (GHG)' emission into the atmosphere to that quantity which can be naturally absorbed into nature or due to human activities. (F)\n";
    std::cout << "A2. No, only the concept of climate neutrality is used referring to the limitation of greenhouse gases (GHG)' emission into the atmosphere to that quantity which can be naturally absorbed into nature or due to human activities; but carbon neutrality is neither used, nor explained. (F)\n";
    std::cout << "A3. No, the climate neutrality refers to the limitation of greenhouse gases (GHG)' emission into the atmosphere to that quantity which can be naturally absorbed into nature or due to human activities, but carbon neutrality refers only to the carbon dioxide emissions decrease until the equal balance with its absorption into environment or due to human activities (T)\n";
    std::cout << "A4. No, these concepts are not the same, as the climate neutrality refers to the equal balance between the GSG emission into atmosphere and its absorption by nature and human activities, and the carbon neutrality refers to the carbon cycle into the nature. (F)\n";

    char response3;
    std::cout << "Enter your choice (1, 2, 3, 4): ";
    std::cin >> response3;
    if (response3 == '3')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 4
    std::cout << "\n4. Which are the greenhouse gases (GHG) and name the most abundant among them?\n";
    std::cout << "A1. The greenhouse gases (GHG) comprise carbon dioxide and ozone, with the carbon dioxide the most abundant. (F)\n";
    std::cout << "A2. GHGs include carbon dioxide, methane, nitrous oxide, chlorofluorocarbons, ozone, and water vapor, with carbon dioxide of about 80% of the total (T).\n";
    std::cout << "A3. Beside the determination of carbon dioxide, ozone and water vapor, there are not precise information about other gases and one cannot appreciate the GHGs quantitative composition. (F)\n";
    std::cout << "A4. The GHGs composition varies so much function of weather, environment, human activity and other situations and consequently beside the abundant presence of carbon dioxide, there is not a general evaluation. (F)\n";

    char response4;
    std::cout << "Enter your choice (1, 2, 3, 4): ";
    std::cin >> response4;
    if (response4 == '2')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 5
    std::cout << "\n5. Has the transition towards climate neutrality economic and social benefices or it brings only higher economic costs?\n";
    std::cout << "A1. Beside the higher economic costs, the transition towards climate neutrality brings significant opportunities for economic growth, markets and jobs, technological development. (T)\n";
    std::cout << "A2. There are not economic or social opportunities due to transition towards climate neutrality, it brings only higher economic costs. (F)\n";
    std::cout << "A3. The transition towards climate neutrality does not involve higher economic costs, but brings only economic and social benefices (F)\n";
    std::cout << "A4. The transition towards climate neutrality has no economic or social consequences, either positive or negative (F)\n";

    char response5;
    std::cout << "Enter your choice (1, 2, 3, 4): ";
    std::cin >> response5;
    if (response5 == '1')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 6
    std::cout << "\n6. The carbon dioxide utilization by chemical / biochemical transformation into useful products was studied?\n";
    std::cout << "A1. There are not technological researches regarding chemical / biochemical transformation of carbon dioxide into useful products (F).\n";
    std::cout << "A2. Ther are many technological studies regarding chemical / biochemical transformation of carbon dioxide into useful products, but not economically developed due to still technical challenges. (T).\n";
    std::cout << "A3. Ther are already new industrial developments to use the carbon dioxide emissions for practical applications (F).\n";
    std::cout << "A4. Due to huge technological and economical difficulties there is no interest to develop technologies for using the carbon dioxide (F).\n";

    char response6;
    std::cout << "Enter your choice (1, 2, 3, 4): ";
    std::cin >> response6;
    if (response6 == '2')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Întrebarea 7
    std::cout << "\n7. The progress target and the needed actions towards achieving climate neutrality is comprised into an existing specific EU law?\n";
    std::cout << "A1. The European Union Commission adopted the EU Climate Law in 2021 dedicated to the tasks of achieving climate neutrality (T).\n";
    std::cout << "A2. There is not an EU Climate Law, as the topic was defined in other EU Commission laws and documents in connection with the actions for climate change stopping. (F)\n";
    std::cout << "A3. There is a proposal of EU Climate Law still in public debate (F).\n";
    std::cout << "A4. There is the EU Climate Law, but the EU Commission decided to replace this existing law with a new one more appropriate for the climate changing and socio-economic needed transformations (F).\n";

    char response7;
    std::cout << "Enter your choice (1, 2, 3, 4): ";
    std::cin >> response7;
    if (response7 == '1')
    {
        score += 5; // Adaugă 5 puncte la scor dacă răspunsul este corect
    }

    // Afisează scorul final și salvează-l în fișierul de ieșire
    std::cout << "\nFinal score: " << score << "/35\n";
    outputFile << "Final score: " << score << "/35\n";

    // Închide fișierul de ieșire
    outputFile.close();

    return 0;
}
