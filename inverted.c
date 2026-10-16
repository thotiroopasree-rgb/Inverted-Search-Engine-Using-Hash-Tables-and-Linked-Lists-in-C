#include "inverted.h"

/* Function definitions */
int validate_files(char argc,char *argv[], F_node **head)
{
    if(argc <= 1)
    {
        printf("ERROR: enter the files.\n");
		return 0;
    }
    int len=0;
    FILE *fp;
    long int size;
    
    for(int i=1; i < argc; i++ )
    {
        len = strlen(argv[i]);
        if(len < 4)
        {
            printf("INvalid file extension give the file name size more than 4.\n");
            continue;
        }
        
        if(strcmp(argv[i] + (len - 4), ".txt")!= 0)
        {
            printf("ERROR: File must have .txt extension.\n");
            continue;
        }
        fp = fopen(argv[i], "r");

        if(fp == NULL)
        {
            printf("Error: FILE %s does not exists cannot be opened.\n",argv[i]);
            continue;
        }
        fseek(fp,0,SEEK_END);
        size = ftell(fp);
        if(size == 0)
        {
            printf("ERROR: file is empty.\n");
            fclose(fp);
            continue;
        }
        fclose(fp);

        int duplicate = 0;
        F_node *temp = *head;

        while (temp != NULL)
        {
            if (strcmp(argv[i], temp->f_name) == 0)
            {
                duplicate = 1;
                break;
            }

            temp = temp->link;
        }

        if (duplicate)
        {
            printf("ERROR: File %s is already added.\n", argv[i]);
            continue;
        }

        insert_last(head, argv[i]);
        return SUCCESS;
        //print_filenames(&head);

    }

    
}


int insert_last(F_node **head, char *f_name)
{
    F_node *new = malloc(sizeof(F_node));

    if (new == NULL)
    {
        return FAILURE;
    }

    strcpy(new->f_name, f_name);
    new->link = NULL;

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    F_node *temp = *head;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new;

    return SUCCESS;
}
// printing the file names
int print_filenames(F_node *head)
{
    if(head == NULL)
    {
        printf("File list is Empty.\n");
        return FAILURE;
    }
    while(head != NULL)
    {
        printf("%s---->",head->f_name);
        head = head->link;
    }
    printf("NULL");
    printf("\n");
    return SUCCESS;
}