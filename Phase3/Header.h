#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
//====================================================================================================================
#define USER_ADDRESS "users.txt"
#define MESS_ADDRESS "messages.txt"
//====================================================================================================================
struct USERS
{
	struct tm time;
	char* phone;
	char* user;
	char* pass;
	int login_status;
	struct USERS* next_user;
};
struct MESSAGES
{
	time_t secs;
	struct tm time;
	char* sender;
	char* reciever;
	char* mess;
	int read_status;
	int mes_id;
	struct MESSAGES* next_message;
};
//====================================================================================================================
typedef struct USERS Users;
typedef struct MESSAGES Messages;
//====================================================================================================================
void text_col(char* colour);
char* get_input(void);
char* fget_input(FILE* ffile);
void clear_buffer(void);

int users_end_check(Users* samp);
int messages_end_check(Messages* samp);
int phone_num_check(char* temp_phone);

Users* create_new_user_node(void);
void add_user(Users* users, Messages* messages, char* temp_user, char* temp_pass, char* temp_phone, Users* new_user);
Messages* create_new_message_node(void);

Users* last_user_finder(Users* head);
Users* user_finder(Users* head, char* username);
Users* phone_finder(Users* head, char* phone);
Users* now_user_finder(Users* head);
Messages* last_mess_finder(Messages* head);

void change_messages_info(Messages* messages, char* p_user, char* c_user);

void main_command(Users* users, Messages* messages);
void sub_command(Users* users, Messages* messages);
void signup(Users* users, Messages* messages);
void close(Users* users, Messages* messages);
void login(Users* users, Messages* messages);
void logout(Users* users, Messages* messages);
void info(Users* head);
void about(Users* users);
void edit_user(Users* users, Messages* messages);
void edit_pass(Users* users);
void show_sent(Users* users, Messages* messages);
void sendm(Users* users, Messages* messages);
void show_recieved(Users* users, Messages* messages);
void show_preview(Users* users, Messages* messages);
void read_user_data(Users* users, FILE* userp);
void read_messages_data(Messages* messages, FILE* messp);
void write_user_data(Users* users, FILE* userp);
void write_messages_data(Messages* messages, FILE* messp);
//====================================================================================================================

