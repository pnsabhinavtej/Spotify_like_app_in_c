// only int main with all the files and also dont forget" header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
int main()
{
    printf("THESE ARE THE FOLLOWING COMMANDS: ");
    help();
    printf("Dont hestitate to ask help anytime\n");
    printf("you can look at the instructions anytime by clicking 0 \n");
    printf("Give the command to start\n");
    FILE* his=fopen("history.txt", "w");
    // for(int i=0;i<100;i++)
    // {
    //     new[i]->next=NULL;
    // }
    fprintf(his, "COMMAND HISTORY:\n");
    int history=0;
    int cmd;
    scanf("%d", &cmd);
    if(cmd==14)
    {
        history++;
        printf("YOU ARE MISSING LOT OF FUN!");
        fprintf(his, "%d. Exit\n", history);
        return 0;
    }
    while(cmd!=14)
    {
        if(cmd==0)
        {
            help();
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==1)
        {
            history++;
            fprintf(his, "%d.List all songs\n", history);
            printf("Here's a curated list of songs, feel free to explore all the songs and see what connects your vibe!\n");
            copy_songs();
            printf("\n");
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==2)
        {
            history++;
            fprintf(his, "%d.List all albums\n", history);
            listall_albums();
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==3)
        {
            history++;
            fprintf(his, "%d.Create new album\n", history);
            createnew_album();
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==4)
        {
            history++;
            song_adder_album();
            fprintf(his, "%d.Add song to album\n", history);
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==5)
        {
            history++;
            fprintf(his, "%d.Delete song from album\n", history);
            song_delete_album();
            printf("Deleted the song given by you from the recommended album !\n");
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==6)
        {
            history++;
            fprintf(his, "%d.Add album to playlist\n", history);
            add_album_playlist(&head);
            printf("Added all the songs from the suggested album to your playlist !\n");
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==7)
        {
            history++;
            fprintf(his, "%d.Add song to playlist\n", history);
            add_song_to_playlist(&head);
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==8)
        {
            history++;
            fprintf(his, "%d.Show playlist\n", history);
            show_playlist(head);
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==9)
        {
            history++;
            fprintf(his, "%d.Play next song \n", history);
            next_song_pointer(head);
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==10)
        {
            history++;
            fprintf(his, "%d.Play previous song\n", history);
            prev_song_pointer(head);
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==11)
        {
            history++;
            fprintf(his, "%d.Show current playing song\n", history);
            present_song_pointer(head);
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==12)
        {
            history++;
            fprintf(his, "%d.Remove the song from the playlist\n", history);
            delete_song_playlist(&head);
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else if(cmd==13)
        {
            history++;
            fprintf(his, "%d.Show history\n", history);
            fflush(his);
            // fclose(his);
            printf("your given commands are the following: \n");
            FILE* re=fopen("history.txt", "r");
            char str[100];
            while(fgets(str, sizeof(str), re)!=NULL)
            {
                printf("%s", str);
            }
            printf("\n");
            fclose(re);
            printf("Give the next command...\n");
            scanf("%d", &cmd);
        }
        else
        {
            history++;
            fprintf(his, "%d.Unknown\n", history);
            printf("Please give the command correctly\n");
            printf("You might take help by clicking 0\n");
            printf("Give the next command... (correct one)\n");
            scanf("%d", &cmd);
        }
    }

    history++;
    fprintf(his, "%d. Exit\n", history);
    printf("HOPE YOU ENJOYED!\n");
}