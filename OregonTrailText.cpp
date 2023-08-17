/*
Daniel Gibson: CSCi 1300 Spring 2018
Recitation: 106 - Ashwin Sankaralingam
Cloud9 Workspace Editor Link: https://ide.c9.io/danielgib/csci1300
Homework 8 - Problem #1
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <assert.h>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;



class supplies
{
public:
    supplies()//default constructor
    {
        cash = 1200; //starting amount of cash
        food = 0;
        oxen = 0;
        bullets = 0;
        wagonParts = 0;
        medKit = 0;
        wagonHealth = 100;
    }

    void purchaseWagon()
    {
        cash = cash - 200; //wagon costs 200$, must have wagon
    }

    int getCash()//return amount of cash left
    {
        return cash;
    }

    void setCash(int tCash)//sets amount of cash
    {
        cash = tCash;
        if (cash <= 0)
        {
            cash = 0;
        }
    }

    int getFood()//returns amount of food left
    {
        return food;
    }

    void setFood(int tFood)//sets food, if over 1000 cant carry that much so max 1000
    {
        if ((food + tFood) > 1000)
        {
            food = 1000;
        }
        food = tFood;
        if (food <= 0)
        {
            food = 0;
        }
    }

    /*
    * Algorithm: that sets the amount of food over a certain time span depending on how many days and people
    * 1. if statments checking how many days you are eating, if not 1, 2, or 3, then deafult 14 days
    * 2. sets food acordingy to the amount of days times amount of food eaten per person
    * Parameters: amount of days resting and number of people both int type
    * Outputs: Nothing
    * Returns: Nothing
    */
    void setRestFood(int day, int numPeople)
    {

        if (day == 1)
        {
            int x = 0;
            int food1 = getFood();
            food = food1 - (3 * numPeople);
        }
        if (day == 2)
        {
            int food2 = getFood();
            food = food2 - 2 * (3 * numPeople);
        }
        if (day == 3)
        {
            int food3 = getFood();
            food = food3 - 3 * (3 * numPeople);

        }
        else
        {
            int food4 = getFood();
            food = food4 - (14 * numPeople);
        }
    }

    void setMisFood(int days, int numPeople)//sets food for misfortunes
    {
        int foodT = food;
        food = foodT - ((3 * numPeople) * days);
        if (food <= 0)
        {
            food = 0;
        }
    }

    int getOxen()//returns amount of oxen u have
    {
        return oxen;
    }

    void setOxen(int tOxen)//sets oxen
    {
        oxen = tOxen;
        if (oxen <= 0)
        {
            oxen = 0;
        }
    }

    int getBullets()//returns amount of bullets
    {
        return bullets;
    }

    void setBullets(int tBullets)//sets bullets
    {
        bullets = tBullets;
        if (bullets <= 0)
        {
            bullets = 0;
        }
    }

    int getWagonPart()//returns amount of wagon parts owned
    {
        return wagonParts;
    }

    void setWagonParts(int tWagonParts)//sets wagon parts
    {
        wagonParts = tWagonParts;
        if (wagonParts <= 0)
        {
            wagonParts = 0;
        }
    }

    void setWagonHealth(int tWagonHealth)//sets wagons health
    {
        wagonHealth = tWagonHealth;
    }

    int getWagonHealth()//returns  wagons health
    {
        return wagonHealth;
    }

    int getMedKit()//returns amount of medkits owned
    {
        return medKit;
    }

    void setMedKit(int tMedKit)//sets medical kits
    {
        medKit = tMedKit;
        if (medKit <= 0)
        {
            medKit = 0;
        }
    }


    /*
    * Algorithm: that sets the amount of food gained by killing an animal and returns the amount of bullets used to kill it if enough bullets are available
    * 1. if statments checking the index passed down as a parememter to what animals has been caught
    * 2. if statment to check if player has enough bullets to kill said animals
    * 3. If true then returns amount of bullets used to kill animal plus sets food gained by killing animals
    * 4. If bear deer or moose the weights are randomly sleceted in givn range at the top
    * Parameters: Index if what animal was killed
    * Outputs: Nothing
    * Returns: 0 or number of bullets used
    */
    int setHuntingBullets(int num)
    {
        srand(time(0));
        int deer = rand() % (55 - 30) + 30;
        int bear = rand() % (250 - 100) + 100;
        int moose = rand() % (600 - 300) + 300;
        if (num == 1)//rabbit fox
        {
            if (bullets >= 18)
            {
                food = food + 7;
                return 18;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 2)//rabbit
        {
            if (bullets >= 10)
            {
                food = food + 2;
                return 10;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 3)//deer
        {
            if (bullets >= 5)
            {
                food = food + deer;
                return 5;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 4)//deer rabbit
        {
            if (bullets >= 15)
            {
                food = food + deer + 2;
                return 15;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 5)//deer fox
        {
            if (bullets >= 13)
            {
                food = food + deer + 5;
                return 13;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 6)//deer fox rabbit
        {
            if (bullets >= 25)
            {
                food = food + deer + 7;
                return 25;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 7)//bear
        {
            if (bullets >= 10)
            {
                food = food + bear;
                return 10;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 8)//bear rabbit
        {
            if (bullets >= 20)
            {
                food = food + bear + 2;
                return 20;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 9)//bear fox
        {
            if (bullets >= 18)
            {
                food = food + bear + 5;
                return 18;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 10)//bear deer
        {
            if (bullets >= 15)
            {
                food = food + deer + bear;
                return 15;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 11)//bear rabbit fox
        {
            if (bullets >= 28)
            {
                food = food + bear + 7;
                return 28;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 12)//bear deer fox
        {
            if (bullets >= 23)
            {
                food = food + bear + deer + 5;
                return 23;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 13)//bear deer fox rabbit
        {
            if (bullets >= 33)
            {
                food = food + bear + deer + 7;
                return 33;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 14)//moose
        {
            if (bullets >= 12)
            {
                food = food + moose;
                return 12;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 15)//moose rabbit
        {
            if (bullets >= 22)
            {
                food = food + moose + 2;
                return 22;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 16)//moose fox
        {
            if (bullets >= 20)
            {
                food = food + moose + 5;
                return 20;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 17)//moose deer
        {
            if (bullets >= 17)
            {
                food = food + moose + deer;
                return 17;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 18)//moose bear
        {
            if (bullets >= 22)
            {
                food = food + moose + bear;
                return 22;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 19)//moose fox rabbit
        {
            if (bullets >= 28)
            {
                food = food + moose + 7;
                return 28;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 20)//moose deer fox
        {
            if (bullets >= 25)
            {
                food = food + moose + deer + 5;
                return 25;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 21)//moose bear deer
        {
            if (bullets >= 27)
            {
                food = food + moose + bear + deer;
                return 27;
            }
            else
            {
                return 0;
            }
        }
        else if (num == 22)//moose bear deer fox rabbit
        {
            if (bullets >= 45)
            {
                food = food + moose + bear + deer + 7;
                return 45;
            }
            else
            {
                return 0;
            }
        }
    }

    void setHuntingFood(int numPeople, int foodPerPerson)
    {
        food = food - (numPeople * foodPerPerson);
    }

private:
    int cash;//in round dollars
    int food; //in lbs
    int oxen;// number of oxen
    int yokes;//number of yokes
    int bullets;
    int wagonParts;
    int medKit;
    int wagonHealth;

};


class dateAndLocation
{
public:
    dateAndLocation()//default contructor
    {
        miles = 0;//miles since begingining
        location = "Independence Missouri";//statrting locations name
        endDay = 30;//end day is the 30th
        endMonth = 11;//end month is november
        speed = 0;//default speed is 0 without any oxen
        milesToNext = 102;//by default the closest milestone from the start is 102 miles away
        day = 0;
        month = 0;
        milestoneCheck = 0;

        //open milestones function and read from it int default arrays
        int i, j, k;
        int l = 0;//index for digit
        int digit[4];//digits of the mileage
        string name;
        string lineOfSpecifics;
        ifstream milestoneFile;
        milestoneFile.open("milestones.txt");
        if (milestoneFile.is_open())//checks if file was opened correctly
        {
            for (i = 0; i < 15; i++)
            {
                getline(milestoneFile, name);
                milestoneName[i] = name;
                getline(milestoneFile, lineOfSpecifics);
                j = 1;
                while (true)
                {
                    for (k = 1; lineOfSpecifics[k] != 'm'; k++)
                    {
                        digit[l] = (int)lineOfSpecifics[k] - 48;
                        l++;
                        j++;
                    }
                    j += 3;
                    if (j + 1 >= lineOfSpecifics.size())
                    {
                        milestone[i] = 2;
                        riverDepth[i] = 0;//no river so default to zero feet
                        break;
                    }
                    if (lineOfSpecifics[j] == 'R')
                    {
                        milestone[i] = 0;
                        j += 6;
                        riverDepth[i] = (int)lineOfSpecifics[j] - 48;
                        break;
                    }
                    else if (lineOfSpecifics[j] = 'F')
                    {
                        milestone[i] = 1;
                        riverDepth[i] = 0;//no river so default to zero feet
                        break;
                    }
                }
                if (l == 3)
                {
                    milestoneLocation[i] = digit[0] * 100 + digit[1] * 10 + digit[2];

                }
                else if (l == 4)
                {
                    milestoneLocation[i] = digit[0] * 1000 + digit[1] * 100 + digit[2] * 10 + digit[3];

                }
                else
                {
                    cout << "Error" << endl; //if l is not 3 or 4 then it is wrong
                }
                l = 0;
            }
        }
        else //file did not open for reading succsesfully
        {
            cout << "Error" << endl;
        }
    }


    void startDate(int tDay, int tMonth)//sets start day and month
    {
        day = tDay;
        month = tMonth;
    }

    void setDate(int tDay, int tMonth)//sets current day and month
    {
        day = tDay;
        month = tMonth;
    }

    int getDay()//return current day
    {
        return day;
    }

    void setDay(int tDay)//sets current day
    {
        day = tDay;
    }

    void setMonth(int tMonth)//sets current month
    {
        month = tMonth;
    }

    int getMonth()//returns current month
    {
        return month;
    }

    /*
    * Algorithm: that returns the name of the given month passed down as a parameter
    * 1. if statments chekcing which month has been passed down as a parameter
    * 2. returns the name of the month
    * Parameters: month(int type)
    * Outputs: Nothing
    * Returns: name of the month
    */
    string getMonthName(int month)
    {
        string monthName;
        if (month == 1)
        {
            monthName = "January";
            return monthName;
        }
        if (month == 2)
        {
            monthName = "Febuary";
            return monthName;
        }
        if (month == 3)
        {
            monthName = "March";
            return monthName;
        }
        if (month == 4)
        {
            monthName = "April";
            return monthName;
        }
        if (month == 5)
        {
            monthName = "May";
            return monthName;
        }
        if (month == 6)
        {
            monthName = "June";
            return monthName;
        }
        if (month == 7)
        {
            monthName = "July";
            return monthName;
        }
        if (month == 8)
        {
            monthName = "August";
            return monthName;
        }
        if (month == 9)
        {
            monthName = "September";
            return monthName;
        }
        if (month == 10)
        {
            monthName = "October";
            return monthName;
        }
        if (month == 11)
        {
            monthName = "November";
            return monthName;
        }
        if (month == 12)
        {
            monthName = "December";
            return monthName;
        }

    }


    /*
    * Algorithm: that takes a certain day and returns the the suffix of it
    * 1. if statments to check if given day has suffix of st, cnd, rd, or th
    * 2. returns suffix
    * Parameters: day (int type)
    * Outputs: Nothing
    * Returns: Suffix of given day
    */
    string getDayName(int i)
    {
        string suffix;
        if (i == 1 || i == 21 || i == 31)//st
        {
            suffix = "st";
            return suffix;
        }
        if (i == 2 || i == 22)///cnd
        {
            suffix = "cnd";
            return suffix;
        }
        if (i == 3 || i == 23)//rd
        {
            suffix = "rd";
            return suffix;
        }
        else//th
        {
            suffix = "th";
            return suffix;
        }
    }


    void setMiles(int tMiles)//sets current miles travled
    {
        miles = tMiles;
    }

    int getMiles()//returns miles travled
    {
        return miles;
    }

    /*
    * Algorithm: that calulates the probability of raiders attacking and returns 1 if they do and 0 if not
    * 1. Equation to find probaility of raiders
    * 2. random number generator between 1 and 100
    * 3. if statement to check if random number is less then or equal to the probality of getting raiders
    * Parameters: None
    * Outputs: Nothing
    * Returns: 1 for raiders, 0 for no radiers
    */
    int riders()
    {
        int M = miles;
        int tb = pow((M / 100 - 4), 2);
        int prob = (((tb + 72) / (tb + 12)) - 1) / 10;
        prob = prob * 100;
        srand(time(0));
        int r = rand() % (100) + 1;
        if (r <= prob)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int dL_getOxen(supplies& S)//returns amount of oxen owned
    {
        return S.getOxen();
    }


    /*
    * Algorithm: that sets the speed per week the wagon travels depnding on the amount of oxen owned
    * 1. if statments checking how many oxen are owned and what the speed should be set
    * Parameters: S (type supplies)
    * Outputs: Nothing
    * Returns: Nothing
    */
    void setSpeed(supplies& S)
    {
        //1 yoke, 2 oxen= 70 mi per week
        //2 yoke, 4 oxen = 140 mi per week
        int oxen = dL_getOxen(S);
        if (oxen == 2)
        {
            speed = 70;
        }
        if (oxen == 4)
        {
            speed = 88;
        }
        if (oxen == 6)
        {
            speed = 106;
        }
        if (oxen == 8)
        {
            speed = 124;
        }
        if (oxen == 10)
        {
            speed = 140;
        }
    }

    int getSpeed()//returns current speed per week of wagon
    {
        return speed;
    }


    int nearestMilestone()
    {
        if (miles >= milestoneLocation[milestoneCheck])
        {
            milestoneCheck++;
        }
        int milesToGo = abs(miles - milestoneLocation[milestoneCheck]);
        return milesToGo;
    }

    string getMilestoneName()
    {
        return milestoneName[milestoneCheck];
    }

    int getMilestoneType()
    {
        return milestone[milestoneCheck];
    }

    int getRiverDepth()
    {
        return riverDepth[milestoneCheck];
    }

private:
    int milestoneCheck;
    int miles;//how many miles since the beginging
    string location;
    int day;
    int month;
    int endDay;
    int endMonth;
    int speed;//miles traveled by wagon in 2 weeks
    int milestone[15]; //milestone type 0 for river 1 for fort 2 for landmark
    int currentMilestoneType;
    int milestoneLocation[15];
    int currentMilestoneLocation;
    string milestoneName[15];
    string currentMilestoneName;
    int milesToNext;
    int milestoneIndex;
    int riverDepth[15];

};


class peopleAndMisfortunes
{
public:
    peopleAndMisfortunes()//default consrtuctor
    {
        leaderHealth = 100;
        numPeople = 0;
        misfortuneNum = -1;
        for (int i = 0; i < 5; i++)//sets all players health to 100
        {
            //health[i] = 100;
            health.push_back(100);
        }
    }

    void setLeader(string nameOfL)//sets name of wagon leader and increases number of people
    {
        leader = nameOfL;
        numPeople++;
    }


    /*
   * Algorithm: that sets a players name in the party
   * 1. if statment to see if index is in array
   * 2. sats players name at given index passed down as paremter then inccreases the number of people counter.
   * Parameters: name (string type) / name of player, index(int type) / index of player in names array
   * Outputs: error message if name has alreadt been entered
   * Returns: Nothing
   */
    void setName(string tName, int index)
    {
        if (index <= numPeople || index > 0)
        {
            name.push_back(tName);
            numPeople++;
        }
        else
        {
            cout << "The name entered already exists" << endl;
        }
    }

    string getName(int index)//returns name of player at given index passed down as parameter
    {
        return name[index];
    }

    int getNumPeople()//returns number of people in traveling party including wagon leader
    {
        return numPeople;
    }


    int misfortune(int index)//return number depnding on which misfortune was chosen by passed down parameter
    {
        if (index == 0)
        {
            //disease
            return 0;
        }
        if (index == 1)
        {
            //oxen death
            return 1;
        }
        if (index == 2)
        {
            //theif attack
            return 2;
        }
        if (index == 3)
        {
            //wagon malfunction
            return 3;
        }
        if (index == 4)
        {
            //bad weather
            return 4;
        }

    }

    void setMisfortuneNum(int misNum)//sets misfortune number
    {
        misfortuneNum = misNum;
    }

    int getMisfortuneNum()//returns misfortunes number
    {
        return misfortuneNum;
    }

    int rRest()//returns amount of days rested
    {
        int rest = randomRest();//gets random number between 0 and 2
        if (rest == 0)
        {
            return 0;
        }
        if (rest == 1)
        {
            return 1;
        }
        if (rest == 2)
        {
            return 2;
        }
    }

    /*
   * Algorithm: that returns the name of the disease contracted passed down by given parameter
   * 1. if statments checking what diease was contracted by passed down parameter
   * 2. sets diseases name then returns it
   * Parameters: num (int type) / what disaese was contracted
   * Outputs: Nothing
   * Returns: Name of disease
   */
    string disease(int num)
    {
        string disease;
        if (num == 1)
        {
            disease = "Typhoid";
            return disease;
        }
        if (num == 2)
        {
            disease = "Cholera";
            return disease;
        }
        if (num == 3)
        {
            disease = "Diarrhea";
            return disease;
        }
        if (num == 4)
        {
            disease = "Measels";
            return disease;
        }
        if (num == 5)
        {
            disease = "Dysentery";
            return disease;
        }
        if (num == 6)
        {
            disease = "Fever";
            return disease;
        }
    }

    string rDisease()//random number generator between 1 and 6
    {
        srand(time(0));
        int r = rand() % (6) + 1;
        return disease(r);
    }

    int rHunt()//random number generator between 1 and 100
    {
        srand(time(0));
        int r = rand() % (100) + 1;
        return r;
    }

    /*
   * Algorithm: that returns index of what animal was caught
   * 1. if statements for what animal was originally caught
   * 2. if statments to check if random generated probalilty is less then certain number
   * 3. returns number depending if probailit is smaller or not
   * Parameters: num(int type) / what animal was orginally seen
   * Outputs: Nothing
   * Returns: index of what animal/animals was caught
   */
    int rAnimal(int num)
    {
        int prob = rHunt();
        if (num == 1)//rabit or fox
        {
            if (prob <= 25)
            {
                return 1; //fox and rabbit
            }
            else
            {
                return 2; //rabbit
            }
        }
        else if (num == 2)//rabbit fox deer
        {
            //15%
            if (prob <= 50)//deer rabbit
            {
                if (prob <= 25)//deer fox
                {
                    if (prob <= 15)
                    {
                        return 6;//deer fox rabbit
                    }
                    return 5;//deer fox
                }
                return 4;//deer rabbit
            }
            else
            {
                return 3; //deer
            }
        }
        else if (num == 3)//rabbit fox deer bear
        {
            //7%
            if (prob <= 50)//bear rabbit
            {
                if (prob <= 40)//bear fox
                {
                    if (prob <= 30)//bear deer
                    {
                        if (prob <= 20)//bear rabbit fox
                        {
                            if (prob <= 10)//bear deer fox
                            {
                                if (prob <= 5)//bear deer fox rabbit
                                {
                                    return 13;
                                }
                                return 12;//bear deer fox
                            }
                            return 11;//bear rabbit fox
                        }
                        return 10;//bear deer
                    }
                    return 9;//bear fox
                }
                return 8;//bear rabbit
            }
            else//bear
            {
                return 7;
            }
        }
        else if (num == 4)//rabbit fox deer bear moose
        {
            //5%
            if (prob <= 40)//rabbit moose
            {
                if (prob <= 35)//fox moose
                {
                    if (prob <= 30)//deer moose
                    {
                        if (prob <= 25)//bear moose
                        {
                            if (prob <= 20)//rabbit fox moose
                            {
                                if (prob <= 15)//fox dear moose
                                {
                                    if (prob <= 10)//deer bear moose
                                    {
                                        if (prob <= 5)//rabbit fox dear moose
                                        {
                                            return 22;
                                        }
                                    }
                                    return 21;//deer bear moose
                                }
                                return 20;//fox dear moose
                            }
                            return 19;//rabbit fox moose
                        }
                        return 18;//bear moose
                    }
                    return 17;//deer moose
                }
                return 16;//fox moose
            }
            return 15;//rabbit moose
        }
        else//moose
        {
            return 14;//moose
        }
    }


    /*
   * Algorithm: that returns the name of the animal / animals
   * 1. if statments to check what animal it is with given index passed down as a paremeter
   * 2. sets animals name then returns it
   * Parameters: animalNum(int type) / index of what animal
   * Outputs: Nothing
   * Returns: animals name
   */
    string animalName(int animalNum)
    {
        string animal;
        if (animalNum == 1)//rabbit fox
        {
            animal = "rabbit and a fox";
            return animal;
        }
        else if (animalNum == 2)//rabbit
        {
            animal = "rabbit";
            return animal;
        }
        else if (animalNum == 3)//deer
        {
            animal = "deer";
            return animal;
        }
        else if (animalNum == 4)//deer reabbit
        {
            animal = "deer and a rabbit";
            return animal;
        }
        else if (animalNum == 5)//deer fox
        {
            animal = "deer and a fox";
            return animal;
        }
        else if (animalNum == 6)//deer fox rabbit
        {
            animal = "deer, a fox, and a rabbit";
            return animal;
        }
        else if (animalNum == 7)//bear
        {
            animal = "bear";
            return animal;
        }
        else if (animalNum == 8)//bear rabbit
        {
            animal = "bear and a rabbit";
            return animal;
        }
        else if (animalNum == 9)//bear fox
        {
            animal = "bear and a fox";
            return animal;
        }
        else if (animalNum == 10)//bear deer
        {
            animal = "bear and a deer";
            return animal;
        }
        else if (animalNum == 11)//bear rabbit fox
        {
            animal = "bear, a rabbit, and a fox";
            return animal;
        }
        else if (animalNum == 12)//bear deer fox
        {
            animal = "bear, a deer, and a fox";
            return animal;
        }
        else if (animalNum == 13)//bear deer fox rabbit
        {
            animal = "bear, a deer, a fox, and a rabbit";
            return animal;
        }
        else if (animalNum == 14)//moose
        {
            animal = "moose";
            return animal;
        }
        else if (animalNum == 15)//moose rabbit
        {
            animal = "moose and a rabbit";
            return animal;
        }
        else if (animalNum == 16)//moose fox
        {
            animal = "moose and a fox";
            return animal;
        }
        else if (animalNum == 17)//moose deer
        {
            animal = "moose and a deer";
            return animal;
        }
        else if (animalNum == 18)//moose bear
        {
            animal = "moose and a bear";
            return animal;
        }
        else if (animalNum == 19)//moose fox rabbit
        {
            animal = "moose, a fox, and a rabbit";
            return animal;
        }
        else if (animalNum == 20)//moose deer fox
        {
            animal = "moose, a deer, and a fox";
            return animal;
        }
        else if (animalNum == 21)//moose bear deer
        {
            animal = "moose, a bear, a deer";
            return animal;
        }
        else if (animalNum == 22)//moose bear deer fox rabbit
        {
            animal = "moose, a bear, a deer, a fox, and a rabbit";
            return animal;
        }
    }


    int rWeather()//random generator between 5 and 1
    {
        srand(time(0));
        int r = rand() % (5) + 1;
        return r;
    }

    int problem()//random number generator between 1 and 10
    {
        srand(time(0));
        int r = rand() % (10) + 1;
        return r;
    }

    int rTheif()//random generator between 10 and 26
    {
        srand(time(0));
        int r = rand() % (26 - 10) + 10;
        return r;
    }

    /*
   * Algorithm: that returns a random name of a person in the party
   * 1. random number generator between 1 and 5
   * 2. if statment that goes to which random number between 1 and 5 was slected then returns that players name
   * Parameters: None
   * Outputs: Nothing
   * Returns: name of player
   */
    int rNameNum()
    {
        string tName;
        srand(time(0));
        int r = rand() % (5) + 1;
        return r;
    }

    string rName(int index)
    {
        if (index == 1)
        {
            return name[0];
        }
        if (index == 2)
        {
            return name[1];
        }
        if (index == 3)
        {
            return name[2];
        }
        if (index == 4)
        {
            return name[3];
        }
        if (index == 5)
        {
            return leader;
        }
    }

    int randomRest()//random number generator between 0 and 2
    {
        int i = 0;
        srand(time(0));
        i = rand() % 3;
        return i;
    }

    int random()//random number generator between 1 and 100, if random number was under 40 then misfurtone
    {
        int i = 0;
        srand(time(0));
        i = rand() % 100;
        if (i < 40)
        {
            return randomMIS();
        }
        else
        {
            return -1;
        }
    }

    int randomMIS()//random number generator between 0 and 5
    {
        int i = 0;
        srand(time(0));
        i = rand() % 5;
        return misfortune(i);
    }



    void setPlayerHealth(int index)//set player at ith index's health
    {
        if (index <= 4)//checks if player is party member
        {
            health[index] = health[index] - 50; //takes away the ith index of the health array and takes away 50
            if (health[index] == 0)
            {
                health.erase(health.begin() + index - 1);
                name.erase(name.begin() + index - 1);
                numPeople--;
            }
        }
        else//if player is in not in array of names then it is leader
        {
            leaderHealth = leaderHealth - 50;//takes away 50 from leader
        }
    }

    void setLeaderHealth(int tLeaderHealth)//sets leaders health
    {
        leaderHealth = tLeaderHealth;
    }

    int getLeaderHealth()///returns leaders current health
    {
        return leaderHealth;
    }

    string getLeaderName()//returns wagon leaders name
    {
        return leader;
    }

    void checkDead(int index)
    {

    }

    int getPlayerHealth(int index)
    {
        return health[index];
    }

    void setPlayerHealthFull()
    {
        for (int i = 0; i < health.size(); i++)
        {
            health[i] = 100;
        }
    }

private:
    int misfortuneNum;
    int leaderHealth;
    vector<string> name;//4 party members
    string leader; //1 wagon leader
    int numPeople; //number of people left in party
    vector<int> health;//health array for 4 party
};


//_________PROTOTYPING_____________
void setLeaderName(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void setPartyNames(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void start(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void statusUpdate(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void turn(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void visitStore(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void shopOxen(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void shopFood(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void shopAmmo(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void shopMisc(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void quit();
void rest(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void trail(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void hunt(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void milestone(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void misfortune(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void EndGame(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
void raiders(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S);
int end(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S, string cause);


/*
* Algorithm: that asks and sets the wagon leaders name
* 1. cout asking for leaders name
* 2. sets leaders name then goes to party names
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: cout asking for leaders name and welcome to game
* Returns: Nothing
*/
void setLeaderName(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S) //enter and set the wagon leaders name
{
    string leader;
    cout << "Welcome to the Oregon Trail." << endl;
    cout << "What is the first name of the wagon leader? ";
    cin >> leader;
    pAM.setLeader(leader);
    setPartyNames(dL, pAM, S);
}

/*
* Algorithm: that asks for the rest of the parts names then sets them
* 1. cout asking for 4 names in the party
* 2. sets each name in people and misfortunes class then goes to start function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: cout asking for party members
* Returns: Nothing
*/
void setPartyNames(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S) //one by one enter names of the party memebers adn set them
{
    string name1;
    string name2;
    string name3;
    string name4;
    cout << "What are the first names of the four other memebers in your party? " << endl;
    cout << "1: ";
    cin >> name1;
    pAM.setName(name1, 0);
    cout << endl << "2: ";
    cin >> name2;
    pAM.setName(name2, 1);
    cout << endl << "3: ";
    cin >> name3;
    pAM.setName(name3, 2);
    cout << endl << "4: ";
    cin >> name4;
    pAM.setName(name4, 3);
    start(dL, pAM, S);

}

/*
* Algorithm: asks player when they are going to oregon and asks for what date they would like to depart
* 1. cout telling player where they are going and then asks what date they would like to depart on
* 2. while loop to contue asking player for a answer until a valid one has been selected
* 3. sets date according to what user slected then tells user they must buy supplies then goes to visit store function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: asks for date and tells user they must visit store
* Returns: Nothing
*/
void start(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    string date;
    bool check = true;
    int num;
    cout << "It is 1847. Your jumping off\nplace for Oregon is Independence,\nMissouri. You must decide which\nmonth to leave Independence." << endl;
    while (check)
    {
        cout << "1. March 28th, 1847\n2. March 1st, 1847\n3. May 1st, 1847" << endl;
        cin >> num;
        if (num == 1)
        {
            date = "March 28th, 1847";
            check = false;
            //set date
            dL.startDate(28, 3);
        }
        if (num == 2)
        {
            date = "March 1st, 1847";
            check = false;
            //set date
            dL.startDate(1, 3);
        }
        if (num == 3)
        {
            date = "May 1st, 1847";
            check = false;
            //setdate
            dL.startDate(1, 5);
        }
        else
        {
            cout << "Please choose a valid option" << endl;
        }
    }
    cout << "You will depart on " << date << ", you must reach Oregon City by November 30th, 1847." << endl;
    cout << "Before leaving Independence you\nshould buy equipment and\nsupplies. You have $1200.00 in\ncash,";
    cout << " but you don't have to\nspend it all now." << endl;
    cout << "You had saved $1200.00 to spend on the trip, and you've just paid $200.00\nfor a wagon." << endl;
    S.purchaseWagon();
    visitStore(dL, pAM, S);
}

/*
* Algorithm: that displays to the user at the begining of each turn various stats
* 1. tells user the current date, total miles traveled, closest landmark and how far away it is, and remaining supplies then goes to turn function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: tells user date, total milage,nearest landmark, and remaining supplies
* Returns: Nothing
*/
void statusUpdate(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int i = 0;
    int food = S.getFood();
    int bullets = S.getBullets();
    int wagonParts = S.getWagonPart();
    int medKits = S.getMedKit();
    int cash = S.getCash();
    int miles = dL.getMiles();
    int milesAway = dL.nearestMilestone();
    string milestoneName = dL.getMilestoneName();
    int monthI = dL.getMonth();
    string month = dL.getMonthName(monthI);
    int day = dL.getDay();
    string dayPref = dL.getDayName(day);
    //date

    cout << " ---------------------------------------------------------------------------------------------------------" << endl;
    cout << month << " " << day << dayPref << ", 1847" << endl;
    //total miles travled
    cout << "Total mileage is " << miles << "." << endl;
    //next landmark
    cout << "The next closest milestone is " << milestoneName << " " << milesAway << " miles away." << endl;
    //food available
    //number of bullets left
    //cash available
    cout << "FOOD:      BULLETS:      WAGON PARTS:      MEDICAL KITS:       CASH:" << endl;
    cout << food << "            " << bullets << "          " << wagonParts << "             " << medKits << "                   " << cash << endl;
    cout << " ---------------------------------------------------------------------------------------------------------" << endl;
    turn(dL, pAM, S);
}


/*
* Algorithm: that asks the user what they wish to do during there turn then goes to given function
* 1. cout asking user what they would like to do for there turn
* 2. while loop that continues to ask user for input until correct one has been selected
* 3. if 1 then goes to rest function, if 2 then ges to trail function, if 3 then goes to hunt function, if 4 then quits
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: asks user for what they would like to do for there turning
* Returns: Nothing
*/
void turn(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int choice;
    bool check = true;

    while (check)
    {
        check = true;
        choice = 0;
        cout << "Do you want to\n1. Stop to rest\n2. Continue on the trail\n3. Hunt\n4. Quit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            check = false;
            //rest
            rest(dL, pAM, S);
        }
        if (choice == 2)
        {
            check = false;
            //continue
            trail(dL, pAM, S);
        }
        if (choice == 3)
        {
            check = false;
            //hunt
            hunt(dL, pAM, S);
        }
        if (choice == 4)
        {
            check = false;
            //quit
            quit();
        }
        else
        {
            cout << "Please enter a valid option." << endl;
        }
    }
}

/*
* Algorithm: that sets date and food depending how many people and how many days the wagon party rested for
* 1. Random number i generated from rRest function
* 2. if statment for how many days partys rested randomly generated by i
* 3. if i = 0 then rested for 1 day, if  i=1 then rested for 2 days, if i=2 then rested for 3 days
* 4. sets date and food acordingly then goes to misfortune function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: tells player how many days the party rested
* Returns: Nothing
*/
void rest(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int i = pAM.rRest();
    int month = dL.getMonth();
    int day = dL.getDay();
    int people = pAM.getNumPeople();
    if (i == 0)
    {
        cout << "You have rested for 1 day." << endl;
        //set food per person
        S.setRestFood(1, people);
        day = day + 1;
        dL.setDate(day, month);
        misfortune(dL, pAM, S);
    }
    if (i == 1)
    {
        cout << "You have rested for 2 days." << endl;
        //set food perperson
        S.setRestFood(2, people);
        day = day + 2;
        dL.setDate(day, month);
        pAM.setPlayerHealthFull();
        misfortune(dL, pAM, S);
    }
    if (i == 2)
    {
        cout << "You have rested for 3 days." << endl;
        //set food per person
        S.setRestFood(3, people);
        day = day + 3;
        dL.setDate(day, month);
        misfortune(dL, pAM, S);
    }
}


/*
* Algorithm: that sets partys date and miles traveled and food
* 1. if statments to check what the current month it is by how many days are in the month and adds 14 days to it
* 2. sets new date and food eaten then goes to misfortunes function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: Nothing
* Returns: Nothing
*/
void trail(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int speed = dL.getSpeed();
    int miles = dL.getMiles();
    int day = dL.getDay();
    int month = dL.getMonth();
    int food = S.getFood();
    int people = pAM.getNumPeople();
    int landmark = -1;

    //miles = miles + speed;
    int x = 0;
    while (x < speed)
    {
        if (miles == 102 || miles == 185 || miles == 304 || miles == 554 || miles == 640 || miles == 830 || miles == 932 || miles == 989 || miles == 1151 || miles == 1295 || miles == 1395 || miles == 1534 || miles == 1648 || miles == 1808 || miles == 1863)
        {
            landmark = 1;
        }
        miles = miles + 1;
        x++;
    }
    dL.setMiles(miles);
    //set new dates but check to see which month it is and if the amount of days added changes the month
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        //months that have 31 days
        for (int i = 0; i < 14; i++)
        {
            day = day + 1;
            if (day == 31)
            {
                day = 0;
                month++;
            }
        }
        dL.setDate(day, month);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        //months that have 30 days
        for (int i = 0; i < 14; i++)
        {
            day = day + 1;
            if (day == 30)
            {
                day = 0;
                month++;
            }
        }
        dL.setDate(day, month);

    }
    else if (month == 2)
    {
        //months that have 28 days
        for (int i = 0; i < 14; i++)
        {
            day = day + 1;
            if (day == 28)
            {
                day = 0;
                month++;
            }
        }
        dL.setDate(day, month);

    }

    if (landmark == 1)
    {
        //milestone function
        S.setRestFood(4, people);
        milestone(dL, pAM, S);
    }
    else
    {
        S.setRestFood(4, people);
        misfortune(dL, pAM, S);
    }
}


/*
* Algorithm: that randomly sees if a player has found and animal and asks them if they wish to hunt it and asks them to solve puzzle if they do
* 1. random number generator to see if player enountered animal then sets aniamls class
* 2. random generator again to see if player caught more then one animal, then asks if they wish to hunt it
* 3. if they wish to hunt then check to see if player has more then 10 bullets
* 4. if player has more then 10 bullets player is asked to solve puzzle, player has 3 tries to guess a random number between 1 and 10
* 5. if player guess correctly checks player has enough bullets to kill
* 6. if player succsessfully kills sets bullets and food accordinly, then goes to misfotunes function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: asks player if they found animals or not and if they would like to hunt it
* Returns: Nothing
*/
void hunt(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int people = pAM.getNumPeople();
    int day = dL.getDay();
    dL.setDay(day + 1);
    S.setRestFood(1, people);
    int anPerc = pAM.rHunt();
    int animalClass = 0;
    if (anPerc <= 50)
    {
        if (anPerc <= 25)
        {
            if (anPerc <= 15)
            {
                if (anPerc <= 7)
                {
                    if (anPerc <= 5)
                    {
                        animalClass = 4;
                    }
                }
                animalClass = 3;
            }
            animalClass = 2;
        }
        animalClass = 1;
    }
    else
    {
        cout << "You did not have any succsess finding an animal, better luck next time!" << endl;
        misfortune(dL, pAM, S);
    }
    int choice = 0;
    bool check = true;
    int animal = pAM.rAnimal(animalClass);
    string name = pAM.animalName(animal);
    cout << "You got lucky! You encountered a " << name << "! Do you want to" << endl;
    while (check)
    {
        cout << "Hunt? (1) Yes, (2) No" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int bullets = S.getBullets();
            if (bullets > 10)
            {
                check = false;
                int x = pAM.problem();
                int pChoice = 0;
                for (int p = 0; p < 3; p++)
                {
                    cout << "Guess a number between 1 and 10, you have 3 tries to get it right" << endl;
                    cin >> pChoice;
                    if (pChoice == x)
                    {
                        //take away bullets add food
                        int numBull = S.setHuntingBullets(animal);
                        if (numBull == 0)
                        {
                            cout << "Not enough ammo! Better luck next time!" << endl;
                            misfortune(dL, pAM, S);
                        }
                        else
                        {
                            cout << "Success, you killed a " << name << endl;
                            S.setBullets(bullets - numBull);
                            bool checkEat = true;
                            int eatChoice;
                            cout << "Would you like to eat?" << endl;
                            while (checkEat)
                            {
                                eatChoice = 0;
                                checkEat = true;
                                cout << "1. Yes\n2. No" << endl;
                                cin >> eatChoice;
                                if (eatChoice == 1)
                                {
                                    checkEat = false;
                                    cout << "How would you like to eat?" << endl;
                                    bool checkEat2 = true;
                                    int eatChoice2;
                                    while (checkEat2)
                                    {
                                        checkEat2 = true;
                                        eatChoice2 = 0;
                                        cout << "1. Poorly\n2. Moderatley\n3. Well" << endl;
                                        cin >> eatChoice2;
                                        if (eatChoice2 == 1)//poorly
                                        {
                                            checkEat2 = false;
                                            cout << "You eat poorly! Each party member will only consume 2Lbs of food each." << endl;
                                            S.setHuntingFood(people, 2);
                                            misfortune(dL, pAM, S);
                                        }
                                        if (eatChoice2 == 2)//moderaley
                                        {
                                            checkEat2 = false;
                                            cout << "You eat moderatley! Each party member will only consume 3Lbs of food each." << endl;
                                            S.setHuntingFood(people, 3);
                                            misfortune(dL, pAM, S);
                                        }
                                        if (eatChoice2 == 3)//well
                                        {
                                            checkEat2 = false;
                                            cout << "You eat well! Each party member will only consume 5Lbs of food each." << endl;
                                            S.setHuntingFood(people, 5);
                                            pAM.setPlayerHealthFull();
                                            misfortune(dL, pAM, S);
                                        }
                                        else
                                        {
                                            cout << "Please enter a valid option." << endl;
                                        }
                                    }
                                }
                                if (eatChoice == 2)
                                {
                                    checkEat = false;
                                    misfortune(dL, pAM, S);
                                }
                                else
                                {
                                    cout << "Please enter a valid option." << endl;
                                }
                            }
                            misfortune(dL, pAM, S);
                        }
                    }
                    else
                    {
                        cout << "Sorry that's incorrect, you have " << 2 - p << " tries left!" << endl;
                    }
                }
                cout << "The hunt was unsuccseful!" << endl;
                misfortune(dL, pAM, S);
            }
            else
            {
                cout << "The hunt was unsuccseful!" << endl;
                misfortune(dL, pAM, S);
            }
        }
        else if (choice == 2)
        {
            check = false;
            misfortune(dL, pAM, S);
        }
        else
        {
            cout << "Please enter a valid option." << endl;
        }
    }
}



/*
* Algorithm: that gives user options depnding on what milestone has been reached.
* 1. if statment checking which milestone user is at, 0 for river, 1 for fort, 2 for landmark
* 2. if 0 then river, asks user if they want to cross river or continue on journey
* 3. if 1 then fort, asks user if the want to rest, continue, or shop
* 4. if 2 then landmark, asks user if they wish to rest or continue
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs:
* Returns: Nothing
*/
void milestone(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    string milestoneName = dL.getMilestoneName();
    int milestone = dL.getMilestoneType();
    int cash = S.getCash();
    int people = pAM.getNumPeople();
    bool checkRiverChoice = true;
    bool checkLandmarkChoice = true;
    bool checkFortChoice = true;
    if (milestone == 0)//river
    {
        int choice;
        int riverDepth = dL.getRiverDepth();
        cout << "Congradulations! You made it to " << milestoneName << "." << endl;
        while (checkRiverChoice)
        {
            checkRiverChoice = true;
            choice = 0;
            cout << "Would you like to\n1. Rest\n2. Cross the river" << endl;
            cin >> choice;
            if (choice == 1)
            {
                //set food and days
                int i = pAM.rRest();
                int month = dL.getMonth();
                int day = dL.getDay();
                int people = pAM.getNumPeople();
                if (i == 0)
                {
                    cout << "You have rested for 1 day." << endl;
                    //set food per person
                    S.setRestFood(1, people);
                    day = day + 1;
                    dL.setDate(day, month);
                }
                if (i == 1)
                {
                    cout << "You have rested for 2 days." << endl;
                    //set food perperson
                    S.setRestFood(2, people);
                    day = day + 2;
                    dL.setDate(day, month);
                    pAM.setPlayerHealthFull();
                }
                if (i == 2)
                {
                    cout << "You have rested for 3 days." << endl;
                    //set food per person
                    S.setRestFood(3, people);
                    day = day + 3;
                    dL.setDate(day, month);
                    pAM.setPlayerHealthFull();
                }
            }
            if (choice == 2)
            {
                checkRiverChoice = false;
                if (riverDepth > 3)
                {
                    cout << "The river is over 3ft deep! You must pay a ferry $10 a person to cross." << endl;
                    if (cash >= (people * 10))
                    {
                        S.setCash(cash - (people * 10));
                        statusUpdate(dL, pAM, S);
                    }
                    else
                    {
                        cout << "You do not have enough money!" << endl;
                        string cause = "was not able to cross the river";
                        end(dL, pAM, S, cause);
                    }
                }
                else
                {
                    cout << "Success! You crossed the river!" << endl;
                    statusUpdate(dL, pAM, S);
                }
            }
            else
            {
                cout << "Please enter a valid option." << endl;
            }
        }
    }
    if (milestone == 1)//fort
    {
        int choice = 0;
        cout << "Congradulations! You made it to " << milestoneName << "." << endl;
        while (checkFortChoice)
        {
            choice = 0;
            checkFortChoice = true;
            cout << "Would you like to\n1. Rest\n2. Shop\n3. Continue" << endl;
            cin >> choice;
            if (choice == 1)//rest
            {
                int i = pAM.rRest();
                int month = dL.getMonth();
                int day = dL.getDay();
                int people = pAM.getNumPeople();
                if (i == 0)
                {
                    cout << "You have rested for 1 day." << endl;
                    //set food per person
                    S.setRestFood(1, people);
                    day = day + 1;
                    dL.setDate(day, month);
                }
                if (i == 1)
                {
                    cout << "You have rested for 2 days." << endl;
                    //set food perperson
                    S.setRestFood(2, people);
                    day = day + 2;
                    dL.setDate(day, month);
                    pAM.setPlayerHealthFull();
                }
                if (i == 2)
                {
                    cout << "You have rested for 3 days." << endl;
                    //set food per person
                    S.setRestFood(3, people);
                    day = day + 3;
                    dL.setDate(day, month);
                    pAM.setPlayerHealthFull();
                }
            }
            if (choice == 2)//store
            {
                checkFortChoice = false;
                visitStore(dL, pAM, S);
            }
            if (choice == 3)//continue
            {
                misfortune(dL, pAM, S);
            }
            else
            {
                cout << "Please enter a valid option." << endl;
            }
        }
    }
    if (milestone == 2)//landmark
    {
        int choice = 0;
        cout << "Congradulations! You made it to " << milestoneName << "." << endl;
        while (checkLandmarkChoice)
        {
            checkLandmarkChoice = true;
            cout << "Would you like to\n1. Rest\n2. Continue" << endl;
            cin >> choice;
            if (choice == 1)
            {
                int i = pAM.rRest();
                int month = dL.getMonth();
                int day = dL.getDay();
                int people = pAM.getNumPeople();
                if (i == 0)
                {
                    cout << "You have rested for 1 day." << endl;
                    //set food per person
                    S.setRestFood(1, people);
                    day = day + 1;
                    dL.setDate(day, month);
                }
                if (i == 1)
                {
                    cout << "You have rested for 2 days." << endl;
                    //set food perperson
                    S.setRestFood(2, people);
                    day = day + 2;
                    dL.setDate(day, month);
                    pAM.setPlayerHealthFull();
                }
                if (i == 2)
                {
                    cout << "You have rested for 3 days." << endl;
                    //set food per person
                    S.setRestFood(3, people);
                    day = day + 3;
                    dL.setDate(day, month);
                    pAM.setPlayerHealthFull();
                }
            }
            if (choice == 2)
            {
                checkLandmarkChoice = false;
                misfortune(dL, pAM, S);
            }
            else
            {
                cout << "Please enter a valid option." << endl;
            }
        }

    }
}




/*
* Algorithm: that tells player how much cash they have and the things they need to buy, then asks play what they would like to buy or if they want to continue to the trail
* 1. cout tells play remaining cash and why they need to buy item. then asks player what they would like the choose
* 2. while loop that continues running until player has entered a valid option
* 3. if choice is 1 then goes to shop oxn function, if 2 goes to shop food fucntion, if 3 then goes to shop ammo function, if 4 then goes to shop misc function, if 5 then goes to status update function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: shop information then asks user what option they would like to choose
* Returns: Nothing
*/
void visitStore(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int choice;
    bool check = true;
    int currentCash = S.getCash();

    cout << "You have $" << currentCash << " left." << endl;
    cout << " You will need to spend the rest of your money on the\nfollowing items:" << endl;
    cout << "- OXEN: You can spend $100-$200 on your team. The more you spend,\nthe faster you'll go becuase you'll have better animals" << endl;
    cout << "- FOOD: The more you have, the less chance there is of getting sick" << endl;
    cout << "- AMMUNITION: You will need bullets for attacks by animals and\nbandits, and for hunting food" << endl;
    cout << "- MISCELLANEOUS SUPPLIES: This includes medicine and other things\nyou will need for sickness and emergency repairs" << endl;
    cout << "You can spend all your money before you start your trip, or you can\nsave some of your cash to spend at forts along the way when you run" << endl;
    cout << "low. However, items cost more at the forts. You can also go hunting\nalong the way to get more food." << endl;
    cout << "What would you like to purchase." << endl;
    while (check) //while loop that continues to ask u to enter a valid option until you have and check is set to false and loop stops
    {
        cout << "1. Oxen\n2. Food\n3. Ammunition\n4. Miscellaneous Supplies\n5. To continue to the trail" << endl;
        cin >> choice;

        if (choice == 1)
        {
            //buy oxen
            shopOxen(dL, pAM, S);
            check = false;
        }
        if (choice == 2)
        {
            //buy food
            shopFood(dL, pAM, S);
            check = false;
        }
        if (choice == 3)
        {
            //buy ammo
            shopAmmo(dL, pAM, S);
            check = false;
        }
        if (choice == 4)
        {
            //buy misc supp
            shopMisc(dL, pAM, S);
            check = false;
        }
        if (choice == 5)
        {
            //quit
            check = false;
            //go to turn
            statusUpdate(dL, pAM, S);
        }
        else
        {
            cout << "Please enter a valid option" << endl;
        }
    }
}


/*
* Algorithm: that tells the user information about oxen then asks how many they would like to purchase
* 1. cout tells user oxen price then asks how many they would like to purchase
* 2. while loops to make sure user spends over 100 on oxen and no more then 200 then goes to visit store function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: tells user oxen info then ask user for how many they would like to purchase
* Returns: Nothing
*/
void shopOxen(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    bool oxenChecker = true;
    int moneyCheck = 0;
    int yokes;
    bool check = true;
    int choice;
    bool checking = true;
    moneyCheck = S.getCash();
    int oxenCheck = S.getOxen();
    int cashCheck = S.getCash();

    while (checking)
    {
        oxenChecker = true;
        check = true;
        checking = true;
        yokes = 0;
        oxenCheck = 0;
        cout << "You must purchase between $100-$200 on oxen." << endl;
        cout << "There is 2 oxen in a yoke, each yoke is $40." << endl;
        while (check)
        {
            while (oxenChecker)
            {
                cout << "How many yokes do you wish to purchase? ";
                cin >> yokes;

                if ((S.getOxen() * 20) + (yokes * 40) > 200)
                {
                    cout << S.getOxen() << endl;
                    cout << "You may not spend over $200 on oxen" << endl;
                }
                else
                {
                    oxenChecker = false;
                }
            }
            if ((yokes * 40) <= 100 && (yokes * 40) >= 200)
            {
                cout << "You must spend between $100-$200 on oxen, please enter a valid input." << endl;
            }
            else
            {
                check = false;
            }
        }
        cout << "Would you like to purchase " << yokes << " yokes for $" << yokes * 40 << "?" << endl;
        check = true;
        while (check)
        {
            cout << "1. Yes\n2. No" << endl;
            cin >> choice;
            if (choice == 1)
            {
                int x = 0;
                x = S.getCash() - (yokes * 40);
                S.setCash(x);
                check = false;
                checking = false;
                S.setOxen(yokes * 2);
                dL.setSpeed(S);
                cout << "Thank you for your purchase, you have purchased " << yokes << " yoke(s) and " << yokes * 2 << " oxen for $" << yokes * 40 << ". You have $" << x << " left." << endl;
                cout << " ---------------------------------------------------------------------------------------------------------" << endl;
                visitStore(dL, pAM, S);
                break;
            }
            if (choice == 2)
            {
                check = false;
            }
            else
            {
                cout << "Please enter a valid option." << endl;
            }
        }
    }
}


/*
* Algorithm: that tells user how much food they should buy then asks how much they would like to buy
* 1. cout telling user recomended amount of food to purchase then price of food per pound then how much they would like to purchase
* 2. while loop chekcing that user has enough cash to make purchase then goes to visit store function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: info about food then asks user hpw much they would like to purchase
* Returns: Nothing
*/
void shopFood(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    bool check = true;
    bool check2 = true;
    bool check3 = true;
    int food1;
    int choice;
    int cashCheck = S.getCash();
    bool foodCheck = true;

    cout << "I recommend for your journey you should purchase at least 200Lbs per person." << endl;

    while (check3)
    {
        while (check)
        {
            check = true;
            check2 = true;
            food1 = 0;
            choice = 0;
            foodCheck = true;
            cout << "Food is 50 cents per pound." << endl;

            while (foodCheck)//while loop to check that user has enough money to make the purchase
            {
                cout << "How many pounds of food would you like to purchase? ";
                cin >> food1;
                if ((cashCheck - (food1 * .5)) < 0)
                {
                    cout << "You do not have enough cash to make that purchase. Please enter a new value." << endl;
                }
                else
                {
                    foodCheck = false;
                    break;
                }
            }


            cout << "Would you like to purchase " << food1 << "Lbs of food for $" << food1 * .5 << "." << endl;
            while (check2)
            {
                cout << "1. Yes\n2. No" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    int x = 0;
                    x = S.getCash() - food1 * .5;
                    S.setCash(x);
                    S.setFood(food1);
                    cout << "Thank you for your purchase, you have purchased " << food1 << "Lbs of food for $" << food1 * .5 << ". You have $" << x << " left." << endl;
                    cout << " ---------------------------------------------------------------------------------------------------------" << endl;
                    check = false;
                    check2 = false;
                    check3 = false;
                    visitStore(dL, pAM, S);
                }
                if (choice == 2)
                {
                    check2 = false;
                }
                else
                {
                    cout << "Please enter a valid choice." << endl;
                    check2 = false;
                    check3 = false;
                }
            }
        }
    }
}


/*
* Algorithm: that tells user info about ammuntion then asks how much they would like to purchase
* 1. cout to tell user information and pricing of bullets then asks how much they would like to purchase
* 2. while loop to check that user has enought money to make transaction
* 3. if enough money asks user if they would like to make purchase
* 4. if purchase made then cout what they bought and remaining money the go to visit store function
* 5. if no then while loop isnt stopped and goes back to beginging and asks user what they would like to purchase
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: tells user info about ammo then asks how much they would like to purchase
* Returns: Nothing
*/
void shopAmmo(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int box;
    int choice;
    int cashCheck = S.getCash();
    bool ammoCheck = true;
    bool check = true;
    bool check2 = true;
    bool check3 = true;
    while (check)
    {
        box = 0;
        choice = 0;
        check = true;
        check2 = true;
        ammoCheck = true;
        cout << "A box of 20 bullets costs $2" << endl;


        while (ammoCheck)
        {
            cout << "How many boxes do you wish to purchas? " << endl;
            cin >> box;
            if ((cashCheck - (box * 2)) < 0)
            {
                cout << "You do not have enough cash available for that purchase, please enter a valid amount." << endl;
            }
            else
            {
                ammoCheck = false;
            }
        }

        cout << "Would you like to purchase " << box << " boxe(s) of bullets for $" << box * 2 << endl;
        while (check2)
        {
            cout << "1. Yes\n2. No" << endl;
            cin >> choice;
            if (choice == 1)
            {
                check = false;
                check2 = false;


                int x = 0;
                x = S.getCash() - box * 2;
                S.setCash(x);
                S.setBullets(box * 20);
                cout << "Thank you for your purchase, you have purchased " << box << " boxe(s) of bullets for $" << box * 2 << ". You have $" << x << " left." << endl;
                cout << " ---------------------------------------------------------------------------------------------------------" << endl;
                visitStore(dL, pAM, S);
            }
            if (choice == 2)
            {
                check2 = false;
            }
            else
            {
                check = false;
                cout << "Please enter a valid choice." << endl;
            }
        }
    }

}


/*
* Algorithm: that tells user info about wagon parts and how many they would like to purchase then tells user info about medical kits then asks how many they would like to purchase
* 1. cout tells user info about wagon parts then asks them how many they wish to purchase
* 2. while loop to check that user has enough money for purchase then another while loop if they wish to not purchase
* 3. cout that tells user info about medical kits then asks them how many they wish to purchase
* 4. while loop to check if user has enough money then another while loop if they wish to not purchase
* 5. cout tells user what they purchased then remainging cash then goes to visit store function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: asks user info about wagon parts and med kits then asks how many they wish to purchase
* Returns: Nothing
*/
void shopMisc(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int cashCheck = S.getCash();
    int parts;
    int choice;
    bool partCheck = true;
    bool check = true;
    bool check2 = true;
    while (check)
    {
        check = true;
        check2 = true;
        partCheck = true;
        parts = 0;
        choice = 0;

        cout << "Wagon parts (wheels, axels, tongues) cost $20 a part" << endl;


        while (partCheck)
        {
            cout << "How many wagon parts would you like to purchase?" << endl;
            cin >> parts;
            if ((cashCheck - (parts * 20)) < 0)
            {
                cout << "You do not have enough cash for this purchase, please enter a valid amount." << endl;
            }
            else
            {
                partCheck = false;
            }
        }

        cout << "Would you like to pruchase " << parts << " wagon parts for $" << parts * 20 << "?" << endl;
        while (check2)
        {
            cout << "1. Yes\n2. No" << endl;
            cin >> choice;
            if (choice == 1)
            {
                int x = 0;
                x = S.getCash() - (parts * 20);
                S.setCash(x);
                S.setWagonParts(parts);
                cout << "Thank you for your purchase, you have bought " << parts << " wagon parts for $" << parts * 20 << ". You have $" << x << " left." << endl;
                check = false;
                check2 = false;
                break;
            }
            if (choice == 2)
            {
                check2 = false;
            }
            else
            {
                check = false;
                cout << "Please enter a valid choice." << endl;
            }
        }
    }

    int cashCheck2 = S.getCash();
    int medical;
    int choice2;
    bool medCheck = true;
    bool check3 = true;
    bool check4 = true;

    while (check3)
    {
        check3 = true;
        check4 = true;
        medCheck = true;
        medical = 0;
        choice2 = 0;

        cout << "Medical aid kits cost $25 a kit." << endl;
        while (medCheck)
        {
            cout << "How many medical kits do you wish to purchase?" << endl;
            cin >> medical;
            if ((cashCheck2 - (medical * 25)) < 0)
            {
                cout << "You do not have enough cash for this purchase, please enter a valid amount." << endl;
            }
            else
            {
                medCheck = false;
            }
        }




        cout << "Would you like to purchase " << medical << " medical kits for $" << medical * 25 << "?" << endl;
        while (check4)
        {
            cout << "1. Yes\n2. No" << endl;
            cin >> choice2;
            if (choice2 == 1)
            {

                check3 = false;
                check4 = false;
                int y = 0;
                y = S.getCash() - (medical * 25);
                S.setCash(y);
                S.setMedKit(medical);
                cout << "Thank you for your purchase, you have bought " << medical << " medical kits for $" << medical * 25 << ". You have $" << y << " left." << endl;
            }
            if (choice2 == 2)
            {
                check4 = false;
            }
            else
            {
                check3 = false;
                cout << "Please enter a valid option." << endl;
            }
        }
    }

    int z = S.getCash();

    cout << "You have bought " << parts << " wagon parts and " << medical << " medical kits for a total of $" << (parts * 20) + (medical * 25) << ". You have $" << z << " left." << endl;
    cout << " ---------------------------------------------------------------------------------------------------------" << endl;
    visitStore(dL, pAM, S);
}


/*
* Algorithm: that checks condtions that end the game
* 1. if statments that each check a condtion that end the game, then goes to end function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: how the player died or if they won and reached oregon
* Returns: Nothing
*/
void EndGameChecker(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int month = dL.getMonth();
    int day = dL.getDay();
    int leaderHealth = pAM.getLeaderHealth();
    int food = S.getFood();
    int oxen = S.getOxen();
    int wagonParts = S.getWagonPart();
    int wagonHealth = S.getWagonHealth();
    int miles = dL.getMiles();
    string leader = pAM.getLeaderName();
    string cause;

    if (miles >= 2040)
    {
        cout << "Congratulations! You made it to Oregon City by" << endl;
        cause = "Congratulations! You made it to Oregon City!";
        end(dL, pAM, S, cause);
    }
    if (month >= 11 && day >= 30)
    {
        cout << "November 30th, 1847 has arrived. Your party was not able to comlete the trail on time." << endl;
        cout << "Better luck next time! You stats have been saved to the file." << endl;
        //go to end game save file
        cause = "November 30th arrived sooner then expected. You were not able to make it to Oregon.";
        end(dL, pAM, S, cause);
    }
    if (food <= 0) //check food
    {
        cout << "You have died from starvation!" << endl;
        cout << "Better luck next time! You stats have been saved to the file." << endl;
        //go to end game save file
        cause = " died from starvation!";
        cause = leader + cause;
        end(dL, pAM, S, cause);
    }
    if (oxen <= 0)  //check oxen
    {
        cout << "All your oxen have died! Your party will not be able to complete to trail." << endl;
        cout << "Better luck next time! You stats have been saved to the file." << endl;
        //go to end game save file
        cout << "All you oxen died!";
        end(dL, pAM, S, cause);
    }
    if (wagonParts <= 0 && wagonHealth <= 50) //check wagon / wagon parts
    {
        cout << "Your wagon has broken down and you have no more parts! Your party will not be able to complete the trail." << endl;
        cout << "Better luck next time! You stats have been saved to the file." << endl;
        //go to end game save file
        cause = "Your wagon broke down and you were not able to repair it.";
        end(dL, pAM, S, cause);
    }
    if (leaderHealth <= 0) //check if leader is dead
    {
        cout << "You have died! your party will not be able to complete the trail without you." << endl;
        cout << "Better luck next time! You stats have been saved to the file." << endl;
        //go to end game save file
        cause = " died from ";
        //cause = leader + cause + sickness;
        end(dL, pAM, S, cause);
    }
    else
    {
        raiders(dL, pAM, S);
    }
}


/*
* Algorithm: that checks if the player has met with attacing raiders then asks how they wish to deal with it
* 1. int m comes from raider probality function, if m is 1 then the player has met raiders
* 2. if player meets raiders asks the player how they would like the handle them
* 3. if 1 then player runs sets food and ox and wagon parts accorily then goes to status update function
* 4. if 2 then player attacks raiders and is asked to solve puzz;e, if puzzle is solved correct then players supplys are changed accorinly and goes to satus update function
* 5. if player looses puzzle then supplies changed accordingly and goes to status update function
* 6. if 3 then player surrenders and supplys are set accordingly and goes to status update function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs:
* Returns:
*/
void raiders(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    int choice;
    bool check = true;
    int ox = S.getOxen();
    int wagonpart = S.getWagonPart();
    int food = S.getFood();
    int bullets = S.getBullets();
    int cash = S.getCash();
    int m = dL.riders();
    //check radier probaility
    if (m == 1)//if raiders________________________________________change
    {
        cout << "Rider ahead! They look hostile!" << endl;
        cout << "Would you like to" << endl;
        while (check)
        {
            cout << "1. Run\n2. Attack\n3.Surrender" << endl;
            cin >> choice;
            if (choice == 1)
            {
                check = false;
                S.setFood(food - 10);
                S.setWagonParts(wagonpart - 1);
                S.setOxen(ox - 1);
                cout << "In the hectic flee, you lost 1 ox, 10lbs of food, and 1 wagon part." << endl;
                statusUpdate(dL, pAM, S);
            }
            else if (choice == 2)
            {
                int puzzle = pAM.problem();
                int pChoice;
                for (int p = 0; p < 3; p++)
                {
                    cout << "Guess a number between 1 and 10, you have 3 tries to get it right" << endl;
                    cin >> pChoice;
                    if (pChoice == puzzle)
                    {
                        S.setBullets(bullets + 50);
                        S.setFood(food - 50);
                        cout << "Success! You beat the attacking riders! You pluder 50 lbs of food and 50 bullets!" << endl;
                        statusUpdate(dL, pAM, S);
                    }
                    else
                    {
                        cout << "Sorry that's incorrect, you have " << 2 - p << " tries left!" << endl;
                    }
                }
                cout << "Oh no! The riders won! They spare your lives but have taken a quarter of your remaining cash reserves and 50 bullets!" << endl;
                int cash2 = cash / 4;
                S.setCash(cash - cash2);
                S.setBullets(bullets - 50);
                statusUpdate(dL, pAM, S);
            }
            else if (choice == 3)
            {
                int cash3 = cash / 4;
                S.setCash(cash - cash3);
                cout << "You surrender to the attacking rider, you loose a quarter of your remaining cash reserves!" << endl;
                statusUpdate(dL, pAM, S);
            }
            else
            {
                cout << "Please enter a valid option." << endl;
            }
        }
    }
    else
    {
        statusUpdate(dL, pAM, S);
    }
}


/*
* Algorithm: that checks if a misfortune has occured and responds accordingly
* 1. mis calulated by random number generator functio
* 2. if mis is 0 then disease occurs, random players is effected with random disease, then go to end game chekcer functio
* 3. if mis i 1 then an oxen death occus, 1 oxen is removed then goes to end game check funtion
* 4. if mis is 2 then a theif attack occus, theif steal random number lbs of food then goes to end game checker function
* 5. if mis is 3 then a part of the wagon breaks, wagon health decreases then checks if wagon parts are availbe to repair, goes to end game checker function
* 6. if mis is 4 then bad weather occurs, random number decides what weather occurs, food and date set accordinly then goes to end game checker function
* 7. if mis is none then no misfortune occured, then goes to end game checker function
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: tells player what misfortune has occured and what they have lossed
* Returns: Nothing
*/
void misfortune(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S)
{
    //check if there is a misfurtune
    int mis = pAM.random();
    if (mis == 0)//disease
    {
        pAM.setMisfortuneNum(0);
        string disease = pAM.rDisease();
        int nameIndex = pAM.rNameNum();
        string name = pAM.rName(nameIndex);
        int playerHealth = pAM.getPlayerHealth(nameIndex);
        cout << "Oh no! " << name << " has contracted " << disease << endl;
        //set players health
        if (playerHealth <= 50)
        {
            cout << "Oh no! " << name << " has died from " << disease << "." << endl;
        }
        pAM.setPlayerHealth(nameIndex);
        EndGameChecker(dL, pAM, S);
    }
    if (mis == 1)//oxen death
    {
        pAM.setMisfortuneNum(1);
        int oxen = S.getOxen();
        oxen = oxen - 1;
        S.setOxen(oxen);
        cout << "Oh no! One of the oxen has died! You have " << oxen << " oxen left." << endl;
        //endgame checker
        EndGameChecker(dL, pAM, S);
    }
    if (mis == 2)//theif attack
    {
        pAM.setMisfortuneNum(2);
        int theif = pAM.rTheif();
        int food = S.getFood();
        food = food - theif;
        S.setFood(food);
        cout << "Oh no! Last night you got attacked by a theif. He stole " << theif << " Lbs of food. You have " << food << " Lbs of food left." << endl;
        //endgame checker
        EndGameChecker(dL, pAM, S);
    }
    if (mis == 3)//wagon break
    {
        pAM.setMisfortuneNum(3);
        int wagonP = S.getWagonPart();
        int wagonH = S.getWagonHealth();

        wagonH = wagonH - 50;
        S.setWagonHealth(wagonH);

        cout << "Oh no! One of your wheels is broken!" << endl;
        if (wagonP <= 0)
        {
            //endgame checker
            EndGameChecker(dL, pAM, S);
        }
        else
        {
            int wFood = S.getFood();
            int people = pAM.getNumPeople();
            wagonP = wagonP - 1;
            S.setWagonParts(wagonP);
            S.setMisFood(1, people);
            int tFood = S.getFood();
            int uFood = people * 3;

            cout << "You must wait 1 day to repair your wagon. You have eaten " << uFood << " Lbs of food and have " << tFood << " Lbs of food left. You have " << wagonP << " wagon parts left." << endl;

            EndGameChecker(dL, pAM, S);
            //end game checker
        }
    }
    if (mis == 4)
    {
        //bad weather
        pAM.setMisfortuneNum(4);
        int weatherINT = pAM.rWeather();

        if (weatherINT == 1)//Heavy rain 1 day
        {
            int food1 = S.getFood();
            int numPeople1 = pAM.getNumPeople();
            S.setMisFood(1, numPeople1);

            cout << "Oh no! The weather is rotten! Heavy rain!" << endl;
            cout << "You must wait 1 day for it to past." << endl;

            //end game checker
            EndGameChecker(dL, pAM, S);
        }
        if (weatherINT == 2)//hail 1 day
        {
            int food2 = S.getFood();
            int numPeople2 = pAM.getNumPeople();
            S.setMisFood(1, numPeople2);

            cout << "Oh no! The weather is rotten! Hail!" << endl;
            cout << "You must wait 1 day for it to past." << endl;

            //endgame checker
            EndGameChecker(dL, pAM, S);
        }
        if (weatherINT == 3)//storm 3 days
        {
            int food3 = S.getFood();
            int numPeople3 = pAM.getNumPeople();
            S.setMisFood(3, numPeople3);

            cout << "Oh no! The weather is rotten! Storm!" << endl;
            cout << "You must wait 3 days for it to past." << endl;

            //end game chekcer
            EndGameChecker(dL, pAM, S);
        }
        if (weatherINT == 4)//Blizzard 3 days
        {
            int food4 = S.getFood();
            int numPeople4 = pAM.getNumPeople();
            S.setMisFood(3, numPeople4);

            cout << "Oh no! The weather is rotten! Blizzard!" << endl;
            cout << "You must wait 3 days for it to past." << endl;

            //end game checker
            EndGameChecker(dL, pAM, S);
        }
        if (weatherINT == 5)//Hurricane 7 days
        {
            int food5 = S.getFood();
            int numPeople5 = pAM.getNumPeople();
            S.setMisFood(7, numPeople5);

            cout << "Oh no! The weather is rotten! Hurricane!" << endl;
            cout << "You must wait 7 days for it to past." << endl;

            //end game checker
            EndGameChecker(dL, pAM, S);
        }

    }
    else
    {
        //statusUpdate(dL, pAM, S);
        EndGameChecker(dL, pAM, S);
    }

}


/*
* Algorithm: that writes the players stats to a file
* 1. opens file for writing
* 2. writes to file, cause of death, wagon leaders name, miles travled, and remaining cash
* Parameters: dL(date and location type), pAM(people and misfortunes type), S (supplies type)
* Outputs: Nothing
* Returns: Nothing
*/
int end(dateAndLocation& dL, peopleAndMisfortunes& pAM, supplies& S, string death)
{
    ofstream end;
    end.open("results.txt");
    if (end.is_open())
    {
        string leader = pAM.getLeaderName();
        int miles = dL.getMiles();
        int cash = S.getCash();
        //death
        end << death << endl;
        //leader name
        end << "Wagon Leader: " << leader << endl;
        //miles traveled
        end << "Miles Traveled: " << miles << endl;
        //cash remaining
        end << "Cash Remaining: " << cash << endl;
        exit(0);
    }
}

void quit()
{
    cout << "Sorry to see you cut your trip to Oregon so short, see you again next time!" << endl;
    exit(0);
}


int main()
{
    supplies S;
    peopleAndMisfortunes pAM;
    dateAndLocation dL;
    setLeaderName(dL, pAM, S);
    return 0;
}
