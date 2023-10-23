#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "utils.h"

struct person newN(){
    struct person temp;
    strcpy(temp.title,"\0\0");
    temp.key = -1;
    temp.str = NULL;
    for(int i=0;i<5;i++)
        strcpy(temp.info[i],"\0\0");
    return temp;
};

int generateSongsFile(){
    int rt = 1;
    FILE *outfile;

    // open file for writing
    outfile = fopen ("person.dat", "wb");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }


    struct person input1;
    input1 = newN();
    strcpy(input1.title,"ed");
    input1.key = 1;
    input1.str = "Ed Sheeran is a English singer-songwriter";
    strcpy(input1.info[0],"Some songs by Ed Sheeran: ");
    strcpy(input1.info[1],"Perfect");
    strcpy(input1.info[2],"Castle on the Hill");
    strcpy(input1.info[3],"Galway Girl");
    strcpy(input1.info[4],"Thinking Out Loud");

    struct person input2;
    input2 = newN();
    strcpy(input2.title,"taylor");
    input2.key = 2;
    input2.str = "Taylor Swift is a American singer-songwriter";
    strcpy(input2.info[0],"Some songs by Taylor Swift: ");
    strcpy(input2.info[1],"Perfect");
    strcpy(input2.info[2],"Love Story");
    strcpy(input2.info[3],"Blank Space");

    struct person input3;
    input3 = newN();
    strcpy(input3.title,"selena");
    input3.key = 3;
    input3.str = "Selena Marie Gomez is an American singer, actress, and producer.";
    strcpy(input3.info[0],"Some songs by Selena Gomez: ");
    strcpy(input3.info[1],"It Ain't Me");
    strcpy(input3.info[2],"Kill Em with Kindness");
    strcpy(input3.info[3],"Back to You");
    strcpy(input3.info[4],"Wolves");

    struct person input4;
    input4 = newN();
    strcpy(input4.title,"lata");
    input4.key = 4;
    input4.str = "Lata Mangeshkar was an Indian playback singer.";
    strcpy(input4.info[0],"Some songs by Lata Mangeshkar:");
    strcpy(input4.info[1],"Lo Chali Main");
    strcpy(input4.info[2],"Lag Jaa Gale");
    strcpy(input4.info[3],"Mere Khwabon Mein");
    strcpy(input4.info[4],"Yeh Galiyan Yeh Chaubara");

    struct person input5;
    input5 = newN();
    strcpy(input5.title,"kishore");
    input5.key = 5;
    input5.str = "Kishore Kumar was an Indian playback singer and actor. ";
    strcpy(input5.info[0],"Some songs by Kishore Kumar:");
    strcpy(input5.info[1],"Ek Ladki Bheegi Bhaagi Si");
    strcpy(input5.info[2],"Phir Suhani Sham Dhali");
    strcpy(input5.info[3],"Kehne Ki Nahin Baat");
    strcpy(input5.info[4],"Koi Humdum Na Raha");

    // write struct to file
    printf("Hello\n\n\n");
    fwrite (&input1, sizeof(struct person), 1, outfile);
    fwrite (&input2, sizeof(struct person), 1, outfile);
    fwrite (&input3, sizeof(struct person), 1, outfile);
    fwrite (&input4, sizeof(struct person), 1, outfile);
    fwrite (&input5, sizeof(struct person), 1, outfile);
    /*if(fwrite != 0){
        //printf("contents to file written successfully !\n");
        rt =  1;
    }
    else{
        printf("error writing songs file !\n");
        rt =  0;
    }*/

    //printf("Hello\n\n\n");

    // close file
    fclose (outfile);
    

    return rt;

}


int generateFloraFaunaFile(){
    int rt = 1;
    int i = 0;
    FILE *outfile;

    // open file for writing
    outfile = fopen ("florafauna.dat", "wb");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }

    struct person input1;
    input1 = newN();
    strcpy(input1.title,"flora");
    input1.key = 1;
    input1.str = "Flora is a collective term for a group of plant life found in a particular region.";
    strcpy(input1.info[0],"The term flora in Latin means \" Goddess of the Flower.\" ");
    strcpy(input1.info[1],"The whole plant kingdom is represented by this name.");

    struct person input2;
    input2 = newN();
    strcpy(input2.title,"fauna");
    input2.key = 2;
    input2.str = "Fauna represents the animal life indigenous to a region.";
    strcpy(input2.info[0],"As per Roman mythology, Fauna or \"Faunus\" is the name of the goddess of fertility.");
    strcpy(input2.info[1],"The whole animal kingdom is represented by this name.");

    // write struct to file
    fwrite (&input1, sizeof(struct person), 1, outfile);
    fwrite (&input2, sizeof(struct person), 1, outfile);

    struct person input3;
    input3 = newN();
    strcpy(input3.title,"mango");
    input3.key = 3;
    input3.str = "A mango is an edible stone fruit produced by Mango Tree/( Mangifera Indica /)";
    strcpy(input3.info[0],"The mango tree growing zone is limited to tropical climates. ");
    strcpy(input3.info[1],"The Mangifera Indica is believed to have originated from the region between northeastern India.");

    struct person input4;
    input4 = newN();
    strcpy(input4.title,"apple");
    input4.key = 4;
    input4.str = "An apple is an edible fruit produced by an apple tree (Malus domestica).";
    strcpy(input4.info[0],"Apple trees are cultivated worldwide and are the most widely grown species in the genus Malus.");
    strcpy(input4.info[1],"Apple tree originated in Central Asia, where its wild ancestor, Malus sieversii,is still found today.");
    //strcpy(input4.info[2],"Apples have been grown for thousands of years in Asia and Europe.");
    strcpy(input4.info[3],"Apples were brought to North America by European colonists. ");

    struct person input5;
    input5 = newN();
    strcpy(input5.title,"banana");
    input5.key = 5;
    input5.str = "A banana is an elongated, edible fruit botanically a berry.";
    strcpy(input5.info[0],"Banana produced by several kinds of large herbaceous flowering plants in the genus Musa.");
    strcpy(input5.info[1],"The banana plant is the largest herbaceous flowering plant.");

    struct person input6;
    input6 = newN();
    strcpy(input6.title,"tree");
    input6.key = 6;
    input6.str = "Tree is a part of Flora";
    strcpy(input6.info[0],"In botany, a tree is a perennial plant with an elongated stem, or trunk, usually supporting branches and leaves. ");
    strcpy(input6.info[1],"Trees from all around the world have been visited, worshipped, and celebrated.");
    strcpy(input6.info[2],"Some example Apple trees, Mango trees, Banana trees, mangrove trees and many more.");

    struct person input7;
    input7 = newN();
    strcpy(input7.title,"mangrove");
    input7.key = 7;
    input7.str = "Mangrove is a type of tree and part of Flora";
    strcpy(input7.info[0],"Mangrove forests are a group of trees and shrubs that live along sheltered subtropic and tropical coastlines.");
    strcpy(input7.info[1],"The species of trees that exist in mangroves have a unique capability of growing within reach of the tides in salty soil.");
    strcpy(input7.info[2],"Mangroves also play a very important role in protecting coastlines from storms and rising waters.");

    struct person input8;
    input8 = newN();
    strcpy(input8.title,"lion");
    input8.key = 8;
    input8.str = "The lion is a large cat of the genus Panthera native to Africa and India.";
    strcpy(input8.info[0],"It has a muscular, broad-chested body, short, rounded head, round ears, and a hairy tuft at the end of its tail.\" ");

    struct person input9;
    input9 = newN();
    strcpy(input9.title,"tiger");
    input9.key = 9;
    input9.str = "The tiger is the largest living cat species and a member of the genus Panthera.";
    strcpy(input9.info[0],"It is most recognisable for its dark vertical stripes on orange fur with a white underside.\" ");
    strcpy(input9.info[1],"An apex predator, it primarily preys on ungulates such as deer and wild boar.");

    struct person input10;
    input10 = newN();
    strcpy(input10.title,"rabbit");
    input10.key = 10;
    input10.str = "Rabbits, also known as bunnies or bunny rabbits, are small mammals in the family Leporidae of the order Lagomorpha. ";
    strcpy(input10.info[0],"Rabbit, Any small, bounding, gnawing mammal of the family Leporidae.");

    // write struct to file
    fwrite (&input3, sizeof(struct person), 1, outfile);
    fwrite (&input4, sizeof(struct person), 1, outfile);
    fwrite (&input5, sizeof(struct person), 1, outfile);
    fwrite (&input6, sizeof(struct person), 1, outfile);
    fwrite (&input7, sizeof(struct person), 1, outfile);
    fwrite (&input8, sizeof(struct person), 1, outfile);
    fwrite (&input9, sizeof(struct person), 1, outfile);
    fwrite (&input10, sizeof(struct person), 1, outfile);
    /*if(fwrite != 0){
        //printf("contents to file written successfully !\n");
        rt =  1;
    }
    else{
        printf("error writing flora fauna file !\n");
        rt =  0;
    }*/

    // close file
    fclose(outfile);

    return rt;
}

int generateSportsFile(){
    int rt = 1;
    int i = 0;
    FILE *outfile;

    // open file for writing
    outfile = fopen ("sports.dat", "wb");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }

    struct person input1;
    input1 = newN();
    strcpy(input1.title,"sports");
    input1.key = 1;
    input1.str = "Sports is an activity involving physical exertion and skill in which an individual or team competes against another.";
    strcpy(input1.info[0],"Sports can, through casual or organized participation, improve one's physical health.\" ");

    struct person input2;
    input2 = newN();
    strcpy(input2.title,"football");
    input2.key = 2;
    input2.str = "Football is also called association football or soccer.";
    strcpy(input2.info[0],"It is a game involving two teams of 11 players.");
    strcpy(input2.info[1],"Players try to maneuver the ball into the other team's goal without using their hands or arms.");
    strcpy(input2.info[1],"The team that scores more goals wins.");

    // write struct to file
    fwrite (&input1, sizeof(struct person), 1, outfile);
    fwrite (&input2, sizeof(struct person), 1, outfile);

    struct person input3;
    input3 = newN();
    strcpy(input3.title,"tennis");
    input3.key = 3;
    input3.str = "Tennis is believed to have originated during 12th or 13th century in France.";
    strcpy(input3.info[0],"Tennis is played in Singles, and Doubles variants.");
    strcpy(input3.info[1],"Singles has one player on each side of the court.");
    strcpy(input3.info[1],"Doubles match has two players per team.");

    struct person input4;
    input4 = newN();
    strcpy(input4.title,"volleyball");
    input4.key = 4;
    input4.str = "Volleyball is a game played by two teams";
    strcpy(input4.info[0],"There are usually of six players on a side");

    struct person input5;
    input5 = newN();
    strcpy(input5.title,"golf");
    input5.key = 5;
    input5.str = "Golf is a cross-country game";
    strcpy(input5.info[0],"Player strikes a small ball with clubs from a series of starting points into holes on course.");
    strcpy(input5.info[1],"The player who holes his ball in the fewest strokes wins.");

    struct person input6;
    input6 = newN();
    strcpy(input6.title,"basketball");
    input6.key = 7;
    input6.str = "Basketball is usually a indoors games.";
    strcpy(input6.info[0],"Basketball is played between two teams of five players each on a rectangular court.");
    strcpy(input6.info[1],"Each team tries to score by tossing the ball through the opponent's goal.");

    struct person input7;
    input7 = newN();
    strcpy(input7.title,"cricket");
    input7.key = 8;
    input7.str = "Cricket is a bat-and-ball game.";
    strcpy(input7.info[0],"Cricket is a game played between two teams, generally of 11 members each.");
    strcpy(input7.info[0],"Today, it is a popular sport in many countries");

    // write struct to file
    fwrite (&input3, sizeof(struct person), 1, outfile);
    fwrite (&input4, sizeof(struct person), 1, outfile);
    fwrite (&input5, sizeof(struct person), 1, outfile);
    fwrite (&input6, sizeof(struct person), 1, outfile);
    fwrite (&input7, sizeof(struct person), 1, outfile);

    /*if(fwrite != 0){
        //printf("contents to file written successfully !\n");
        rt =  1;
    }
    else{
        printf("error writing sports file !\n");
        rt =  0;

    }*/

    // close file
    fclose(outfile);
    return rt;
}


