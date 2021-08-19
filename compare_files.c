#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int flag=0;
    printf("COMPARE WORKING..\n");

    if (argc < 3)
    {
        printf("\nInsufficient Arguments: \n");
        return 0;
    }
    else
    {
        fp1 = fopen(argv[1],  "rb");
        if (fp1 == NULL)
        {
            printf("\nError in opening file %s\n", argv[1]);
            flag=1;
        }

        fp2 = fopen(argv[2], "rb");
        if (fp2 == NULL)
        {
            printf("\nError in opening file %s\n", argv[2]);
            flag=1;
        }

        if (flag==1)
        return 1;

        char *buffer_1;
        char *buffer_2;
        long filelen_1;
        long filelen_2;

        fseek(fp1, 0, SEEK_END);	// Jump to the end of the file
        filelen_1 = ftell(fp1);		// Get the current byte offset in the file
        rewind(fp1);			    // Jump back to the beginning of the file

        buffer_1 = (char *)malloc(filelen_1 * sizeof(char)); 	// Enough memory for the file
        fread(buffer_1, filelen_1, 1, fp1); 			        // Read in the entire file
        fclose(fp1);

        fseek(fp2, 0, SEEK_END);	// Jump to the end of the file
        filelen_2 = ftell(fp2);		// Get the current byte offset in the file
        rewind(fp2);			    // Jump back to the beginning of the file

        buffer_2 = (char *)malloc(filelen_2 * sizeof(char));	// Enough memory for the file
        fread(buffer_2, filelen_2, 1, fp2);		                // Read in the entire file
        fclose(fp2);

        if (filelen_1 != filelen_2)
        {
            printf("File sizes are not equal. So, files are not equal.\n");
            return 0;
        }

        int i = memcmp(buffer_1, buffer_2, filelen_1);
        if(i == 0)
        {
            printf("Files are equal!\n");
        }
        else
        {
            printf("Files are not equal!\n");
        }
        return 0;
    }
}
