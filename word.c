#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAXLENGHT 13
int count=0, i;

char words[26][5][MAXLENGHT] = {
    {"apple", "apricot", "avocado", "allay", "alien"},       // A +
    {"banana", "blueberry", "blackberry", "bus", "bullet"}, // B +
    {"cherry", "cantaloupe", "cranberry", "cup", "cologne"}, // C +
    {"date", "dragonfruit", "durian", "daisy", "demon"},     // D +
    {"elderberry", "eggplant", "endive", "enemy", "egg"},  // E
    {"fig", "feijoa", "fingerlime", "family", "fragile"},       // F
    {"grape", "guava", "gooseberry", "glass", "guitar"},      // G
    {"honeydew", "hackberry", "hawthorn", "hot", "handsome"}, // H
    {"iceberg", "ivy", "indianfig", "ideal", "iron"},       // I
    {"jackfruit", "jalapeno", "jicama", "jump", "june"},   // J
    {"kiwi", "kumquat", "kale", "knife", "key"},           // K
    {"lemon", "lime", "lychee", "logic", "leopard"},           // L +
    {"mango", "melon", "mulberry", "mouse", "money"},        // M
    {"nectarine", "nutmeg", "nashi", "night", "north"},      // N
    {"orange", "olive", "okra", "orchid", "overflow"},           // O +
    {"papaya", "peach", "pear", "pocket", "pineapple"},           // P +
    {"quince", "quinoa", "queenfruit", "quiz", "quack"},    // Q
    {"raspberry", "rhubarb", "roseapple", "rich", "rainbow"}, // R
    {"strawberry", "spinach", "soursop", "star", "song"},  // S
    {"tangerine", "tomato", "tamarind", "technical", "terrific"},   // T
    {"ugli", "upland", "uva", "university", "unique"},             // U
    {"vanilla", "vine", "vetch", "video", "vortex"},          // V
    {"watermelon", "walnut", "wheat", "walk", "wrath"},     // W
    {"xigua", "xylocarp", "xerophyte", "xenon", "x-ray"},    // X
    {"yogurt", "yam", "yellowfruit", "yes", "yo"},      // Y
    {"zebrawood", "zucchini", "ziziphus", "zinc", "zen"}
};

bool gameActive = true;

char wordCheck(char userW[]){
    int lenWordCheck = strlen(userW);
    i=0;
    int check = 0;
    while(userW[i]<0 || userW[i]>26 && i<lenWordCheck){
        check++;
        i++;
    }
    if(check !=0){
        printf("YOU ENTERED WRONG STUFFS. TRY AGAIN.\n\n");
    }
}

char* randomChoose(int lastLetter){
    //[0,2] araılığında olması lazım. harf seçtik hangi kelimeyi seçeceğimize karar veriyoruz.
    int randNum = (rand() % 5);
    return words[lastLetter][randNum];
    /*  fonksiyon char tipinde tanımlandı. dolayısıyla bir geri dönüş bekliyor. burada return kullanılmak zorunda. 
        yoksa derleyici bunu bir hata olarak algılayacaktı.*/
}

bool keepGoing(char* userW, char* chosenWord){
    int lenC = strlen(chosenWord); //strlen null karakteri saymaz
    if(userW[0] != chosenWord[lenC-1]){
        printf("??\nENTER A WORD THAT ENDS WITH THE LAST LETTER OF GIVEN WORD.\n\n");
        count++;
    }
    return true;
}

int main(){
    srand(time(NULL)); //rastgele sayı üreticisi. yoksa rand hep aynı sayıları en baştan başlayarak verecektir.

    char userW[MAXLENGHT];
    int len;
    int lastLetter;


    printf("ENTER A WORD:\n");
    scanf("%s",userW);
    wordCheck(userW);

    while(gameActive){
        len = strlen(userW);
        lastLetter = (userW[len-1] - 'a');
        //printf("last letter:%c\n",(lastLetter+'a'));

        if(lastLetter < 0 || lastLetter > 26){
            printf("YOU ENTERED WRONG STUFFS. TRY AGAIN.\n\n");
            gameActive = false;
            continue;
        }

        if(count>4){
            printf("\nYOU FAILED TOO MANY TIMES. TAKE A BREAK...\n");
            gameActive = false;
            continue; //döngüde spesifik bir değer için döngüyü es geçme. ama döngüyü bitirmez veyahut içinden çıkmaz. 
                      //break: döngüyü direkt es geçer. bitirir.
        }

        char* chosenWord = randomChoose(lastLetter);
        printf("NEW WORD: %s\nENTER NEW WORD:\n",chosenWord);
        scanf("%s",userW);
        wordCheck(userW);

        gameActive = keepGoing(userW,chosenWord);    
    }

    printf("YOU LOST.");
    return 0;
}