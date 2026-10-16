#include "inverted.h"

void create_database(hash *HT, F_node *head)
{
    F_node *f_temp = head;
    FILE *fp;
    char word[25];

    while (f_temp != NULL)
    {
        fp = fopen(f_temp->f_name, "r");

        if (fp == NULL)
        {
            printf("ERROR: Unable to open file %s\n", f_temp->f_name);
            f_temp = f_temp->link;
            continue;
        }

        while (fscanf(fp, "%24s", word) == 1)
        {
            int index = get_index(word);

            M_node *m_temp = HT[index].H_link;

            while (m_temp != NULL)
            {
                if (strcmp(m_temp->word, word) == 0)
                {
                    S_node *s_temp = m_temp->sub_link;

                    while (s_temp != NULL)
                    {
                        if (strcmp(s_temp->filename, f_temp->f_name) == 0)
                        {
                            s_temp->word_count++;
                            break;
                        }

                        s_temp = s_temp->sub_link;
                    }

                    if (s_temp == NULL)
                    {
                        S_node *new_sub = malloc(sizeof(S_node));

                        if (new_sub == NULL)
                        {
                            fclose(fp);
                            return;
                        }

                        strcpy(new_sub->filename, f_temp->f_name);
                        new_sub->word_count = 1;
                        new_sub->sub_link = m_temp->sub_link;

                        m_temp->sub_link = new_sub;
                        m_temp->file_count++;
                    }

                    break;
                }

                m_temp = m_temp->main_link;
            }

            if (m_temp == NULL)
            {
                M_node *new_main = malloc(sizeof(M_node));

                if (new_main == NULL)
                {
                    fclose(fp);
                    return;
                }

                S_node *new_sub = malloc(sizeof(S_node));

                if (new_sub == NULL)
                {
                    free(new_main);
                    fclose(fp);
                    return;
                }

                strcpy(new_main->word, word);
                new_main->file_count = 1;

                strcpy(new_sub->filename, f_temp->f_name);
                new_sub->word_count = 1;
                new_sub->sub_link = NULL;

                new_main->sub_link = new_sub;

                new_main->main_link = HT[index].H_link;
                HT[index].H_link = new_main;
            }
        }

        fclose(fp);
        f_temp = f_temp->link;
    }
}
