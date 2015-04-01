#include <stdio.h>
#include <string.h>
    
struct Inputdata
{
    char suit;
    char value;
    int suit_weight;
    int value_weight;
};
struct Record
{
    int value; 
};
int StraightFlush_or_Flush(int value[])
{
    int i;
    for(i = 0;i < 9;i++)
    {
        int sum = 0;
        sum += value[i] + value[i+1] + value[i+2] + value[i+3] + value[i+4];
        if(sum == 5)
        {
            return 1;           //is StraightFlush
        }
    }
    return 4;                   //is Flush
}

int Other(int value[])
{
    int i;
    for(i = 0;i < 13;i++)
    {
        if(value[i] == 4){return 2;}        //is Bomb
        if(value[i] == 3)
        {
            int j;
            for(j = 0;j < 13;j++)
            {
                if(value[j] == 2)
                {
                    return 3;               // is Full House
                }
            }
            return 6;                       // is Triplet
        }
        if(value[i] == 2)
        {
            int k;
            for(k = 0;k < 13;k++)
            {
                if(i != k)
                {
                    if(value[k] == 2)
                    {
                        return 7;           //is Two Pairs
                    }
                }
            }
            return 8;                       //is Pairs
        }
    }
    for(i = 0;i < 9;i++)
    {
        int sum = 0;
        sum += value[i] + value[i+1] + value[i+2] + value[i+3] + value[i+4];
        if(sum == 5)
        {
            return 5;           //is Straight
        }
    }
    return 9;                   //is High Card
}

void Output(int which_answer,int value[],struct Inputdata inputdata[],struct Record record[])
{
    switch(which_answer){
        case 1:
        {
            int i,j,temp;
            char temp_value;
            for(i = 0;i < 4;i++)
            {
                for(j = i+1; j < 5;j++)
                {
                    if(inputdata[j].value_weight < inputdata[i].value_weight)
                    {
                        temp = inputdata[j].value_weight;
                        inputdata[j].value_weight = inputdata[i].value_weight;
                        inputdata[i].value_weight = temp;

                        temp_value = inputdata[j].value;
                        inputdata[j].value = inputdata[i].value;
                        inputdata[i].value = temp_value;
                    }
                }
            }
            if(inputdata[4].value_weight != 8)
            {
                printf("%c%c-straight flush\n",inputdata[4].suit,inputdata[4].value);
            }
            else
            {
                printf("%c10-straight flush\n",inputdata[4].suit);
            }
            for(i = 0;i < 5;i++)
            {
                if(inputdata[i].value_weight != 8)
                {
                   printf("%c%c ",inputdata[i].suit,inputdata[i].value);
                }
                else
                {
                    printf("%c10 ",inputdata[i].suit);
                }
            }
            printf("\n");
            break;
        }
        case 2:
        {
            int i,j;
            int first = inputdata[0].value_weight;
            int spec;
            int temp,temp_suit_weight;
            char temp_value,temp_suit;
            for(i = 1;i < 5;i++)
            {
                if(first != inputdata[i].value_weight)
                {
                    if(i == 4)                                  //fifth isn't same
                    {
                        temp = inputdata[0].value_weight;
                        inputdata[0].value_weight = inputdata[i].value_weight;
                        inputdata[i].value_weight = temp;

                        temp_value = inputdata[0].value;
                        inputdata[0].value = inputdata[i].value;
                        inputdata[i].value = temp_value;

                        temp_suit = inputdata[0].suit;
                        inputdata[0].suit = inputdata[i].suit;
                        inputdata[i].suit = temp_suit;

                        temp_suit_weight = inputdata[0].suit_weight;
                        inputdata[0].suit_weight = inputdata[i].suit_weight;
                        inputdata[i].suit_weight = temp_suit_weight;
                        break;
                    }
                    if(first != inputdata[i+1].value_weight)        //first isn't same
                    {
                        break;
                    }
                    else
                    {                                           //second isn't same
                        temp = inputdata[0].value_weight;
                        inputdata[0].value_weight = inputdata[i].value_weight;
                        inputdata[i].value_weight = temp;

                        temp_value = inputdata[0].value;
                        inputdata[0].value = inputdata[i].value;
                        inputdata[i].value = temp_value;

                        temp_suit = inputdata[0].suit;
                        inputdata[0].suit = inputdata[i].suit;
                        inputdata[i].suit = temp_suit;

                        temp_suit_weight = inputdata[0].suit_weight;
                        inputdata[0].suit_weight = inputdata[i].suit_weight;
                        inputdata[i].suit_weight = temp_suit_weight;
                        break;
                    }   
                }
            }
            for(i = 1;i < 4;i++)
            {
                for(j = i+1; j < 5;j++)
                {
                    if(inputdata[j].suit_weight < inputdata[i].suit_weight)
                    {
                        temp_suit_weight = inputdata[j].suit_weight;
                        inputdata[j].suit_weight = inputdata[i].suit_weight;
                        inputdata[i].suit_weight = temp_suit_weight;

                        temp_suit = inputdata[j].suit;
                        inputdata[j].suit = inputdata[i].suit;
                        inputdata[i].suit = temp_suit;
                    }
                }
            }
            if(inputdata[4].value_weight != 8)
            {
                printf("%c-four of a kind\n",inputdata[4].value);
            }
            else
            {
                printf("10-four of a kind\n");
            }
            for(i = 0;i < 5;i++)
            {
                if(inputdata[i].value_weight != 8)
                {
                   printf("%c%c ",inputdata[i].suit,inputdata[i].value);
                }
                else
                {
                    printf("%c10 ",inputdata[i].suit);
                }
            }
            printf("\n");
            break;
        }
        case 3:
        {
            int temp,temp_suit_weight;
            char temp_value,temp_suit;
            int three_index;
            int two_index;
            int i,j;
            int index = 1;
            for(i = 0;i < 13;i++)
            {
                if(record[i].value == 3)
                {
                    three_index = i;        //know what number is three same
                }
                else if(record[i].value == 2)
                {
                    two_index = i;        //know what number is two same
                }
            }
            char new_suit[5];
            char new_value[5];
            int new_suit_weight[5];
            int new_value_weight[5];
            int two_address[2];
            int three_address[3];
            int three_cont = 0;
            int two_cont = 0;
            for(i = 0;i < 5;i++)
            {
                if(inputdata[i].value_weight == three_index)
                {
                    three_address[three_cont] = i;
                    three_cont++;
                }
                else
                {
                    two_address[two_cont] = i;
                    two_cont++;
                }
            }
            int con = 0;
            for(i = 0;i < 2;i++)
            {
                new_suit[con] = inputdata[two_address[i]].suit;
                new_suit_weight[con] = inputdata[two_address[i]].suit_weight;
                new_value[con] = inputdata[two_address[i]].value;
                new_value_weight[con] = inputdata[two_address[i]].value_weight;
                con++;
            }
            for(i = 0;i < 3;i++)
            {
                new_suit[con] = inputdata[three_address[i]].suit;
                new_suit_weight[con] = inputdata[three_address[i]].suit_weight;
                new_value[con] = inputdata[three_address[i]].value;
                new_value_weight[con] = inputdata[three_address[i]].value_weight;
                con++;
            }
            if(new_suit_weight[0] > new_suit_weight[1])
            {
                temp = new_value_weight[0];
                new_value_weight[0] = new_value_weight[1];
                new_value_weight[1] = temp;

                temp_value = new_value[0];
                new_value[0] = new_value[1];
                new_value[1] = temp_value;

                temp_suit_weight = new_suit_weight[0];
                new_suit_weight[0] = new_suit_weight[1];
                new_suit_weight[1] = temp_suit_weight;

                temp_suit = new_suit[0];
                new_suit[0] = new_suit[1];
                new_suit[1] = temp_suit;
            }
            for(i = 2;i < 4;i++)
            {
                for(j = i+1;j < 5;j++)
                {
                    if(new_suit_weight[i] > new_suit_weight[j])
                    {
                        temp = new_value_weight[i];
                        new_value_weight[i] = new_value_weight[j];
                        new_value_weight[j] = temp;

                        temp_value = new_value[i];
                        new_value[i] = new_value[j];
                        new_value[j] = temp_value;

                        temp_suit_weight = new_suit_weight[i];
                        new_suit_weight[i] = new_suit_weight[j];
                        new_suit_weight[j] = temp_suit_weight;

                        temp_suit = new_suit[i];
                        new_suit[i] = new_suit[j];
                        new_suit[j] = temp_suit;
                    }
                }
            }
            if(new_suit_weight[4] != 8)
            {
                printf("%c-full house\n",new_value[4]);
            }
            else
            {
                printf("10-full house\n");
            }
            for(i = 0;i < 5;i++)
            {
                if(new_suit_weight[4] != 8)
                {
                   printf("%c%c ",new_suit[i],new_value[i]);
                }
                else
                {
                    printf("%c10 ",new_suit[i]);
                }
            }
            printf("\n");
            break;
        }
        case 4:
        {
            int i,j,temp;
            char temp_value;
            int sum = 0;
            for(i = 0; i < 5;i++)
            {
                sum += inputdata[i].value_weight;
            }
            if(sum == 18)
            {
                printf("Is not considered a straight\n");
                break;
            }
            for(i = 0;i < 4;i++)
            {
                for(j = i+1; j < 5;j++)
                {
                    if(inputdata[j].value_weight < inputdata[i].value_weight)
                    {
                        temp = inputdata[j].value_weight;
                        inputdata[j].value_weight = inputdata[i].value_weight;
                        inputdata[i].value_weight = temp;

                        temp_value = inputdata[j].value;
                        inputdata[j].value = inputdata[i].value;
                        inputdata[i].value = temp_value;
                    }
                }
            }
            if(inputdata[4].value_weight != 8)
            {
                printf("%c%c-flush\n",inputdata[4].suit,inputdata[4].value);
            }
            else
            {
                printf("%c10-flush\n",inputdata[4].suit);
            }
            for(i = 0;i < 5;i++)
            {
                if(inputdata[i].value_weight != 8)
                {
                   printf("%c%c ",inputdata[i].suit,inputdata[i].value);
                }
                else
                {
                    printf("%c10 ",inputdata[i].suit);
                }
            }
            printf("\n");
            break;
        }
        case 5:
        {
            int i,j,temp;
            char temp_value;
            char temp_suit;
            for(i = 0;i < 4;i++)
            {
                for(j = i+1; j < 5;j++)
                {
                    if(inputdata[j].value_weight < inputdata[i].value_weight)
                    {
                        temp = inputdata[j].value_weight;
                        inputdata[j].value_weight = inputdata[i].value_weight;
                        inputdata[i].value_weight = temp;

                        temp_value = inputdata[j].value;
                        inputdata[j].value = inputdata[i].value;
                        inputdata[i].value = temp_value;

                        temp_suit = inputdata[j].suit;
                        inputdata[j].suit = inputdata[i].suit;
                        inputdata[i].suit = temp_suit;
                    }
                }
            }
            if(inputdata[4].value_weight != 8)
            {
                printf("%c%c-straight\n",inputdata[4].suit,inputdata[4].value);
            }
            else
            {
                printf("%c10-straight\n",inputdata[4].suit);
            }
            for(i = 0;i < 5;i++)
            {
                if(inputdata[i].value_weight != 8)
                {
                   printf("%c%c ",inputdata[i].suit,inputdata[i].value);
                }
                else
                {
                    printf("%c10 ",inputdata[i].suit);
                }
            }
            printf("\n");
            break;
        }
        case 6:
        {
            int temp,temp_suit_weight;
            char temp_value,temp_suit;
            int three_index;
            int two_index;
            int i,j;
            for(i = 0;i < 13;i++)
            {
                if(record[i].value == 3)
                {
                    three_index = i;        //know what number is three same
                }
            }
            char new_suit[5];
            char new_value[5];
            int new_suit_weight[5];
            int new_value_weight[5];
            int two_address[2];
            int three_address[3];
            int three_cont = 0;
            int two_cont = 0;
            for(i = 0;i < 5;i++)
            {
                if(inputdata[i].value_weight == three_index)
                {
                    three_address[three_cont] = i;
                    three_cont++;
                }
                else
                {
                    two_address[two_cont] = i;
                    two_cont++;
                }
            }
            for(i= 0;i<3;i++)
            {
                printf("three_address is : %d\n",three_address[i]);
            }
            int con = 0;
            for(i = 0;i < 2;i++)
            {
                new_suit[con] = inputdata[two_address[i]].suit;
                new_suit_weight[con] = inputdata[two_address[i]].suit_weight;
                new_value[con] = inputdata[two_address[i]].value;
                new_value_weight[con] = inputdata[two_address[i]].value_weight;
                con++;
            }
            for(i = 0;i < 3;i++)
            {
                new_suit[con] = inputdata[three_address[i]].suit;
                new_suit_weight[con] = inputdata[three_address[i]].suit_weight;
                new_value[con] = inputdata[three_address[i]].value;
                new_value_weight[con] = inputdata[three_address[i]].value_weight;
                con++;
            }
            if(new_suit_weight[0] > new_suit_weight[1])
            {
                temp = new_value_weight[0];
                new_value_weight[0] = new_value_weight[1];
                new_value_weight[1] = temp;

                temp_value = new_value[0];
                new_value[0] = new_value[1];
                new_value[1] = temp_value;

                temp_suit_weight = new_suit_weight[0];
                new_suit_weight[0] = new_suit_weight[1];
                new_suit_weight[1] = temp_suit_weight;

                temp_suit = new_suit[0];
                new_suit[0] = new_suit[1];
                new_suit[1] = temp_suit;
            }
            for(i = 2;i < 4;i++)
            {
                for(j = i+1;j < 5;j++)
                {
                    if(new_suit_weight[i] > new_suit_weight[j])
                    {
                        temp = new_value_weight[i];
                        new_value_weight[i] = new_value_weight[j];
                        new_value_weight[j] = temp;

                        temp_value = new_value[i];
                        new_value[i] = new_value[j];
                        new_value[j] = temp_value;

                        temp_suit_weight = new_suit_weight[i];
                        new_suit_weight[i] = new_suit_weight[j];
                        new_suit_weight[j] = temp_suit_weight;

                        temp_suit = new_suit[i];
                        new_suit[i] = new_suit[j];
                        new_suit[j] = temp_suit;
                    }
                }
            }
            if(new_suit_weight[4] != 8)
            {
                printf("%c-three of a kind\n",new_value[4]);
            }
            else
            {
                printf("10-three of a kind\n");
            }
            for(i = 0;i < 5;i++)
            {
                if(new_suit_weight[4] != 8)
                {
                   printf("%c%c ",new_suit[i],new_value[i]);
                }
                else
                {
                    printf("%c10 ",new_suit[i]);
                }
            }
            printf("\n");
            break;
        }
        case 7:
        {
            int temp,temp_suit_weight;
            char temp_value,temp_suit;
            int first_two_index;
            int second_two_index;
            int i,j;
            int key = 0;
            for(i = 0;i < 13;i++)
            {
                if((record[i].value == 2) && key == 0)
                {
                    first_two_index = i;        //know what number is two same
                    key = 1;
                }
                else if((record[i].value == 2) && key == 1)
                {
                    second_two_index = i;
                }
            }
            char new_suit[5];
            char new_value[5];
            int new_suit_weight[5];
            int new_value_weight[5];
            int two_address[2];
            int second_two_address[2];
            int one_address;
            int two_cont = 0;
            int second_two_cont = 0;
            for(i = 0;i < 5;i++)
            {
                if(inputdata[i].value_weight == first_two_index)
                {
                    two_address[two_cont] = i;
                    two_cont++;
                }
                else if(inputdata[i].value_weight == second_two_index)
                {
                    second_two_address[second_two_cont] = i;
                    second_two_cont++;
                }
                else
                {
                    one_address = i;
                }
            }
            int con = 0;
            new_suit[con] = inputdata[one_address].suit;
            new_suit_weight[con] = inputdata[one_address].suit_weight;
            new_value[con] = inputdata[one_address].value;
            new_value_weight[con] = inputdata[one_address].value_weight;
            con++;
            for(i = 0;i < 2;i++)
            {
                new_suit[con] = inputdata[two_address[i]].suit;
                new_suit_weight[con] = inputdata[two_address[i]].suit_weight;
                new_value[con] = inputdata[two_address[i]].value;
                new_value_weight[con] = inputdata[two_address[i]].value_weight;
                con++;
            }
            for(i = 0;i < 2;i++)
            {
                new_suit[con] = inputdata[second_two_address[i]].suit;
                new_suit_weight[con] = inputdata[second_two_address[i]].suit_weight;
                new_value[con] = inputdata[second_two_address[i]].value;
                new_value_weight[con] = inputdata[second_two_address[i]].value_weight;
                con++;
            }
            if(new_suit_weight[1] > new_suit_weight[2])
            {
                temp = new_value_weight[1];
                new_value_weight[1] = new_value_weight[2];
                new_value_weight[2] = temp;

                temp_value = new_value[1];
                new_value[1] = new_value[2];
                new_value[2] = temp_value;

                temp_suit_weight = new_suit_weight[1];
                new_suit_weight[1] = new_suit_weight[2];
                new_suit_weight[2] = temp_suit_weight;

                temp_suit = new_suit[1];
                new_suit[1] = new_suit[2];
                new_suit[2] = temp_suit;
            }
            if(new_suit_weight[3] > new_suit_weight[4])
            {
                temp = new_value_weight[3];
                new_value_weight[3] = new_value_weight[4];
                new_value_weight[4] = temp;

                temp_value = new_value[3];
                new_value[3] = new_value[4];
                new_value[4] = temp_value;

                temp_suit_weight = new_suit_weight[3];
                new_suit_weight[3] = new_suit_weight[4];
                new_suit_weight[4] = temp_suit_weight;

                temp_suit = new_suit[3];
                new_suit[3] = new_suit[4];
                new_suit[4] = temp_suit;
            }
            if(new_suit_weight[4] != 8)
            {
                printf("%c%c-two pairs\n",new_suit[4],new_value[4]);
            }
            else
            {
                printf("%c10-two pairs\n",new_suit[4]);
            }
            for(i = 0;i < 5;i++)
            {
                if(new_suit_weight[4] != 8)
                {
                   printf("%c%c ",new_suit[i],new_value[i]);
                }
                else
                {
                    printf("%c10 ",new_suit[i]);
                }
            }
            printf("\n");
            break;
        }
        case 8:
        {
            int temp,temp_suit_weight;
            char temp_value,temp_suit;
            int two_index;
            int i,j;
            for(i = 0;i < 13;i++)
            {
                if(record[i].value == 2)
                {
                    two_index = i;        //know what number is two same
                }
            }
            char new_suit[5];
            char new_value[5];
            int new_suit_weight[5];
            int new_value_weight[5];
            int two_address[2];
            int three_address[3];
            int three_cont = 0;
            int two_cont = 0;
            for(i = 0;i < 5;i++)
            {
                if(inputdata[i].value_weight == two_index)
                {
                    two_address[two_cont] = i;
                    two_cont++;
                }
                else
                {
                    three_address[three_cont] = i;
                    three_cont++;
                }
            }
            int con = 0;
            for(i = 0;i < 3;i++)
            {
                new_suit[con] = inputdata[three_address[i]].suit;
                new_suit_weight[con] = inputdata[three_address[i]].suit_weight;
                new_value[con] = inputdata[three_address[i]].value;
                new_value_weight[con] = inputdata[three_address[i]].value_weight;
                con++;
            }
            for(i = 0;i < 2;i++)
            {
                new_suit[con] = inputdata[two_address[i]].suit;
                new_suit_weight[con] = inputdata[two_address[i]].suit_weight;
                new_value[con] = inputdata[two_address[i]].value;
                new_value_weight[con] = inputdata[two_address[i]].value_weight;
                con++;
            }
            if(new_suit_weight[3] > new_suit_weight[4])
            {
                temp = new_value_weight[3];
                new_value_weight[3] = new_value_weight[4];
                new_value_weight[4] = temp;

                temp_value = new_value[3];
                new_value[3] = new_value[4];
                new_value[4] = temp_value;

                temp_suit_weight = new_suit_weight[3];
                new_suit_weight[3] = new_suit_weight[4];
                new_suit_weight[4] = temp_suit_weight;

                temp_suit = new_suit[3];
                new_suit[3] = new_suit[4];
                new_suit[4] = temp_suit;
            }
            for(i = 0;i < 2;i++)
            {
                for(j = i+1;j < 3;j++)
                {
                    if(new_suit_weight[i] > new_suit_weight[j])
                    {
                        temp = new_value_weight[i];
                        new_value_weight[i] = new_value_weight[j];
                        new_value_weight[j] = temp;

                        temp_value = new_value[i];
                        new_value[i] = new_value[j];
                        new_value[j] = temp_value;

                        temp_suit_weight = new_suit_weight[i];
                        new_suit_weight[i] = new_suit_weight[j];
                        new_suit_weight[j] = temp_suit_weight;

                        temp_suit = new_suit[i];
                        new_suit[i] = new_suit[j];
                        new_suit[j] = temp_suit;
                    }
                }
            }
            if(new_suit_weight[4] != 8)
            {
                printf("%c%c-pair\n",new_suit[4],new_value[4]);
            }
            else
            {
                printf("%c10-pair\n",new_suit[4]);
            }
            for(i = 0;i < 5;i++)
            {
                if(new_suit_weight[4] != 8)
                {
                   printf("%c%c ",new_suit[i],new_value[i]);
                }
                else
                {
                    printf("%c10 ",new_suit[i]);
                }
            }
            printf("\n");
            break;
        }
        case 9:
        {
            int i,j,temp;
            char temp_value;
            char temp_suit;
            for(i = 0;i < 4;i++)
            {
                for(j = i+1; j < 5;j++)
                {
                    if(inputdata[j].value_weight < inputdata[i].value_weight)
                    {
                        temp = inputdata[j].value_weight;
                        inputdata[j].value_weight = inputdata[i].value_weight;
                        inputdata[i].value_weight = temp;

                        temp_value = inputdata[j].value;
                        inputdata[j].value = inputdata[i].value;
                        inputdata[i].value = temp_value;

                        temp_suit = inputdata[j].suit;
                        inputdata[j].suit = inputdata[i].suit;
                        inputdata[i].suit = temp_suit;
                    }
                }
            }
            if(inputdata[4].value_weight != 8)
            {
                printf("%c%c-high card\n",inputdata[4].suit,inputdata[4].value);
            }
            else
            {
                printf("%c10-high card\n",inputdata[4].suit);
            }
            for(i = 0;i < 5;i++)
            {
                if(inputdata[i].value_weight != 8)
                {
                   printf("%c%c ",inputdata[i].suit,inputdata[i].value);
                }
                else
                {
                    printf("%c10 ",inputdata[i].suit);
                }
            }
            printf("\n");
            break;
        }
    }
}




int main()
{   
    char input[15];
    printf("Input data:\n");
    while(fgets(input,16,stdin))
    {
        int i;
        int which_answer = 0;
        int index = 0;
        int suit[4] = {0};
        int value[13] = {0};
        struct Inputdata inputdata[5];
        struct Record record[13];
        for(i = 0;i < 13;i++)
        {
            record[i].value = 0;
        }
        char *test = strtok(input, " ");
        while (test != NULL){
            inputdata[index].suit = test[0];
            inputdata[index].value = test[1];
            switch (inputdata[index].suit){
                case 'S':
                    suit[0]++;
                    inputdata[index].suit_weight = 4;
                    break;
                case 'H':
                    suit[1]++;
                    inputdata[index].suit_weight = 3;
                    break;
                case 'D':
                    suit[2];
                    inputdata[index].suit_weight = 2;
                    break;
                case 'C':
                    suit[3]++;
                    inputdata[index].suit_weight = 1;
                    break;
            }
            switch (inputdata[index].value){
                case 'A':
                    value[12]++;
                    inputdata[index].value_weight = 12;
                    record[12].value++;
                    break;
                case '2':
                    value[0]++;
                    inputdata[index].value_weight = 0;
                    record[0].value++;
                    break;
                case '3':
                    value[1]++;
                    inputdata[index].value_weight = 1;
                    record[1].value++;
                    break;
                case '4':
                    value[2]++;
                    inputdata[index].value_weight = 2;
                    record[2].value++;
                    break;
                case '5':
                    value[3]++;
                    inputdata[index].value_weight = 3;
                    record[3].value++;
                    break;
                case '6':
                    value[4]++;
                    inputdata[index].value_weight = 4;
                    record[4].value++;
                    break;
                case '7':
                    value[5]++;
                    inputdata[index].value_weight = 5;
                    record[5].value++;
                    break;
                case '8':
                    value[6]++;
                    inputdata[index].value_weight = 6;
                    record[6].value++;
                    break;
                case '9':
                    value[7]++;
                    inputdata[index].value_weight = 7;
                    record[7].value++;
                    break;
                case 'T':
                    value[8]++;
                    inputdata[index].value_weight = 8;
                    record[8].value++;
                    break;
                case 'J':
                    value[9]++;
                    inputdata[index].value_weight = 9;
                    record[9].value++;
                    break;
                case 'Q':
                    value[10]++;
                    inputdata[index].value_weight = 10;
                    record[10].value++;
                    break;
                case 'K':
                    value[11]++;
                    inputdata[index].value_weight = 11;
                    record[11].value++;
                    break;
            }
            test = strtok(NULL, " ");
            index++;
        }
        int suit_index = 0;
        int value_index = 0;
        int no_pass1 = 1;
        for(suit_index = 0;suit_index < 4;suit_index++)
        {
            if(suit[suit_index] == 5)
            {
                which_answer = StraightFlush_or_Flush(value);
                no_pass1 = 0;
                Output(which_answer,value,inputdata,record);           
                break;
            }
        }
        if(no_pass1)
        {
            which_answer = Other(value);
            Output(which_answer,value,inputdata,record);
        }
        printf("\nInput data:\n");
    }
    return 0;
}
