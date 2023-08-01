#include <unistd.h>
#include<stdio.h>
#include<stdbool.h>

//Creating a Function to the incident where user still in the lift while power cut happens
void PowerInterupt(int PowerCutFloor,int DistanceToDestinationFloor,int CurrentFloor,int DestinationFloor,int DistanceToPowerCutFloor){

    DistanceToDestinationFloor=CurrentFloor-DestinationFloor;
    DistanceToPowerCutFloor=CurrentFloor-PowerCutFloor;

    if(DistanceToDestinationFloor<0){
        DistanceToDestinationFloor=DistanceToDestinationFloor*-1;
    }

    if(DistanceToPowerCutFloor<0){
        DistanceToPowerCutFloor=DistanceToPowerCutFloor*-1;
    }


    if(DistanceToDestinationFloor>DistanceToPowerCutFloor){
            if (DestinationFloor<CurrentFloor){

                printf("\n\n");
                char statement[] = "We're going down dear user. You may feel a flying a bit.";
                int delay = 50000;

                for (int i = 0; statement[i] != '\0'; i++) {
                    putchar(statement[i]);
                    fflush(stdout);

                    usleep(delay);
                }

                putchar('\n');

                printf("\n");
                while(CurrentFloor>=PowerCutFloor){
                    printf("\nFloor %d\n", CurrentFloor);

                    #ifdef _WIN32
                        Sleep(500);
                    #else
                        usleep(500000);
                    #endif
                    CurrentFloor--;
                }
                printf("\n\nPower Cut is detected. The lift will stop at the closest Bottom floor..\n\n");
                int ClosestFloor=PowerCutFloor-1;
                printf("\nFloor %d\n",ClosestFloor);
                //printf("\nDoor Opens\n\n");

                printf("\n\n");
                char statement8[] = "Door Opens..";
                int delay8 = 50000;

                for (int i = 0; statement8[i] != '\0'; i++) {
                    putchar(statement8[i]);
                    fflush(stdout);

                    usleep(delay8);
                }

                putchar('\n');

                printf("\n");
                char statement9[] = "Have a Nice Day!!";
                int delay9 = 50000;

                for (int i = 0; statement9[i] != '\0'; i++) {
                    putchar(statement9[i]);
                    fflush(stdout);

                    usleep(delay9);
                }

                putchar('\n');
            printf("\n\n\n");

            }


            else if (DestinationFloor>CurrentFloor){
                printf("\n");
                char statement[] = "We're going up dear user. You may feel a flying a bit.";
                int delay = 50000;

                for (int i = 0; statement[i] != '\0'; i++) {
                    putchar(statement[i]);
                    fflush(stdout);

                    usleep(delay);
                }

                putchar('\n');


                while(CurrentFloor<=PowerCutFloor){
                    printf("\nFloor %d\n",CurrentFloor);

                    #ifdef _WIN32
                        Sleep(500);
                    #else
                        usleep(500000);
                    #endif
                    CurrentFloor++;
                }
                //Notify the user about the power cut
                printf("\nPower Cut is detected. The lift will stop at the closest Bottom floor\n");
                int ClosestFloor=PowerCutFloor-1;
                printf("\nFloor %d\n",ClosestFloor);
                printf("\nDoor Opens..\n\n");
            }




    }
    else {
       /* //Incident of when a power cut happens before user reach destination
        printf("\nPower Cut is detected. The lift will stop at the closest Bottom floor\n");
        int ClosestFloor=PowerCutFloor-1;
        printf("\nFloor %d\n",ClosestFloor);
        printf("\nDoor Opens\n"); */

        if (DestinationFloor<CurrentFloor){

                            printf("\n\n");
                            char statement10[] = "We're going down dear user. You may feel a flying a bit.";
                            int delay10 = 50000;

                            for (int i = 0; statement10[i] != '\0'; i++) {
                                putchar(statement10[i]);
                                fflush(stdout);

                                usleep(delay10);
                            }

                            putchar('\n');

                            printf("\n");
                            while(CurrentFloor>=DestinationFloor){
                                printf("\nFloor %d\n", CurrentFloor);

                                #ifdef _WIN32
                                    Sleep(500);
                                #else
                                    usleep(500000);
                                #endif
                                CurrentFloor--;
                            }

                            printf("\n\n");
                            char statement11[] = "Door Opens..";
                            int delay11 = 50000;

                            for (int i = 0; statement11[i] != '\0'; i++) {
                                putchar(statement11[i]);
                                fflush(stdout);

                                usleep(delay11);
                            }
                            putchar('\n');



                            char statement12[] = "Have a Nice Day!!";
                            int delay12 = 50000;

                            for (int i = 0; statement12[i] != '\0'; i++) {
                                putchar(statement12[i]);
                                fflush(stdout);

                                usleep(delay12);
                            }
                            putchar('\n');

                       }


                       else if (DestinationFloor>CurrentFloor){

                            printf("\n");
                            char statement13[] = "We're going up dear user. You may feel a flying a bit.";
                            int delay13= 50000;

                            for (int i = 0; statement13[i] != '\0'; i++) {
                                putchar(statement13[i]);
                                fflush(stdout);

                                usleep(delay13);
                            }

                            putchar('\n');


                            //printf("\nWe're going up dear user. You may feel some G torque.\n");
                            while(CurrentFloor<=DestinationFloor){
                                printf("\nFloor %d\n",CurrentFloor);

                                #ifdef _WIN32
                                    Sleep(500);
                                #else
                                    usleep(500000);
                                #endif
                                CurrentFloor++;
                            }

                            printf("\n");
                            char statement14[] = "Door Opens..";
                            int delay14 = 50000;

                            for (int i = 0; statement14[i] != '\0'; i++) {
                                putchar(statement14[i]);
                                fflush(stdout);

                                usleep(delay14);
                            }

                            putchar('\n');


                            char statement15[] = "Have a Nice Day!!";
                            int delay15 = 50000;

                            for (int i = 0; statement15[i] != '\0'; i++) {
                                putchar(statement15[i]);
                                fflush(stdout);

                                usleep(delay15);
                            }

                            putchar('\n');

                       }
    }
}







void main(){
    bool power=true;  //assuming there is not a power cut yet.To Check what happen if power cut happens before user enter the lift by changing this to false
    //bool FireAlarm=false;
    int CurrentFloor=9;   //assuming current floor as 1st flow
    int DestinationFloor;
    int PowerCutFloor=3;  //assuming the electricity will cut at 5th flow
    int IntrerruptionSeq; //To check whether what happen if a power cut happens while the user still on the lift enter any key
    int DistanceToDestinationFloor; //Creating this To check whether the lift will pass the floor where power cut happens or not
    int DistanceToPowerCutFloor;

    //Incident of not any power cut till the user reach his destination
    while(power==true){

        //Asking the details of Destination from user
        char statement[] = "Enter Your Destination Floor (1-10):";
        int delay = 50000;

        for (int i = 0; statement[i] != '\0'; i++) {
            putchar(statement[i]);
            fflush(stdout);

            usleep(delay);
        }

        //putchar('\n');

        scanf("%d",&DestinationFloor);


        if((DestinationFloor>=1)&&(DestinationFloor<=10)){
                printf("\n");
                char statement[] = "Do you want to initiate Interruption Sequence?If yes Press 1 or else press any other entry:";
                int delay = 50000;

                for (int i = 0; statement[i] != '\0'; i++) {
                    putchar(statement[i]);
                    fflush(stdout);

                    usleep(delay);
                }


                scanf("%d",&IntrerruptionSeq);//To check whether what will happen if a power cut happens while the user still on the lift enter any key.

                //If there is a Power cut
                if (IntrerruptionSeq==1){
                        PowerInterupt(PowerCutFloor,DistanceToDestinationFloor,CurrentFloor,DestinationFloor,DistanceToPowerCutFloor); //the function we create at the beginning.
                }


                //If there is not any power cut

                else if(IntrerruptionSeq!=1){
                       //If the lift moving down
                       if (DestinationFloor<CurrentFloor){

                            printf("\n\n");
                            char statement[] = "We're going down dear user. You may feel a flying a bit.";
                            int delay = 50000;

                            for (int i = 0; statement[i] != '\0'; i++) {
                                putchar(statement[i]);
                                fflush(stdout);

                                usleep(delay);
                            }

                            putchar('\n');

                            printf("\n");
                            while(CurrentFloor>=DestinationFloor){
                                printf("\nFloor %d\n", CurrentFloor);

                                #ifdef _WIN32
                                    Sleep(500);
                                #else
                                    usleep(500000);
                                #endif
                                CurrentFloor--;
                            }

                            printf("\n\n");
                            char statement2[] = "Door Opens..";
                            int delay2 = 50000;

                            for (int i = 0; statement2[i] != '\0'; i++) {
                                putchar(statement2[i]);
                                fflush(stdout);

                                usleep(delay2);
                            }
                            putchar('\n');



                            char statement3[] = "Have a Nice Day!!";
                            int delay3 = 50000;

                            for (int i = 0; statement3[i] != '\0'; i++) {
                                putchar(statement3[i]);
                                fflush(stdout);

                                usleep(delay3);
                            }
                            putchar('\n');

                            break;

                       }


                       else if (DestinationFloor>CurrentFloor){

                            printf("\n");
                            char statement[] = "We're going up dear user. You may feel a flying a bit.";
                            int delay = 50000;

                            for (int i = 0; statement[i] != '\0'; i++) {
                                putchar(statement[i]);
                                fflush(stdout);

                                usleep(delay);
                            }

                            putchar('\n');


                            //printf("\nWe're going up dear user. You may feel some G torque.\n");
                            while(CurrentFloor<=DestinationFloor){
                                printf("\nFloor %d\n",CurrentFloor);

                                #ifdef _WIN32
                                    Sleep(500);
                                #else
                                    usleep(500000);
                                #endif
                                CurrentFloor++;
                            }

                            printf("\n");
                            char statement4[] = "Door Opens..";
                            int delay4 = 50000;

                            for (int i = 0; statement4[i] != '\0'; i++) {
                                putchar(statement4[i]);
                                fflush(stdout);

                                usleep(delay4);
                            }

                            putchar('\n');


                            char statement5[] = "Have a Nice Day!!";
                            int delay5 = 50000;

                            for (int i = 0; statement5[i] != '\0'; i++) {
                                putchar(statement5[i]);
                                fflush(stdout);

                                usleep(delay5);
                            }

                            putchar('\n');


                            break;
                       }
                }
        }

        else{
            printf("\nThe Floor Number you enter is invalid please try again..\n\n"); //if user enter an invalid floor number
        }
    }



    //Incident when a power cut happens before user enter the lift.A notice for user.


    if(power==false){

        printf("\n");
        char statement7[] = "Power Cut is Detected.Please Use the staircase..";
        int delay7 = 50000;

        for (int i = 0; statement7[i] != '\0'; i++) {
            putchar(statement7[i]);
            fflush(stdout);

            usleep(delay7);
        }
        putchar('\n');
        printf("\n");

    }

}



