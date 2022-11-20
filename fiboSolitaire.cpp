#include<iostream>
#include<string>
#include "Card.h"
#include "Deck.h"

using namespace std;

bool isFibo(int number)
{

    int fibo_elements [13] = {1,1,2,3,5,8,13,21,34,55,89,144,233};

    for(int i = 0; i < 13; i++)
    {
      if(fibo_elements[i] == number)
      {
        return true;
      }
    }
    return false;
}

int main()
{

    int piles = 0;
    int user_input;
    

    cout << "Welcome to Fibonacci Solitaire!" << endl;
    cout << "1) New Deck" << endl;
    cout << "2) Display Deck" << endl;
    cout << "3) Shuffle Deck" << endl;
    cout << "4) Play Solitaire" << endl;
    cout << "5) Exit"<< endl;
    cin >> user_input;

    Deck d;
    while(user_input != 5){
        if(user_input == 1)
        {
            d.refreshDeck();
        }
        else if(user_input == 2)
        {
            d.display();
        }
        else if(user_input == 3)
        {
            d.shuffle();
        }
        else
        {   
            Card lift;
            cout << "Playing Fibonacci Solitaire !!!"<<endl;;
            // int sum_cards = d.deal().getValue();
            int sum_cards = 0;
            while(d.isEmpty() == false)
            {   
                
                if(isFibo(sum_cards) == false)
                {
                    lift = d.deal();
                    lift.display();
                    sum_cards = sum_cards + lift.getValue();
                }
                else
                {
                    cout << "fibo: " << sum_cards;
                    sum_cards = 0;
                    piles++;
                    cout << endl;
                }
                if(d.isEmpty())
                {
                  cout << "last hand value: " << sum_cards;
                }
            }
            
            
            if(isFibo(sum_cards) == true && d.isEmpty() == true)
            {
                cout << "\nWinner in " << piles << " piles! "<< endl;
            }
            else if(d.isEmpty() == true && isFibo(sum_cards) == false)
            {
                cout << "\nLoser in " << piles << " piles! " << endl;
            }

            piles = 0;
        }
        
        cout << "Welcome to Fibonacci Solitaire!" << endl;
        cout << "1) New Deck" << endl;
        cout << "2) Display Deck" << endl;
        cout << "3) Shuffle Deck" << endl;
        cout << "4) Play Solitaire" << endl;
        cout << "5) Exit"<< endl;
        cin >> user_input;
    }

    return 0;
}