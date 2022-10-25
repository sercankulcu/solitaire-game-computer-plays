#include <cstdlib>
#include <iostream>
#include <time.h>       /* time */

using namespace std;

#define CARD_COUNT  52
#define TYPE_CARD_COUNT  13

bool checkIfExists(int cards[], int card, int total)
{
     for(int i = 0; i < total; i++)
     {
             if(cards[i] == card)
                         return false;
     }
     return true;
}

void shuffle(int cards[])
{
     srand((unsigned)time(0));
     
     for(int i = 0; i < CARD_COUNT; i++)
     {
             int temp = -1;
             bool result = false;
             while(result == false)
             {
                          temp = rand() % CARD_COUNT;
                          result = checkIfExists(cards, temp, i);
             }
             cards[i] = temp;
     }
}

int purgeCards(int cards[])
{     
      int temp[CARD_COUNT];
      for(int i = 0; i < CARD_COUNT; i++)
     {
              temp[i] = cards[i];
     }
      int lastCard = 0;
     for(int i = 0; i < CARD_COUNT; i++)
     {
             if(temp[i] != -1)
             {
                         cards[lastCard++] = temp[i];
             }
     }
     for(int i = lastCard; i < CARD_COUNT; i++)
     {
             cards[i] = -1;
     }
     return lastCard + 1;
}

bool play(int cards[])
{
     int heartA[TYPE_CARD_COUNT] = {-1};
     int cloverA[TYPE_CARD_COUNT] = {-1};
     int diamondA[TYPE_CARD_COUNT] = {-1};
     int spadeA[TYPE_CARD_COUNT] = {-1};
     int heartK[TYPE_CARD_COUNT] = {-1};
     int cloverK[TYPE_CARD_COUNT] = {-1};
     int diamondK[TYPE_CARD_COUNT] = {-1};
     int spadeK[TYPE_CARD_COUNT] = {-1};
     int heartACount = 0;
     int cloverACount = 0;
     int diamondACount = 0;
     int spadeACount = 0;
     int heartKCount = 0;
     int cloverKCount = 0;
     int diamondKCount = 0;
     int spadeKCount = 0;
     int lastCard = CARD_COUNT;
     bool gameFinished = false;
     
     while(gameFinished != true)
     {
                        printf("\nnext turn \n");
      gameFinished = true;
      int takenCard = 0;
      for(int i = 2; i < lastCard;)
      {
             //i += 2;
             if(i >= lastCard - 1)
                  i = lastCard;
             printf("\n %d ", cards[i]);
             if(cards[i] == 0)
             {
               heartA[heartACount++] = cards[i];
               
               gameFinished = false;         
               printf("card taken %d \n", cards[i]);
             cards[i] = -1;
             takenCard++;
             }
             else if(cards[i] == 12)
             {
               heartK[heartKCount++] = cards[i];
             
               gameFinished = false;
             printf("card taken %d \n", cards[i]);
             takenCard++;  cards[i] = -1;
               }
             else if(cards[i] == 13)
             {
               cloverA[cloverACount++] = cards[i];
               
               gameFinished = false;
             printf("card taken %d \n", cards[i]);
             takenCard++;cards[i] = -1;
             }
             else if(cards[i] == 25)
             {
               cloverK[cloverKCount++] = cards[i];
                  
               gameFinished = false;
             printf("card taken %d \n", cards[i]);
             takenCard++;cards[i] = -1;
             }
             else if(cards[i] == 26)
             {
               diamondA[diamondACount++] = cards[i];
                  
               gameFinished = false;
             printf("card taken %d \n", cards[i]);
             takenCard++;cards[i] = -1;
             }
             else if(cards[i] == 38)
             {
               diamondK[diamondKCount++] = cards[i];
                  
               gameFinished = false;
             printf("card taken %d \n", cards[i]);
             takenCard++;cards[i] = -1;
             }
             else if(cards[i] == 39)
             {
               spadeA[spadeACount++] = cards[i];
                  
               gameFinished = false;
             printf("card taken %d \n", cards[i]);
             takenCard++;cards[i] = -1;
             }
             else if(cards[i] == 51)
             {
               spadeK[spadeKCount++] = cards[i];
                  
               gameFinished = false;
             printf("card taken %d \n", cards[i]);
             takenCard++;cards[i] = -1;
             }
             else
             {
                 if(heartACount > 0 && cards[i] == heartA[heartACount-1] + 1)
                 {
                     heartA[heartACount++] = cards[i];
               
               gameFinished = false;           
             printf("card taken %d \n", cards[i]);
                 takenCard++;cards[i] = -1;
                 }
                 else if(cloverACount > 0 && cards[i] == cloverA[cloverACount-1] + 1)
                 {
                     cloverA[cloverACount++] = cards[i];
               
               gameFinished = false;           
             printf("card taken %d \n", cards[i]);
                 takenCard++;cards[i] = -1;
                 }
                 else if(diamondACount > 0 && cards[i] == diamondA[diamondACount-1] + 1)
                 {
                     diamondA[diamondACount++] = cards[i];
               
               gameFinished = false;           
             printf("card taken %d \n", cards[i]);
               takenCard++;cards[i] = -1;
                 }
                 else if(spadeACount > 0 && cards[i] == spadeA[spadeACount-1] + 1)
                 {
                     spadeA[spadeACount++] = cards[i];
               
               gameFinished = false;           
             printf("card taken %d \n", cards[i]);
               takenCard++;cards[i] = -1;
                 }
                  else if(heartKCount > 0 && cards[i] == heartK[heartKCount-1] - 1)
                 {
                     heartK[heartKCount++] = cards[i];
               
               gameFinished = false;           
             printf("card taken %d \n", cards[i]);
               takenCard++;cards[i] = -1;
                 }
                 else if(cloverKCount > 0 && cards[i] == cloverK[cloverKCount-1] - 1)
                 {
                     cloverK[cloverKCount++] = cards[i];
               
               gameFinished = false;           
             printf("card taken %d \n", cards[i]);
               takenCard++;cards[i] = -1;
                 }
                 else if(diamondKCount > 0 && cards[i] == diamondK[diamondKCount-1] - 1)
                 {
                     diamondK[diamondKCount++] = cards[i];
               
               gameFinished = false;           
             printf("card taken %d \n", cards[i]);
               takenCard++;cards[i] = -1;
                 }
                 else if(spadeKCount > 0 && cards[i] == spadeK[spadeKCount-1] - 1)
                 {
                     spadeK[spadeKCount++] = cards[i];
                
               gameFinished = false;           
             printf("card taken %d \n", cards[i]);
               takenCard++;cards[i] = -1;
                 }
                 else
                 {
                     i += 3 + takenCard;
                 }
             }
             i -= 1;
      }
      lastCard = purgeCards(cards);
      printf("last card %d \n", lastCard);
      
      printf("\nheart a ");
      for(int a = 0; a < TYPE_CARD_COUNT; a++)
              printf("%d ", heartA[a]);
              printf("\nclover a ");
      for(int a = 0; a < TYPE_CARD_COUNT; a++)
              printf("%d ", cloverA[a]);
      printf("\ndiamond a ");
      for(int a = 0; a < TYPE_CARD_COUNT; a++)
              printf("%d ", diamondA[a]);
      printf("\nspade a ");
      for(int a = 0; a < TYPE_CARD_COUNT; a++)
              printf("%d ", spadeA[a]);
      printf("\nheart k ");
      for(int a = 0; a < TYPE_CARD_COUNT; a++)
              printf("%d ", heartK[a]);
              printf("\nclover k ");
      for(int a = 0; a < TYPE_CARD_COUNT; a++)
              printf("%d ", cloverK[a]);
      printf("\ndiamond k ");
      for(int a = 0; a < TYPE_CARD_COUNT; a++)
              printf("%d ", diamondK[a]);
      printf("\nspade k ");
      for(int a = 0; a < TYPE_CARD_COUNT; a++)
              printf("%d ", spadeK[a]);  
              printf("\n");                      
     }
     
     if(lastCard < 3)
                 return true;
     return false;
}

int main(int argc, char *argv[])
{
    
     int cards[CARD_COUNT];
    shuffle(cards); 
    for(int i = 0; i < CARD_COUNT; i++)
     {
            printf("%d ", cards[i]);
     }
    bool result = play(cards);        
    
    if(result)
              printf("YOU WIN!");
    
    for(int i = 0; i < CARD_COUNT; i++)
     {
            printf("%d ", cards[i]);
     }
    //system("PAUSE");
    return EXIT_SUCCESS;
}

