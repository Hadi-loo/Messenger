// Hadi Babalou's Introduction to Computing Systems and Programming project, phase2, part1
//====================================================================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//====================================================================================================================
// defining const values
#define n_users 4
#define max_len 21
#define mes_max_len 31
#define max_mes 10
#define phone_len 12
//====================================================================================================================
// declaring functions
void main_menu(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void signup_menu(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void get_pass(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void get_user(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void login_menu(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void user_pass_check(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, int wrong_pass_check, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void show_actions(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void send_message(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void show_message(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void send_message(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void show_message(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void show_recieved_messages(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
void show_sent_messages(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len]);
//====================================================================================================================
// defining functions
void main_menu(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	if (p_func_check == 1)
		system("cls");
	printf("please choose one of the following options:\n");
	printf("1 to signup			2 to login			3 to quit\n");
	int mm_comm = 0, mm_comm_check;
	mm_comm_check = scanf("%d", &mm_comm);
	char buff_cleaner;
	while ((buff_cleaner = getchar()) != '\n');
	if (mm_comm_check == 1)
	{
		if (mm_comm == 1) /*SignUp menu*/
		{
			signup_menu(1, phone, user, pass, sent_messages, recieved_messages);
		}
		else if (mm_comm == 2) /*login menu*/
		{
			login_menu(1, phone, user, pass, sent_messages, recieved_messages);
		}
		else if (mm_comm == 3) /*Quit*/
		{
			system("cls");
			printf("Hope to see you again! Goodbye :)\n");
			return;
		}
		else /*invalid command for main menu action*/
		{
			system("cls");
			printf("oops... you entered wrong code! please try again\n");
			main_menu(0, phone, user, pass, sent_messages, recieved_messages);
		}
	}
	else  /*invalid command for main menu action*/
	{
		system("cls");
		printf("wrong code! try again\n");
		main_menu(0, phone, user, pass, sent_messages, recieved_messages);
	}
}

void signup_menu(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	int empty_user_check = 0, empty_user_index;
	int phone_check = 1;
	char temp_phone[2 * phone_len];
	char null[] = { NULL };
	if (p_func_check == 1)
		system("cls");
	for (int i = 0; i < n_users; i++)
	{
		if (strcmp(phone[i], null) == 0)
		{
			empty_user_check = 1;
			empty_user_index = i;
			break;
		}
	}
	if (empty_user_check == 1)
	{
		printf("enter your phone number: ");
		scanf("%[^\n]s", temp_phone);
		char buff_cleaner;
		while ((buff_cleaner = getchar()) != '\n');
		if (strlen(temp_phone) == phone_len - 1)
		{
			if (temp_phone[0] == '0')
			{
				for (int i = 1; i < phone_len - 1; i++)
				{
					if ((temp_phone[i] < '0') || (temp_phone[i] > '9'))
					{
						phone_check = 0;
						break;
					}
				}
			}
			else
			{
				phone_check = 0;
			}
		}
		else
		{
			phone_check = 0;
		}
		if (phone_check == 1)
		{
			int frequent_phone = 1;
			for (int i = 0; i < n_users; i++)
			{
				if (strcmp(temp_phone, phone[i]) == 0)
				{
					frequent_phone = 0;
					break;
				}
			}
			if (frequent_phone == 1)
			{
				strcpy(phone[empty_user_index], temp_phone);
				get_pass(1, phone, user, pass, empty_user_index, sent_messages, recieved_messages);
			}
			else
			{
				system("cls");
				printf("phone number exist\n");
				main_menu(0, phone, user, pass, sent_messages, recieved_messages);
			}
		}
		else
		{
			system("cls");
			printf("wrong phone number format!\n");
			signup_menu(0, phone, user, pass, sent_messages, recieved_messages);
		}
	}
	else
	{
		system("cls");
		printf("sorry. no room to join our community :(\n");
		main_menu(0, phone, user, pass, sent_messages, recieved_messages);
	}
}
void get_pass(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	char temp_pass[2*max_len] = { NULL }, temp_re_pass[2*max_len] = { NULL };
	int pass_check = 1;
	if (p_func_check == 1)
		system("cls");
	printf("enter your password:  ");
	scanf("%[^\n]s", temp_pass);
	char buff_cleaner;
	while ((buff_cleaner = getchar()) != '\n');
	for (unsigned int i = 0; i < strlen(temp_pass); i++)
		if ((temp_pass[i] == ' ') || (temp_pass[i] == '\t'))
		{
			pass_check = 0;
			break;
		}
	if ((strlen(temp_pass)>5) && (strlen(temp_pass)<21) && (pass_check == 1))
	{
		system("cls");
		printf("re-enter your password:  ");
		scanf("%[^\n]s", temp_re_pass);
		char buff_cleaner;
		while ((buff_cleaner = getchar()) != '\n');
		if (strcmp(temp_pass, temp_re_pass) == 0)
		{
			strcpy(pass[index], temp_pass);
			get_user(1, phone, user, pass, index, sent_messages, recieved_messages);
		}
		else
		{
			system("cls");
			printf("password doesn't match\n");
			get_pass(0, phone, user, pass, index, sent_messages, recieved_messages);
		}
	}
	else
	{
		system("cls");
		printf("invalid password\n");
		get_pass(0, phone, user, pass, index, sent_messages, recieved_messages);
	}
}
void get_user(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	char temp_user[2 * max_len] = { NULL };
	int user_check = 1;
	if (p_func_check == 1)
		system("cls");
	printf("enter your username:  ");
	scanf("%[^\n]s", temp_user);
	char buff_cleaner;
	while ((buff_cleaner = getchar()) != '\n');
	for (unsigned int i = 0; i < strlen(temp_user); i++)
		if (temp_user[i] == ' ')
		{
			user_check = 0;
			break;
		}
	if ((strlen(temp_user) < 21) && (user_check == 1))
	{
		int frequent_user = 1;
		for (int i = 0; i < index; i++)
		{
			if (strcmp(temp_user, user[i]) == 0)
			{
				frequent_user = 0;
				break;
			}
		}
		if (frequent_user == 1)
		{
			system("cls");
			strcpy(user[index], temp_user);
			printf("signup was successful!\n");
			show_actions(0, phone, user, pass, index, sent_messages, recieved_messages);
		}
		else
		{
			system("cls");
			printf("username exist\n");
			get_user(0, phone, user, pass, index, sent_messages, recieved_messages);
		}
	}
	else
	{
		system("cls");
		printf("username can't be more than 20 characters and space can't be used in it\n");
		get_user(0, phone, user, pass, index, sent_messages, recieved_messages);
	}
}

void login_menu(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	char temp_user[2 * max_len] = { NULL };
	int index;
	if (p_func_check == 1)
		system("cls");
	printf("enter your username: ");
	scanf("%[^\n]s", temp_user);
	char buff_cleaner;
	while ((buff_cleaner = getchar()) != '\n');
	int user_existence = 0;
	for (int i = 0; i < n_users; i++)
	{
		if (strcmp(user[i], temp_user) == 0)
		{
			user_existence = 1;
			index = i;
			break;
		}
	}
	if (user_existence == 1)
	{
		user_pass_check(1, phone, user, pass, index, 0, sent_messages, recieved_messages);
	}
	else
	{
		system("cls");
		printf("username doesn't exist\n");
		main_menu(0, phone, user, pass, sent_messages, recieved_messages);
	}
}
void user_pass_check(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, int wrong_pass_check, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	char temp_pass[2*max_len] = { NULL };
	if (p_func_check == 1)
		system("cls");
	printf("enter your password: ");
	scanf("%[^\n]s", temp_pass);
	if (strcmp(pass[index], temp_pass) == 0)
	{
		show_actions(1, phone, user, pass, index, sent_messages, recieved_messages);
	}
	else
	{
		wrong_pass_check += 1;
		if (wrong_pass_check == 3)
		{
			time_t c_time = time(NULL);
			system("cls");
			printf("you've entered 3 incorrect passwords! now you have to wait 30 seconds\n");
			while ((time(NULL) - c_time) < 30);
			wrong_pass_check = 0;
			main_menu(1, phone, user, pass, sent_messages, recieved_messages);
		}
		else
		{
			system("cls");
			printf("wrong password\n");
			user_pass_check(0, phone, user, pass, index, wrong_pass_check, sent_messages, recieved_messages);
		}
	}
}
void show_actions(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	if (p_func_check == 1)
		system("cls");
	printf("what do you want to do?!\n");
	printf("1. send message\n");
	printf("2. show messages\n");
	printf("3. create channel\n");
	printf("4. create group\n");
	printf("5. log out\n");
	int lm_comm, lm_comm_check;
	char buff_cleaner;
	lm_comm_check = scanf("%d", &lm_comm);
	while ((buff_cleaner = getchar()) != '\n');
	if (lm_comm_check == 1)
	{
		if (lm_comm == 1)
		{
			send_message(1, phone, user, pass, index, sent_messages, recieved_messages);
		}
		else if (lm_comm == 2)
		{
			show_message(1, phone, user, pass, index, sent_messages, recieved_messages);
		}
		else if (lm_comm == 3)
		{
			//create_channel();
			show_actions(1, phone, user, pass, index, sent_messages, recieved_messages);
		}
		else if (lm_comm == 4)
		{
			//create_group();
			show_actions(1, phone, user, pass, index, sent_messages, recieved_messages);
		}
		else if (lm_comm == 5)
		{
			main_menu(1, phone, user, pass, sent_messages, recieved_messages);
		}
		else
		{
			system("cls");
			printf("wrong command\n");
			show_actions(0, phone, user, pass, index, sent_messages, recieved_messages);
		}
	}
	else
	{
		system("cls");
		printf("invalid command\n");
		show_actions(0, phone, user, pass, index, sent_messages, recieved_messages);
	}
}

void send_message(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	char temp_user[2 * max_len] = { NULL };
	if (p_func_check == 1)
		system("cls");
	printf("enter destination username: ");
	scanf("%[^\n]s", temp_user);
	char buff_cleaner;
	while ((buff_cleaner = getchar()) != '\n');
	int user_existence = 0;
	int destination_index;
	for (int i = 0; i < n_users; i++)
	{
		if (strcmp(user[i], temp_user) == 0)
		{
			user_existence = 1;
			destination_index = i;
			break;
		}
	}
	if (user_existence == 1)
	{
		char null[] = { NULL };
		int empty_mes_index;
		int empty_mes_check = 0;
		for (int i = 0; i < max_mes; i++)
		{
			if (strcmp(sent_messages[index][destination_index][i], null) == 0)
			{
				empty_mes_check = 1;
				empty_mes_index = i;
				break;
			}
		}
		if (empty_mes_check == 1)
		{
			system("cls");
			printf("enter your message: ");
			char temp_message[2 * mes_max_len];
			scanf("%[^\n]s", temp_message);
			char buff_cleaner;
			while ((buff_cleaner = getchar()) != '\n');
			if (strlen(temp_message) > mes_max_len)
			{
				printf("message length must be less than %d\n", mes_max_len);
				send_message(0, phone, user, pass, index, sent_messages, recieved_messages);
			}
			else
			{
				strcpy(sent_messages[index][destination_index][empty_mes_index], temp_message);
				strcpy(recieved_messages[destination_index][index][empty_mes_index], temp_message);
				printf("message sent\n");
				show_actions(0, phone, user, pass, index, sent_messages, recieved_messages);
			}
		}
		else
		{
			printf("maximum amount of messages to this user reached\n");
			show_actions(0, phone, user, pass, index, sent_messages, recieved_messages);
		}

	}
	else
	{
		printf("username not found\n");
		send_message(0, phone, user, pass, index, sent_messages, recieved_messages);
	}
}
void show_message(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	char buff_cleaner;
	int sm_comm = 0, sm_comm_check;
	if (p_func_check == 1)
		system("cls");
	printf("what do you want to do?!\n");
	printf("1. show recieved messages\n");
	printf("2. show sent messages\n");
	sm_comm_check = scanf("%d", &sm_comm);
	while ((buff_cleaner = getchar()) != '\n');
	if (sm_comm_check == 1)
	{
		if (sm_comm == 1)
		{
			show_recieved_messages(1, phone, user, pass, index, sent_messages, recieved_messages);
		}
		else if (sm_comm == 2)
		{
			show_sent_messages(1, phone, user, pass, index, sent_messages, recieved_messages);
		}
		else
		{
			printf("invalid command\n");
			show_message(0, phone, user, pass, index, sent_messages, recieved_messages);
		}
	}
	else
	{
		printf("wrong command format\n");
		show_message(0, phone, user, pass, index, sent_messages, recieved_messages);
	}
}
void show_recieved_messages(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	if (p_func_check == 1)
		system("cls");
	char temp_user[max_len * 2] = { NULL };
	printf("enter destination username: ");
	scanf("%[^\n]s", temp_user);
	char buff_cleaner;
	while ((buff_cleaner = getchar()) != '\n');
	int user_existence = 0;
	int destination_index;
	for (int i = 0; i < n_users; i++)
	{
		if (strcmp(user[i], temp_user) == 0)
		{
			user_existence = 1;
			destination_index = i;
			break;
		}
	}
	if (user_existence == 1)
	{
		char null[] = { NULL };
		for (int i = 0; i < max_mes; i++)
		{
			if (strcmp(recieved_messages[index][destination_index][i], null) == 0)
			{
				if (i == 0)
					printf("there is no messages to show\n");
				break;
			}
			else
			{
				printf("%d) %s\n", i + 1, recieved_messages[index][destination_index][i]);
			}
		}
		show_actions(0, phone, user, pass, index, sent_messages, recieved_messages);
	}
	else
	{
		printf("username doesn't exist\n");
		show_recieved_messages(0, phone, user, pass, index, sent_messages, recieved_messages);
	}
}
void show_sent_messages(int p_func_check, char phone[][phone_len], char user[][max_len], char pass[][max_len], int index, char sent_messages[n_users][n_users][max_mes][mes_max_len], char recieved_messages[n_users][n_users][max_mes][mes_max_len])
{
	if (p_func_check == 1)
		system("cls");
	char temp_user[max_len * 2] = { NULL };
	printf("enter destination username: ");
	scanf("%[^\n]s", temp_user);
	char buff_cleaner;
	while ((buff_cleaner = getchar()) != '\n');
	int user_existence = 0;
	int destination_index;
	for (int i = 0; i < n_users; i++)
	{
		if (strcmp(user[i], temp_user) == 0)
		{
			user_existence = 1;
			destination_index = i;
			break;
		}
	}
	if (user_existence == 1)
	{
		char null[] = { NULL };
		for (int i = 0; i < max_mes; i++)
		{
			if (strcmp(sent_messages[index][destination_index][i], null) == 0)
			{
				if (i == 0)
					printf("there is no messages to show\n");
				break;
			}
			else
			{
				printf("%d) %s\n", i + 1, sent_messages[index][destination_index][i]);
			}
		}
		show_actions(0, phone, user, pass, index, sent_messages, recieved_messages);
	}
	else
	{
		printf("username doesn't exist\n");
		show_sent_messages(0, phone, user, pass, index, sent_messages, recieved_messages);
	}
}
/*
int create_channel(void)
{

}
int create_group(void)
{

}
*/
//====================================================================================================================
int main(void)
{
	char phone[n_users][phone_len] = { NULL };
	char pass[n_users][max_len] = { NULL };
	char user[n_users][max_len] = { NULL };
	char sent_messages[n_users][n_users][max_mes][mes_max_len] = { NULL };
	char recieved_messages[n_users][n_users][max_mes][mes_max_len] = { NULL };
	//------------------------------------------------------------------------------
	printf("welcome!\n\n");
	main_menu(0, phone, user, pass, sent_messages, recieved_messages);
	return 0;
}