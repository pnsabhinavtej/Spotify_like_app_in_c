#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
song* new[100]={NULL};
album albums[100];
playlist * head=NULL;
int playlist_songs_count=0;
int count=0;
int pointer=0;
int arr[100];
int freq[100]={0};
void song_finder(int index)
{
    if(index==1)
    {
        printf("Jai Shree Ram (AADIPURUSH)\n");
    }
    else if(index==2)
    {
        printf("Aarambhamele (JERSEY)\n");
    }
    else if(index==3)
    {
        printf("Dheera Dheera (KGF)\n");
    }
    else if(index==4)
    {
        printf("Fear (DEVARA)\n");
    }
    else if(index==5)
    {
        printf("Naatu Naatu (RRR)\n");
    }
    else if(index==6)
    {
        printf("Nijama Kalaa (LUCKY BHASKER)\n");
    }
    else if(index==7)
    {
        printf("Dheevara (BAAHUBALI)\n");
    }
    else if(index==8)
    {
        printf("Dharshana (KARTHIKEYA 2)\n");
    }
    else if(index==9)
    {
        printf("Jai Ballaya (VEERA SIMHA REDDY)\n");
    }
    else if(index==10)
    {
        printf("Inkem Inkem Kavale (GEETHA GOVINDAM)\n");
    }
    else if(index==11)
    {
        printf("Rise Of Shyam (SHYAM SINGHA ROY)\n");
    }
    else if(index==12)
    {
        printf("Kesariya (BRAHMASTRA)\n");
    }
    else if(index==13)
    {
        printf("Apna Bana Le (BHEDIYA)\n");
    }
    else if(index==14)
    {
        printf("Raataan Lambiyan (SHERSHAAH)\n");
    }
    else if(index==15)
    {
        printf("Tere Pyaar Mein (TU JHOOTHI MAIN MAKKAAR)\n");
    }
    else if(index==16)
    {
        printf("Chaleya (JAWAN)\n");
    }
    else if(index==17)
    {
        printf("Tum Hi Ho (AASHIQUI 2)\n");
    }
    else if(index==18)
    {
        printf("Raanjhanaa - Title Track (RAANJHANAA)\n");
    }
    else if(index==19)
    {
        printf("Pasoori Nu (SATYAPREM KI KATHA)\n");
    }
    else if(index==20)
    {
        printf("Ghoomar (PADMAAVAT)\n");
    }
    else if(index==21)
    {
        printf("Manike (THANK GOD)\n");
    }
    else if(index==22)
    {
        printf("Blinding Lights (THE WEEKND)\n");
    }
    else if(index==23)
    {
        printf("Shape of You (ED SHEERAN)\n");
    }
    else if(index==24)
    {
        printf("Believer (IMAGINE DRAGONS)\n");
    }
    else if(index==25)
    {
        printf("Senorita (SHAWN MENDES & CAMILA CABELLO)\n");
    }
    else if(index==26)
    {
        printf("See You Again (WIZ KHALIFA ft. CHARLIE PUTH)\n");
    }
    else if(index==27)
    {
        printf("Counting Stars (ONEREPUBLIC)\n");
    }
    else if(index==28)
    {
        printf("When I Was Your Man (BRUNO MARS)\n");
    }
    else if(index==29)
    {
        printf("Let Her Go (PASSENGER)\n");
    }
    else if(index==30)
    {
        printf("Night Changes (ONE DIRECTION)\n");
    }
    else if(index==31)
    {
        printf("Unholy (SAM SMITH & KIM PETRAS)\n");
    }
}
void copy_songs()
{
    FILE * ptr=fopen("songs.txt", "r");
    char str[100];
    while(fgets(str, sizeof(str), ptr)!=NULL)
    {
        printf("%s", str);
    }
    fclose(ptr);
}
void help()
{
    FILE* fptr;
    fptr=fopen("commands.txt", "r");
    char cmmd[100];
    while(fgets(cmmd, sizeof(cmmd), fptr)!=NULL)
    {
        printf("%s", cmmd);
    }
    fclose(fptr);
    printf("\n");
}
int findindex_album()
{
    if(count==0)
    {
        return -1;
    }
    else
    {
        char searchName[100];
        printf("Enter album name : \n");
        scanf(" %[^\n]", searchName); 
        for(int i = 0; i < count; i++) {
            if(strcmp(albums[i].name, searchName) == 0) 
            {
                return i;

            }
        }
        return -1;
    }
}
void listall_albums()
{
    if(count==0)
    {
        printf("No albums created\n");
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            printf("%d. %s\n", i+1, albums[i].name);
            song* temp=new[i];
            if(freq[i]==0)
            {
                printf("       ");
                printf("No songs added\n");
                continue;
            }
            for(int j=0;j<freq[i];j++)
            {
                printf("       %d.", j+1);
                song_finder(temp->index);
                temp=temp->next;
            }
            // free(temp);
        }
        printf("These are the list of albums made by you!\n");
    }
}
void createnew_album()
{
    printf("Enter the name of the album\n");
    int ch;
    while((ch=getchar())!='\n' && ch!=EOF);
    int def=1;
    fgets(albums[count].name, sizeof(albums[count].name), stdin);
    albums[count].name[strcspn(albums[count].name, "\n")] = 0;
    for(int i = 0; i < count; i++) {
            if(strcmp(albums[i].name, albums[count].name) == 0) 
            {
                def=0;
                break;  
            }
        }
    if(def==0)
    {
        printf("An album already exists with this name.. please try again!\n");
        return;
    }
    else
    {
        count++;
        printf("created new album as per you request!\n");
    }
}

song* create_song(int d)
{
    song* temp;
    temp=malloc(sizeof(song));
    temp->index=d;
    temp->next=NULL;
    return temp;
}
void song_adder_album()
{

    int z=findindex_album();
    if(z==-1)
    {
        printf("Album not found..\n");
        printf("Try again\n");
        return;
    }
    printf("Here are the list of songs..\n");
    copy_songs();
    printf("\n");
    printf("Enter the index of the song you want to add to this album...\n");
    int d;
    scanf("%d", &d);
    if(d<1 || d>31)
    {
        printf("Song not found!\n");
        return;
    }
    song* temp= create_song(d);
    song* abhi=new[z];
    song** ptr=&new[z];
    // int r=freq[z];
    if(freq[z]==0)
    {
        new[z]=temp;
        *ptr=temp;
        freq[z]++;
    }
    else
    {
        for(int i=0;i<freq[z];i++)
        {
            if(d==abhi->index)
            {
                printf("Song is already in the album...\n");
                return;
            }
            abhi=abhi->next;
        }
        abhi=new[z];
        for(int i=0;i<freq[z]-1;i++)
        {
            abhi=abhi->next;
        }
        abhi->next=temp;
        freq[z]++;
    }
    printf("Added the song given by you to the recommended album !\n");
}
void song_delete_album()
{
    int z=findindex_album();
    if(z==-1)
    {
        printf("Album not found..\n");
        printf("Try again\n");
        return;
    }
    song* temp=new[z];
    if(freq[z]==0)
    {
        printf("       ");
        printf("No songs added to delete any song..\n");
        return;
    }
    for(int j=0;j<freq[z];j++)
    {
        printf("       %d.", j+1);
        song_finder(temp->index);
        temp=temp->next;
    }
    printf("Enter the index of the song you want to delete from this album...\n");
    int d;
    scanf("%d", &d);
    if(d>freq[z]+1 || d<0)
    {
        printf("Song not found!\n");
        return;
    }
    freq[z]--;
    temp=new[z];
    int member_album=1;
    if(d==1)
    {
        new[z]=temp->next;
        free(temp);
        printf("Deleted the song given by you from the recommended album !\n");
        return;
    //  free(head);
    }
    else
    {
        for (int i = 1; i < d - 1; i++)
        {
            temp = temp->next;
        }
        song* del = temp->next;        // node to delete
        temp->next = del->next;        // skip it
        free(del);                     // free correct node
    }
    printf("Deleted the song given by you from the recommended album !\n");
}
playlist* create_playlist(int index)
{
    playlist* temp;
    temp=malloc(sizeof(playlist));
    temp->next=NULL;
    temp->prev=NULL;
    temp->index=index;
    return temp;
}
void add_song_to_playlist(playlist** head)
{
    printf("Enter the index of the song\n");
    int index;
    scanf("%d", &index);
    if(index>31 || index<1)
    {
      printf("Please see the list of the songs clearly and give the instructions accordingly\n");
      return;
    }
    int flag=0;
    for(int i=0;i<playlist_songs_count;i++)
    {
      if(arr[i]==index)
      {
        flag=1;
        break;
      }
    }
    if(flag==1)
    {
      printf("The song is already in your playlist...\n");
      return;
    }
    arr[playlist_songs_count]=index;
    playlist* temp =create_playlist(index);
    playlist_songs_count++;
    if(*head==NULL)
    {
        *head=temp;
        printf("Added the song given by you to your playlist !\n");
        return;
    }
    else
    {
        playlist* ptr=*head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
        printf("Added the song given by you to your playlist !\n");
        return;
    }
}
void add_album_playlist(playlist** head)
{
    int z=findindex_album();
    if(z==-1)
    {
        printf("Album not found..\n");
        printf("Try again\n");
        return;
    }
    song* r;
    r=new[z];
    for(int i=0;i<freq[z];i++)
    {
        int bmw=0;
        for(int i=0;i<playlist_songs_count;i++)
        {
            if(arr[i]==r->index)
            {
                bmw=1;
                printf("Playlist already have the song ");
                song_finder(r->index);
                r=r->next;
                break;
            }
        }
        if(bmw==1)
        {
            continue;
        }
        arr[playlist_songs_count]=r->index;
        playlist* temp =create_playlist(r->index);
        playlist_songs_count++;
        if(*head==NULL)
        {
            *head=temp;
        }
        else
        {
            playlist* ptr=*head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->prev=ptr;
        }
        r=r->next; 
    }
    printf("Added all the relavent songs given from the album to your  to your playlist !\n");
    return;
}
void show_playlist(playlist* head)
{
    if(head==NULL)
    {
        printf("There is no song to the playlist! \n");
        return;
    }
    else
    {
        int no=1;
        playlist* ptr=head;
        while(ptr!=NULL)
        {
            printf("%d.", no);
            song_finder(ptr->index);
            no++;
            ptr=ptr->next;
        }
        printf("Turn up the volume and get ready to vibe !\n");
    }
}
void next_song_pointer(playlist* head)
{
    if(head==NULL || head->next==NULL)
    {
        printf("FIRST ADD SONGS TO THE PLAYLIST");
        return;
    }
    else
    {
      if(pointer==0)
      {
        printf("Please give the song you want to listen by giving command 11\n");
        return;
      }
        if(pointer==playlist_songs_count) pointer=0;
        pointer++;
        int member=1;
        playlist* temp=head;
        while(temp!=NULL)
        {
            if(member==pointer)
            {
                printf("clicked on song -> ");
                printf("%d.", member);
                song_finder(temp->index);
                member++;
                temp=temp->next;
            }
            else
            {
                printf("                   ");
                printf("%d.", member);
                song_finder(temp->index);
                member++;
                temp=temp->next;
            }
        }
    }
}
void prev_song_pointer(playlist* head)
{
    if(head==NULL)
    {
        printf("FIRST ADD SONGS TO THE PLAYLIST");
        return;
    }
    else if(head->next==NULL)
    {
        printf("THERE IS ONLY ONE SONG.....");
    }
    else
    {
      if(pointer==0)
      {
        printf("Please give the song you want to listen by giving command 11\n");
        return;
      }
        if(pointer==1) pointer=playlist_songs_count;
        else
        {
            pointer--;
        }
        int member=1;
        playlist* temp=head;
        while(temp!=NULL)
        {
            if(member==pointer)
            {
                printf("clicked on song -> ");
                printf("%d.", member);
                song_finder(temp->index);
                member++;
                temp=temp->next;
            }
            else
            {
                printf("                   ");
                printf("%d.", member);
                song_finder(temp->index);
                member++;
                temp=temp->next;
            }
        }
    }    
}
void present_song_pointer(playlist* head)
{
    if(head==NULL)
    {
        printf("FIRST ADD SONGS TO THE PLAYLIST\n");
        return;
    }
    else
    {
      if(pointer<=0)
      {
        printf("Give the song you want to here\n");
        int d;
        scanf("%d", &d);
        if(d>playlist_songs_count || d<1)
        {
          printf("Please click the correct song you want to listen\n");
        }
        pointer=d;
      }
        int member=1;
        playlist* temp=head;
        while(temp!=NULL)
        {
            if(member==pointer)
            {
                printf("clicked on song -> ");
                printf("%d.", member);
                song_finder(temp->index);
                member++;
                temp=temp->next;
            }
            else
            {
                printf("                   ");
                printf("%d.", member);
                song_finder(temp->index);
                member++;
                temp=temp->next;
            }
        }
        temp=head;
        member=1;

        while(temp!=NULL)
        {
            if(member==pointer)
            {
                printf("Playing the song: ");
                song_finder(temp->index);
                break;
            }
            else
            {
                temp=temp->next;
                member++;
            }
        }
    }    
}
void delete_song_playlist(playlist** head)
{
    playlist* temp=*head;
    int member=1;
    if(temp==NULL)
    {
        printf("First add song to the playlist\n");
    }
    else if(temp->next==NULL)
    {
        printf("This is your playlist...\n");
        if(*head==NULL)
        {
            printf("You didnt add any song to the playlist! \n");
            return;
        }
        else
        {
            int no=1;
            playlist* ptr=*head;
            while(ptr!=NULL)
            {
                printf("%d.", no);
                song_finder(ptr->index);
                no++;
                ptr=ptr->next;
            }
        }
        pointer=0;
        playlist_songs_count--;
        free(temp);
        *head=NULL;
    }
    else
    {
        printf("This is your playlist....\n");
        if(*head==NULL)
        {
            printf("You didnt add any song to the playlist! \n");
            return;
        }
        else
        {
            int no=1;
            playlist* ptr=*head;
            while(ptr!=NULL)
            {
                printf("%d.", no);
                song_finder(ptr->index);
                no++;
                ptr=ptr->next;
            }
        }
        printf("Enter the no which you want to delete\n");
        int name;
        scanf("%d", &name);
        if(name==1)
        {
            // member++;
            pointer=0;
            playlist_songs_count--;
            *head=temp->next;
            temp->next->prev==NULL;
            temp->next==NULL;
            free(temp);
        }
        else if(name>playlist_songs_count && name<1)
        {
            printf("Please see the index of the playlist clearly...\n");
        }
        else
        {
            playlist_songs_count--; 
            while(temp!=NULL)
            {
                if(member==name)
                {
                  if(temp->next==NULL)
                  {
                    pointer=0;
                    temp->prev->next=NULL;
                    temp->prev=NULL;
                    printf("Removed the song \n");
                    song_finder(temp->index);
                    free(temp);
                    break;
                  }
                  else
                  {
                    pointer=0;
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    temp->next=NULL;
                    temp->prev=NULL;
                    printf("Removed the song \n");
                    song_finder(temp->index);
                    free(temp);
                    break;
                  }
                }
                else
                {
                  temp=temp->next;
                  member++;
                }
            }
        }
    }
}