/*Hadi Babalou's introduction to computing systems project - Phase 1*/
#include <stdio.h>
int first_time = 1;
main()
{
	int check1 = 1, check2 = 1, check3 = 1;
	long long int user1 = 0, user2 = 0, user3 = 0;
	long int pass1 = 0, pass2 = 0, pass3 = 0;
	char buff_cleaner;
	if (first_time == 1)
	{
		printf("welcome!\n\n");
		first_time = 0;
	}
	while (check1 == 1) /*main menu*/
	{
		int mm_comm = 0; /*command for main menu*/
		int mm_comm_check;
		int check2 = 1;
		printf("please choose one of the following options:\n");
		printf("1 to signup			2 to login			3 to quit\n");
		mm_comm_check = scanf("%d", &mm_comm);
		while ((buff_cleaner = getchar()) != '\n');
		if (mm_comm_check == 1)
		{
			if (mm_comm == 1) /*SignUp menu*/
			{
				if ((user1 == 0) || (user2 == 0) || (user3 == 0))
				{
					long long int temp_user = 0;
					long int temp_pass = 0, temp_re_pass = 0;
					printf("enter your phone number: ");
					int user_check;
					user_check = scanf("%lld", &temp_user);
					while ((buff_cleaner = getchar()) != '\n');
					if (user_check == 0)
					{
						printf("wrong phone number format!\n");
					}
					else
					{
						if ((temp_user < 9999999999) && (temp_user > 9010000000)) /*checking format of the phone number*/
						{
							if ((temp_user == user1) || (temp_user == user2) || (temp_user == user3)) /*existed username*/
							{
								printf("phone number exist. please go to login page\n");
							}
							else /*getting password from user*/
							{
								int pass_check = 1;
								while (pass_check == 1)
								{
									int pass_format_check, re_pass_format_check;
									printf("enter your password:  ");
									pass_format_check = scanf("%ld", &temp_pass);
									while ((buff_cleaner = getchar()) != '\n');
									if ((pass_format_check == 1) && ((temp_pass > 0) && (temp_pass < 1000000)))
									{
										printf("re-enter your password:  ");
										re_pass_format_check = scanf("%ld", &temp_re_pass);
										while ((buff_cleaner = getchar()) != '\n');
										if (re_pass_format_check == 1)
										{
											if (temp_pass == temp_re_pass)
											{
												pass_check = 0;
												if (user1 == 0)
												{
													user1 = temp_user;
													pass1 = temp_pass;
													printf("signup was successful!\n");
												}
												else if (user2 == 0)
												{
													user2 = temp_user;
													pass2 = temp_pass;
													printf("signup was successful!\n");
												}
												else if (user3 == 0)
												{
													user3 = temp_user;
													pass3 = temp_pass;
													printf("signup was successful!\n");
												}
											}
											else
											{
												printf("password doesn't match\n");
											}
										}
										if (re_pass_format_check == 0)
										{
											printf("password doesn't match\n");
										}
									}
									else
									{
										printf("wrong password format!\n");
									}
								}
							}
						}
						else
						{
							printf("wrong phone number format. please try again\n");
						}
					}
				}
				else
				{
					printf("sorry. no room to join our community :(\n");
				}
			}
			else if (mm_comm == 2) /*login menu*/
			{
				long long int temp_user = 0;
				long int temp_pass = 0;
				int temp_user_check;
				printf("enter your phone number: ");
				temp_user_check = scanf("%lld", &temp_user);
				while ((buff_cleaner = getchar()) != '\n');
				if (temp_user_check == 1)
				{
					if ((temp_user == user1) || (temp_user == user2) || (temp_user == user3))
					{
						printf("enter your password: ");
						int temp_pass_check;
						temp_pass_check = scanf("%ld", &temp_pass);
						while ((buff_cleaner = getchar()) != '\n');
						if (temp_pass_check == 1)
						{
							if (((temp_user == user1) && (temp_pass == pass1)) || ((temp_user == user2) && (temp_pass == pass2)) || ((temp_user == user3) && (temp_pass == pass3)))
							{
								while (check2 == 1)
								{
									int lm_comm; /*login menu command*/
									int lm_comm_check;
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
										if (lm_comm == 5)
										{
											check2 = 0;
										}
									}
									else
									{
										printf("invalid command!\n");
									}
								}
							}
							else
							{
								printf("wrong password\n");
							}
						}
						else
							printf("wrong password format\n");
					}
					else
					{
						printf("phone number doesn't exist\n");
					}
				}
				else
				{
					printf("wrong phone number format!\n");
				}
			}
			else if (mm_comm == 3) /*Quit*/
			{
				printf("Hope to see you again! Goodbye :)\n");
				check1 = 0;
			}
			else /*invalid command for main menu action*/
			{
				printf("oops... you entered wrong code! please try again\n");
			}
		}
		else
		{
			printf("wrong code! try again\n");
		}
	}
}