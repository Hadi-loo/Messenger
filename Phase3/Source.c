// Hadi Babalou's Introduction to Computing Systems and Programming project, phase3, part2
//====================================================================================================================
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
//====================================================================================================================
void text_col(char* colour)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (strcmp(colour, "green") == 0)
		SetConsoleTextAttribute(hConsole, 10);
	if (strcmp(colour, "red") == 0)
		SetConsoleTextAttribute(hConsole, 4);
	if (strcmp(colour, "cyan") == 0)
		SetConsoleTextAttribute(hConsole, 15);
	if (strcmp(colour, "lblue") == 0)
		SetConsoleTextAttribute(hConsole, 9);
	if (strcmp(colour, "lcyan") == 0)
		SetConsoleTextAttribute(hConsole, 11);
	if (strcmp(colour, "default") == 0)
		SetConsoleTextAttribute(hConsole, 7);
	return;
}
char* get_input(void)
{
	char* input;
	int i = 2;
	char temp = getchar();
	if ((temp == '\n') || (temp == ' '))
		return "";
	input = (char*)malloc(sizeof(char));
	input[0] = temp;
	temp = getchar();
	while ((temp != '\n') && (temp != ' '))
	{
		input = (char *)realloc(input, i * sizeof(char));
		input[i - 1] = temp;
		i++;
		temp = getchar();
	}
	input = (char*)realloc(input, i * sizeof(char));
	input[i - 1] = '\0'; // put NULL at the end of string
	return input;
}
char* fget_input(FILE* ffile)
{
	char* input;
	int i = 2;
	char temp = fgetc(ffile);
	if (temp == '\n')
		return "";
	input = (char*)malloc(sizeof(char));
	input[0] = temp;
	temp = fgetc(ffile);
	while (temp != '\n')
	{
		input = (char *)realloc(input, i * sizeof(char));
		input[i - 1] = temp;
		i++;
		temp = fgetc(ffile);
	}
	input = (char*)realloc(input, i * sizeof(char));
	input[i - 1] = '\0'; // put NULL at the end of string
	return input;
}
void clear_buffer(void)
{
	fseek(stdin, 0, SEEK_END);
	return;
}

int users_end_check(Users* samp)
{
	if (samp == NULL)
		return 0;
	else if (samp->next_user == NULL)
		return 1;
	else
		return 2;
}
int messages_end_check(Messages* samp)
{
	if (samp == NULL)
		return 0;
	else if (samp->next_message == NULL)
		return 1;
	else
		return 2;
}
int phone_num_check(char* temp_phone)
{
	if ((strlen(temp_phone) == 11) && (temp_phone[0] == '0'))
	{
		for (int i = 1; i < 11; i++)
			if ((temp_phone[i] < '0') || (temp_phone[i] > '9'))
				return 0;
		return 1;
	}
	else
		return 0;
}

Users* create_new_user_node(void)
{
	Users* new_node = (Users*)malloc(sizeof(Users));
	return new_node;
}
void add_user(Users* users, Messages* messages, char* temp_user, char* temp_pass, char* temp_phone, Users* new_user)
{
	new_user->user = (char*)malloc((strlen(temp_user) + 1) * sizeof(char));
	strcpy(new_user->user, temp_user);
	new_user->phone = (char*)malloc((strlen(temp_phone) + 1) * sizeof(char));
	strcpy(new_user->phone, temp_phone);
	new_user->pass = (char*)malloc((strlen(temp_pass) + 1) * sizeof(char));
	strcpy(new_user->pass, temp_pass);
	new_user->login_status = 1;
	time_t t = time(NULL);
	memcpy(&(new_user->time), localtime(&t), sizeof(struct tm));
	new_user->time.tm_year += 1900;
	new_user->time.tm_mon += 1;
	new_user->next_user = NULL;
	(last_user_finder(users))->next_user = new_user;
	return;
}
Messages* create_new_message_node(void)
{
	Messages* new_node = (Messages*)malloc(sizeof(Messages));
	return new_node;
}

Users* last_user_finder(Users* head)
{
	while (users_end_check(head) != 1)
		head = head->next_user;
	return head;
}
Messages* last_mess_finder(Messages* head)
{
	while (messages_end_check(head) != 1)
		head = head->next_message;
	return head;
}
Users* user_finder(Users* head, char* username)
{
	while (users_end_check(head) != 0)
	{
		if (strcmp(head->user, username) == 0)
			return head;
		head = head->next_user;
	}
	return NULL;
}
Users* phone_finder(Users* head, char* phone)
{
	while (users_end_check(head) != 0)
	{
		if (strcmp(head->phone, phone) == 0)
			return head;
		head = head->next_user;
	}
	return NULL;
}
Users* now_user_finder(Users* head)
{
	while (users_end_check(head) != 0)
	{
		if (head->login_status == 1)
			return head;
		head = head->next_user;
	}
	return NULL;
}

void change_messages_info(Messages* messages, char* p_user, char* c_user)
{
	messages = messages->next_message;
	while (messages_end_check(messages) != 0)
	{
		if (strcmp(messages->sender, p_user) == 0)
			messages->sender = c_user;
		if (strcmp(messages->reciever, p_user) == 0)
			messages->reciever = c_user;
		messages = messages->next_message;
	}
	return;
}

void main_command(Users* users, Messages* messages)
{
	text_col("lcyan");
	printf(">> ");
	text_col("default");

	char* comm = get_input();
	if (strcmp(comm, "login") == 0)
		login(users, messages);
	else if (strcmp(comm, "signup") == 0)
		signup(users, messages);
	else if (strcmp(comm, "close") == 0)
		close(users, messages);
	else if (strcmp(comm, "info") == 0)
	{
		info(users);
		main_command(users, messages);
	}
	else if ((strcmp(comm, "about") == 0) || (strcmp(comm, "send") == 0) || (strcmp(comm, "logout") == 0) || (strcmp(comm, "edit_username") == 0) || (strcmp(comm, "edit_pass") == 0) || (strcmp(comm, "show_sent") == 0) || (strcmp(comm, "show_recieved") == 0))
	{
		text_col("red");
		printf("\t\t you need to login first\n");
		text_col("default");
		clear_buffer();
		free(comm);
		main_command(users, messages);
	}
	else {
		text_col("red");
		printf("\t\t invalid command. please try again\n");
		text_col("default");
		clear_buffer();
		free(comm);
		main_command(users, messages);
	}
	return;
}

void signup(Users* users, Messages* messages)
{
	Users* new_user = create_new_user_node();
	char* temp_user = get_input();
	if (user_finder(users, temp_user) == NULL)
	{
		char* temp_pass = get_input();
		if (strlen(temp_pass) >= 6)
		{
			char* temp_phone = get_input();
			if (phone_num_check(temp_phone) == 1)
			{
				if (phone_finder(users, temp_phone) == NULL)
				{
					add_user(users, messages, temp_user, temp_pass, temp_phone, new_user);
					text_col("cyan");
					printf("\t\t signup was successful!\n");
					text_col("default");
					sub_command(users, messages);
				}
				else
				{
					text_col("red");
					printf("\t\t phone number exist\n");
					text_col("default");
					free(new_user);
					main_command(users, messages);
				}
			}
			else
			{
				text_col("red");
				printf("\t\t incorrect phone number\n");
				text_col("default");
				free(new_user);
				main_command(users, messages);
			}
		}
		else
		{
			text_col("red");
			printf("\t\t your password must have 5 characters at least\n");
			text_col("default");
			clear_buffer();
			free(new_user);
			main_command(users, messages);
		}
	}
	else
	{
		text_col("red");
		printf("\t\t username exist\n");
		text_col("default");
		clear_buffer();
		free(new_user);
		main_command(users, messages);
	}
}
void login(Users* users, Messages* messages)
{
	char* temp_user = get_input();
	Users* now_user = user_finder(users, temp_user);
	if (now_user == NULL)
	{
		text_col("red");
		printf("\t\t username doesn't exist\n");
		text_col("default");
		clear_buffer();
		free(temp_user);
		main_command(users, messages);
	}
	else
	{
		char* temp_pass = get_input();
		if (strcmp(now_user->pass, temp_pass) == 0)
		{
			now_user->login_status = 1;
			text_col("cyan");
			printf("\t\t successfully loged in\n");
			text_col("default");
			show_preview(users, messages);
			sub_command(users, messages);
		}
		else
		{
			text_col("red");
			printf("\t\t wrong password\n");
			text_col("default");
			free(temp_user);
			free(temp_pass);
			main_command(users, messages);
		}
	}
}
void info(Users* head)
{
	head = head->next_user;
	text_col("lcyan");
	while (users_end_check(head) != 0)
	{
		printf("\t\t%s\n", head->user);
		head = head->next_user;
	}
	text_col("default");
	printf("\n");
}
void close(Users* users, Messages* messages)
{
	FILE* userp = fopen(USER_ADDRESS, "w");
	FILE* messp = fopen(MESS_ADDRESS, "w");
	write_user_data(users, userp);
	write_messages_data(messages, messp);
	text_col("lcyan");
	printf("\n\n\t\t\t Hope to see you again! :)\n\n\n\n");
	text_col("default");
}

void sub_command(Users* users, Messages* messages)
{
	text_col("lcyan");
	printf(">> ");
	text_col("default");

	char* sub_comm = get_input();
	if (strcmp(sub_comm, "logout") == 0)
		logout(users, messages);
	else if (strcmp(sub_comm, "edit_username") == 0)
	{
		edit_user(users, messages);
		sub_command(users, messages);
	}
	else if (strcmp(sub_comm, "edit_pass") == 0)
	{
		edit_pass(users);
		sub_command(users, messages);
	}
	else if (strcmp(sub_comm, "send") == 0)
	{
		sendm(users, messages);
		sub_command(users, messages);
	}
	else if (strcmp(sub_comm, "show_sent") == 0)
	{
		show_sent(users, messages);
		sub_command(users, messages);
	}
	else if (strcmp(sub_comm, "show_recieved") == 0)
	{
		show_recieved(users, messages);
		sub_command(users, messages);
	}
	else if (strcmp(sub_comm, "info") == 0)
	{
		info(users);
		sub_command(users, messages);
	}
	else if (strcmp(sub_comm, "about") == 0)
	{
		about(users);
		sub_command(users, messages);
	}
	else if (strcmp(sub_comm, "close") == 0)
		close(users, messages);
	else if (strcmp(sub_comm, "login") == 0)
	{
		text_col("red");
		printf("\t\t you need to logout first\n");
		text_col("default");
		clear_buffer();
		free(sub_comm);
		sub_command(users, messages);
	}
	else if (strcmp(sub_comm, "signup") == 0)
	{
		text_col("red");
		printf("\t\t you need to logout first\n");
		text_col("default");
		clear_buffer();
		free(sub_comm);
		sub_command(users, messages);
	}
	else
	{
		text_col("red");
		printf("\t\t invalid command\n");
		text_col("default");
		clear_buffer();
		free(sub_comm);
		sub_command(users, messages);
	}
}

void about(Users* users)
{
	char* temp_user = get_input();
	Users* now_user = user_finder(users, temp_user);
	if (now_user == NULL)
	{
		text_col("red");
		printf("\t\t username doesn't exist\n");
		text_col("default");
		free(temp_user);
	}
	else
	{
		text_col("lcyan");
		printf("\t user name: %s\n", now_user->user);
		printf("\t phone number: %s\n", now_user->phone);
		printf("\t signed up in %d/%02d/%02d %02d:%02d:%02d\n", now_user->time.tm_mday, now_user->time.tm_mon, now_user->time.tm_year, now_user->time.tm_hour, now_user->time.tm_min, now_user->time.tm_sec);
		free(temp_user);
		text_col("default");
	}
}
void edit_user(Users* users, Messages* messages)
{
	char* temp_user = get_input();
	if (user_finder(users, temp_user) == NULL)
	{
		Users* now_user = now_user_finder(users);
		change_messages_info(messages, now_user->user, temp_user);
		now_user->user = temp_user;
		text_col("cyan");
		printf("\t\t username successfully changed\n");
		text_col("default");
	}
	else
	{
		text_col("red");
		printf("\t\t username exist\n");
		text_col("default");
		free(temp_user);
	}
}
void edit_pass(Users* users)
{
	char* temp_pass = get_input();
	if (strlen(temp_pass) >= 6)
	{
		Users* now_user = now_user_finder(users);
		if (strcmp(now_user->pass, temp_pass) == 0)
		{
			text_col("red");
			printf("\t\t this is your current password!\n");
			text_col("default");
			free(temp_pass);
		}
		else
		{
			now_user->pass = temp_pass;
			text_col("cyan");
			printf("\t\t password successfully changed\n");
			text_col("default");
		}
	}
	else
	{
		text_col("red");
		printf("\t\t password must have 5 characters at least\n");
		text_col("default");
		free(temp_pass);
	}
}
void sendm(Users* users, Messages* messages)
{
	char* temp_user = get_input();
	Users* now_user = now_user_finder(users);
	Users* dest_user = user_finder(users, temp_user);
	if (dest_user == NULL)
	{
		text_col("red");
		printf("\t\t username doesn't exist\n");
		text_col("default");
		free(temp_user);
	}
	else
	{
		char* temp_mess = get_input();
		Messages* last_message = last_mess_finder(messages);
		Messages* new_node = create_new_message_node();
		new_node->mess = temp_mess;
		new_node->read_status = 0;
		new_node->mes_id = last_message->mes_id + 1;
		new_node->sender = now_user->user;
		new_node->reciever = dest_user->user;
		time_t t = time(NULL);
		new_node->secs = t;
		memcpy(&(new_node->time), localtime(&t), sizeof(struct tm));
		new_node->time.tm_year += 1900;
		new_node->time.tm_mon += 1;
		new_node->next_message = NULL;
		last_message->next_message = new_node;
		text_col("cyan");
		printf("\t\t message successfully sent\n");
		text_col("default");
	}
}
void show_sent(Users* users, Messages* messages)
{
	char* dest_username = get_input();
	Users* dest_user = user_finder(users, dest_username);
	if (dest_user == NULL)
	{
		text_col("red");
		printf("\t\t username doesn't exist\n");
		text_col("default");
		free(dest_username);
	}
	else
	{
		messages = messages->next_message;
		Users* now_user = now_user_finder(users);
		int empty_check = 0;
		while (messages_end_check(messages) != 0)
		{
			if (strcmp(now_user->user, messages->sender) == 0)
			{
				if (strcmp(dest_username, messages->reciever) == 0)
				{
					if (messages->read_status == 0)
						text_col("green");
					printf("\t\t message ID: %d\n", messages->mes_id);
					printf("\t\t sent in %02d/%02d/%02d %02d:%02d:%02d to %s\n", messages->time.tm_mday, messages->time.tm_mon, messages->time.tm_year, messages->time.tm_hour, messages->time.tm_min, messages->time.tm_sec, dest_username);
					printf("\t\t %s\n\n", messages->mess);
					empty_check = 1;
					if (messages->read_status == 0)
						text_col("default");
				}
			}
			messages = messages->next_message;
		}
		if (empty_check == 0)
		{
			printf("\t\t there is no messages to show\n");
			free(dest_username);
		}
	}
}
void show_recieved(Users* users, Messages* messages)
{
	char* dest_username = get_input();
	Users* dest_user = user_finder(users, dest_username);
	if (dest_user == NULL)
	{
		text_col("red");
		printf("\t\t username doesn't exist\n");
		text_col("default");
		free(dest_username);
	}
	else
	{
		messages = messages->next_message;
		Users* now_user = now_user_finder(users);
		int empty_check = 0;
		while (messages_end_check(messages) != 0)
		{
			if (strcmp(dest_username, messages->sender) == 0)
			{
				if (strcmp(now_user->user, messages->reciever) == 0)
				{
					printf("\t\t message ID: %d\n", messages->mes_id);
					printf("\t\t sent in %02d/%02d/%02d %02d:%02d:%02d from %s\n", messages->time.tm_mday, messages->time.tm_mon, messages->time.tm_year, messages->time.tm_hour, messages->time.tm_min, messages->time.tm_sec, dest_username);
					printf("\t\t %s\n\n", messages->mess);
					messages->read_status = 1;
					empty_check = 1;
				}
			}
			messages = messages->next_message;
		}
		if (empty_check == 0)
		{
			printf("\t\t there is no messages to show\n");
			free(dest_username);
		}
	}
}
void show_preview(Users* users, Messages* messages)
{
	messages = messages->next_message;
	Users* now_user = now_user_finder(users);
	int empty_check = 0;
	while (messages_end_check(messages) != 0)
	{
		if (strcmp(now_user->user, messages->reciever) == 0)
		{
			if (messages->read_status == 0)
			{
				if (empty_check == 0)
					printf("\n\t\t Unread messages:\n");
				printf("\n\t\t message ID: %d\n", messages->mes_id);
				printf("\t\t sent in %02d/%02d/%02d %02d:%02d:%02d from %s\n", messages->time.tm_mday, messages->time.tm_mon, messages->time.tm_year, messages->time.tm_hour, messages->time.tm_min, messages->time.tm_sec, messages->sender);
				empty_check = 1;
			}
		}
		messages = messages->next_message;
	}
	if (empty_check == 0)
	{
		printf("\t\t there is no messages to show\n");
	}
}
void logout(Users* users, Messages* messages)
{
	Users* now_user = now_user_finder(users);
	if (now_user == NULL)
	{
		text_col("red");
		printf("\t\t you need to login first\n");
		text_col("default");
		main_command(users, messages);
	}
	else
	{
		now_user->login_status = 0;
		text_col("cyan");
		printf("\t\t successfully loged out\n");
		text_col("default");
		main_command(users, messages);
	}
}

void read_user_data(Users* users, FILE* userp)
{
	int n = atoi(fget_input(userp));
	for (int i = 0; i < n; i++)
	{
		Users* new_user = create_new_user_node();
		new_user->user = fget_input(userp);
		new_user->pass = fget_input(userp);
		new_user->phone = fget_input(userp);
		new_user->login_status = 0;
		new_user->time.tm_year = atoi(fget_input(userp));
		new_user->time.tm_mon = atoi(fget_input(userp));
		new_user->time.tm_mday = atoi(fget_input(userp));
		new_user->time.tm_hour = atoi(fget_input(userp));
		new_user->time.tm_min = atoi(fget_input(userp));
		new_user->time.tm_sec = atoi(fget_input(userp));
		new_user->next_user = NULL;
		users->next_user = new_user;
		users = users->next_user;
	}
	return;
}
void read_messages_data(Messages* messages, FILE* messp)
{
	int n = atoi(fget_input(messp));
	for (int i = 0; i < n; i++)
	{
		Messages* new_mess = create_new_message_node();
		new_mess->mes_id = atoi(fget_input(messp));
		new_mess->read_status = atoi(fget_input(messp));
		new_mess->sender = fget_input(messp);
		new_mess->reciever = fget_input(messp);
		new_mess->mess = fget_input(messp);
		new_mess->secs = atoi(fget_input(messp));
		new_mess->time.tm_year = atoi(fget_input(messp));
		new_mess->time.tm_mon = atoi(fget_input(messp));
		new_mess->time.tm_mday = atoi(fget_input(messp));
		new_mess->time.tm_hour = atoi(fget_input(messp));
		new_mess->time.tm_min = atoi(fget_input(messp));
		new_mess->time.tm_sec = atoi(fget_input(messp));
		new_mess->next_message = NULL;
		messages->next_message = new_mess;
		messages = messages->next_message;
	}
	return;
}
void write_user_data(Users* users, FILE* userp)
{
	int n = 0;
	Users* counter = users->next_user;
	while (users_end_check(counter) != 0)
	{
		n++;
		counter = counter->next_user;
	}
	fprintf(userp, "%d\n", n);
	if (n == 0)
		return;
	users = users->next_user;
	for (int i = 0; i < n; i++)
	{
		fprintf(userp, "%s\n", users->user);
		fprintf(userp, "%s\n", users->pass);
		fprintf(userp, "%s\n", users->phone);
		fprintf(userp, "%d\n", users->time.tm_year);
		fprintf(userp, "%d\n", users->time.tm_mon);
		fprintf(userp, "%d\n", users->time.tm_mday);
		fprintf(userp, "%d\n", users->time.tm_hour);
		fprintf(userp, "%d\n", users->time.tm_min);
		fprintf(userp, "%d\n", users->time.tm_sec);
		users = users->next_user;
	}
	return;
}
void write_messages_data(Messages* messages, FILE* messp)
{
	Messages* last_mess = last_mess_finder(messages);
	fprintf(messp, "%d\n", last_mess->mes_id);
	if (last_mess->mes_id == 0)
		return;
	messages = messages->next_message;
	for (int i = 0; i < last_mess->mes_id; i++)
	{
		fprintf(messp, "%d\n", messages->mes_id);
		fprintf(messp, "%d\n", messages->read_status);
		fprintf(messp, "%s\n", messages->sender);
		fprintf(messp, "%s\n", messages->reciever);
		fprintf(messp, "%s\n", messages->mess);
		fprintf(messp, "%d\n", (int)messages->secs);
		fprintf(messp, "%d\n", messages->time.tm_year);
		fprintf(messp, "%d\n", messages->time.tm_mon);
		fprintf(messp, "%d\n", messages->time.tm_mday);
		fprintf(messp, "%d\n", messages->time.tm_hour);
		fprintf(messp, "%d\n", messages->time.tm_min);
		fprintf(messp, "%d\n", messages->time.tm_sec);
		messages = messages->next_message;
	}
	return;
}
//====================================================================================================================
int main(void)
{
	Users users;
	Messages messages;

	users.user = "";
	users.phone = "";
	users.next_user = NULL;
	messages.next_message = NULL;
	messages.mes_id = 0;

	FILE* userp = fopen(USER_ADDRESS, "r");
	FILE* messp = fopen(MESS_ADDRESS, "r");
	if ((userp != NULL) && (messp != NULL))
	{
		read_user_data(&users, userp);
		read_messages_data(&messages, messp);
	}

	main_command(&users, &messages);
}