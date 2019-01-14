
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int word_count(char *word_list, char select_word)
{
    for(int i = 0; i < strlen(word_list); i++)
    {
        if(word_list[i] == select_word)
        {
            return i;
        }
    }

    return strlen(word_list);
}

void new_password(char *pas)
{
    char list[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    char last_word;
    int last_count = 0;
    int count = 0;

    for(int i = 0; i < 256; i++)
    {
        if(!pas[i])
        {
            count = i;
            break;
        }
    }

    if(count != 0)
    {
        last_word = pas[count - 1];
    }
    else
    {
        pas[0] = list[0];
        return;
    }

    int current_word_count;

    if(pas[0] == list[35])
    {
        //printf("%s\n", pas);
    }
    
    if(last_word == list[strlen(list) - 1])
    {
        if(strlen(pas) == 1)
        {
            pas[0] = list[0];
            pas[1] = list[0];
            return;
        }
        
        for(int i = strlen(pas) - 2; i > -1; i--)
        {
            current_word_count = word_count(list, pas[i]);

            if(current_word_count != strlen(list) - 1)
            {
                for(int r = i + 1; r < strlen(pas); r++)
                {
                    pas[r] = list[0];
                }
                
                pas[i] = list[current_word_count + 1];
                return;
            }
            else if(i == 0)
            {
                int ps_length = strlen(pas);
                for(int r = 0; r < ps_length + 1; r++)
                {
                    pas[r] = list[0];
                }
                return;
            }
        }
    }

    last_count = word_count(list, last_word);
    pas[count - 1] = list[last_count + 1];
    return;
}

int main()
{
    char password[256];
    for(int i = 0; i < 36*37 + 3; i++)
    {
        new_password(password);
        printf("%s\n", password);
    }
    /*
    char file_name[] = "testp.pdf";
    char out_file_name[] = "testp.pdf.de";
    char qpdf_shell[] = "./pasword.sh";
    char sh[100];
    sprintf(sh, "%s %s %s %s", qpdf_shell, pasword, file_name, out_file_name);
    printf("%s\n", sh);
    system(sh);
    if(fopen(out_file_name, "r"))
    {
        printf("ok\n");
    }
    else
    {
        printf("no\n");
    }
    */
}

