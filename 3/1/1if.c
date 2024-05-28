#include<stdio.h>

int gauti_kvadrata(int x,int y){
            if (x > 0 && y > 0)   // Check if both 'x' and 'y' are positive.
            return 0;   // Print a message indicating the quadrant.
        else if (x < 0 && y > 0)   // Check if 'x' is negative and 'y' is positive.
            return 0;   // Print a message indicating the quadrant.
        else if (x < 0 && y < 0)   // Check if both 'x' and 'y' are negative.
            return 0;   // Print a message indicating the quadrant.
        else if (x > 0 && y < 0)   // Check if 'x' is positive and 'y' is negative.
            return 0;  // Print a message indicating the quadrant.
        else if (x == 0 && y == 0)   // Check if both 'x' and 'y' are zero.
            return 0;
        return 0;
}

int main(int argc, char* argv[])
{
    //for initialization of coordinates

    char *filename = argv[1];
    FILE *file;
    file = fopen(filename, "r");

    int x, y;
    while (fscanf(file, "%d %d\n", &x, &y) != EOF)
    {
        gauti_kvadrata(x, y);
    }
    

    

return 0;
}