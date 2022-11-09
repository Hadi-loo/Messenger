#include <stdio.h>
#include <time.h>
//====================================================================================================================
long long int user1 = 0, user2 = 0, user3 = 0, temp_user = 0;
long int pass1 = 0, pass2 = 0, pass3 = 0, temp_pass = 0, temp_re_pass = 0, c_time;
char buff_cleaner;
int mm_comm = 0, lm_comm = 0, wrong_pass_check = 0;
int mm_comm_check, user_check, pass_check, temp_user_check, temp_pass_check, lm_comm_check;
int pass_format_check, re_pass_format_check;
//====================================================================================================================
int welcome(void);
int main_menu(int p_func_check);
int signup_menu(int p_func_check);
int login_menu(int p_func_check);
int user_pass_check(int p_func_check);
int get_pass(int p_func_check);
int show_actions(int p_func_check);
/*
int send_message(void);
int show_message(void);
int create_channel(void);
int create_group(void);
*/
//====================================================================================================================
int welcome(void)
{
	printf("welcome!\n\n");
}
int main_menu(int p_func_check)
{
	if (p_func_check == 1)
		system("cls");
	printf("please choose one of the following options:\n");
	printf("1 to signup			2 to login			3 to quit\n");
	mm_comm_check = scanf("%d", &mm_comm);
	while ((buff_cleaner = getchar()) != '\n');
	if (mm_comm_check == 1)
	{
		if (mm_comm == 1) /*SignUp menu*/
		{
			signup_menu(1);
		}
		else if (mm_comm == 2) /*login menu*/
		{
			login_menu(1);
		}
		else if (mm_comm == 3) /*Quit*/
		{
			system("cls");
			printf("Hope to see you again! Goodbye :)\n");
			return 0;
		}
		else /*invalid command for main menu action*/
		{
			system("cls");
			printf("oops... you entered wrong code! please try again\n");
			main_menu(0);
		}
	}
	else
	{
		system("cls");
		printf("wrong code! try again\n");
		main_menu(0);
	}
}
int signup_menu(int p_func_check)
{
	if ((user1 == 0) || (user2 == 0) || (user3 == 0))
	{
		if (p_func_check == 1)
			system("cls");
		printf("enter your phone number: ");
		user_check = scanf("%lld", &temp_user);
		while ((buff_cleaner = getchar()) != '\n');
		if (user_check == 1)
		{
			if ((temp_user < 9999999999) && (temp_user > 9010000000)) /*checking format of the phone number*/
			{
				if ((temp_user != user1) && (temp_user != user2) && (temp_user != user3))
				{
					get_pass(1);
				}
				else
				{
					system("cls");
					printf("phone number exist\n");
					main_menu(0);
				}
			}
			else
			{
				system("cls");
				printf("invalid phone nmber\n");
				signup_menu(0);
			}
		}
		else
		{
			system("cls");
			printf("wrong phone number format!\n");
			signup_menu(0);
		}
	}
	else
	{
		system("cls");
		printf("sorry. no room to join our community :(\n");
		main_menu(0);
	}
}
int get_pass(int p_func_check)
{
	if (p_func_check == 1)
		system("cls");
	printf("enter your password:  ");
	pass_format_check = scanf("%ld", &temp_pass);
	while ((buff_cleaner = getchar()) != '\n');
	if ((pass_format_check == 1) && ((temp_pass > 0) && (temp_pass < 1000000)))
	{
		system("cls");
		printf("re-enter your password:  ");
		re_pass_format_check = scanf("%ld", &temp_re_pass);
		while ((buff_cleaner = getchar()) != '\n');
		if (re_pass_format_check == 1)
		{
			if (temp_pass == temp_re_pass)
			{
				if (user1 == 0)
				{
					user1 = temp_user;
					pass1 = temp_pass;
					system("cls");
					printf("signup was successful!\n");
					show_actions(0);
				}
				else if (user2 == 0)
				{
					user2 = temp_user;
					pass2 = temp_pass;
					system("cls");
					printf("signup was successful!\n");
					show_actions(0);
				}
				else if (user3 == 0)
				{
					user3 = temp_user;
					pass3 = temp_pass;
					system("cls");
					printf("signup was successful!\n");
					show_actions(0);
				}
			}
			else
			{
				system("cls");
				printf("password doesn't match\n");
				get_pass(0);
			}
		}
		else
		{
			system("cls");
			printf("invalid password\n");
			get_pass(0);
		}
	}
	else
	{
		system("cls");
		printf("invalid password\n");
		get_pass(0);
	}
}
int login_menu(int p_func_check)
{
	if (p_func_check == 1)
		system("cls");
	printf("enter your phone number: ");
	temp_user_check = scanf("%lld", &temp_user);
	while ((buff_cleaner = getchar()) != '\n');
	if (temp_user_check == 1)
	{
		if ((temp_user == user1) || (temp_user == user2) || (temp_user == user3))
		{
			user_pass_check(1);
		}
		else
		{
			system("cls");
			printf("phone number doesn't exist\n");
			main_menu(0);
		}
	}
	else
	{
		system("cls");
		printf("wrong phone number format!\n");
		main_menu(0);
	}
}
int show_actions(int p_func_check)
{
	if (p_func_check == 1)
		system("cls");
	printf("what do you want to do?!\n");
	printf("1. send message\n");
	printf("2. show messages\n");
	printf("3. create channel\n");
	printf("4. create group\n");
	printf("5. log out\n");
	lm_comm_check = scanf("%d", &lm_comm);
	while ((buff_cleaner = getchar()) != '\n');
	if (lm_comm_check == 1)
	{
		if (lm_comm == 1)
		{
			//send_message();
			show_actions(1);
		}
		else if (lm_comm == 2)
		{
			//show_message();
			show_actions(1);
		}
		else if (lm_comm == 3)
		{
			//create_channel();
			show_actions(1);
		}
		else if (lm_comm == 4)
		{
			//create_group();
			show_actions(1);
		}
		else if (lm_comm == 5)
		{
			main_menu(1);
		}
		else
		{
			system("cls");
			printf("wrong command\n");
			show_actions(0);
		}

	}
	else
	{
		system("cls");
		printf("invalid command\n");
		show_actions(0);
	}
}
int user_pass_check(int p_func_check)
{
	if (p_func_check == 1)
		system("cls");
	printf("enter your password: ");
	temp_pass_check = scanf("%ld", &temp_pass);
	while ((buff_cleaner = getchar()) != '\n');
	if (temp_pass_check == 1)
	{
		if (((temp_user == user1) && (temp_pass == pass1)) || ((temp_user == user2) && (temp_pass == pass2)) || ((temp_user == user3) && (temp_pass == pass3)))
		{
			show_actions(1);
		}
		else
		{
			wrong_pass_check += 1;
			if (wrong_pass_check == 3)
			{
				c_time = time(NULL);
				system("cls");
				printf("you've entered 3 incorrect passwords! now you have to wait 30 seconds\n");
				while ((time(NULL) - c_time) < 30);
				wrong_pass_check = 0;
				main_menu(0);
			}
			else
			{
				system("cls");
				printf("wrong password\n");
				user_pass_check(0);
			}
			//login_menu();
		}
	}
	else
	{
		system("cls");
		printf("wrong password format\n");
		login_menu(0);
	}
}
/*
int send_message(void)
{

}
int show_message(void)
{

}
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
	welcome();
	main_menu(1);
}