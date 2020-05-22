#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check for 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // open memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open card.raw\n ");
        return 2;
    }

    // initalize image outfile
    FILE *img = NULL;

    // declare array to store file name in form 000.jpg
    char filename[8];

    // declare buffer to hold 512 BYTES
    BYTE arr[512];

    // running count for total jpgs found
    int counter = 0;

    while (true)
    {
        // read from memory card a block that contains 512 BYTES
        int bytes_read = fread(arr, sizeof(BYTE), 512, file);

        // if 0 bytes read, must be end of file
        if (bytes_read == 0)
        {
            break;
        }

        // check for jpeg header
        if (arr[0] == 0xff && arr[1] == 0xd8 && arr[2] == 0xff && (arr[3] & 0xf0) == 0xe0)
        {

            // check if first jpeg found
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                counter++;
                img = fopen(filename, "w");
            }

            // if not first jpeg, close previous image file and open new one
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                counter++;
                img = fopen(filename, "w");
            }
        }

        // if an image file is open, write to it
        if (img != NULL)
        {
            fwrite(arr, sizeof(BYTE), bytes_read, img);
        }
    }

    // close open files
    fclose(img);
    fclose(file);

    return 0;
}










