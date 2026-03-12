
#ifndef HEADER_H
#define HEADER_H
typedef struct song 
{
    int index;
    struct song* next;
}song;
typedef struct album
{
    char name[100];
}album;
typedef struct playlist
{
    int index;
    struct playlist* next;
    struct playlist* prev;
}playlist;
extern song* new[100];
extern album albums[100];
extern playlist * head;
extern int playlist_songs_count;
extern int count;
extern int pointer;
extern int arr[100];
extern int freq[100];
void song_finder(int index);
void copy_songs();
void help();
int findindex_album();
void listall_albums();
void createnew_album();
song* create_song(int d);
void song_adder_album();
void song_delete_album();
playlist* create_playlist(int index);
void add_song_to_playlist(playlist** head);
void add_album_playlist(playlist** head);
void show_playlist(playlist* head);
void next_song_pointer(playlist* head);
void prev_song_pointer(playlist* head);
void present_song_pointer(playlist* head);
void delete_song_playlist(playlist** head);
#endif
